CREATE TABLE `npcs` (
  `playerid` int(11) NOT NULL,
  `fileName` varchar(256) NOT NULL,
  `data` blob NOT NULL,
  KEY `npcs_playerid_idx` (`playerid`),
  CONSTRAINT `npcs_playerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE PROCEDURE `saveNPCData` (p_playername varchar(40),
p_filename varchar(256), p_data blob)
BEGIN
    declare alreadyPersisted int;
    declare lPlayerId int;

    select id into lPlayerId
    from players where name = p_playername;

    if lPlayerId is not null then
        select playerid into alreadyPersisted
        from npcs 
        where playerid = lPlayerId and filename = p_filename;
    
        if alreadyPersisted is not null then
            update npcs set data = p_data
            where playerid = lPlayerId and filename = p_filename;
        else
            insert into npcs (playerid,filename,data) 
                values (lPlayerId,p_filename,p_data);
        end if;
    end if;
END;
##