ALTER TABLE experienceObservations
    MODIFY COLUMN observationKey varchar(128) DEFAULT NULL;
##
DROP PROCEDURE IF EXISTS saveExperienceObservation;
##
CREATE PROCEDURE saveExperienceObservation (
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
    DECLARE savedId int;
    SET savedId = NULL;
    IF NULLIF(p_observationKey, '') IS NOT NULL THEN
        SELECT id INTO savedId FROM experienceObservations
        WHERE playerId = p_playerid AND
            (observationKey = p_observationKey OR
                (observationKey IS NULL AND
                    CAST(id AS CHAR) = p_observationKey))
        LIMIT 1;
    END IF;
    IF savedId IS NULL THEN
        INSERT INTO experienceObservations (
            observationKey, playerId, observationType, actor, subject,
            participants, observationTime, location, observationContext,
            observationMetadata)
        VALUES (
            NULLIF(p_observationKey, ''), p_playerid, p_observationType,
            p_actor, p_subject, p_participants, p_observationTime,
            p_location, p_context, p_metadata);
        SET savedId = LAST_INSERT_ID();
    END IF;
    SET savedId = LAST_INSERT_ID(savedId);
END;
