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
drop function if exists demoteWizardToPlayer;
##
drop function if exists saveParty;
##
drop function if exists setWizardLevel;
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
drop function if exists createRole;
##
drop procedure if exists removeCompositeResearchElement;
##
drop procedure if exists saveCompositeResearchElement;
##
drop procedure if exists saveCompositeResearch;
##
drop procedure if exists saveRoles;
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
drop procedure if exists savePartyMember;
##
drop procedure if exists deleteParty;
##
drop procedure if exists saveNPCData;
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
drop procedure if exists saveSustainedEffect;
##
drop procedure if exists deleteSustainedEffect;
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
drop procedure if exists removeResearch;
##
drop procedure if exists removeTraits;
##
drop procedure if exists removeDomainUnits;
##
drop procedure if exists removeDomainHenchmen;
##
drop procedure if exists removeDomainComponents;
##
drop procedure if exists removeDomainSection;
##
drop procedure if exists removeDomains;
##
drop procedure if exists removePlayer;
##
drop function if exists saveUser;
##
drop function if exists saveBasicPlayerInformation;
##
drop function if exists saveResearchChoice;
##
drop table if exists compositeResearchElements;
##
drop table if exists compositeResearch;
##
drop table if exists playerRoles;
##
drop table if exists roles;
##
drop table if exists roleTypes;
##
drop table if exists partyMembers;
##
drop table if exists parties;
##
drop table if exists npcs;
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
drop table if exists sustainedEffects;
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
drop table if exists versionInfo;
##
