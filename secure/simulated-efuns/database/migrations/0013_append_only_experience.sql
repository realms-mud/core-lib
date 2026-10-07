ALTER TABLE `experienceObservations`
  ADD COLUMN `observationKey` varchar(128) DEFAULT NULL;
##
UPDATE `experienceObservations`
SET `observationKey` = CONCAT('legacy-', `id`)
WHERE `observationKey` IS NULL;
##
ALTER TABLE `experienceObservations`
  MODIFY COLUMN `observationKey` varchar(128) NOT NULL,
  ADD UNIQUE KEY `experience_observationKey_unique` (`observationKey`);
##
DROP PROCEDURE IF EXISTS `pruneExperience`;
##
DROP PROCEDURE IF EXISTS `saveExperienceObservation`;
##
CREATE PROCEDURE `saveExperienceObservation` (
	p_observationKey varchar(128),
	p_playerid int,
	p_observationType varchar(80),
	p_actor varchar(200),
	p_subject varchar(200),
	p_participants text,
	p_observationTime bigint,
	p_location varchar(255),
	p_context mediumtext,
	p_metadata mediumtext)
BEGIN
	INSERT INTO experienceObservations (
		observationKey,
		playerId,
		observationType,
		actor,
		subject,
		participants,
		observationTime,
		location,
		observationContext,
		observationMetadata)
	VALUES (
		p_observationKey,
		p_playerid,
		p_observationType,
		p_actor,
		p_subject,
		p_participants,
		p_observationTime,
		p_location,
		p_context,
		p_metadata)
	ON DUPLICATE KEY UPDATE
		observationKey = experienceObservations.observationKey;
