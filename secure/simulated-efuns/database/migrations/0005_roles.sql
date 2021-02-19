CREATE TABLE `roleTypes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `type` varchar(20) NOT NULL,
  `level` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `roleTypes_level` FOREIGN KEY (`level`) REFERENCES `wizardTypes` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=latin1;
##
insert into roleTypes (type,level) values 
('development', (select id from wizardTypes where type = 'admin')), 
('web master', (select id from wizardTypes where type = 'admin')),
('area', (select id from wizardTypes where type = 'wizard')), 
('guild', (select id from wizardTypes where type = 'senior')),
('hr', (select id from wizardTypes where type = 'admin')),
('liason', (select id from wizardTypes where type = 'senior')),
('leadership', (select id from wizardTypes where type = 'elder'));
##
CREATE TABLE `roles` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(80) NOT NULL,
  `typeid` int(11)  NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `roles_typeid` FOREIGN KEY (`typeid`) REFERENCES `roleTypes` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `playerRoles` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `roleid` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `playerRoles_playerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `playerRoles_roleid` FOREIGN KEY (`roleid`) REFERENCES `roles` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE PROCEDURE `saveRoles` (p_playername varchar(40), p_role varchar(80))
BEGIN
    declare alreadyPersisted int;
    declare lPlayerId int;

    select id into lPlayerId
    from players where name = p_playername;

    if lPlayerId is not null then
        select playerid into alreadyPersisted
        from playerRoles
        inner join roles on playerRoles.roleid = roles.id
        where playerRoles.playerid = lPlayerId and roles.name = p_role;

        if alreadyPersisted is null then
            insert into playerRoles (playerid, roleid) 
                values (lPlayerId, (select id from roles where name = p_role));
        end if;
    end if;
END;
##
CREATE FUNCTION `createRole` (p_role varchar(80), p_type varchar(20))
RETURNS int(11) NOT DETERMINISTIC
    READS SQL DATA
BEGIN
    declare lRoleId int;
    declare lTypeId int;

    select id into lRoleId
    from roles where name = p_role;

    select id into lTypeId
    from roleTypes where type = p_type;

    if lTypeId is not null then
        if lRoleId is not null then
            update roles set typeid = lTypeId
            where id = lRoleId;
        else
            insert into roles (name, typeid) 
            values (p_role, lTypeId);

            select id into lRoleId
            from roles where name = p_role;
        end if;
    end if;
RETURN lRoleId;
END;
##
