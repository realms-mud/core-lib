-- Table for constructed research (spells)
CREATE TABLE `constructedResearch` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) NOT NULL,
  `alias` varchar(20),
  `playerid` int(11) NOT NULL,
  `constraint` varchar(100),
  `type` varchar(200),
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `constructedResearch_playerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `constructedResearchElements` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `constructedresearchid` int(11) NOT NULL,
  `researchid` int(11) NOT NULL,
  `type` varchar(20) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `constructedResearchElements_researchid` FOREIGN KEY (`researchid`) REFERENCES `research` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `constructedResearchElements_constructedresearchid` FOREIGN KEY (`constructedresearchid`) REFERENCES `constructedResearch` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
DROP PROCEDURE IF EXISTS `saveConstructedResearch`;
##
CREATE PROCEDURE `saveConstructedResearch` (p_playername varchar(40), p_name varchar(100),
    p_alias varchar(20), p_constraint varchar(100), p_type varchar(200))
BEGIN
    declare alreadyPersisted int;
    declare lPlayerId int;

    select id into lPlayerId
    from players where name = p_playername;

    if lPlayerId is not null then
        select id into alreadyPersisted
        from constructedResearch
        where playerid = lPlayerId and name = p_name;

        if alreadyPersisted is null then
            insert into constructedResearch (playerid, `name`, alias, `constraint`, `type`) 
                values (lPlayerId, p_name, p_alias, p_constraint, p_type);
        else
            update constructedResearch set alias = p_alias, 
                                           `constraint` = p_constraint, 
                                           `type` = p_type
            where id = alreadyPersisted;
        end if;
    end if;
END;
##
DROP PROCEDURE IF EXISTS `saveConstructedResearchElement`;
##
CREATE PROCEDURE `saveConstructedResearchElement` (p_playername varchar(40), 
    p_constructedResearchName varchar(100), p_path varchar(200), p_type varchar(20))
BEGIN
    declare lResearchId int;
    declare lConstructedResearchId int;
    declare alreadyPersisted int;

    select research.id into lResearchId
    from research
    inner join players on players.id = research.playerid and 
                          players.name = p_playername
    where research.path = p_path and research.researchComplete = 1;

    select constructedResearch.id into lConstructedResearchId
    from constructedResearch 
    inner join players on players.id = constructedResearch.playerid and 
                          players.name = p_playername
    where constructedResearch.name = p_constructedResearchName;

    if lResearchId is not null and lConstructedResearchId is not null then
        select id into alreadyPersisted
        from constructedResearchElements
        where constructedresearchid = lConstructedResearchId and
              researchid = lResearchId;

        if alreadyPersisted is null then
            insert into constructedResearchElements 
                (constructedresearchid, researchid, `type`) 
                values (lConstructedResearchId, lResearchId, p_type);
        else
            update constructedResearchElements 
            set `type` = p_type
            where id = alreadyPersisted;
        end if;
    end if;
END;
##
DROP PROCEDURE IF EXISTS `deleteConstructedResearch`;
##
CREATE PROCEDURE `deleteConstructedResearch` (
    p_playerName VARCHAR(100),
    p_name VARCHAR(255),
    p_constraint VARCHAR(255)
)
BEGIN
    DECLARE l_constructedId INT;
    
    SELECT cr.id INTO l_constructedId
    FROM constructedResearch cr
    INNER JOIN players p ON cr.playerId = p.id
    WHERE p.name = p_playerName 
        AND cr.name = p_name 
        AND cr.`constraint` = p_constraint;
    
    IF l_constructedId IS NOT NULL THEN
        DELETE FROM constructedResearchElements 
        WHERE constructedResearchId = l_constructedId;
        
        DELETE FROM constructedResearch WHERE id = l_constructedId;
    END IF;
END;
##
DROP PROCEDURE IF EXISTS `deleteConstructedResearchByConstraint`;
##
CREATE PROCEDURE `deleteConstructedResearchByConstraint` (
    p_playerName VARCHAR(100),
    p_constraint VARCHAR(255)
)
BEGIN
    DECLARE l_playerId INT;
    DECLARE l_constructedId INT;
    DECLARE finished INT DEFAULT 0;
    
    DECLARE constructedList CURSOR FOR
        SELECT cr.id FROM constructedResearch cr
        INNER JOIN players p ON cr.playerId = p.id
        WHERE p.name = p_playerName AND cr.`constraint` = p_constraint;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET finished = 1;
    
    OPEN constructedList;
    LoopConstructed: LOOP
        FETCH constructedList INTO l_constructedId;
        IF finished = 1 THEN
            LEAVE LoopConstructed;
        END IF;
        
        DELETE FROM constructedResearchElements 
        WHERE constructedResearchId = l_constructedId;
    END LOOP LoopConstructed;
    CLOSE constructedList;
    
    SELECT id INTO l_playerId FROM players WHERE name = p_playerName;
    DELETE FROM constructedResearch 
    WHERE playerId = l_playerId AND `constraint` = p_constraint;
END;
##
DROP PROCEDURE IF EXISTS `removeConstructedResearch`;
##
CREATE PROCEDURE `removeConstructedResearch` ( p_playerid int )
BEGIN
    DECLARE l_constructedId INT;
    DECLARE finished INT DEFAULT 0;

    DECLARE constructedResearchList CURSOR FOR
        SELECT id FROM constructedResearch
        WHERE playerid = p_playerid;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET finished = 1;

    OPEN constructedResearchList;
    LoopConstructedResearch: LOOP
        FETCH constructedResearchList INTO l_constructedId;
        IF finished = 1 THEN
            LEAVE LoopConstructedResearch;
        END IF;

        DELETE FROM constructedResearchElements 
        WHERE constructedresearchid = l_constructedId;
    END LOOP LoopConstructedResearch;
    CLOSE constructedResearchList;

    DELETE FROM constructedResearch WHERE playerid = p_playerid;
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
        call removeConstructedResearch(localPlayerId);
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
##