END;
##
DROP FUNCTION IF EXISTS observationDecode;
##
CREATE FUNCTION observationDecode(source LONGTEXT) RETURNS LONGTEXT
DETERMINISTIC NO SQL
BEGIN
	DECLARE cursorPos INT DEFAULT 1;
	DECLARE separatorPos INT;
	DECLARE payloadPos INT;
	DECLARE payloadEnd INT;
	DECLARE payloadSize INT;
	DECLARE countValue INT;
	DECLARE depthValue INT DEFAULT 0;
	DECLARE validValue INT DEFAULT 1;
	DECLARE readyValue INT DEFAULT 0;
	DECLARE tagValue VARCHAR(20);
	DECLARE lengthValue LONGTEXT;
	DECLARE payloadValue LONGTEXT;
	DECLARE nodeValue LONGTEXT;
	DECLARE stackValue LONGTEXT DEFAULT '[]';
	DECLARE frameValue LONGTEXT;
	DECLARE childrenValue LONGTEXT;
	DECLARE resultValue LONGTEXT DEFAULT '["invalid",0]';
	IF LEFT(source, 16) = '@experiences-v2@' THEN
		SET source = SUBSTRING(source, 17);
	ELSEIF LEFT(source, 15) = '@experience-v1@' THEN
		SET source = SUBSTRING(source, 16);
	END IF;
	parseLoop: WHILE validValue = 1 DO
		IF readyValue = 0 THEN
			SET separatorPos = LOCATE(':', source, cursorPos);
			IF separatorPos <= cursorPos THEN
				SET validValue = 0;
			ELSE
				SET tagValue = SUBSTRING(source, cursorPos,
					separatorPos - cursorPos);
				SET payloadPos = separatorPos + 1;
				SET separatorPos = LOCATE(':', source, payloadPos);
				SET lengthValue = SUBSTRING(source, payloadPos,
					separatorPos - payloadPos);
				SET payloadPos = separatorPos + 1;
				SET payloadSize = CAST(lengthValue AS UNSIGNED);
				SET payloadEnd = payloadPos + payloadSize;
				IF lengthValue NOT REGEXP '^[0-9]+$' OR
					tagValue NOT IN
						('string','mapping','array','integer','float') OR
					payloadEnd > CHAR_LENGTH(source) + 1 OR
					(depthValue > 0 AND payloadEnd > CAST(JSON_UNQUOTE(
						JSON_EXTRACT(stackValue,
						CONCAT('$[', depthValue - 1, '].end'))) AS UNSIGNED))
				THEN
					SET validValue = 0;
				ELSE
					SET payloadValue = SUBSTRING(source, payloadPos,
						payloadSize);
					SET cursorPos = payloadEnd;
					IF tagValue IN ('mapping','array') THEN
						SET separatorPos = LOCATE(':', payloadValue);
						SET lengthValue = LEFT(payloadValue, separatorPos - 1);
						IF separatorPos < 2 OR
							lengthValue NOT REGEXP '^[0-9]+$' THEN
							SET validValue = 0;
						ELSE
							SET countValue = CAST(lengthValue AS UNSIGNED) *
								IF(tagValue = 'mapping', 2, 1);
							SET cursorPos = payloadPos + separatorPos;
							SET stackValue = JSON_ARRAY_APPEND(stackValue,
								'$', JSON_OBJECT('tag', tagValue,
								'end', payloadEnd, 'count', countValue,
								'children', JSON_ARRAY()));
							SET depthValue = depthValue + 1;
							IF countValue = 0 THEN
								SET nodeValue = JSON_ARRAY(tagValue,
									JSON_ARRAY());
								SET readyValue = 1;
								SET depthValue = depthValue - 1;
								SET stackValue = JSON_REMOVE(stackValue,
									CONCAT('$[', depthValue, ']'));
								IF cursorPos <> payloadEnd THEN
									SET validValue = 0;
								END IF;
							END IF;
						END IF;
					ELSE
						SET nodeValue = JSON_ARRAY(tagValue, payloadValue);
						SET readyValue = 1;
					END IF;
				END IF;
			END IF;
		ELSEIF depthValue = 0 THEN
			SET resultValue = nodeValue;
			LEAVE parseLoop;
		ELSE
			SET frameValue = JSON_EXTRACT(stackValue,
				CONCAT('$[', depthValue - 1, ']'));
			SET childrenValue = JSON_ARRAY_APPEND(
				JSON_EXTRACT(frameValue, '$.children'), '$',
				JSON_EXTRACT(nodeValue, '$'));
			SET countValue = CAST(JSON_UNQUOTE(JSON_EXTRACT(frameValue,
				'$.count')) AS UNSIGNED) - 1;
			IF countValue = 0 THEN
				IF cursorPos <> CAST(JSON_UNQUOTE(JSON_EXTRACT(frameValue,
					'$.end')) AS UNSIGNED) THEN
					SET validValue = 0;
				END IF;
				SET nodeValue = JSON_ARRAY(JSON_UNQUOTE(
					JSON_EXTRACT(frameValue, '$.tag')),
					JSON_EXTRACT(childrenValue, '$'));
				SET depthValue = depthValue - 1;
				SET stackValue = JSON_REMOVE(stackValue,
					CONCAT('$[', depthValue, ']'));
			ELSE
				SET stackValue = JSON_SET(stackValue,
					CONCAT('$[', depthValue - 1, '].children'),
					JSON_EXTRACT(childrenValue, '$'),
					CONCAT('$[', depthValue - 1, '].count'), countValue);
				SET readyValue = 0;
			END IF;
		END IF;
	END WHILE;
	RETURN IF(validValue, resultValue, '["invalid",0]');
END;
##
DROP FUNCTION IF EXISTS observationLegacy;
##
CREATE FUNCTION observationLegacy(source LONGTEXT, kind VARCHAR(20))
RETURNS LONGTEXT DETERMINISTIC NO SQL
BEGIN
	DECLARE resultValue LONGTEXT DEFAULT '[]';
	DECLARE nodeValue LONGTEXT;
	DECLARE itemValue LONGTEXT;
	DECLARE keyValue LONGTEXT;
	DECLARE scalarValue LONGTEXT;
	DECLARE separatorPos INT;
	DECLARE dividerPos INT;
	DECLARE delimiterValue CHAR(2) DEFAULT CHAR(35,35);
	IF LEFT(source, 16) = '@experiences-v2@' OR
		LEFT(source, 15) = '@experience-v1@' THEN
		SET nodeValue = observationDecode(source);
		IF JSON_UNQUOTE(JSON_EXTRACT(nodeValue, '$[0]')) = kind THEN
			SET resultValue = JSON_EXTRACT(nodeValue, '$[1]');
		END IF;
	ELSE
		WHILE CHAR_LENGTH(source) > 0 DO
			SET separatorPos = LOCATE(delimiterValue, source);
			SET itemValue = IF(separatorPos = 0, source,
				LEFT(source, separatorPos - 1));
			SET source = IF(separatorPos = 0, '',
				SUBSTRING(source, separatorPos + 2));
			IF kind = 'array' THEN
				SET resultValue = JSON_ARRAY_APPEND(resultValue, '$',
					JSON_ARRAY('string', itemValue));
			ELSE
				SET dividerPos = LOCATE(':=:', itemValue);
				IF dividerPos > 0 THEN
					SET keyValue = LEFT(itemValue, dividerPos - 1);
					SET scalarValue = SUBSTRING(itemValue, dividerPos + 3);
					SET nodeValue = JSON_ARRAY('string', scalarValue);
					IF scalarValue REGEXP '^-?[0-9]+$' THEN
						SET nodeValue = JSON_ARRAY('integer', scalarValue);
					ELSEIF LEFT(scalarValue, 1) = '"' AND
						RIGHT(scalarValue, 1) = '"' THEN
						SET nodeValue = JSON_ARRAY('string',
							SUBSTRING(scalarValue, 2,
							CHAR_LENGTH(scalarValue) - 2));
					END IF;
					SET resultValue = JSON_ARRAY_APPEND(resultValue, '$',
						JSON_ARRAY('string', keyValue), '$',
						JSON_EXTRACT(nodeValue, '$'));
				END IF;
			END IF;
		END WHILE;
	END IF;
	RETURN JSON_ARRAY(kind, JSON_EXTRACT(resultValue, '$'));
