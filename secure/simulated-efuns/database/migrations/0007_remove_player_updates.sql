CREATE PROCEDURE `removeCompositeResearch` ( p_playerid int )
BEGIN
    declare compositeId int;
    declare finished int default 0;

    declare compositeResearchList cursor for
        select id from compositeResearch
        where playerid = p_playerid;
    declare continue handler for not found set finished = 1;

    open compositeResearchList;
    LoopCompositeResearch: loop
        fetch compositeResearchList into compositeId;
        if finished = 1 then
            leave LoopCompositeResearch;
        end if;

        delete from compositeResearchElements 
        where compositeresearchid = compositeId;
    end loop LoopCompositeResearch;
    close compositeResearchList;

    delete from compositeResearch where playerid = p_playerid;
END;
##
CREATE PROCEDURE `removeSustainedEffects` ( p_playerid int )
BEGIN
    declare lResearchId int;
    declare finished int default 0;

    declare researchList cursor for
        select id from research
        where playerId = p_playerid;
    declare continue handler for not found set finished = 1;

    open researchList;
    LoopResearch: loop
        fetch researchList into lResearchId;
        if finished = 1 then
            leave LoopResearch;
        end if;
        delete from sustainedEffects where researchId = lResearchId;
    end loop LoopResearch;
    close researchList;
END;
##
DROP PROCEDURE IF EXISTS removeResearch;
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

    delete from researchChoices where playerId = p_playerid;

    call removeSustainedEffects(p_playerid);
    delete from research where playerId = p_playerid;

    delete from openResearchTrees where playerId = p_playerid;
END;
##
DROP PROCEDURE IF EXISTS removePlayer;
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
        delete from parties where creatorid = localPlayerId;
        delete from playerRoles where playerid = localPlayerId;
        delete from npcs where playerid = localPlayerId;
        call removeCompositeResearch(localPlayerId);
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