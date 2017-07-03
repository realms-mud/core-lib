drop view TestDB.basicPlayerData;
##
drop view TestDB.researchChoicesView;
##
drop view TestDB.traitsView;
##
drop procedure TestDB.saveBiologicalInformation;
##
drop procedure TestDB.saveCombatInformation;
##
drop procedure TestDB.saveMaterialAttributes;
##
drop procedure TestDB.saveMaterialAttribute;
##
drop function TestDB.saveBasicPlayerInformation;
##
drop table TestDB.biological;
##
drop table TestDB.combatStatisticsForRace;
##
drop table TestDB.combatStatistics;
##
drop table TestDB.guilds;
##
drop table TestDB.materialAttributes;
##
drop table TestDB.openResearchTrees;
##
drop table TestDB.playerCombatData;
##
drop table TestDB.quests;
##
drop table TestDB.research;
##
drop table TestDB.researchChoiceItems;
##
drop table TestDB.researchChoices;
##
drop table TestDB.skills;
##
drop table TestDB.wizards;
##
drop table TestDB.wizardTypes;
##
drop table TestDB.timedtraits;
##
drop table TestDB.traits;
##
drop table TestDB.temporaryTraits;
##
drop table TestDB.inventory;
##
drop table TestDB.players;
##
CREATE TABLE TestDB.`players` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(40) NOT NULL,
  `race` varchar(20) NOT NULL,
  `age` int(10) unsigned NOT NULL,
  `gender` int(10) unsigned NOT NULL,
  `ghost` int(10) unsigned NOT NULL DEFAULT '0',
  `strength` int(11) NOT NULL,
  `intelligence` int(11) NOT NULL,
  `dexterity` int(11) NOT NULL,
  `wisdom` int(11) NOT NULL,
  `constitution` int(11) NOT NULL,
  `charisma` int(11) NOT NULL,
  `invisible` int(11) NOT NULL DEFAULT '0',
  `whenCreated` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `attributePoints` int(11) NOT NULL DEFAULT '0',
  `skillPoints` int(11) NOT NULL DEFAULT '0',
  `researchPoints` int(11) NOT NULL DEFAULT '0',
  `unassignedExperience` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name_UNIQUE` (`name`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`biological` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `intoxicated` int(11) NOT NULL DEFAULT '0',
  `stuffed` int(11) NOT NULL DEFAULT '0',
  `drugged` int(11) NOT NULL DEFAULT '0',
  `soaked` int(11) NOT NULL DEFAULT '0',
  `headache` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `playerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`combatStatistics` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `type` varchar(100) NOT NULL,
  `name` varchar(40) NOT NULL,
  `level` int(11) NOT NULL,
  `key` varchar(100) DEFAULT NULL,
  `timesKilled` int(11) DEFAULT NULL,
  `playerid` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `combatStatisticsplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`combatStatisticsForRace` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `race` varchar(20) NOT NULL,
  `timesKilled` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `combatStatisticsForRaceplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`guilds` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `name` varchar(40) NOT NULL,
  `level` int(11) NOT NULL DEFAULT '0',
  `experience` int(11) NOT NULL DEFAULT '0',
  `rank` varchar(45) DEFAULT NULL,
  `title` varchar(45) DEFAULT NULL,
  `pretitle` varchar(45) DEFAULT NULL,
  `leftGuild` int(11) DEFAULT NULL,
  `anathema` int(11) DEFAULT NULL,
  `rankAdvancedAt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `guildsplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`materialAttributes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `type` varchar(40) NOT NULL,
  `value` varchar(80) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `materialAttributesplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`openResearchTrees` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `researchTree` varchar(128) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `openResearchTreesplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`playerCombatData` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `hitPoints` int(11) NOT NULL,
  `maxHitPoints` int(11) NOT NULL,
  `spellPoints` int(11) NOT NULL,
  `maxSpellPoints` int(11) NOT NULL,
  `staminaPoints` int(11) NOT NULL,
  `maxStaminaPoints` int(11) NOT NULL,
  `wimpy` int(11) NOT NULL DEFAULT '0',
  `onKillList` int(11) NOT NULL DEFAULT '0',
  `timeToHealHP` int(11) NOT NULL DEFAULT '0',
  `timeToHealSP` int(11) NOT NULL DEFAULT '0',
  `timeToHealST` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `playerCombatDataplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`quests` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `path` varchar(128) NOT NULL,
  `name` varchar(45) NOT NULL,
  `state` varchar(45) NOT NULL,
  `statesCompleted` varchar(256) DEFAULT NULL,
  `isActive` tinyint(4) NOT NULL DEFAULT '0',
  `isCompleted` tinyint(4) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `questsplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`research` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerId` int(11) NOT NULL,
  `path` varchar(128) NOT NULL,
  `whenResearchBegan` int(11) NOT NULL DEFAULT '0',
  `whenResearchComplete` int(11) DEFAULT NULL,
  `timeSpentLearning` int(11) DEFAULT NULL,
  `researchComplete` tinyint(4) NOT NULL DEFAULT '0',
  `timeToCompleteLearning` int(11) DEFAULT NULL,
  `cooldown` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `researchplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`researchChoices` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerId` int(11) NOT NULL,
  `name` varchar(45) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `researchChoicesplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`researchChoiceItems` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `researchChoiceId` int(11) NOT NULL,
  `selectionNumber` varchar(5) NOT NULL,
  `type` varchar(15) NOT NULL,
  `name` varchar(45) NOT NULL,
  `description` varchar(256) NOT NULL,
  `key` varchar(128) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `researchChoiceId_idx` (`researchChoiceId`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`wizardTypes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `type` varchar(20) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`wizards` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerId` int(11) NOT NULL,
  `typeId` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `playerid_idx` (`playerId`),
  KEY `typeid_idx` (`typeId`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`skills` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `name` varchar(45) NOT NULL,
  `value` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `skillsplayerid_idx` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`temporaryTraits` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `traitList` varchar(512) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `temptraitsplayerid_idx` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`traits` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `path` varchar(128) NOT NULL,
  `name` varchar(45) NOT NULL,
  `added` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `traits_playerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`timedtraits` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `traitid` int(11) NOT NULL,
  `endTime` int(11) NOT NULL,
  `expireMessage` varchar(256) DEFAULT NULL,
  `triggeringResearch` varchar(128) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `timed_traitsid` FOREIGN KEY (`traitid`) REFERENCES `traits` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