END;
##
DROP FUNCTION IF EXISTS observationScalarEqual;
##
CREATE FUNCTION observationScalarEqual(expectedValue LONGTEXT,
	actualValue LONGTEXT) RETURNS TINYINT DETERMINISTIC NO SQL
BEGIN
	DECLARE kindValue VARCHAR(20);
	DECLARE resultValue INT DEFAULT 0;
	SET kindValue = JSON_UNQUOTE(JSON_EXTRACT(expectedValue, '$[0]'));
	IF kindValue = JSON_UNQUOTE(JSON_EXTRACT(actualValue, '$[0]')) THEN
		IF kindValue = 'integer' THEN
			SET resultValue = CAST(JSON_UNQUOTE(JSON_EXTRACT(expectedValue,
				'$[1]')) AS SIGNED) = CAST(JSON_UNQUOTE(JSON_EXTRACT(
				actualValue, '$[1]')) AS SIGNED);
		ELSEIF kindValue = 'float' THEN
			SET resultValue = (JSON_UNQUOTE(JSON_EXTRACT(expectedValue,
				'$[1]')) + 0e0) = (JSON_UNQUOTE(JSON_EXTRACT(actualValue,
				'$[1]')) + 0e0);
		ELSEIF kindValue = 'string' THEN
			SET resultValue = BINARY JSON_UNQUOTE(JSON_EXTRACT(expectedValue,
				'$[1]')) = BINARY JSON_UNQUOTE(JSON_EXTRACT(actualValue,
				'$[1]'));
		END IF;
	END IF;
	RETURN COALESCE(resultValue, 0);
END;
##
DROP FUNCTION IF EXISTS observationMember;
##
CREATE FUNCTION observationMember(nodeValue LONGTEXT, keyValue LONGTEXT)
RETURNS LONGTEXT DETERMINISTIC NO SQL
BEGIN
	DECLARE indexValue INT DEFAULT 0;
	DECLARE resultValue LONGTEXT DEFAULT NULL;
	DECLARE entriesValue LONGTEXT;
	IF JSON_UNQUOTE(JSON_EXTRACT(nodeValue, '$[0]')) = 'mapping' THEN
		SET entriesValue = JSON_EXTRACT(nodeValue, '$[1]');
		WHILE indexValue < JSON_LENGTH(entriesValue) DO
			IF observationScalarEqual(JSON_EXTRACT(entriesValue,
				CONCAT('$[', indexValue, ']')), keyValue) THEN
				SET resultValue = JSON_EXTRACT(entriesValue,
					CONCAT('$[', indexValue + 1, ']'));
			END IF;
			SET indexValue = indexValue + 2;
		END WHILE;
	END IF;
	RETURN resultValue;
END;
##
DROP FUNCTION IF EXISTS observationValueMatches;
##
CREATE FUNCTION observationValueMatches(expectedValue LONGTEXT,
	actualValue LONGTEXT) RETURNS TINYINT DETERMINISTIC NO SQL
