drop view if exists basicPlayerData;
##
drop view if exists researchChoicesView;
##
drop view if exists traitsView;
##
drop view if exists componentsView;
##
drop view if exists environmentView;
##
drop function if exists savePlayerDomain;
##
drop function if exists saveDomainSection;
##
drop function if exists saveDomainComponent;
##
drop function if exists saveDomainHenchman;
##
drop function if exists saveRegion;
##
drop function if exists saveEnvironmentInstance;
##
drop function if exists saveEnvironmentalElement;
##
drop function if exists saveEnvironmentalObject;
##
drop function if exists authenticateUser;
##
drop procedure if exists saveEnvironmentExit;
##
drop procedure if exists saveRegionMapDecorators;
##
drop procedure if exists saveRegionExit;
##
drop function if exists saveDomainUnit;
##
drop procedure if exists saveHenchmanSkills;
##
drop procedure if exists saveHenchmanTraits;
##
drop procedure if exists saveUnitTraits;
##
drop procedure if exists saveDomainComponentMaterials;
##
drop procedure if exists saveBiologicalInformation;
##
drop procedure if exists saveCombatInformation;
##
drop procedure if exists saveMaterialAttributes;
##
drop procedure if exists saveMaterialAttribute;
##
drop procedure if exists saveGuild;
##
drop procedure if exists saveQuest;
##
drop procedure if exists saveSkills;
##
drop procedure if exists saveTraits;
##
drop procedure if exists saveTemporaryTraits;
##
drop procedure if exists saveResearch;
##
drop procedure if exists pruneResearchChoices;
##
drop procedure if exists saveResearchChoiceOption;
##
drop procedure if exists saveOpenResearchTrees;
##
drop procedure if exists pruneInventory;
##
drop procedure if exists saveInventoryItem;
##
drop procedure if exists saveFaction;
##
drop procedure if exists saveCombatStatistics;
##
drop procedure if exists saveCombatStatisticsForRace;
##
drop procedure if exists saveWizardLevel;
##
drop procedure if exists saveOpinionOfCharacter;
##
drop procedure if exists saveCharacterState;
##
drop procedure if exists saveSetting;
##
drop procedure if exists saveBlockedUser;
##
drop procedure if exists updateLoginTime;
##
drop procedure if exists saveIssue;
##
drop procedure if exists saveHolding;
##
drop procedure if exists saveDomainBuilding;
##
drop procedure if exists createUser;
##
drop function if exists saveBasicPlayerInformation;
##
drop function if exists saveResearchChoice;
##
drop table if exists temporaryBans;
##
drop table if exists IPAddresses;
##
drop table if exists users;
##
drop table if exists environmentShops;
##
drop table if exists environmentalElements;
##
drop table if exists environmentalObjects;
##
drop table if exists environmentExits;
##
drop table if exists environmentDescriptions;
##
drop table if exists regionExits;
##
drop table if exists regionMapDecorators;
##
drop table if exists environmentInstances;
##
drop table if exists regions;
##
drop table if exists domainUnitTraits;
##
drop table if exists domainUnits;
##
drop table if exists domainHenchmanTraits;
##
drop table if exists domainHenchmanSkills;
##
drop table if exists domainHenchmen;
##
drop table if exists domainComponentMaterials;
##
drop table if exists domainComponentUpgrades;
##
drop table if exists domainSectionComponents;
##
drop table if exists domainSections;
##
drop table if exists domains;
##
drop table if exists settings;
##
drop table if exists blockedUsers;
##
drop table if exists opinions;
##
drop table if exists characterStates;
##
drop table if exists biological;
##
drop table if exists combatStatisticsForRace;
##
drop table if exists combatStatistics;
##
drop table if exists guilds;
##
drop table if exists materialAttributes;
##
drop table if exists openResearchTrees;
##
drop table if exists playerCombatData;
##
drop table if exists quests;
##
drop table if exists research;
##
drop table if exists researchChoiceItems;
##
drop table if exists researchChoices;
##
drop table if exists skills;
##
drop table if exists wizards;
##
drop table if exists wizardTypes;
##
drop table if exists timedtraits;
##
drop table if exists traits;
##
drop table if exists temporaryTraits;
##
drop table if exists inventory;
##
drop table if exists factions;
##
drop table if exists players;
##
drop table if exists environment;
##
drop table if exists issues;
##
CREATE TABLE `temporaryBans` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `IPAddress` varchar(15) NOT NULL,
  `BannedUntil` datetime NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `login` varchar(40) NOT NULL,
  `password` varchar(20) NOT NULL,
  `isDisabled` tinyint(1) NOT NULL DEFAULT '0',
  `lastIPAddress` varchar(15) NOT NULL,
  `LastLogin` datetime NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name_UNIQUE` (`login`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `IPAddresses` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `userId` int(11) NOT NULL,
  `IPAddress` varchar(15) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `IPAddresses_userId` FOREIGN KEY (`userId`) REFERENCES `users` (`id`) 
  ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `issues` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `status` smallint NOT NULL DEFAULT '0',
  `loggedBy` varchar(40) NOT NULL,
  `assignedTo` varchar(40),
  `firstLoggedTime` datetime NOT NULL,
  `affectedObject` varchar(255) NOT NULL,
  `location` varchar(255) NOT NULL,
  `data` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `environment` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `currentTime` int(11) NOT NULL DEFAULT '0',
  `currentDay` int(11) NOT NULL DEFAULT '0',
  `currentYear` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
INSERT INTO environment (currentTime, currentDay, currentYear) values (660, 92, 2942);
##
CREATE TABLE `players` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(40) NOT NULL,
  `race` varchar(20) NOT NULL,
  `age` bigint unsigned NOT NULL,
  `gender` tinyint unsigned NOT NULL DEFAULT '0',
  `ghost` tinyint unsigned NOT NULL DEFAULT '0',
  `strength` int(11) NOT NULL DEFAULT '0',
  `intelligence` int(11) NOT NULL DEFAULT '0',
  `dexterity` int(11) NOT NULL DEFAULT '0',
  `wisdom` int(11) NOT NULL DEFAULT '0',
  `constitution` int(11) NOT NULL DEFAULT '0',
  `charisma` int(11) NOT NULL DEFAULT '0',
  `invisible` tinyint NOT NULL DEFAULT '0',
  `whenCreated` datetime NOT NULL,
  `LastLogin` datetime NOT NULL,
  `location` varchar(200) NOT NULL,
  `attributePoints` smallint NOT NULL DEFAULT '0',
  `skillPoints` smallint NOT NULL DEFAULT '0',
  `researchPoints` smallint NOT NULL DEFAULT '0',
  `unassignedExperience` bigint DEFAULT NULL,
  `playerMoney` bigint DEFAULT NULL,
  `userId` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name_UNIQUE` (`name`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `biological` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `intoxicated` smallint NOT NULL DEFAULT '0',
  `stuffed` smallint NOT NULL DEFAULT '0',
  `drugged` smallint NOT NULL DEFAULT '0',
  `soaked` smallint NOT NULL DEFAULT '0',
  `headache` smallint NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `playerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `combatStatistics` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(40) NOT NULL,
  `level` int(11) NOT NULL,
  `foeKey` varchar(200) DEFAULT NULL,
  `timesKilled` int(11) DEFAULT NULL,
  `playerid` int(11) NOT NULL,
  `isNemesis` tinyint NOT NULL DEFAULT '0',
  `isBestKill` tinyint NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `combatStatisticsplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `combatStatisticsForRace` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `race` varchar(20) NOT NULL,
  `timesKilled` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `combatStatisticsForRaceplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `guilds` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `name` varchar(40) NOT NULL,
  `level` int(11) NOT NULL DEFAULT '0',
  `experience` bigint NOT NULL DEFAULT '0',
  `rank` varchar(45) DEFAULT NULL,
  `title` varchar(45) DEFAULT NULL,
  `pretitle` varchar(45) DEFAULT NULL,
  `leftGuild` bigint DEFAULT NULL,
  `anathema` bigint DEFAULT NULL,
  `rankAdvancedAt` bigint DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `guildsplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `materialAttributes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `type` varchar(40) NOT NULL,
  `value` varchar(80) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `materialAttributesplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `openResearchTrees` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `researchTree` varchar(200) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `openResearchTreesplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `playerCombatData` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `hitPoints` int(11) NOT NULL,
  `maxHitPoints` int(11) NOT NULL,
  `spellPoints` int(11) NOT NULL,
  `maxSpellPoints` int(11) NOT NULL,
  `staminaPoints` int(11) NOT NULL,
  `maxStaminaPoints` int(11) NOT NULL,
  `wimpy` smallint NOT NULL DEFAULT '0',
  `onKillList` tinyint NOT NULL DEFAULT '0',
  `timeToHealHP` smallint NOT NULL DEFAULT '0',
  `timeToHealSP` smallint NOT NULL DEFAULT '0',
  `timeToHealST` smallint NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `playerCombatDataplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `quests` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `path` varchar(200) NOT NULL,
  `name` varchar(45) NOT NULL,
  `state` varchar(45) NOT NULL,
  `statesCompleted` varchar(256) DEFAULT NULL,
  `isActive` tinyint NOT NULL DEFAULT '0',
  `isCompleted` tinyint NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `questsplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `research` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerId` int(11) NOT NULL,
  `path` varchar(200) NOT NULL,
  `whenResearchBegan` bigint NOT NULL DEFAULT '0',
  `whenResearchComplete` bigint DEFAULT NULL,
  `timeSpentLearning` int(11) DEFAULT NULL,
  `researchComplete` tinyint NOT NULL DEFAULT '0',
  `timeToCompleteLearning` int(11) DEFAULT NULL,
  `cooldown` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `researchplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `researchChoices` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerId` int(11) NOT NULL,
  `name` varchar(45) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `researchChoicesplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `researchChoiceItems` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `researchChoiceId` int(11) NOT NULL,
  `selectionNumber` varchar(5) NOT NULL,
  `type` varchar(15) NOT NULL,
  `name` varchar(45) NOT NULL,
  `description` varchar(256) NOT NULL,
  `key` varchar(200) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `researchChoiceId_idx` (`researchChoiceId`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;
##
CREATE TABLE `wizardTypes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `type` varchar(20) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=latin1;
##
insert into wizardTypes (type) values ('apprentice'), ('wizard'),
('creator'), ('highwizard'),('senior'),('admin'),('elder'),('sage'),
('archwizard'),('demigod'),('god'),('owner'),('emeritus');
##
CREATE TABLE `wizards` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerId` int(11) NOT NULL,
  `typeId` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `playerid_idx` (`playerId`),
  KEY `typeid_idx` (`typeId`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
##
CREATE TABLE `skills` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `name` varchar(45) NOT NULL,
  `value` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `skillsplayerid_idx` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
##
CREATE TABLE `temporaryTraits` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `traitList` varchar(512) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `temptraitsplayerid_idx` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
##
CREATE TABLE `traits` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `path` varchar(200) NOT NULL,
  `name` varchar(45) NOT NULL,
  `added` bigint NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `traits_playerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
##
CREATE TABLE `timedtraits` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `traitid` int(11) NOT NULL,
  `endTime` int(11) NOT NULL,
  `expireMessage` varchar(256) DEFAULT NULL,
  `triggeringResearch` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `timed_traitsid` FOREIGN KEY (`traitid`) REFERENCES `traits` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
##
CREATE TABLE `factions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `path` varchar(200) NOT NULL,
  `disposition` varchar(20) NOT NULL,
  `reputation` int(11) NOT NULL,
  `lastInteraction` int(11) NOT NULL,
  `lastReputation` int(11) NOT NULL,
  `numberOfInteractions` int(11) NOT NULL,
  `dispositionTime` bigint NOT NULL,
  `isMember` tinyint(4) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `factions_playerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
##
CREATE TABLE `inventory` (
  `playerid` int(11) NOT NULL,
  `fileName` varchar(200) NOT NULL,
  `data` blob NOT NULL,
  `isEquipped` tinyint NOT NULL DEFAULT '0',
  KEY `inventory_playerid_idx` (`playerid`),
  CONSTRAINT `inventory_playerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `opinions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerId` int(11) NOT NULL,
  `targetKey` varchar(200) NOT NULL,
  `opinion` int(11) NOT NULL DEFAULT '0',
  `type` VARCHAR(45) NOT NULL DEFAULT 'neutral',
  `lastInteraction` bigint DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `opinions_playerid_idx` (`playerId`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
##
CREATE TABLE `characterStates` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerId` int(11) NOT NULL,
  `targetKey` varchar(200) NOT NULL,
  `state` varchar(80) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `characterStates_playerid_idx` (`playerId`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
##
CREATE TABLE `settings` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `setting` varchar(40) NOT NULL,
  `value` varchar(20) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `settingsplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `blockedUsers` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `playerid` int(11) NOT NULL,
  `blockedPlayerId` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `blockingplayerid` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `blockedplayersid` FOREIGN KEY (`blockedPlayerId`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `domains` (
  `id` INT(11) NOT NULL AUTO_INCREMENT,
  `playerid` INT(11) NOT NULL,
  `name` VARCHAR(128) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `player_key_idx` (`playerid` ASC),
  CONSTRAINT `player_key` FOREIGN KEY (`playerid`) REFERENCES `players` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `domainSections` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `type` VARCHAR(64) NOT NULL,
  `name` VARCHAR(100) NOT NULL,
  `constructionStart` bigint NOT NULL,
  `timeLeft` INT DEFAULT NULL,
  `completionTime` bigint DEFAULT NULL,
  `domainId` INT NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `domainid_for_section_idx` (`domainId` ASC),
  CONSTRAINT `domainid_for_section` FOREIGN KEY (`domainId`) REFERENCES `domains` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `domainSectionComponents` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `sectionid` INT NOT NULL,
  `type` VARCHAR(100) NOT NULL,
  `name` VARCHAR(100) NOT NULL,
   `maximumStructure` INT NOT NULL,
   `currentStructure` INT NOT NULL,
   `timeUntilRepaired` INT DEFAULT NULL,
  PRIMARY KEY (`id`),
  INDEX `component_section_idx` (`sectionid` ASC),
  CONSTRAINT `component_section` FOREIGN KEY (`sectionid`) REFERENCES `domainSections` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `domainComponentMaterials` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `componentId` INT NOT NULL,
  `type` VARCHAR(45) NOT NULL,
  `name` VARCHAR(64) NOT NULL,
  PRIMARY KEY (`id`),
  INDEX `component_material_idx` (`componentId` ASC),
  CONSTRAINT `component_material` FOREIGN KEY (`componentId`) REFERENCES `domainSectionComponents` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `domainComponentUpgrades` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `componentId` INT NOT NULL,
  `name` VARCHAR(128) NOT NULL,
  PRIMARY KEY (`id`),
  INDEX `component_upgrade_idx` (`componentId` ASC),
  CONSTRAINT `component_upgrade` FOREIGN KEY (`componentId`) REFERENCES `domainSectionComponents` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `domainHenchmen` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `originatingLocationId` INT NOT NULL,
  `currentLocation` VARCHAR(256) NOT NULL,
  `name` VARCHAR(128) NOT NULL,
  `gender` INT NOT NULL,
  `race` VARCHAR(45) NOT NULL DEFAULT 'human',
  `age` INT NOT NULL DEFAULT 21,
  `activity` VARCHAR(64) NOT NULL DEFAULT 'idle',
  `persona` VARCHAR(64) NOT NULL,
  `level` INT NOT NULL DEFAULT 1,
  `experience` INT NOT NULL DEFAULT 0,
  `opinion` INT NOT NULL DEFAULT 0,
  `opinionType` VARCHAR(45) NOT NULL DEFAULT 'neutral',
  PRIMARY KEY (`id`),
  INDEX `henchman_base_location_idx` (`originatingLocationId` ASC),
  CONSTRAINT `henchman_base_location` FOREIGN KEY (`originatingLocationId`) REFERENCES `domainSectionComponents` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `domainHenchmanSkills` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `henchmanId` int(11) NOT NULL,
  `name` varchar(45) NOT NULL,
  `value` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `skillshenchmanid_idx` FOREIGN KEY (`henchmanId`) REFERENCES `domainHenchmen` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
##
CREATE TABLE `domainHenchmanTraits` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `henchmanId` int(11) NOT NULL,
  `path` varchar(200) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  CONSTRAINT `traits_henchmanId` FOREIGN KEY (`henchmanId`) REFERENCES `domainHenchmen` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
##
CREATE TABLE `domainUnits` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `type` VARCHAR(45) NOT NULL,
  `name` VARCHAR(100) NOT NULL,
  `morale` INT NOT NULL,
  `maxTroops` INT NOT NULL,
  `currentTroops` INT NOT NULL,
  `movement` INT NOT NULL,
  `skill` INT NOT NULL,
  `locationId` INT NOT NULL,
  `currentLocation` VARCHAR(256) DEFAULT NULL,
  `leaderId` INT DEFAULT NULL,
  `leaderIsOwner` TINYINT NOT NULL,
  PRIMARY KEY (`id`),
  INDEX `unit_location_idx` (`locationId` ASC),
  CONSTRAINT `unit_location` FOREIGN KEY (`locationId`) REFERENCES `domainSectionComponents` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `unit_leader` FOREIGN KEY (`leaderId`) REFERENCES `domainHenchmen` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `domainUnitTraits` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `unitId` INT NOT NULL,
  `name` VARCHAR(128) NOT NULL,
  PRIMARY KEY (`id`),
  INDEX `unit_trait_idx` (`unitId` ASC),
  CONSTRAINT `unit_trait` FOREIGN KEY (`unitId`) REFERENCES `domainUnits` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `regions` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(256) NOT NULL,
  `type` VARCHAR(45) NOT NULL,
  `x-dimension` TINYINT NOT NULL,
  `y-dimension` TINYINT NOT NULL,
  `entryPoint` VARCHAR(256) NOT NULL,
  `entryDirection` VARCHAR(20) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  UNIQUE INDEX `name_UNIQUE` (`name` ASC),
  INDEX `region_entry_info` (`entryPoint`, `entryDirection` ASC)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `environmentInstances` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `regionId` INT NULL,
  `x-coordinate` INT NULL,
  `y-coordinate` INT NULL,
  `type` VARCHAR(40) NULL,
  `identifier` VARCHAR(256) NOT NULL,
  `name` VARCHAR(128) NULL,
  `isCloned` BINARY NOT NULL DEFAULT false,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `instance_region_idx` (`regionId` ASC),
  CONSTRAINT `instance_region` 
      FOREIGN KEY (`regionId`) 
      REFERENCES `regions` (`id`)
      ON DELETE NO ACTION 
      ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `regionExits` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `regionId` INT NOT NULL,
  `environmentId` INT NOT NULL,
  `location` VARCHAR(256) NOT NULL,
  `direction` VARCHAR(20) NOT NULL,
  `state` VARCHAR(80) NULL DEFAULT 'default',
  `x-coordinate` INT NOT NULL,
  `y-coordinate` INT NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `region_exit_idx` (`regionId` ASC),
  INDEX `region_environment_exit_idx` (`environmentId` ASC),
  CONSTRAINT `region_exit` 
      FOREIGN KEY (`regionId`) 
      REFERENCES `regions` (`id`)
      ON DELETE NO ACTION 
      ON UPDATE NO ACTION,
  CONSTRAINT `region_environment_exit`
      FOREIGN KEY (`environmentId`)
      REFERENCES `environmentInstances` (`id`)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `regionMapDecorators` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `regionId` INT NOT NULL,
  `class` VARCHAR(20) NOT NULL,
  `type` VARCHAR(20) NOT NULL,
  `size` VARCHAR(20) NOT NULL,
  `color` VARCHAR(20) NOT NULL,
  `x-coordinate` INT NOT NULL,
  `y-coordinate` INT NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `region_decorator_idx` (`regionId` ASC),
  CONSTRAINT `region_decorator` 
      FOREIGN KEY (`regionId`) 
      REFERENCES `regions` (`id`)
      ON DELETE NO ACTION 
      ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `environmentDescriptions` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `environmentId` INT NOT NULL,
  `state` VARCHAR(80) NULL,
  `description` LONGTEXT NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `environment_description_idx` (`environmentId` ASC),
  CONSTRAINT `environment_description`
      FOREIGN KEY (`environmentId`)
      REFERENCES `environmentInstances` (`id`)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `environmentShops` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `environmentId` INT NOT NULL,
  `shop` VARCHAR(256) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `environment_shop_idx` (`environmentId` ASC),
  CONSTRAINT `environment_shop`
      FOREIGN KEY (`environmentId`)
      REFERENCES `environmentInstances` (`id`)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `environmentExits` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `environmentId` INT NOT NULL,
  `location` VARCHAR(256) NOT NULL,
  `direction` VARCHAR(20) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `environment_exit_idx` (`environmentId` ASC),
  CONSTRAINT `environment_exit`
      FOREIGN KEY (`environmentId`)
      REFERENCES `environmentInstances` (`id`)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `environmentalElements` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `environmentId` INT NOT NULL,
  `type` VARCHAR(45) NOT NULL,
  `value` VARCHAR(256) NOT NULL,
  `state` VARCHAR(80) NULL,
  `location` VARCHAR(40) NULL,
  `x-coordinate` INT NULL,
  `y-coordinate` INT NULL,
  `z-coordinate` INT NULL,
  `x-rotation` INT NULL,
  `y-rotation` INT NULL,
  `z-rotation` INT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `environment_element_idx` (`environmentId` ASC),
  CONSTRAINT `environment_element` FOREIGN KEY (`environmentId`) REFERENCES `environmentInstances` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE TABLE `environmentalObjects` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `environmentId` INT NOT NULL,
  `state` VARCHAR(80) NULL,
  `path` VARCHAR(256) NOT NULL,
  `isRandom` BINARY NOT NULL DEFAULT false,
  `probability` TINYINT NULL,
  `quantity` TINYINT NULL,
  `type` VARCHAR(10) NOT NULL DEFAULT 'object',
  PRIMARY KEY (`id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `environment_object_idx` (`environmentId` ASC),
  CONSTRAINT `environment_object`
      FOREIGN KEY (`environmentId`)
      REFERENCES `environmentInstances` (`id`)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
##
CREATE VIEW `basicPlayerData` AS select `players`.`name` AS `name`,
                                        `players`.`race` AS `race`,
                                        `players`.`age` AS `age`,
                                        `players`.`gender` AS `gender`,
                                        `players`.`ghost` AS `ghost`,
                                        `players`.`strength` AS `strength`,
                                        `players`.`intelligence` AS `intelligence`,
                                        `players`.`dexterity` AS `dexterity`,
                                        `players`.`wisdom` AS `wisdom`,
                                        `players`.`constitution` AS `constitution`,
                                        `players`.`charisma` AS `charisma`,
                                        `players`.`invisible` AS `invisible`,
                                        `biological`.`intoxicated` AS `intoxicated`,
                                        `biological`.`stuffed` AS `stuffed`,
                                        `biological`.`drugged` AS `drugged`,
                                        `biological`.`soaked` AS `soaked`,
                                        `biological`.`headache` AS `headache`,
                                        `playerCombatData`.`hitPoints` AS `hitPoints`,
                                        `playerCombatData`.`maxHitPoints` AS `maxHitPoints`,
                                        `playerCombatData`.`spellPoints` AS `spellPoints`,
                                        `playerCombatData`.`maxSpellPoints` AS `maxSpellPoints`,
                                        `playerCombatData`.`staminaPoints` AS `staminaPoints`,
                                        `playerCombatData`.`maxStaminaPoints` AS `maxStaminaPoints`,
                                        `playerCombatData`.`wimpy` AS `wimpy`,
                                        `playerCombatData`.`onKillList` AS `onKillList`,
                                        `playerCombatData`.`timeToHealHP` AS `timeToHealHP`,
                                        `playerCombatData`.`timeToHealSP` AS `timeToHealSP`,
                                        `playerCombatData`.`timeToHealST` AS `timeToHealST`,
                                        `players`.`whenCreated` AS `whenCreated`,
                                        `players`.`LastLogin` AS `LastLogin`,
                                        `players`.`location` AS `location`,
                                        `players`.`attributePoints` AS `availableAttributePoints`,
                                        `players`.`skillPoints` AS `availableSkillPoints`,
                                        `players`.`researchPoints` AS `availableResearchPoints`,
                                        `players`.`unassignedExperience` AS `unassignedExperience`,
                                        `players`.`playerMoney` AS `playerMoney`,
                                        `players`.`id` AS `playerId` 
                               from ((`players` 
                               join `biological` on((`players`.`id` = `biological`.`playerid`))) 
                               join `playerCombatData` on((`players`.`id` = `playerCombatData`.`playerid`)));
##
CREATE VIEW `researchChoicesView` AS select `researchChoices`.`playerId` AS `playerId`,
                                            `researchChoices`.`name` AS `Choice`,
                                            `researchChoiceItems`.`selectionNumber` AS `selectionNumber`,
                                            `researchChoiceItems`.`type` AS `type`,
                                            `researchChoiceItems`.`name` AS `name`,
                                            `researchChoiceItems`.`description` AS `description`,
                                            `researchChoiceItems`.`key` AS `key` 
                                     from (`researchChoices` 
                                     join `researchChoiceItems` on((`researchChoices`.`id` = `researchChoiceItems`.`researchChoiceId`)));
##
CREATE VIEW `traitsView` AS select `traits`.`playerid` AS `playerid`,
                                   `traits`.`path` AS `path`,
                                   `traits`.`name` AS `name`,
                                   `traits`.`added` AS `added`,
                                   `timedtraits`.`endTime` AS `endTime`,
                                   `timedtraits`.`expireMessage` AS `expireMessage`,
                                   `timedtraits`.`triggeringResearch` AS `triggeringResearch` 
                            from (`traits` 
                            left join `timedtraits` on((`traits`.`id` = `timedtraits`.`traitid`)));
##
CREATE VIEW `componentsView` AS 
    select `domainSectionComponents`.`sectionid` AS `sectionId`,
        `domainSectionComponents`.`id` AS `componentId`,
		`domainSectionComponents`.`type` AS `componentType`,
        `domainSectionComponents`.`name` AS `componentName`,
        `domainSectionComponents`.`maximumStructure` AS `maximumStructure`,
        `domainSectionComponents`.`currentStructure` AS `currentStructure`,
        `domainSectionComponents`.`timeUntilRepaired` AS `timeUntilRepaired`,
        `metal`.`name` as `metal`,
        `stone`.`name` as `stone`,
        `textile`.`name` as `textile`,
        `wood`.`name` as `wood`
    from `domainSectionComponents` 
    left outer join `domainComponentMaterials` as `metal`
		on `domainSectionComponents`.`id` = `metal`.`componentId` and `metal`.`type` = 'metal'
    left outer join `domainComponentMaterials` as `stone`
		on `domainSectionComponents`.`id` = `stone`.`componentId` and `stone`.`type` = 'stone'
    left outer join `domainComponentMaterials` as `textile`
		on `domainSectionComponents`.`id` = `textile`.`componentId` and `textile`.`type` = 'textile'
    left outer join `domainComponentMaterials` as `wood`
		on `domainSectionComponents`.`id` = `wood`.`componentId` and `wood`.`type` = 'wood';
##
CREATE VIEW `environmentView` AS
    select `environmentInstances`.`id` AS `environmentId`,
           `environmentInstances`.`regionId` AS `regionId`,
           `environmentInstances`.`x-coordinate` AS `x-coordinate`,
           `environmentInstances`.`y-coordinate` AS `y-coordinate`,
           `environmentInstances`.`type` AS `type`,
           `environmentInstances`.`identifier` AS `identifier`,
           `environmentInstances`.`name` AS `name`,
           `environmentInstances`.`isCloned` AS `isCloned`,
           `environmentDescriptions`.`description` AS `description`,
           `environmentShops`.`shop` AS `shop`
    from `environmentInstances`
    left outer join `environmentDescriptions`
        on `environmentDescriptions`.`environmentId` = `environmentInstances`.`id` 
        AND (`environmentDescriptions`.`state` = 'default' OR `environmentDescriptions`.`state` is null)
    left outer join `environmentShops`
        on `environmentShops`.`environmentId` = `environmentInstances`.`id`;
##
CREATE FUNCTION `saveBasicPlayerInformation`(p_name varchar(40),
p_race varchar(20), p_age int, p_gender int, p_ghost int, p_strength int,
p_intelligence int, p_dexterity int, p_wisdom int, p_constitution int,
p_charisma int, p_invisible int, p_attributes int, p_skill int,
p_research int, p_unassigned int, p_location varchar(200), p_money int) RETURNS int(11)
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
                           attributePoints = p_attributes,
                           skillPoints = p_skill,
                           researchPoints = p_research,
                           unassignedExperience = p_unassigned,
                           location = p_location,
                           playerMoney = p_money,
                           LastLogin = now()
        where id = pid;
    else
        insert into players (name, race, age, gender, ghost, strength,
        intelligence, dexterity, wisdom, constitution, charisma, invisible,
        attributePoints, skillPoints, researchPoints, unassignedExperience, 
        whenCreated, LastLogin, location, playerMoney)
        values (p_name, p_race, p_age, p_gender, p_ghost, p_strength, 
        p_intelligence, p_dexterity, p_wisdom, p_constitution, p_charisma, 
        p_invisible, p_attributes, p_skill, p_research, p_unassigned, now(), now(), p_location, p_money);
    
        select id into pid from players where name = p_name;
    end if;
RETURN pid;
END;
##
CREATE FUNCTION `savePlayerDomain` (p_player varchar(40), p_name varchar(128)) RETURNS int(11)
BEGIN
    declare pid int;
    declare domainId int;
    
    select id into pid
    from players where name = p_player;
 
    if pid is not null then
        select id into domainId
        from domains where playerid = pid and name = p_name;
    
        if domainId is null then
            insert into domains (playerid, name)
            values (pid, p_name);

            select id into domainId
            from domains where playerid = pid and name = p_name;
        end if;
    end if;
RETURN domainId;
END;
##
CREATE FUNCTION `saveDomainSection` ( p_domainId int,  p_type varchar(100), 
    p_name varchar(100), p_start int, p_end int, p_timeLeft int) RETURNS int(11)
BEGIN
    declare sectionId int;

    select id into sectionId
    from domainSections where domainId = p_domainId and type = p_type;
    
    if sectionId is not null then
        update domainSections set type = p_type,
                           name = p_name,
                           constructionStart = p_start,
                           timeLeft = p_timeLeft,
                           completionTime = p_end
        where id = sectionId;
    else
        insert into domainSections (type, name, constructionStart, timeLeft,
            completionTime, domainId)
        values (p_type, p_name, p_start, p_timeLeft, p_end, p_domainId);

        select id into sectionId
        from domainSections where domainId = p_domainId and type = p_type;
    end if;
RETURN sectionId;
END;
##
CREATE FUNCTION `saveDomainComponent` ( p_sectionId int,  p_type varchar(100), 
    p_name varchar(100), p_max int, p_current int, p_time int) RETURNS int(11)
BEGIN
    declare componentId int;

    select id into componentId
    from domainSectionComponents 
    where sectionId = p_sectionId and type = p_type;

    if componentId is not null then
        update domainSectionComponents set type = p_type,
                           name = p_name,
                           maximumStructure = p_max,
                           currentStructure = p_current,
                           timeUntilRepaired = p_time
        where id = componentId;
    else
        insert into domainSectionComponents (sectionId, type, name, maximumStructure, 
            currentStructure, timeUntilRepaired)
        values (p_sectionId, p_type, p_name, p_max, p_current, p_time);

        select id into componentId
        from domainSectionComponents 
        where sectionId = p_sectionId and type = p_type;
    end if;
RETURN componentId;
END;
##
CREATE FUNCTION `saveDomainHenchman` ( p_locationId int,  p_name varchar(128), 
    p_gender int,  p_race varchar(45), p_age int, p_currentLocation varchar(256),
    p_activity varchar(64), p_persona varchar(64), p_level int, p_experience int, 
    p_opinion int, p_opinionType varchar(45)) RETURNS int(11)
BEGIN
    declare henchmanId int;

    select id into henchmanId
    from domainHenchmen 
    where originatingLocationId = p_locationId and name = p_name and persona = p_persona;

    if henchmanId is not null then
        update domainHenchmen set age = p_age,
                           currentLocation = p_currentLocation,
                           activity = p_activity,
                           level = p_level,
                           experience = p_experience,
                           opinion = p_opinion,
                           opinionType = p_opinionType
        where id = henchmanId;
    else
        INSERT INTO domainHenchmen
            (originatingLocationId, currentLocation, name, gender, race, age, activity, persona,
                level, experience, opinion, opinionType)
        VALUES (p_locationId, p_currentLocation, p_name, p_gender, p_race, p_age, p_activity, 
                p_persona, p_level, p_experience, p_opinion, p_opinionType);

        select id into henchmanId
        from domainHenchmen 
        where originatingLocationId = p_locationId and name = p_name and persona = p_persona;
    end if;
RETURN henchmanId;
END;
##
CREATE FUNCTION `saveDomainUnit` ( p_locationId int,  p_type varchar(45),
    p_name varchar(100), p_morale int, p_maxTroops int, p_currentTroops int,
    p_movement int, p_skill int, p_leaderId int, p_leaderIsOwner int, 
    p_currentLocation varchar(256)) RETURNS int(11)
BEGIN
    declare unitId int;

    select id into unitId
    from domainUnits 
    where locationId = p_locationId and name = p_name and type = p_type;

    if unitId is not null then
        update domainUnits set morale = p_morale,
                           maxTroops = p_maxTroops,
                           currentTroops = p_currentTroops,
                           movement = p_movement,
                           skill = p_skill,
                           leaderId = p_leaderId,
                           leaderIsOwner = p_leaderIsOwner,
                           currentLocation = p_currentLocation
        where id = unitId;

    else
        insert into domainUnits 
            (type, name, morale, maxTroops, currentTroops, movement, skill, locationId,
                leaderIsOwner, currentLocation)
            values (p_type, p_name, p_morale, p_maxTroops, p_currentTroops, p_movement, 
                p_skill, p_locationId, p_leaderIsOwner, p_currentLocation);

        select id into unitId
        from domainUnits 
        where locationId = p_locationId and name = p_name and type = p_type;

        if p_leaderId > 0 then
            update domainUnits set leaderId = p_leaderId
            where id = unitId;  
        end if;

    end if;
RETURN unitId;
END;
##
CREATE PROCEDURE `saveDomainComponentMaterials` ( p_componentId int, 
    p_type varchar(45), p_name varchar(64))
BEGIN
    declare materialId int;

    select id into materialId
    from domainComponentMaterials 
    where componentId = p_componentId and type = p_type;

    if materialId is not null then
        update domainComponentMaterials set type = p_type, name = p_name
        where id = materialId;
    else
        insert into domainComponentMaterials (componentId, type, name)
        values (p_componentId, p_type, p_name);
    end if;
END;
##
CREATE PROCEDURE `saveHenchmanSkills` ( p_henchmanId int, 
    p_name varchar(45), p_value int)
BEGIN
    declare skillId int;

    select id into skillId
    from domainHenchmanSkills 
    where henchmanId = p_henchmanId and name = p_name;
    
    if skillId is not null then
        update domainHenchmanSkills set value = p_value
        where id = skillId;
    else
        insert into domainHenchmanSkills (henchmanId, name, value)
        values (p_henchmanId, p_name, p_value);
    end if;
END;
##
CREATE PROCEDURE `saveHenchmanTraits` ( p_henchmanId int, p_path varchar(200))
BEGIN
    declare traitId int;

    select id into traitId
    from domainHenchmanTraits 
    where henchmanId = p_henchmanId and path = p_path;
    
    if traitId is null then
        insert into domainHenchmanTraits (henchmanId, path)
        values (p_henchmanId, p_path);
    end if;
END;
##
CREATE PROCEDURE `saveUnitTraits` ( p_unitId int, p_trait varchar(128))
BEGIN
    declare traitId int;

    select id into traitId
    from domainUnitTraits 
    where unitId = p_unitId and name = p_trait;
    
    if traitId is null then
        insert into domainUnitTraits (unitId, name)
        values (p_unitId, p_trait);
    end if;
END;
##
CREATE PROCEDURE `saveBiologicalInformation`(p_playerid int, p_intoxicated int,
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
CREATE PROCEDURE `saveCombatInformation`(p_playerid int, p_hp int,
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
CREATE PROCEDURE `saveMaterialAttribute`(p_playerid int, p_type varchar(45), p_value varchar(256))
BEGIN
    declare materialId int;
    
    select id into materialId
    from materialAttributes
    where playerid = p_playerid and type = p_type;
    
    if materialId is not null then
        update materialAttributes set value = p_value where id = materialId;
    else
        insert into materialAttributes (playerid, type, value)
        values (p_playerid, p_type, p_value);
    end if;
END;
##
CREATE PROCEDURE `saveMaterialAttributes`(p_playerid int, p_title varchar(256),
p_pretitle varchar(256), p_msgin varchar(256), p_msgout varchar(256),
p_magicalin varchar(256), p_magicalout varchar(256), p_home varchar(256),
p_clone varchar(256), p_short varchar(256), p_long varchar(256))
BEGIN
    if p_title <> '' then
        call saveMaterialAttribute(p_playerid, 'title', p_title);
    end if;
    if p_pretitle <> '' then
        call saveMaterialAttribute(p_playerid, 'pretitle', p_pretitle);
    end if;
    if p_msgin <> '' then
        call saveMaterialAttribute(p_playerid, 'messageIn', p_msgin);
    end if;
    if p_msgout <> '' then
        call saveMaterialAttribute(p_playerid, 'messageOut', p_msgout);
    end if;
    if p_magicalIn <> '' then
        call saveMaterialAttribute(p_playerid, 'magicalMessageIn', p_magicalIn);
    end if;
    if p_magicalOut <> '' then
        call saveMaterialAttribute(p_playerid, 'magicalMessageOut', p_magicalOut);
    end if;
    if p_home <> '' then
        call saveMaterialAttribute(p_playerid, 'messageHome', p_home);
    end if;
    if p_clone <> '' then
        call saveMaterialAttribute(p_playerid, 'messageClone', p_clone);
    end if;
    if p_short <> '' then
        call saveMaterialAttribute(p_playerid, 'shortDescription', p_short);
    end if;
    if p_long <> '' then
        call saveMaterialAttribute(p_playerid, 'longDescription', p_long);
    end if;
END;
##
CREATE PROCEDURE `saveGuild`(p_playerid int, p_guild varchar(40), p_title varchar(45), 
p_pretitle varchar(45), p_rank varchar(45), p_level int, p_experience int, p_leftGuild int,
p_anathema int, p_rankAdvancedAt int)
BEGIN
    declare guildId int;
 
    select id into guildId
    from guilds where playerid = p_playerid and name = p_guild;
    
    if guildId is not null then
        update guilds set title = p_title,
                          pretitle = p_pretitle,
                          rank = p_rank,
                          level = p_level,
                          experience = p_experience,
                          leftGuild = p_leftGuild,
                          anathema = p_anathema,
                          rankAdvancedAt = p_rankAdvancedAt
        where id = guildId;
    else
        insert into guilds (playerid,
                                      name,
                                      title,
                                      pretitle,
                                      rank,
                                      level,
                                      experience,
                                      leftGuild,
                                      anathema,
                                      rankAdvancedAt)
        values (p_playerid, p_guild, p_title, p_pretitle, p_rank, p_level,
                p_experience, p_leftGuild, p_anathema, p_rankAdvancedAt);
    end if;
END;
##
CREATE PROCEDURE `saveQuest` (p_playerid int, p_quest varchar(200), p_name varchar(45), 
p_state varchar(45), p_statesCompleted varchar(45), p_active int, p_completed int)
BEGIN
    declare questId int;
 
    select id into questId
    from quests where playerid = p_playerid and path = p_quest;
    
    if questId is not null then
        update quests set name = p_name,
                          state = p_state,
                          statesCompleted = p_statesCompleted,
                          isActive = p_active,
                          isCompleted = p_completed
        where id = questId;
    else
        insert into quests (playerid, path, name, state, statesCompleted, isActive, isCompleted)
        values (p_playerid, p_quest, p_name, p_state, p_statesCompleted, p_active, p_completed);
    end if;
END;
##
CREATE PROCEDURE `saveResearch`(p_playerid int, p_path varchar(200), p_began int, 
p_whenCompleted int, p_timeSpent int, p_completed int, p_timeToComplete int, 
p_cooldown int)
BEGIN
    declare researchId int;
 
    select id into researchId
    from research where playerid = p_playerid and path = p_path;
    
    if researchId is not null then
        update research set whenResearchBegan = p_began,
                          whenResearchComplete = p_whenCompleted,
                          timeSpentLearning = p_timeSpent,
                          researchComplete = p_completed,
                          timeToCompleteLearning = p_timeToComplete,
                          cooldown = p_cooldown
        where id = researchId;
    else
        insert into research (playerid, path, whenResearchBegan, whenResearchComplete, 
        timeSpentLearning, researchComplete, timeToCompleteLearning, cooldown)
        values (p_playerid, p_path, p_began, p_whenCompleted, p_timeSpent, p_completed,
        p_timeToComplete, p_cooldown);
    end if;
END;
##
CREATE PROCEDURE `pruneResearchChoices` (p_playerid int)
BEGIN
    delete from researchChoiceItems
    where researchChoiceId in (select id from researchChoices where playerid = p_playerid);
    
    delete from researchChoices where playerid = p_playerid;
END;
##
CREATE FUNCTION `saveResearchChoice` (p_playerid int, p_name varchar(45))
RETURNS INTEGER
BEGIN
    declare choiceId int;
    
    insert into researchChoices (playerid, name) values (p_playerId, p_name);
    
    select id into choiceId
    from researchChoices
    where playerId = p_playerid and name = p_name;
    
RETURN choiceId;
END;
##
CREATE PROCEDURE `saveResearchChoiceOption` (p_choiceId int, p_selection varchar(5),
p_type varchar(15), p_name varchar(45), p_description varchar(256), p_key varchar(200))
BEGIN
    insert into researchChoiceItems 
    (researchChoiceId, selectionNumber, type, name, description, researchChoiceItems.key)
    values (p_choiceId, p_selection, p_type, p_name, p_description, p_key);
END;
##
CREATE PROCEDURE `saveOpenResearchTrees` (p_playerid int, p_path varchar(200))
BEGIN
    declare researchId int;
 
    select id into researchId
    from openResearchTrees where playerid = p_playerid and researchTree = p_path;
    
    if researchId is null then
        insert into openResearchTrees (playerId, researchTree)
        values (p_playerid, p_path);
    end if;
END;
##
CREATE PROCEDURE `saveSkills` (p_playerid int, p_name varchar(45), 
p_value int)
BEGIN
    declare skillId int;
 
    select id into skillId
    from skills where playerid = p_playerid and name = p_name;
    
    if skillId is not null then
        update skills set value = p_value
        where id = skillId;
    else
        insert into skills (playerid, name, value)
        values (p_playerid, p_name, p_value);
    end if;
END;
##
CREATE PROCEDURE `saveTraits` (p_playerid int, p_path varchar(200), 
p_name varchar(45), p_added int, p_end int, p_expire varchar(256),
p_trigger varchar(200))
BEGIN
    declare tid int;
 
    select id into tid
    from traits where playerid = p_playerid and path = p_path;
    
    if tid is not null then
        update traits set name = p_name,
                          added = p_added
        where id = tid;

        if p_end is not null and p_end <> 0 then 
            update timedtraits set endTime = p_end,
                              expireMessage = p_expire,
                              triggeringResearch = p_trigger
            where traitid = tid;
        end if;
    else
        insert into traits (playerid, path, name, added)
        values (p_playerid, p_path, p_name, p_added);

        if p_end is not null and p_end <> 0 then
            select id into tid
            from traits where playerid = p_playerid and path = p_path;

               insert into timedtraits (traitid, endTime, expireMessage, triggeringResearch)
            values (tid, p_end, p_expire, p_trigger);
        end if;
    end if;
END;
##
CREATE PROCEDURE `saveTemporaryTraits` (p_playerid int, p_traits varchar(512))
BEGIN
    declare playerId int;
 
    select id into playerId
    from temporaryTraits where playerid = p_playerid;
    
    if playerId is not null then
        update temporaryTraits set traitList = p_traits
        where id = playerId;
    else
        insert into temporaryTraits (playerid, traitList)
        values (p_playerid, p_traits);
    end if;
END;
##
CREATE PROCEDURE `pruneInventory` (p_playerid int)
BEGIN
    delete from inventory where playerid = p_playerid;
END;
##
CREATE PROCEDURE `saveInventoryItem` (p_playerid int,
p_filename varchar(200), p_data blob, p_equipped int)
BEGIN
    insert into inventory (playerid,filename,data,isEquipped) 
        values (p_playerid,p_filename,p_data,p_equipped);
END;
##
CREATE PROCEDURE `saveFaction` (p_playerid int, p_path varchar(200), 
p_disposition varchar(20), p_reputation int, p_lastInteraction int, 
p_lastReputation int, p_numInteractions int, p_dispositionTime int, p_isMember tinyint)
BEGIN
     declare factionId int;

    select id into factionId
    from factions where playerid = p_playerid and path = p_path;
    
    if factionId is not null then
        update factions set disposition = p_disposition,
                            reputation = p_reputation,
                            lastInteraction = p_lastInteraction,
                            lastReputation = p_lastReputation,
                            numberOfInteractions = p_numInteractions,
                            dispositionTime = p_dispositionTime,
                            isMember = p_isMember
        where id = factionId;
    else
        insert into factions (playerid, path, disposition, reputation, lastInteraction, lastReputation, numberOfInteractions, dispositionTime, isMember)
        values (p_playerid, p_path, p_disposition, p_reputation, p_lastInteraction, p_lastReputation, p_numInteractions, p_dispositionTime, p_isMember);
    end if;
END;
##
CREATE PROCEDURE `saveCombatStatistics` (p_playerName varchar(40),
p_key varchar(200), p_name varchar(40), p_level int)
BEGIN    
    declare lPlayerId int;
    declare statId int;
    declare timesPreviouslyKilled int;
    
    select id into lPlayerId
    from players where name = p_playerName;

    if(lPlayerId is not null) then
    
        select id, timesKilled into statId, timesPreviouslyKilled
        from combatStatistics
        where (playerid = lPlayerId) AND (foeKey = p_key);
        
        if(statId is not null) then
            update combatStatistics
            set timesKilled = timesPreviouslyKilled + 1
            where id = statId;
        else
            insert into combatStatistics
            (name, level, foeKey, timesKilled, playerId)
            values (p_name, p_level, p_key, 1, lPlayerId);           
        end if;
        
        update combatStatistics
        set isNemesis = 0, isBestKill = 0
        where playerid = lPlayerId;
        
        -- Stupid MySQL can handle this as an embedded query???
        select id into statId 
        from combatStatistics
        where playerId = lPlayerId
        order by timesKilled desc, level desc
        limit 1;

        update combatStatistics
        set isNemesis = 1
        where id = statId;
 
        select id into statId
        from combatStatistics
        where playerId = lPlayerId
        order by level desc, timesKilled desc
        limit 1;

        update combatStatistics
        set isBestKill = 1
        where id = statId;
                    
    end if;
END;
##
CREATE PROCEDURE `saveCombatStatisticsForRace` 
(p_playerName varchar(40), p_race varchar(20))
BEGIN    
    declare lPlayerId int;
    declare statId int;
    
    select id into lPlayerId
    from players where name = p_playerName;

    if(lPlayerId is not null) then
        select id into statId
        from combatStatisticsForRace
        where (playerid = lPlayerId) AND (race = p_race);
        
        if(statId is not null) then
            update combatStatisticsForRace
            set timesKilled = timesKilled + 1
            where id = statId;
        else
            insert into combatStatisticsForRace
            (playerid, race, timesKilled)
            values (lPlayerId, p_race, 1);           
        end if;
    end if;
END;
##
CREATE PROCEDURE `saveWizardLevel`(p_playerid int, p_level varchar(20))
BEGIN
    declare levelId int;
    declare wizardId int;
    
    select id into levelId
    from wizardTypes where type = p_level;
    
    if levelId is not null then
        select id into wizardId
        from wizards where playerId = p_playerId;
        
        if wizardId is not null then
            update wizards set typeId = levelId
            where id = wizardId;
        else
            insert into wizards (playerId, typeId) values (p_playerId, levelId);
        end if;
    end if;    
END;
##
CREATE PROCEDURE `saveOpinionOfCharacter`(p_playerName varchar(40),
p_targetKey varchar(200), p_opinion int, p_lastInteraction bigint)
BEGIN
    declare lplayerId int;
    declare opinionId int;

    select id into lplayerId
    from players where name = p_playerName;
    
    if lplayerId is not null then
        select id into opinionId
        from opinions where playerId = lplayerId and targetKey = p_targetKey;
        
        if opinionId is not null then
            update opinions set opinion = p_opinion,
                                lastInteraction = p_lastInteraction
            where id = opinionId;
        else
            insert into opinions (playerId, targetKey, opinion, lastInteraction) 
            values (lplayerId, p_targetKey, p_opinion, p_lastInteraction);
        end if;
    end if;    
END;
##
CREATE PROCEDURE `saveCharacterState`(p_playerName varchar(40),
p_targetKey varchar(200), p_state varchar(80))
BEGIN
    declare lplayerId int;
    declare stateId int;

    select id into lplayerId
    from players where name = p_playerName;
    
    if lplayerId is not null then
        select id into stateId
        from characterStates 
        where playerId = lplayerId and targetKey = p_targetKey;
        
        if stateId is not null then
            update characterStates set state = p_state
            where id = stateId;
        else
            insert into characterStates (playerId, targetKey, state) 
            values (lplayerId, p_targetKey, p_state);
        end if;
    end if;    
END;
##
CREATE PROCEDURE `updateLoginTime` (p_playerName varchar(40))
BEGIN
    update players set LastLogin = now() where name = p_playerName;
END;
##
CREATE PROCEDURE `saveSetting`(p_playerName varchar(40),
p_setting varchar(40), p_value varchar(20))
BEGIN
    declare lplayerId int;
    declare lSettingId int;

    select id into lplayerId
    from players where name = p_playerName;
    
    if lplayerId is not null then
        select id into lSettingId
        from settings 
        where playerId = lplayerId and setting = p_setting;
        
        if lSettingId is not null then
            update settings set value = p_value
            where id = lSettingId;
        else
            insert into settings (playerId, setting, value) 
            values (lplayerId, p_setting, p_value);
        end if;
    end if;    
END;
##
CREATE PROCEDURE `saveIssue`(p_id int, p_status int,
    p_loggedBy varchar(40), p_assignedTo varchar(40),
    p_affectedObject varchar(255), p_location varchar(255),
    p_data text)
BEGIN
    if p_id <> 0 then
        update issues set status = p_status,
                          assignedTo = p_assignedTo
        where id = p_id;
    else
        insert into issues (status, loggedBy, firstLoggedTime, affectedObject, 
            location, data)
        values(p_status, p_loggedBy, now(), p_affectedObject, p_location, p_data);
    end if;
END;
##
CREATE PROCEDURE `saveBlockedUser`(p_playerName varchar(40),
p_blockedPlayer varchar(40), actionType varchar(10))
BEGIN
    declare lplayerId int;
    declare lBlockedId int;
    declare lBlockId int;

    select id into lplayerId
    from players where name = p_playerName;
    
    select id into lBlockedId
    from players where name = p_blockedPlayer;

    if lplayerId is not null and lBlockedId is not null then
        select id into lBlockId
        from blockedUsers 
        where playerId = lplayerId and blockedPlayerId = lBlockedId;
        
        if lBlockId is null and actionType = 'block' then
            insert into blockedUsers (playerId, blockedPlayerId) 
            values (lplayerId, lBlockedId);
        elseif lBlockId is not null and actionType = 'unblock' then
            delete from blockedUsers where id = lBlockId;
        end if;
    end if;    
END;
##
CREATE FUNCTION `saveRegion` ( p_name varchar(256), p_type varchar(45), 
    p_x int, p_y int, p_entryPoint varchar(256), p_direction varchar(20)) RETURNS int(11)
BEGIN
    declare regionId int;

    select id into regionId
    from regions where entryPoint = p_entryPoint and entryDirection = p_direction;
    
    if regionId is not null then
        update regions set name = p_name,
                           type = p_type,
                           `x-dimension` = p_x,
                           `y-dimension` = p_y
        where id = regionId;
    else
        insert into regions (name, type, `x-dimension`, `y-dimension`, entryPoint, entryDirection)
        values (p_name, p_type, p_x, p_y, p_entryPoint, p_direction);

        select id into regionId
        from regions where entryPoint = p_entryPoint and entryDirection = p_direction;
    end if;
RETURN regionId;
END;
##
CREATE FUNCTION `saveEnvironmentInstance` ( p_regionId int, p_x int, p_y int, 
    p_type varchar(40), p_identifier varchar(256), p_name varchar(128), p_cloned binary, 
    p_description longtext, p_shop varchar(256), p_state varchar(80)) RETURNS int(11)
BEGIN
    declare lEnvironmentId int;
    declare childId int;

    select id into lEnvironmentId
    from environmentInstances where regionId = p_regionId and identifier = p_identifier;
    
    if lEnvironmentId is not null then
        update environmentInstances set name = p_name,
                           type = p_type,
                           isCloned = p_cloned,
                           `x-coordinate` = p_x,
                           `y-coordinate` = p_y
        where id = lEnvironmentId;
    else
        insert into environmentInstances (regionId, `x-coordinate`, `y-coordinate`, type,
            identifier, name, isCloned)
        values (p_regionId, p_x, p_y, p_type, p_identifier, p_name, p_cloned);

        select id into lEnvironmentId
        from environmentInstances where regionId = p_regionId and identifier = p_identifier;
    end if;

    if p_description <> '' then
        select id into childId
        from environmentDescriptions 
        where environmentId = lEnvironmentId and state = p_state;

        if childId is not null then
            update environmentDescriptions set description = p_description
            where id = childId;
        else
            insert into environmentDescriptions (environmentId, state, description)
            values(lEnvironmentId, p_state, p_description);
        end if;
    end if;

    if p_shop <> '' then
        select id into childId from environmentShops where environmentId = lEnvironmentId;

        if childId is not null then
            update environmentShops set shop = p_shop
            where id = childId;
        else
            insert into environmentShops (environmentId, shop)
            values(lEnvironmentId, p_shop);
        end if;
    end if;
RETURN lEnvironmentId;
END;
##
CREATE PROCEDURE `saveEnvironmentExit` ( p_environmentId int, p_direction varchar(20), 
    p_location varchar(256))
BEGIN
    declare exitId int;

    select id into exitId
    from environmentExits where environmentId = p_environmentId and direction = p_direction;
    
    if exitId is not null then
        update environmentExits set direction = p_direction,
                                    location = p_location
        where id = exitId;
    else
        insert into environmentExits (environmentId, location, direction)
        values (p_environmentId, p_location, p_direction);
    end if;
END;
##
CREATE PROCEDURE `saveRegionExit` ( p_regionId int, p_environmentId int, p_direction varchar(20), 
    p_location varchar(256), p_state varchar(80), p_x int, p_y int)
BEGIN
    declare exitId int;

    select id into exitId
    from regionExits where regionId = p_regionId and
        environmentId = p_environmentId and direction = p_direction;
    
    if exitId is not null then
        update regionExits set location = p_location, 
                               state = p_state,
                               `x-coordinate` = p_x,
                               `y-coordinate` = p_y
        where id = exitId;
    else
        insert into regionExits (regionId, environmentId, location, direction, state, 
            `x-coordinate`, `y-coordinate`)
        values (p_regionId, p_environmentId, p_location, p_direction, p_state, p_x, p_y);
    end if;
END;
##
CREATE PROCEDURE `saveRegionMapDecorators` ( p_regionId int, p_class varchar(20), 
    p_type varchar(20), p_size varchar(20), p_color varchar(20), p_x int, p_y int)
BEGIN
    declare decoratorId int;

    select id into decoratorId
    from regionMapDecorators where regionId = p_regionId and
        `x-coordinate` = p_x and `y-coordinate` = p_y;
    
    if decoratorId is not null then
        update regionMapDecorators set class = p_location, 
                                       type = p_state,
                                       size = p_size,
                                       color = p_color
        where id = decoratorId;
    else
        insert into regionMapDecorators (regionId, class, type, size, color, 
            `x-coordinate`, `y-coordinate`)
        values (p_regionId, p_class, p_type, p_size, p_color, p_x, p_y);
    end if;
END;
##
CREATE FUNCTION `saveEnvironmentalElement` ( p_environmentId int, p_type varchar(45),
    p_value varchar(256), p_state varchar(80), p_location varchar(40), p_x int, 
    p_y int, p_z int, p_x_rot int, p_y_rot int, p_z_rot int) RETURNS int(11)
BEGIN
    declare elementId int;

    select id into elementId from environmentalElements 
    where environmentId = p_environmentId and value = p_value and location = p_location;
    
    if elementId is not null then
        update environmentalElements set type = p_type,
                                         state = p_state,
                                         `x-coordinate` = p_x,
                                         `y-coordinate` = p_y,
                                         `z-coordinate` = p_z,
                                         `x-rotation` = p_x_rot,
                                         `y-rotation` = p_y_rot,
                                         `z-rotation` = p_z_rot
        where id = elementId;
    else
        insert into environmentalElements (environmentId, type, value, state, location,
            `x-coordinate`, `y-coordinate`, `z-coordinate`, `x-rotation`, `y-rotation`,
            `z-rotation`)
        values (p_environmentId, p_type, p_value, p_state, p_location, p_x, p_y, p_z,
            p_x_rot, p_y_rot, p_z_rot);

        select id into elementId from environmentalElements 
        where environmentId = p_environmentId and value = p_value and location = p_location;
    end if;
RETURN elementId;
END;
##
CREATE FUNCTION `saveEnvironmentalObject` ( p_environmentId int, p_state varchar(80),
    p_path varchar(256), p_random binary, p_probability tinyint, p_quantity tinyint,
    p_type varchar(10)) 
    RETURNS int(11)
BEGIN
    declare elementId int;

    select id into elementId from environmentalObjects 
    where environmentId = p_environmentId and path = p_path;
    
    if elementId is not null then
        update environmentalObjects set state = p_state,
                                        isRandom = p_random,
                                        probability = p_probability,
                                        quantity = p_quantity
        where id = elementId;
    else
        insert into environmentalObjects (environmentId, state, path, isRandom, 
            probability, quantity, type)
        values (p_environmentId, p_state, p_path, p_random, p_probability, 
            p_quantity, p_type);

        select id into elementId from environmentalObjects 
        where environmentId = p_environmentId and path = p_path;
    end if;
RETURN elementId;
END;
##
CREATE FUNCTION `authenticateUser` (p_user varchar(40), p_password varchar(80))
    returns varchar(40)
BEGIN
    declare ret varchar(20);
    declare userId int;
    declare hashedPassword varchar(20);
    declare storedPassword varchar(20);

    select id into userId from users
    where login = p_user;

    if userId is not null then
        select password into storedPassword from users
		where login = p_user;

        select cast((select encrypt(p_password, storedPassword)) as char) into hashedPassword;
        if hashedPassword = storedPassword then
            set ret = 'authenticated';
        else
            set ret = 'failed';
        end if;
    else
        set ret = 'no user';
    end if;
RETURN ret;
END;
##
CREATE PROCEDURE `createUser`(p_user varchar(40), p_password varchar(80),
    p_address varchar(15))
BEGIN
    declare userId int;

    select id into userId from users
    where login = p_user;
    
    if userId is null then
        insert into users (login, password, lastIPAddress, LastLogin)
        values (p_user, cast(encrypt(p_password) as char), p_address, now());
    end if;    
END;
##