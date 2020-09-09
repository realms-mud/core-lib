CREATE TABLE `sustainedEffects` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `researchId` int(11) NOT NULL,
  `sustainedActive` tinyint(1) NOT NULL,
  `activeCount` int(11) NOT NULL,
  `ModifierFQN` varchar(256) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `sustainedResearch_researchId` FOREIGN KEY (`researchId`) REFERENCES `research` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE PROCEDURE `saveSustainedEffect` (p_playerid int, p_path varchar(200),
    p_sustainedActive tinyint, p_activeCount int, p_ModifierFQN varchar(256))
BEGIN
    declare effectId int;
    declare lResearchId int;

    select id into lResearchId
    from research where playerid = p_playerid and path = p_path;

    select id into effectId
    from sustainedEffects where researchId = lResearchId;
    
    if effectId is not null then
        update sustainedEffects set sustainedActive = p_sustainedActive,
                                    activeCount = p_activeCount,
                                    ModifierFQN = p_ModifierFQN
        where id = effectId;
    else
        insert into sustainedEffects 
        (researchId, sustainedActive, activeCount, ModifierFQN)
        values (lResearchId, p_sustainedActive, p_activeCount, p_ModifierFQN);
    end if;
END;
##
CREATE PROCEDURE `deleteSustainedEffect` (p_playerid int, p_path varchar(200))
BEGIN
    declare lResearchId int;

    select id into lResearchId
    from research where playerid = p_playerid and path = p_path;

    delete from sustainedEffects where researchId = lResearchId;
END;
##
