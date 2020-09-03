CREATE TABLE `parties` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `creatorid` int(11) NOT NULL,
  `partyName` varchar(256) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `parties_creatorid` FOREIGN KEY (`creatorid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `partyMembers` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `partyid` int(11) NOT NULL,
  `member` varchar(256) NOT NULL,
  `memberType` varchar(12) NOT NULL,
  `experienceEarned` int(11) NOT NULL,
  `bestKill` varchar(256) NOT NULL,
  `memberFollowing` varchar(256),
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `partyMembers_partyid` FOREIGN KEY (`partyid`) REFERENCES `parties` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE FUNCTION `saveParty` (p_creatorName varchar(256), p_partyName varchar(256))
    returns int NOT DETERMINISTIC
    READS SQL DATA
BEGIN
    declare partyId int;

    select id into partyId
    from parties p
    inner join players pl on p.creatorid = pl.id
    where pl.name = p_creatorName and p.partyName = p_partyName;
    
    if partyId is null then
        insert into parties (creatorid,partyName) 
        values (p_creatorid,p_partyName);

        select id into partyId from parties 
        where creatorid = p_creatorid and partyName = p_partyName;

    end if;
RETURN ret;
END;
##
CREATE PROCEDURE `savePartyMember` (p_partyid int,
p_member varchar(256), p_memberType varchar(12), p_experience int,
p_bestKill varchar(256), p_isFollowing varchar(256))
BEGIN
    declare MemberId int;

    select id into MemberId
    from partyMembers 
    where partyid = p_partyid and member = p_member 
        and memberType = p_memberType;
    
    if MemberId is not null then
        update partyMembers set experienceEarned = p_experience, 
                                bestKill = p_bestKill,
                                memberFollowing = p_isFollowing
        where id = MemberId;
    else
        insert into partyMembers (partyid,member,memberType,
            experienceEarned,bestKill,memberFollowing) 
        values (p_partyid,p_member,p_memberType,
            p_experience,p_bestKill,p_isFollowing);
    end if;
END;
##
CREATE PROCEDURE `deleteParty` (p_partyid int)
BEGIN
    declare hasMembers int;

    select count(id) into hasMembers
    from partyMembers 
    where partyid = p_partyid;
    
    if hasMembers > 0 then
        delete from partyMembers where partyId = p_partyId;
    end if;

    delete from parties where id = p_partyId;
END;
##