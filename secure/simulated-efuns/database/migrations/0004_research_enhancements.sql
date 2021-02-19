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
drop procedure if exists removeResearch;
##
CREATE PROCEDURE `removeResearch` ( p_playerid int )
BEGIN
    declare choiceId int;
    declare finished int default 0;

    declare researchChoicesList cursor for
        select id from researchChoices
        where playerId = p_playerid;
    declare continue handler for not found set finished = 1;

    open researchChoicesList;
    LoopResearchChoices: loop
        fetch researchChoicesList into choiceId;
        if finished = 1 then
            leave LoopResearchChoices;
        end if;
        delete from researchChoiceItems where researchChoiceId = choiceId;
    end loop LoopResearchChoices;
    close researchChoicesList;

    delete from sustainedEffects 
    where researchId in (select id from research where playerId = p_playerid);

    delete from researchChoices where playerId = p_playerid;
    delete from research where playerId = p_playerid;
    delete from openResearchTrees where playerId = p_playerid;
END;
##
drop procedure if exists removePlayer;
##
CREATE PROCEDURE `removePlayer` ( p_name varchar(40) )
BEGIN
    declare localUserId int;
    declare localPlayerId int;
    declare characterCount int;

    select id, userId into localPlayerId, localUserId
    from players where name = p_name;

    if localPlayerId is not null then
        delete from biological where playerId = localPlayerId;
        delete from combatStatistics where playerId = localPlayerId;
        delete from combatStatisticsForRace where playerId = localPlayerId;
        delete from guilds where playerId = localPlayerId;
        delete from materialAttributes where playerId = localPlayerId;
        delete from playerCombatData where playerId = localPlayerId;
        delete from quests where playerId = localPlayerId;
        delete from wizards where playerId = localPlayerId;
        delete from skills where playerId = localPlayerId;
        delete from factions where playerId = localPlayerId;
        delete from inventory where playerId = localPlayerId;
        delete from opinions where playerId = localPlayerId;
        delete from characterStates where playerId = localPlayerId;
        delete from settings where playerId = localPlayerId;
        delete from blockedUsers where playerId = localPlayerId;
        delete from npcs where playerId = localPlayerId;
        delete from parties where creatorid = localPlayerId;
        call removeResearch(localPlayerId);
        call removeTraits(localPlayerId);
        call removeDomains(localPlayerId);

        delete from players where id = localPlayerId;

        if localUserId is not null then
            select count(id) into characterCount
            from players where userId = localUserId;

            if characterCount = 0 then
                delete from users where id = localUserId;
            end if;
        end if;
    end if;
END;
##