##
CREATE TABLE TestDB.`inventory` (
  `playerid` int(11) NOT NULL,
  `fileName` varchar(128) NOT NULL,
  `data` blob NOT NULL,
  `isEquipped` int(11) NOT NULL DEFAULT '0',
  KEY `inventory_playerid_idx` (`playerid`),
  CONSTRAINT `inventory_playerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE ALGORITHM=UNDEFINED DEFINER=`realms`@`localhost` SQL SECURITY DEFINER VIEW `TestDB`.`basicPlayerData` AS select `TestDB`.`players`.`name` AS `name`,`TestDB`.`players`.`race` AS `race`,`TestDB`.`players`.`age` AS `age`,`TestDB`.`players`.`gender` AS `gender`,`TestDB`.`players`.`ghost` AS `ghost`,`TestDB`.`players`.`strength` AS `strength`,`TestDB`.`players`.`intelligence` AS `intelligence`,`TestDB`.`players`.`dexterity` AS `dexterity`,`TestDB`.`players`.`wisdom` AS `wisdom`,`TestDB`.`players`.`constitution` AS `constitution`,`TestDB`.`players`.`charisma` AS `charisma`,`TestDB`.`players`.`invisible` AS `invisible`,`TestDB`.`biological`.`intoxicated` AS `intoxicated`,`TestDB`.`biological`.`stuffed` AS `stuffed`,`TestDB`.`biological`.`drugged` AS `drugged`,`TestDB`.`biological`.`soaked` AS `soaked`,`TestDB`.`biological`.`headache` AS `headache`,`TestDB`.`playerCombatData`.`hitPoints` AS `hitPoints`,`TestDB`.`playerCombatData`.`maxHitPoints` AS `maxHitPoints`,`TestDB`.`playerCombatData`.`spellPoints` AS `spellPoints`,`TestDB`.`playerCombatData`.`maxSpellPoints` AS `maxSpellPoints`,`TestDB`.`playerCombatData`.`staminaPoints` AS `staminaPoints`,`TestDB`.`playerCombatData`.`maxStaminaPoints` AS `maxStaminaPoints`,`TestDB`.`playerCombatData`.`wimpy` AS `wimpy`,`TestDB`.`playerCombatData`.`onKillList` AS `onKillList`,`TestDB`.`playerCombatData`.`timeToHealHP` AS `timeToHealHP`,`TestDB`.`playerCombatData`.`timeToHealSP` AS `timeToHealSP`,`TestDB`.`playerCombatData`.`timeToHealST` AS `timeToHealST`,`TestDB`.`players`.`whenCreated` AS `whenCreated`,`TestDB`.`players`.`attributePoints` AS `availableAttributePoints`,`TestDB`.`players`.`skillPoints` AS `availableSkillPoints`,`TestDB`.`players`.`researchPoints` AS `availableResearchPoints`,`TestDB`.`players`.`unassignedExperience` AS `unassignedExperience`,`TestDB`.`players`.`id` AS `playerId` from ((`TestDB`.`players` join `TestDB`.`biological` on((`TestDB`.`players`.`id` = `TestDB`.`biological`.`playerid`))) join `TestDB`.`playerCombatData` on((`TestDB`.`players`.`id` = `TestDB`.`playerCombatData`.`playerid`)));
##
CREATE ALGORITHM=UNDEFINED DEFINER=`realms`@`localhost` SQL SECURITY DEFINER VIEW `TestDB`.`researchChoicesView` AS select `TestDB`.`researchChoices`.`playerId` AS `playerId`,`TestDB`.`researchChoices`.`name` AS `Choice`,`TestDB`.`researchChoiceItems`.`selectionNumber` AS `selectionNumber`,`TestDB`.`researchChoiceItems`.`type` AS `type`,`TestDB`.`researchChoiceItems`.`name` AS `name`,`TestDB`.`researchChoiceItems`.`description` AS `description`,`TestDB`.`researchChoiceItems`.`key` AS `key` from (`TestDB`.`researchChoices` join `TestDB`.`researchChoiceItems` on((`TestDB`.`researchChoices`.`id` = `TestDB`.`researchChoiceItems`.`researchChoiceId`)));
##
CREATE ALGORITHM=UNDEFINED DEFINER=`realms`@`localhost` SQL SECURITY DEFINER VIEW `TestDB`.`traitsView` AS select `TestDB`.`traits`.`playerid` AS `playerid`,`TestDB`.`traits`.`path` AS `path`,`TestDB`.`traits`.`name` AS `name`,`TestDB`.`traits`.`added` AS `added`,`TestDB`.`timedtraits`.`endTime` AS `endTime`,`TestDB`.`timedtraits`.`expireMessage` AS `expireMessage`,`TestDB`.`timedtraits`.`triggeringResearch` AS `triggeringResearch` from (`TestDB`.`traits` left join `TestDB`.`timedtraits` on((`TestDB`.`traits`.`id` = `TestDB`.`timedtraits`.`traitid`)));
##
CREATE FUNCTION TestDB.`saveBasicPlayerInformation`(p_name varchar(40),
p_race varchar(20), p_age int, p_gender int, p_ghost int, p_strength int,
p_intelligence int, p_dexterity int, p_wisdom int, p_constitution int,
p_charisma int, p_invisible int, p_attributes int) RETURNS int(11)
BEGIN
	declare pid int;
    
    select id into pid
    from players where name = p_name;
    
    if pid is not null then
		update players set race = p_race,
						   age = p_age,
                           gender = p_gender,
                           ghost = p_ghost,
                           strength = p_strength,
                           intelligence = p_intelligence,
                           dexterity = p_dexterity,
                           wisdom = p_wisdom,
                           constitution = p_constitution,
                           charisma = p_charisma,
                           invisible = p_invisible,
                           attributePoints = p_attributes
		where id = pid;
	else
		insert into players (name, race, age, gender, ghost, strength, intelligence, dexterity, wisdom, constitution, charisma, invisible, attributePoints, whenCreated)
        values (p_name, p_race, p_age, p_gender, p_ghost, p_strength, p_intelligence, p_dexterity, p_wisdom, p_constitution, p_charisma, p_invisible, p_attributes, now());
    
        select id into pid from players where name = p_name;
    end if;
RETURN pid;
END;
##

CREATE PROCEDURE TestDB.`saveBiologicalInformation`(p_playerid int, p_intoxicated int,
p_stuffed int, p_drugged int, p_soaked int, p_headache int)
BEGIN
	declare pid int;
    
    select id into pid
    from biological where playerid = p_playerid;
    
    if pid is not null then
		update biological set intoxicated = p_intoxicated,
						      stuffed = p_stuffed,
						      drugged = p_drugged,
						      soaked = p_soaked,
						      headache = p_headache
		where id = pid;
	else
		insert into biological (playerid, intoxicated, stuffed, drugged, soaked, headache)
        values (p_playerid, p_intoxicated, p_stuffed, p_drugged, p_soaked, p_headache);
    end if;
END;
##
CREATE PROCEDURE TestDB.`saveCombatInformation`(p_playerid int, p_hp int,
p_maxhp int, p_sp int, p_maxsp int, p_st int, p_maxst int, p_wimpy int,
p_killList int, p_healhp int, p_healsp int, p_healst int)
BEGIN
	declare pid int;
 
    select id into pid
    from playerCombatData where playerid = p_playerid;
    
    if pid is not null then
		update playerCombatData set hitPoints = p_hp,
						      maxHitPoints = p_maxhp,
						      spellPoints = p_sp,
						      maxSpellPoints = p_maxsp,
						      staminaPoints = p_st,
						      maxStaminaPoints = p_maxst,
						      wimpy = p_wimpy,
						      onKillList = p_killList,
						      timeToHealHP = p_healhp,
						      timeToHealSP = p_healsp,
						      timeToHealST = p_healst
		where id = pid;
	else
		insert into playerCombatData (playerid,
									  hitPoints,
									  maxHitPoints,
									  spellPoints,
									  maxSpellPoints,
									  staminaPoints,
									  maxStaminaPoints,
									  wimpy,
									  onKillList,
									  timeToHealHP,
									  timeToHealSP,
									  timeToHealST)
        values (p_playerid, p_hp, p_maxhp, p_sp, p_maxsp, p_st, p_maxst,
				p_wimpy, p_killList, p_healhp, p_healsp, p_healst);
    end if;
END;
##
CREATE PROCEDURE TestDB.`saveMaterialAttribute`(p_playerid int, p_type varchar(45), p_value varchar(256))
BEGIN
	declare materialId int;
    
    select id into materialId
    from materialAttributes
    where playerid = p_playerid and type = p_type;
    
    if materialId is not null then
		update materialAttributes set value = p_title where id = materialId;
	else
		insert into materialAttributes (playerid, type, value)
        values (p_playerid, p_type, p_value);
    end if;
END;
##
CREATE PROCEDURE TestDB.`saveMaterialAttributes`(p_playerid int, p_title varchar(256),
p_pretitle varchar(256), p_msgin varchar(256), p_msgout varchar(256),
p_magicalin varchar(256), p_magicalout varchar(256), p_home varchar(256),
p_clone varchar(256), p_short varchar(256), p_long varchar(256))
BEGIN
	call saveMaterialAttribute(p_playerid, 'title', p_title);
	call saveMaterialAttribute(p_playerid, 'pretitle', p_pretitle);
	call saveMaterialAttribute(p_playerid, 'messageIn', p_msgin);
	call saveMaterialAttribute(p_playerid, 'messageOut', p_msgout);
	call saveMaterialAttribute(p_playerid, 'magicalMessageIn', p_magicalIn);
	call saveMaterialAttribute(p_playerid, 'magicalMessageOut', p_magicalOut);
	call saveMaterialAttribute(p_playerid, 'messageHome', p_home);
	call saveMaterialAttribute(p_playerid, 'messageClone', p_clone);
	call saveMaterialAttribute(p_playerid, 'shortDescription', p_short);
	call saveMaterialAttribute(p_playerid, 'longDescription', p_long);
END;