BEGIN
	DECLARE workValue LONGTEXT DEFAULT '[]';
	DECLARE pairValue LONGTEXT;
	DECLARE expectedKind VARCHAR(20);
	DECLARE actualKind VARCHAR(20);
	DECLARE expectedItems LONGTEXT;
	DECLARE actualItems LONGTEXT;
	DECLARE childValue LONGTEXT;
	DECLARE candidateValue LONGTEXT;
	DECLARE indexValue INT;
	DECLARE candidateIndex INT;
	DECLARE foundValue INT;
	DECLARE validValue INT DEFAULT 1;
	SET workValue = JSON_ARRAY(JSON_ARRAY(JSON_EXTRACT(expectedValue, '$'),
		JSON_EXTRACT(actualValue, '$')));
	WHILE JSON_LENGTH(workValue) > 0 AND validValue DO
		SET pairValue = JSON_EXTRACT(workValue, '$[0]');
		SET workValue = JSON_REMOVE(workValue, '$[0]');
		SET expectedValue = JSON_EXTRACT(pairValue, '$[0]');
		SET actualValue = JSON_EXTRACT(pairValue, '$[1]');
		SET expectedKind = JSON_UNQUOTE(JSON_EXTRACT(expectedValue, '$[0]'));
		SET actualKind = JSON_UNQUOTE(JSON_EXTRACT(actualValue, '$[0]'));
		SET expectedItems = JSON_EXTRACT(expectedValue, '$[1]');
		SET actualItems = JSON_EXTRACT(actualValue, '$[1]');
		IF expectedKind = 'mapping' AND actualKind = 'mapping' THEN
			SET indexValue = 0;
			WHILE indexValue < JSON_LENGTH(expectedItems) AND validValue DO
				SET childValue = observationMember(actualValue,
					JSON_EXTRACT(expectedItems, CONCAT('$[', indexValue, ']')));
				IF childValue IS NULL THEN
					SET validValue = 0;
				ELSE
					SET workValue = JSON_ARRAY_APPEND(workValue, '$',
						JSON_ARRAY(JSON_EXTRACT(expectedItems,
						CONCAT('$[', indexValue + 1, ']')),
						JSON_EXTRACT(childValue, '$')));
				END IF;
				SET indexValue = indexValue + 2;
			END WHILE;
		ELSEIF expectedKind = 'array' AND actualKind = 'array' THEN
			SET indexValue = 0;
			WHILE indexValue < JSON_LENGTH(expectedItems) AND validValue DO
				SET childValue = JSON_EXTRACT(expectedItems,
					CONCAT('$[', indexValue, ']'));
				SET foundValue = 0;
				SET candidateIndex = 0;
				WHILE candidateIndex < JSON_LENGTH(actualItems) AND
					foundValue = 0 DO
					SET candidateValue = JSON_EXTRACT(actualItems,
						CONCAT('$[', candidateIndex, ']'));
					IF JSON_UNQUOTE(JSON_EXTRACT(childValue, '$[0]')) NOT IN
						('mapping','array') THEN
						SET foundValue = observationScalarEqual(childValue,
							candidateValue);
					END IF;
					SET candidateIndex = candidateIndex + 1;
				END WHILE;
				SET validValue = foundValue;
				SET indexValue = indexValue + 1;
			END WHILE;
		ELSEIF expectedKind = 'string' AND actualKind = 'string' THEN
			SET validValue = BINARY LOWER(JSON_UNQUOTE(expectedItems)) =
				BINARY LOWER(JSON_UNQUOTE(actualItems));
		ELSEIF expectedKind = 'integer' AND actualKind = 'integer' THEN
			SET validValue = CAST(JSON_UNQUOTE(expectedItems) AS SIGNED) =
				CAST(JSON_UNQUOTE(actualItems) AS SIGNED);
		ELSEIF expectedKind IN ('integer','float') AND
			actualKind IN ('integer','float') THEN
			SET validValue = (JSON_UNQUOTE(expectedItems) + 0e0) =
				(JSON_UNQUOTE(actualItems) + 0e0);
		ELSE
			SET validValue = 0;
		END IF;
	END WHILE;
	RETURN COALESCE(validValue, 0);
END;
##
DROP FUNCTION IF EXISTS observationMatches;
##
CREATE FUNCTION observationMatches(documentValue LONGTEXT,
	criteriaValue LONGTEXT) RETURNS TINYINT DETERMINISTIC NO SQL
