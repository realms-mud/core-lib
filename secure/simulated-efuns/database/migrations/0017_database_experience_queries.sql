DROP PROCEDURE IF EXISTS prepareExperienceQuery;
##
CREATE PROCEDURE prepareExperienceQuery (
    p_playerId int, p_criteria mediumtext, p_operation varchar(20),
    p_limit int, p_offset int, p_excluded mediumtext)
BEGIN
    DECLARE entriesValue longtext;
    DECLARE residualValue longtext DEFAULT JSON_ARRAY();
    DECLARE keyValue longtext;
    DECLARE expectedValue longtext;
    DECLARE scalarValue longtext;
    DECLARE kindValue varchar(20);
    DECLARE nameValue longtext;
    DECLARE predicateValue longtext;
    DECLARE indexValue int DEFAULT 0;
    DECLARE validValue int DEFAULT 1;
    SET @experienceCriteria = observationDecode(p_criteria);
    SET entriesValue = JSON_EXTRACT(@experienceCriteria, '$[1]');
    SET validValue = JSON_UNQUOTE(JSON_EXTRACT(
        @experienceCriteria, '$[0]')) = 'mapping';
    SET predicateValue = CONCAT('playerId=', p_playerId);
    WHILE indexValue < JSON_LENGTH(entriesValue) AND validValue DO
        SET keyValue = JSON_EXTRACT(entriesValue,
            CONCAT('$[', indexValue, ']'));
        SET expectedValue = JSON_EXTRACT(entriesValue,
            CONCAT('$[', indexValue + 1, ']'));
        SET nameValue = JSON_UNQUOTE(JSON_EXTRACT(keyValue, '$[1]'));
        SET kindValue = JSON_UNQUOTE(JSON_EXTRACT(expectedValue, '$[0]'));
        SET scalarValue = JSON_UNQUOTE(JSON_EXTRACT(expectedValue, '$[1]'));
        IF BINARY keyValue = BINARY JSON_ARRAY('string', 'type') THEN
            SET validValue = kindValue = 'string' AND
                CHAR_LENGTH(scalarValue) > 0;
            SET scalarValue = LOWER(scalarValue);
            SET predicateValue = CONCAT(predicateValue, ' AND (searchType=',
                QUOTE(scalarValue), ' OR (searchType>=',
                QUOTE(CONCAT(scalarValue, '.')), ' AND searchType<',
                QUOTE(CONCAT(scalarValue, '/')), '))');
        ELSEIF BINARY keyValue = BINARY JSON_ARRAY('string', 'since') OR
            BINARY keyValue = BINARY JSON_ARRAY('string', 'until') THEN
            SET validValue = kindValue = 'integer' AND
                CAST(scalarValue AS SIGNED) >= 0;
            SET predicateValue = CONCAT(predicateValue,
                IF(nameValue = 'since', ' AND observationTime>=',
                    ' AND observationTime<='), CAST(scalarValue AS SIGNED));
        ELSEIF BINARY keyValue = BINARY JSON_ARRAY('string', 'ID') THEN
            SET validValue = kindValue = 'string';
            SET predicateValue = CONCAT(predicateValue,
                ' AND (observationKey=', QUOTE(scalarValue));
            IF scalarValue REGEXP '^[0-9]{1,10}$' THEN
                SET predicateValue = CONCAT(predicateValue,
                    ' OR (observationKey IS NULL AND id=',
                    CAST(scalarValue AS UNSIGNED), ' AND CAST(id AS CHAR)=',
                    QUOTE(scalarValue), ')');
            END IF;
            SET predicateValue = CONCAT(predicateValue, ')');
        ELSE
            SET residualValue = JSON_ARRAY_APPEND(residualValue, '$',
                JSON_EXTRACT(keyValue, '$'), '$',
                JSON_EXTRACT(expectedValue, '$'));
        END IF;
        SET indexValue = indexValue + 2;
    END WHILE;
    IF COALESCE(validValue, 0) = 0 THEN
        SET predicateValue = CONCAT(predicateValue, ' AND 0');
    ELSEIF JSON_LENGTH(residualValue) > 0 THEN
        SET @experienceCriteria = JSON_ARRAY('mapping',
            JSON_EXTRACT(residualValue, '$'));
        SET predicateValue = CONCAT(predicateValue,
            ' AND observationMatches(searchDocument,@experienceCriteria)=1');
    END IF;
    SET entriesValue = observationDecode(p_excluded);
    SET entriesValue = JSON_EXTRACT(entriesValue, '$[1]');
    SET indexValue = 0;
    WHILE indexValue < JSON_LENGTH(entriesValue) DO
        SET expectedValue = JSON_EXTRACT(entriesValue,
            CONCAT('$[', indexValue, ']'));
        IF JSON_UNQUOTE(JSON_EXTRACT(expectedValue, '$[0]')) = 'string' THEN
            SET predicateValue = CONCAT(predicateValue,
                ' AND COALESCE(observationKey,CAST(id AS CHAR))<>',
                QUOTE(JSON_UNQUOTE(JSON_EXTRACT(expectedValue, '$[1]'))));
        END IF;
        SET indexValue = indexValue + 1;
    END WHILE;
    IF p_operation = 'query' THEN
        SET @experienceSql = CONCAT(
            'SELECT COALESCE(observationKey,CAST(id AS CHAR)),',
            'observationType,actor,subject,participants,observationTime,',
            'location,observationContext,observationMetadata FROM ',
            'experienceObservations WHERE ', predicateValue,
            ' ORDER BY id LIMIT ', LEAST(100, GREATEST(1, p_limit)),
            ' OFFSET ', GREATEST(0, p_offset));
    ELSEIF p_operation = 'minimum' THEN
        SET @experienceSql = CONCAT(
            'SELECT COUNT(*) INTO @experienceResult FROM (SELECT id FROM ',
            'experienceObservations WHERE ', predicateValue, ' LIMIT ',
            GREATEST(1, p_limit), ') matchingObservations');
    ELSEIF p_operation = 'count' THEN
        SET @experienceSql = CONCAT(
            'SELECT COUNT(*) INTO @experienceResult FROM ',
            'experienceObservations WHERE ', predicateValue);
    ELSE
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT =
            'Invalid experience query operation';
    END IF;
    PREPARE experienceQuery FROM @experienceSql;
    IF p_operation <> 'query' THEN
        SET @experienceResult = NULL;
        EXECUTE experienceQuery;
        DEALLOCATE PREPARE experienceQuery;
    END IF;
END;
