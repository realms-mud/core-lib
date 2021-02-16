CREATE TABLE `compositeResearch` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) NOT NULL,
  `alias` varchar(20),
  `playerid` int(11)  NOT NULL,
  `constraint` varchar(100), 
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `compositeResearch_playerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `compositeResearchElements` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `compositeresearchid` int(11) NOT NULL,
  `researchid` int(11) NOT NULL,
  `type` varchar(20) NOT NULL,
  `description` varchar(256) NOT NULL,
  `orderInSequence` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `compositeResearchElements_researchid` FOREIGN KEY (`researchid`) REFERENCES `research` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `compositeResearchElements_compositeresearchid` FOREIGN KEY (`compositeresearchid`) REFERENCES `compositeResearch` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE PROCEDURE `saveCompositeResearch` (p_playername varchar(40), p_name varchar(100),
    p_alias varchar(20), p_constraint varchar(100))
BEGIN
    declare alreadyPersisted int;
    declare lPlayerId int;

    select id into lPlayerId
    from players where name = p_playername;

    if lPlayerId is not null then
        select id into alreadyPersisted
        from compositeResearch
        where playerid = lPlayerId and name = p_name;

        if alreadyPersisted is null then
            insert into compositeResearch (playerid, `name`, alias, `constraint`) 
                values (lPlayerId, p_name, p_alias, p_constraint);
        else
            update compositeResearch set alias = p_alias, `constraint` = p_constraint
            where id = alreadyPersisted;
        end if;
    end if;
END;
##
CREATE PROCEDURE `saveCompositeResearchElement` (p_playername varchar(40), 
    p_compositeResearchName varchar(100), p_path varchar(200), p_type varchar(20),
    p_description varchar(256), p_order int(11))
BEGIN
    declare lResearchId int;
    declare lCompositeResearchId int;
    declare alreadyPersisted int;

    select research.id into lResearchId
    from research
    inner join players on players.id = research.playerid and 
                        players.name = p_playername
    where research.path = p_path and research.researchComplete = 1;

    select compositeResearch.id into lCompositeResearchId
    from compositeResearch 
    inner join players on players.id = compositeResearch.playerid and 
                          players.name = p_playername
    where compositeResearch.name = p_compositeResearchName;

    if lResearchId is not null and lCompositeResearchId is not null then
        select id into alreadyPersisted
        from compositeResearchElements
        where compositeresearchid = lCompositeResearchId and
              researchid = lResearchId and
              orderInSequence = p_order;

        if alreadyPersisted is null then
            insert into compositeResearchElements 
                (compositeresearchid, researchid, `type`, `description`, orderInSequence) 
                values (lCompositeResearchId, lResearchId, p_type, p_description, p_order);
        else
            update compositeResearchElements 
            set `type` = p_type, 
                `description` = p_description
            where id = alreadyPersisted;
        end if;
    end if;
END;
##  