BEGIN
	DECLARE indexValue INT DEFAULT 0;
	DECLARE validValue INT DEFAULT 1;
	DECLARE entriesValue LONGTEXT;
	DECLARE keyValue LONGTEXT;
	DECLARE nameValue LONGTEXT;
	DECLARE expectedValue LONGTEXT;
	DECLARE actualValue LONGTEXT;
	DECLARE contextValue LONGTEXT;
	DECLARE centerValue LONGTEXT;
	DECLARE radiusValue LONGTEXT;
	DECLARE distanceValue DOUBLE;
	DECLARE centerNumber DOUBLE;
	DECLARE radiusNumber DOUBLE;
	DECLARE minuteNumber DOUBLE;
	SET validValue = JSON_UNQUOTE(JSON_EXTRACT(criteriaValue, '$[0]')) =
		'mapping';
	SET entriesValue = JSON_EXTRACT(criteriaValue, '$[1]');
	SET contextValue = observationMember(documentValue,
		JSON_ARRAY('string','context'));
	WHILE indexValue < JSON_LENGTH(entriesValue) AND validValue DO
		SET keyValue = JSON_EXTRACT(entriesValue,
			CONCAT('$[', indexValue, ']'));
		SET nameValue = JSON_UNQUOTE(JSON_EXTRACT(keyValue, '$[1]'));
		SET expectedValue = JSON_EXTRACT(entriesValue,
			CONCAT('$[', indexValue + 1, ']'));
		SET actualValue = observationMember(documentValue, keyValue);
		IF BINARY keyValue = BINARY JSON_ARRAY('string','time window') THEN
			SET centerValue = observationMember(expectedValue,
				JSON_ARRAY('string','center'));
			SET radiusValue = observationMember(expectedValue,
				JSON_ARRAY('string','minutes'));
			SET actualValue = observationMember(contextValue,
				JSON_ARRAY('string','minutes after midnight'));
			SET validValue = JSON_LENGTH(JSON_EXTRACT(expectedValue, '$[1]'))
				= 4 AND centerValue IS NOT NULL AND radiusValue IS NOT NULL
				AND actualValue IS NOT NULL AND JSON_UNQUOTE(JSON_EXTRACT(
				centerValue, '$[0]')) IN ('integer','float') AND
				JSON_UNQUOTE(JSON_EXTRACT(radiusValue, '$[0]')) IN
				('integer','float') AND JSON_UNQUOTE(JSON_EXTRACT(actualValue,
				'$[0]')) IN ('integer','float');
			IF validValue THEN
				SET centerNumber = JSON_UNQUOTE(JSON_EXTRACT(centerValue,
					'$[1]')) + 0e0;
				SET radiusNumber = JSON_UNQUOTE(JSON_EXTRACT(radiusValue,
					'$[1]')) + 0e0;
				SET minuteNumber = JSON_UNQUOTE(JSON_EXTRACT(actualValue,
					'$[1]')) + 0e0;
				SET distanceValue = ABS(minuteNumber - centerNumber);
				SET validValue = centerNumber >= 0 AND centerNumber < 1440
					AND radiusNumber >= 0 AND radiusNumber <= 720 AND
					minuteNumber >= 0 AND minuteNumber < 1440 AND
					(distanceValue <= radiusNumber OR
					1440 - distanceValue <= radiusNumber);
			END IF;
		ELSEIF BINARY keyValue = BINARY JSON_ARRAY('string','type') THEN
			SET expectedValue = IF(JSON_UNQUOTE(JSON_EXTRACT(expectedValue,
				'$[0]')) = 'string', LOWER(JSON_UNQUOTE(JSON_EXTRACT(
				expectedValue, '$[1]'))), NULL);
			SET actualValue = LOWER(JSON_UNQUOTE(JSON_EXTRACT(actualValue,
				'$[1]')));
			SET validValue = CHAR_LENGTH(expectedValue) > 0 AND
				(BINARY expectedValue = BINARY actualValue OR
				BINARY LEFT(actualValue, CHAR_LENGTH(expectedValue) + 1) =
				BINARY CONCAT(expectedValue, '.'));
		ELSEIF BINARY keyValue IN (BINARY JSON_ARRAY('string','since'),
			BINARY JSON_ARRAY('string','until')) THEN
			SET actualValue = observationMember(documentValue,
				JSON_ARRAY('string','timestamp'));
			SET validValue = JSON_UNQUOTE(JSON_EXTRACT(expectedValue, '$[0]'))
				= 'integer' AND CAST(JSON_UNQUOTE(JSON_EXTRACT(expectedValue,
				'$[1]')) AS SIGNED) >= 0 AND IF(nameValue = 'since',
				CAST(JSON_UNQUOTE(JSON_EXTRACT(actualValue, '$[1]')) AS SIGNED)
				>= CAST(JSON_UNQUOTE(JSON_EXTRACT(expectedValue,
				'$[1]')) AS SIGNED), CAST(JSON_UNQUOTE(JSON_EXTRACT(actualValue,
				'$[1]')) AS SIGNED) <= CAST(JSON_UNQUOTE(JSON_EXTRACT(
				expectedValue, '$[1]')) AS SIGNED));
		ELSE
			IF actualValue IS NULL THEN
				SET actualValue = observationMember(contextValue, keyValue);
			END IF;
			IF actualValue IS NULL THEN
				SET actualValue = observationMember(observationMember(
					documentValue, JSON_ARRAY('string','metadata')), keyValue);
			END IF;
			SET validValue = actualValue IS NOT NULL AND
				observationValueMatches(expectedValue, actualValue);
		END IF;
		SET indexValue = indexValue + 2;
	END WHILE;
	RETURN COALESCE(validValue, 0);
