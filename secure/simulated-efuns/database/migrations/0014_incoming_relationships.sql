CREATE TABLE IF NOT EXISTS `incomingRelationshipDimensions` (
  `playerId` int(11) NOT NULL,
  `sourceKey` varchar(255) NOT NULL,
  `dimension` varchar(80) NOT NULL,
  `value` int(11) NOT NULL DEFAULT '0',
  `updated` bigint NOT NULL DEFAULT '0',
  PRIMARY KEY (`playerId`, `sourceKey`, `dimension`),
  CONSTRAINT `incomingRelationships_playerid` FOREIGN KEY (`playerId`)
    REFERENCES `players` (`id`) ON DELETE CASCADE ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
DROP PROCEDURE IF EXISTS `saveIncomingRelationshipDimension`;
##
CREATE PROCEDURE `saveIncomingRelationshipDimension` (
    p_playerId int, p_sourceKey varchar(255), p_dimension varchar(80),
    p_value int, p_updated bigint)
BEGIN
    INSERT INTO incomingRelationshipDimensions
        (playerId, sourceKey, dimension, value, updated)
    VALUES (p_playerId, p_sourceKey, p_dimension, p_value, p_updated)
    ON DUPLICATE KEY UPDATE value = p_value, updated = p_updated;
END;
##
DROP PROCEDURE IF EXISTS `saveRelationshipHistory`;
##
CREATE PROCEDURE `saveRelationshipHistory` (
    p_playerid int, p_targetKey varchar(255), p_dimension varchar(80),
    p_delta int, p_value int, p_timestamp bigint, p_producer varchar(255),
    p_context mediumtext, p_metadata mediumtext)
BEGIN
    DECLARE l_relationshipId int;
    SELECT id INTO l_relationshipId FROM relationships
    WHERE playerId = p_playerid AND targetKey = p_targetKey;
    IF l_relationshipId IS NOT NULL AND NOT EXISTS (
        SELECT 1 FROM relationshipHistory
        WHERE relationshipId = l_relationshipId AND dimension = p_dimension
            AND delta = p_delta AND value = p_value AND timestamp = p_timestamp
            AND producer <=> p_producer AND context <=> p_context
            AND metadata <=> p_metadata)
    THEN
        INSERT INTO relationshipHistory
            (relationshipId, dimension, delta, value, timestamp,
             producer, context, metadata)
        VALUES (l_relationshipId, p_dimension, p_delta, p_value, p_timestamp,
            p_producer, p_context, p_metadata);
    END IF;
END;
