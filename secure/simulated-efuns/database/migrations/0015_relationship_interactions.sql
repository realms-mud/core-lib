CREATE TABLE IF NOT EXISTS worldRelationshipDimensions (
    sourceKey varchar(255) NOT NULL,
    targetKey varchar(255) NOT NULL,
    dimension varchar(80) NOT NULL,
    value int NOT NULL DEFAULT 0,
    revision bigint NOT NULL DEFAULT 0,
    updated bigint NOT NULL DEFAULT 0,
    PRIMARY KEY (sourceKey, targetKey, dimension)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
DROP PROCEDURE IF EXISTS changeWorldRelationshipDimension;
##
CREATE PROCEDURE changeWorldRelationshipDimension (
    p_source varchar(255), p_target varchar(255), p_dimension varchar(80),
    p_delta int, p_minimum int, p_maximum int, p_updated bigint)
BEGIN
    INSERT INTO worldRelationshipDimensions
        (sourceKey, targetKey, dimension, value, revision, updated)
    VALUES (p_source, p_target, p_dimension,
        LEAST(p_maximum, GREATEST(p_minimum, p_delta)), 1, p_updated)
    ON DUPLICATE KEY UPDATE
        value = LEAST(p_maximum, GREATEST(p_minimum, value + p_delta)),
        revision = revision + 1, updated = p_updated;
END;
##
CREATE TABLE IF NOT EXISTS researchMentorships (
    playerId int NOT NULL,
    researchKey varchar(255) NOT NULL,
    teacherKey varchar(255) NOT NULL,
    changes text NOT NULL,
    PRIMARY KEY (playerId, researchKey),
    CONSTRAINT mentorship_playerid FOREIGN KEY (playerId)
        REFERENCES players (id) ON DELETE CASCADE ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
DROP PROCEDURE IF EXISTS saveResearchMentorship;
##
CREATE PROCEDURE saveResearchMentorship (
    p_player int, p_research varchar(255), p_teacher varchar(255),
    p_changes text)
BEGIN
    INSERT INTO researchMentorships (playerId, researchKey, teacherKey, changes)
    VALUES (p_player, p_research, p_teacher, p_changes)
    ON DUPLICATE KEY UPDATE teacherKey = p_teacher, changes = p_changes;
END;
##
DROP PROCEDURE IF EXISTS pruneResearchMentorships;
##
CREATE PROCEDURE pruneResearchMentorships (p_player int)
BEGIN
    DELETE FROM researchMentorships WHERE playerId = p_player;
END;