END;
##
DROP FUNCTION IF EXISTS observationDocument;
##
CREATE FUNCTION observationDocument(observationKey VARCHAR(128),
	observationType VARCHAR(80), actor VARCHAR(200), subject VARCHAR(200),
	participants TEXT, observationTime BIGINT, location VARCHAR(255),
	observationContext MEDIUMTEXT, observationMetadata MEDIUMTEXT)
RETURNS LONGTEXT DETERMINISTIC NO SQL
BEGIN
	RETURN JSON_ARRAY('mapping', JSON_ARRAY(
		JSON_ARRAY('string','ID'), JSON_ARRAY('string', observationKey),
		JSON_ARRAY('string','type'), JSON_ARRAY('string', observationType),
		JSON_ARRAY('string','actor'), JSON_ARRAY('string', actor),
		JSON_ARRAY('string','subject'), JSON_ARRAY('string',
			COALESCE(subject, '')),
		JSON_ARRAY('string','participants'), JSON_EXTRACT(
			observationLegacy(COALESCE(participants, ''), 'array'), '$'),
		JSON_ARRAY('string','timestamp'), JSON_ARRAY('integer',
			CAST(observationTime AS CHAR)),
		JSON_ARRAY('string','location'), JSON_ARRAY('string',
			COALESCE(location, '')),
		JSON_ARRAY('string','context'), JSON_EXTRACT(observationLegacy(
			COALESCE(observationContext, ''), 'mapping'), '$'),
		JSON_ARRAY('string','metadata'), JSON_EXTRACT(observationLegacy(
			COALESCE(observationMetadata, ''), 'mapping'), '$')));
END;
##
ALTER TABLE experienceObservations
	ADD COLUMN searchDocument JSON,
	ADD COLUMN searchType VARCHAR(80) CHARACTER SET latin1 COLLATE latin1_bin,
	ADD KEY experience_player_type_time (playerId, searchType, observationTime),
	ADD KEY experience_player_time (playerId, observationTime);
##
UPDATE experienceObservations SET searchType = LOWER(observationType),
	searchDocument = JSON_EXTRACT(observationDocument(observationKey, observationType,
	actor, subject, participants, observationTime, location,
	observationContext, observationMetadata), '$');
##
DROP TRIGGER IF EXISTS observationSearchInsert;
##
CREATE TRIGGER observationSearchInsert BEFORE INSERT ON experienceObservations
FOR EACH ROW
BEGIN
	SET NEW.searchType = LOWER(NEW.observationType);
	SET NEW.searchDocument = JSON_EXTRACT(observationDocument(NEW.observationKey,
		NEW.observationType, NEW.actor, NEW.subject, NEW.participants,
		NEW.observationTime, NEW.location, NEW.observationContext,
		NEW.observationMetadata), '$');
END;
##
DROP TRIGGER IF EXISTS observationSearchUpdate;
##
CREATE TRIGGER observationSearchUpdate BEFORE UPDATE ON experienceObservations
FOR EACH ROW
BEGIN
	SET NEW.searchType = LOWER(NEW.observationType);
	SET NEW.searchDocument = JSON_EXTRACT(observationDocument(NEW.observationKey,
		NEW.observationType, NEW.actor, NEW.subject, NEW.participants,
		NEW.observationTime, NEW.location, NEW.observationContext,
		NEW.observationMetadata), '$');
END;
##