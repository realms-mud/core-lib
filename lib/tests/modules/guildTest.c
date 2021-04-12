//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object User;
object Guild;

/////////////////////////////////////////////////////////////////////////////
int AdvanceToLevel(int level, string guild)
{
    int runningLevel = User->guildLevel(guild);
    while((User->guildLevel(guild) < level) && User->memberOfGuild(guild))
    {
        User->addExperience(1000 * runningLevel);
        User->advanceLevel(guild);
        runningLevel = User->guildLevel(guild);
    }
    return runningLevel;
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    destruct(load_object("/lib/tests/support/guilds/testGuild.c"));
    destruct(load_object("/lib/tests/support/guilds/nonCombatGuild.c"));
    object dict = load_object("/lib/dictionaries/guildsDictionary.c");
    dict->resetCache();

    Guild = load_object("/lib/tests/support/guilds/testGuild.c");
    load_object("/lib/dictionaries/environmentDictionary.c");

    ignoreList += ({ "AdvanceToLevel" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User->Name("Bob");
    User->Str(20);
    User->Dex(20);
    User->Con(20);
    User->Int(20);
    User->Wis(20);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
}

/////////////////////////////////////////////////////////////////////////////
void MemberOfGuildReturnsFalseWhenNotMemberOfGuild()
{
    ExpectFalse(User->memberOfGuild("test"));
}

/////////////////////////////////////////////////////////////////////////////
void MemberOfGuildReturnsTrueWhenIfUserJoinedGuild()
{
    ExpectTrue(User->joinGuild("test"));
    ExpectTrue(User->memberOfGuild("test"));
}

/////////////////////////////////////////////////////////////////////////////
void JoinGuildAddsAdvancementSelector()
{
    ExpectTrue(User->joinGuild("test"));
    ExpectTrue(present_clone("/lib/modules/guilds/advanceLevelSelector.c", User));
    command("3", User);
    ExpectFalse(present_clone("/lib/modules/guilds/advanceLevelSelector.c", User));
}

/////////////////////////////////////////////////////////////////////////////
void JoinGuildFiresOnJoinGuildOnSuccess()
{
    ToggleCallOutBypass();
    User->registerEvent(clone_object("/lib/tests/support/guilds/guildEventsSubscriber"));
    User->joinGuild("test");
    string err = catch (command("3", User));
    string expectedError = "*event handler: onJoinGuild called";

    ExpectEq(expectedError, err, "The correct exception is thrown");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void JoinGuildAppliesGuildCriteriaForLevelOne()
{
    ExpectEq(150, User->maxHitPoints(), "maxHitPoints is 150 before joining");
    ExpectEq(0, User->AvailableSkillPoints(), "no skill points available before joining");
    ExpectEq(0, User->researchPoints(), "no research points available before joining");
    ExpectTrue(User->joinGuild("test"));
    ExpectEq(155, User->maxHitPoints(), "maxHitPoints is 155 after joining");
    ExpectEq(5, User->AvailableSkillPoints(), "skill points available after joining");
    ExpectEq(1, User->researchPoints(), "research points available after joining");
}

/////////////////////////////////////////////////////////////////////////////
void EffectiveLevelReturnsOneIfNotInAnyGuild()
{
    ExpectEq(1, User->effectiveLevel());
}

/////////////////////////////////////////////////////////////////////////////
void EffectiveLevelReturnsLevelOfAllJoinedGuilds()
{
    ExpectTrue(User->joinGuild("test"));
    ExpectEq(1, User->effectiveLevel());

    object guild = load_object("/lib/tests/support/guilds/mageGuild.c");
    ExpectTrue(User->joinGuild("fake mage"));
    ExpectEq(2, User->effectiveLevel());
}

/////////////////////////////////////////////////////////////////////////////
void MemberOfGuildsReturnsEmptyListWhenNotInAnyGuilds()
{
    ExpectEq(({}), User->memberOfGuilds());
}

/////////////////////////////////////////////////////////////////////////////
void MemberOfGuildsReturnsListOfJoinedGuilds()
{
    ExpectTrue(User->joinGuild("test"), "Joined test guild");
    ExpectEq(({ "test"}), User->memberOfGuilds(), "list when member of test guild");

    object guild = load_object("/lib/tests/support/guilds/mageGuild.c");

    ExpectTrue(User->joinGuild("fake mage"), "Joined mage guild");
    ExpectEq(({ "test", "fake mage" }), User->memberOfGuilds(), "list when member of test and mage guild");
}

/////////////////////////////////////////////////////////////////////////////
void GuildLevelReturnsZeroWhenNotAMemberOfGuild()
{
    ExpectEq(0, User->guildLevel("test"));
}

/////////////////////////////////////////////////////////////////////////////
void GuildLevelReturnsOneWhenGuildJoined()
{
    ExpectTrue(User->joinGuild("test"), "Joined test guild");
    ExpectEq(1, User->guildLevel("test"), "Guild level");
}

/////////////////////////////////////////////////////////////////////////////
void AddExperienceCorrectlyHandlesOneGuild()
{
    ExpectTrue(User->joinGuild("test"));
    ExpectEq(0, User->guildExperience("test"), "initial test guild experience");
    ExpectEq(1000, User->experienceToNextLevel("test"), "initial experience to next level");
    ExpectTrue(User->addExperience(100), "Experience added");
    ExpectEq(100, User->guildExperience("test"), "test guild experience after experience added");
    ExpectEq(900, User->experienceToNextLevel("test"), "test guild experience to next level");
}

/////////////////////////////////////////////////////////////////////////////
void AddExperienceCapsExperienceToTwiceTheCostForNextLevel()
{
    ExpectTrue(User->joinGuild("test"));
    ExpectEq(0, User->guildExperience("test"), "initial test guild experience");
    ExpectEq(1000, User->experienceToNextLevel("test"), "initial experience to next level");
    ExpectTrue(User->addExperience(30000), "Experience added");
    ExpectEq(2000, User->guildExperience("test"), "test guild experience after experience added");

    ExpectTrue(User->addExperience(30000), "more Experience added");
    ExpectEq(2000, User->guildExperience("test"), "test guild experience does not increase");
}

/////////////////////////////////////////////////////////////////////////////
void ExperienceToNextLevelDoesNotReturnZeroIfGuildUnknown()
{
    ExpectTrue(User->experienceToNextLevel("test"), "initial experience to next level");
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceLevelAdvancesLevelAndAppliesGuildCriteria()
{
    ExpectTrue(User->joinGuild("test"));
    ExpectTrue(User->addExperience(1000), "experience added");
    ExpectEq(0, User->attributePoints(), "no attribute points available before advancing");
    ExpectEq(0, User->getSkill("long sword"), "no long sword skill before advancing");
    ExpectFalse(User->isResearched("/lib/tests/support/research/testGrantedResearchItem.c"), "test research not researched");
    ExpectTrue(User->advanceLevel("test"), "level advanced");
    ExpectEq(2, User->guildLevel("test"), "guild level is 2");
    ExpectEq(160, User->maxHitPoints(), "maxHitPoints is 160 after advancing");
    ExpectEq(10, User->AvailableSkillPoints(), "skill points available after advancing");
    ExpectEq(1, User->attributePoints(), "attribute points available after advancing");
    ExpectEq(2, User->researchPoints(), "research points available after advancing");
    ExpectTrue(User->isResearched("/lib/tests/support/research/testGrantedResearchItem.c"), "test research is researched");
    
    ExpectEq(1, User->getSkill("long sword"), "long sword skill after advancing");
}

/////////////////////////////////////////////////////////////////////////////
void AddExperienceCorrectlyHandlesMultipleGuilds()
{
    ExpectTrue(User->joinGuild("test"));
    ExpectTrue(User->addExperience(1000), "experience added");
    ExpectTrue(User->advanceLevel("test"), "level advanced");
    ExpectTrue(User->joinGuild("fake mage"));

    ExpectEq(0, User->guildExperience("test"), "initial test guild experience");
    ExpectEq(0, User->guildExperience("fake mage"), "initial mage guild experience");

    ExpectTrue(User->addExperience(300), "experience added");
    ExpectEq(200, User->guildExperience("test"), "new test guild experience");
    ExpectEq(100, User->guildExperience("fake mage"), "new mage guild experience");
}

/////////////////////////////////////////////////////////////////////////////
void AddExperienceToSpecificGuildCorrectlyHandled()
{
    ExpectTrue(User->joinGuild("test"));
    ExpectTrue(User->addExperience(1000), "experience added");
    ExpectTrue(User->advanceLevel("test"), "level advanced");
    ExpectTrue(User->joinGuild("fake mage"));

    ExpectEq(0, User->guildExperience("test"), "initial test guild experience");
    ExpectEq(0, User->guildExperience("fake mage"), "initial mage guild experience");

    ExpectTrue(User->addExperience(300, "fake mage"), "experience added");
    ExpectEq(0, User->guildExperience("test"), "new test guild experience");
    ExpectEq(300, User->guildExperience("fake mage"), "new mage guild experience");
}

/////////////////////////////////////////////////////////////////////////////
void AddExperienceToCombatGuildsDoesNotAddToNonCombatGuilds()
{
    ExpectTrue(User->joinGuild("fake smith"));
    ExpectTrue(User->addExperience(1000, "fake smith"), "experience added");
    ExpectTrue(User->advanceLevel("fake smith"), "level advanced");
    ExpectTrue(User->joinGuild("fake mage"));

    ExpectEq(0, User->guildExperience("fake smith"), "initial test guild experience");
    ExpectEq(0, User->guildExperience("fake mage"), "initial mage guild experience");

    ExpectTrue(User->addExperience(300), "experience added");
    ExpectEq(0, User->guildExperience("fake smith"), "new test guild experience");
    ExpectEq(300, User->guildExperience("fake mage"), "new mage guild experience");
}

/////////////////////////////////////////////////////////////////////////////
void GuildRankIsCorrectlyApplied()
{
    ExpectEq(0, User->guildRank("test"));
    ExpectTrue(User->joinGuild("test"));
    ExpectEq("neophyte", User->guildRank("test"), "default guild rank is set");
}

/////////////////////////////////////////////////////////////////////////////
void GuildRankNameIsCorrectlyReturned()
{
    ExpectEq(0, User->guildRankName("test"));
    ExpectTrue(User->joinGuild("test"));
    ExpectEq("neophyte", User->guildRankName("test"), "the guild rank name is correct");
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceLevelFiresOnAdvancedLevelOnSuccess()
{
    ToggleCallOutBypass();
    User->joinGuild("test");
    command("3", User);
    User->addExperience(1000);

    User->registerEvent(clone_object("/lib/tests/support/guilds/guildEventsSubscriber"));
    command("level up", User);
    string err = catch (command("2", User));
    string expectedError = "*event handler: onAdvancedLevel called";

    ExpectEq(expectedError, err, "The correct exception is thrown");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceRankAppliesNewRank()
{
    setUsers(({ User }));
    User->heart_beat();
    ExpectEq(0, User->guildRank("test"));
    ExpectTrue(User->joinGuild("test"));
    ExpectEq("neophyte", User->guildRank("test"), "default guild rank is set");

    ExpectEq(2, User->ageWhenRankAdvanced("test"));
    ExpectFalse(User->isResearched("/lib/tests/support/research/testGrantedResearchItem.c"), "test research not researched");
    User->heart_beat();

    ExpectTrue(User->advanceRank("test"), "guild rank advanced");
    ExpectEq("acolyte", User->guildRank("test"), "guild rank is set");
    ExpectTrue(User->isResearched("/lib/tests/support/research/testGrantedResearchItem.c"), "test research is researched");
    ExpectEq(4, User->ageWhenRankAdvanced("test"));
}

/////////////////////////////////////////////////////////////////////////////
void AdvanceRankFiresOnAdvancedRankOnSuccess()
{
    ToggleCallOutBypass();
    User->joinGuild("test");
    User->registerEvent(clone_object("/lib/tests/support/guilds/guildEventsSubscriber"));
    string err = catch (User->advanceRank("test"));
    string expectedError = "*event handler: onAdvancedRank called";

    ExpectEq(expectedError, err, "The correct exception is thrown");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void CannotAdvanceRankIfTimeoutNotExpired()
{
    ExpectEq(0, User->guildRank("test"));
    ExpectTrue(User->joinGuild("test"));
    ExpectTrue(User->advanceRank("test"), "guild rank advanced");
    ExpectFalse(User->advanceRank("test"), "second guild rank is not advanced");
}

/////////////////////////////////////////////////////////////////////////////
void CanAdvanceRankIfTimeoutExpired()
{
    ExpectEq(0, User->guildRank("test"));
    ExpectTrue(User->joinGuild("test"));
    ExpectTrue(User->advanceRank("test"), "guild rank advanced");

    ExpectFalse(User->advanceRank("test"), "second guild rank not advanced");
    User->agePlayer(4000);
    ExpectTrue(User->advanceRank("test"), "second guild rank advanced");
}

/////////////////////////////////////////////////////////////////////////////
void CanDemoteRank()
{
    ExpectEq(0, User->guildRank("test"));
    ExpectTrue(User->joinGuild("test"));
    ExpectEq("neophyte", User->guildRank("test"), "default guild rank is set");
    ExpectTrue(User->advanceRank("test"), "guild rank advanced");
    ExpectEq("acolyte", User->guildRank("test"), "guild rank is set");

    ExpectTrue(User->demoteRank("test"), "guild rank demoted");
    ExpectEq("neophyte", User->guildRank("test"), "default guild rank is set");
}

/////////////////////////////////////////////////////////////////////////////
void DemoteRankFiresOnDemotedRankOnSuccess()
{
    ToggleCallOutBypass();
    User->joinGuild("test");
    ExpectTrue(User->advanceRank("test"), "guild rank advanced");

    User->registerEvent(clone_object("/lib/tests/support/guilds/guildEventsSubscriber"));
    string err = catch (User->demoteRank("test"));
    string expectedError = "*event handler: onDemotedRank called";

    ExpectEq(expectedError, err, "The correct exception is thrown");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void CannotLeaveGuildIfNotMember()
{
    ExpectFalse(User->leaveGuild("test"));
}

/////////////////////////////////////////////////////////////////////////////
void CanLeaveGuildIfMember()
{
    User->joinGuild("test");
    ExpectTrue(User->leaveGuild("test"));
}

/////////////////////////////////////////////////////////////////////////////
void CanLeaveGuildFailsIfLeavingIsProhibited()
{
    User->joinGuild("test");
    Guild->testProhibitLeavingGuild();
    ExpectFalse(User->leaveGuild("test"));
    Guild->resetProhibitions();
}

/////////////////////////////////////////////////////////////////////////////
void LeaveGuildFiresOnLeaveGuildOnSuccess()
{
    ToggleCallOutBypass();
    User->joinGuild("test");

    User->registerEvent(clone_object("/lib/tests/support/guilds/guildEventsSubscriber"));
    string err = catch (User->leaveGuild("test"));
    string expectedError = "*event handler: onLeaveGuild called";

    ExpectEq(expectedError, err, "The correct exception is thrown");
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void LeavingGuildChangesFormerMemberToAnathema()
{
    User->joinGuild("test");
    User->agePlayer(100000);
    ExpectFalse(User->isAnathema("test"), "user is not anathema before leaving the guild");
    ExpectTrue(User->leaveGuild("test"), "user leaves the guild");
    ExpectTrue(User->isAnathema("test"), "user is anathema after leaving the guild");
}

/////////////////////////////////////////////////////////////////////////////
void CanLeaveGuildFailsIfMemberIsAnathema()
{
    User->joinGuild("test");
    ExpectTrue(User->leaveGuild("test"));
    User->joinGuild("test");
    ExpectFalse(User->leaveGuild("test"));
}

/////////////////////////////////////////////////////////////////////////////
void CannotReJoinGuildsThatHaveDoNotAllowReJoinOfGuildSet()
{
    object guild = load_object("/guilds/background/background.c");

    ExpectTrue(User->joinGuild("background"));
    ExpectTrue(User->leaveGuild("background"));
    User->agePlayer(10000000);
    ExpectFalse(User->joinGuild("background"));
}

/////////////////////////////////////////////////////////////////////////////
void LeavingGuildDoesNotRemoveLearnedGuildSkills()
{
    ExpectEq(150, User->maxHitPoints(), "maxHitPoints is 150 when not a member of the guild");
    User->joinGuild("test");
    ExpectTrue(User->addExperience(1000), "experience added");
    ExpectEq(0, User->getSkill("long sword"), "no long sword skill before advancing");
    ExpectFalse(User->isResearched("/lib/tests/support/research/testGrantedResearchItem.c"), "test research not researched");
    ExpectTrue(User->advanceLevel("test"), "level advanced");
    ExpectEq(2, User->guildLevel("test"), "guild level is 2");
    ExpectEq(160, User->maxHitPoints(), "maxHitPoints is 160 after advancing");
    ExpectTrue(User->isResearched("/lib/tests/support/research/testGrantedResearchItem.c"), "test research is researched");
    ExpectEq(1, User->getSkill("long sword"), "long sword skill after advancing");

    ExpectTrue(User->leaveGuild("test"), "user leaves the guild");
    ExpectEq(0, User->guildLevel("test"), "guild level is now 0");
    ExpectEq(160, User->maxHitPoints(), "maxHitPoints is unchanged after leaving");
    ExpectTrue(User->isResearched("/lib/tests/support/research/testGrantedResearchItem.c"), "test research is still researched");
    ExpectEq(1, User->getSkill("long sword"), "long sword skill is still 6");
}

/////////////////////////////////////////////////////////////////////////////
void GuildsBonusToAppliesBonusSkill()
{
    User->joinGuild("test");
    ExpectTrue(User->addExperience(1000), "experience added");
    ExpectEq(0, User->guildsBonusTo("long sword"), "no long sword skill before advancing");
    ExpectTrue(User->advanceLevel("test"), "level advanced");
    ExpectEq(1, User->guildsBonusTo("long sword"), "long sword skill after advancing");
}

/////////////////////////////////////////////////////////////////////////////
void GuildsBonusToAppliesIncreaseToStats()
{
    ExpectEq(0, User->guildsBonusTo("MaxHitPoints"), "no bonus before joining");
    User->joinGuild("test");
    ExpectTrue(User->addExperience(1000), "experience added");
    ExpectEq(5, User->guildsBonusTo("MaxHitPoints"), "correct bonus at level 1");
    ExpectTrue(User->advanceLevel("test"), "level advanced");
    ExpectEq(10, User->guildsBonusTo("MaxHitPoints"), "correct bonus at level 2");
}

/////////////////////////////////////////////////////////////////////////////
void GuildsResearchTreesCorrectlyAppliesResearchTrees()
{
    User->addSkillPoints(100);
    User->advanceSkill("long sword", 10);
    ExpectEq("", User->availableResearchTrees(), "no trees before joining");
    User->joinGuild("test");
    AdvanceToLevel(4, "test");
    ExpectEq("", User->availableResearchTrees(), "still no trees before level 5");
    AdvanceToLevel(5, "test");
    ExpectEq(({ "/lib/tests/support/guilds/testGuildResearchTree.c" }), User->availableResearchTrees(), "correct trees after advancing to level 5");
}

/////////////////////////////////////////////////////////////////////////////
void CanResearchItemsInGuildResearchTree()
{
    User->addSkillPoints(100);
    User->advanceSkill("long sword", 10);
    ExpectFalse(User->initiateResearch("/lib/tests/support/guilds/testGuildItem.c"), "cannot initiate research when not in guild");
    User->joinGuild("test");
    ExpectFalse(User->initiateResearch("/lib/tests/support/guilds/testGuildItem.c"), "cannot initiate research when tree not available");
    AdvanceToLevel(5, "test");
    ExpectTrue(User->initiateResearch("/lib/tests/support/guilds/testGuildItem.c"), "can research when tree is available");
}

/////////////////////////////////////////////////////////////////////////////
void CannotResearchItemsInGuildResearchTreeAfterLeavingGuild()
{
    User->addSkillPoints(100);
    User->advanceSkill("long sword", 10);
    User->joinGuild("test");
    AdvanceToLevel(5, "test");
    User->leaveGuild("test");
    ExpectTrue(User->isResearched("/lib/tests/support/guilds/testGuildTreeRoot.c"), "tree root has been researched");
    ExpectFalse(User->initiateResearch("/lib/tests/support/guilds/testGuildItem.c"), "cannot research item from tree");
}

/////////////////////////////////////////////////////////////////////////////
void GuildsExtraAttacksCorrectlyAppliesBonusAttacks()
{
    User->addSkillPoints(100);
    User->advanceSkill("long sword", 10);
    ExpectEq("", User->guildsExtraAttacks(), "no attacks before joining");
    User->joinGuild("test");
    AdvanceToLevel(10, "test");
    ExpectEq(({ (["attack type":"weapon"]) }), User->guildsExtraAttacks(), "one attack at level 10");
    AdvanceToLevel(20, "test");
    ExpectEq(({ (["attack type":"weapon"]),(["attack type":"weapon"]) }), User->guildsExtraAttacks(), "second attack at level 20");
}

/////////////////////////////////////////////////////////////////////////////
void GuildsExtraAttacksStillAPpliedAfterLeavingGuild()
{
    User->addSkillPoints(100);
    User->advanceSkill("long sword", 10);
    ExpectEq("", User->guildsExtraAttacks(), "no attacks before joining");
    User->joinGuild("test");
    AdvanceToLevel(10, "test");
    ExpectEq(({ (["attack type":"weapon"]) }), User->guildsExtraAttacks(), "one extra attack at level 10");
    User->leaveGuild("test");
    ExpectEq(({ (["attack type":"weapon"]) }), User->guildsExtraAttacks(), "still one attack after leaving guild");
}

/////////////////////////////////////////////////////////////////////////////
void JoiningGuildAppliesGuildCostForSkills()
{
    ExpectEq(2, User->costToAdvanceSkill("combat"), "unguilded cost for combat skills");
    ExpectEq(2, User->costToAdvanceSkill("magic"), "unguilded cost for magic skills");
    ExpectEq(2, User->costToAdvanceSkill("general"), "unguilded cost for general skills");

    User->joinGuild("test");
    ExpectEq(1, User->costToAdvanceSkill("combat"), "test guild cost for combat skills");
    ExpectEq(2, User->costToAdvanceSkill("magic"), "test guild cost for magic skills");
    ExpectEq(1, User->costToAdvanceSkill("general"), "test guild cost for general skills");

    User->joinGuild("fake mage");
    ExpectEq(1, User->costToAdvanceSkill("combat"), "both guild cost for combat skills");
    ExpectEq(1, User->costToAdvanceSkill("magic"), "both guild cost for magic skills");
    ExpectEq(1, User->costToAdvanceSkill("general"), "both guild cost for general skills");

    User->leaveGuild("test");
    ExpectEq(2, User->costToAdvanceSkill("combat"), "mage guild cost for combat skills");
    ExpectEq(1, User->costToAdvanceSkill("magic"), "mage guild cost for magic skills");
    ExpectEq(1, User->costToAdvanceSkill("general"), "mage guild cost for general skills");
}

/////////////////////////////////////////////////////////////////////////////
void CannotJoinIfMemberOfProhibitedGuild()
{
    Guild->testProhibitedGuildCombinations(({ "fake mage" }));
    User->joinGuild("fake mage");
    ExpectFalse(User->joinGuild("test"));
}

/////////////////////////////////////////////////////////////////////////////
void ProhibitedGuildCheckAlsoChecksCurrentGuildsForMembership()
{
    Guild->testProhibitedGuildCombinations(({ "fake mage" }));
    User->joinGuild("test");
    ExpectFalse(User->joinGuild("fake mage"));
}

/////////////////////////////////////////////////////////////////////////////
void CannotJoinNonexistantGuild()
{
    ExpectFalse(User->joinGuild("weaselhookens"));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeAffectedByArmorType()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blah");
    armor->set("material", "galvorn");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);
    move_object(armor, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("armor type", ({ "chainmail" })));
    User->joinGuild("test");
    ExpectFalse(armor->equip("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeAllowsArmorTypeIfNotBlocked()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blah");
    armor->set("material", "galvorn");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);
    move_object(armor, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("armor type", ({ "plate armor" })));
    User->joinGuild("test");
    ExpectTrue(armor->equip("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeAllowsArmorTypeIfAnyJoinedGuildDoes()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blah");
    armor->set("material", "galvorn");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);
    move_object(armor, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("armor type", ({ "chainmail" })));
    User->joinGuild("test");

    object guild = load_object("/lib/tests/support/guilds/fighterGuild.c");
    guild->init();
    User->joinGuild("fake fighter");
    ExpectTrue(armor->equip("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeAffectedByArmorLocation()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blah");
    armor->set("material", "galvorn");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor | LegGreaves);
    move_object(armor, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("armor location", ({ "leg greaves" })));
    User->joinGuild("test");
    ExpectFalse(armor->equip("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeAllowsArmorLocationNotOfBlockedLocation()
{
    Guild->resetProhibitions();
    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blah");
    armor->set("material", "galvorn");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);
    move_object(armor, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("armor location", ({ "leg greaves" })));
    User->joinGuild("test");
    ExpectTrue(armor->equip("blah"));
    Guild->resetProhibitions();
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeAllowsArmorLocationIfAnyJoinedGuildDoes()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("name", "blah");
    armor->set("material", "galvorn");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor | LegGreaves);
    move_object(armor, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("armor location", ({ "leg greaves" })));
    User->joinGuild("test");

    object guild = load_object("/lib/tests/support/guilds/fighterGuild.c");
    User->joinGuild("fake fighter");
    ExpectTrue(armor->equip("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeAffectedByWeaponType()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("weapon type", ({ "long sword" })));
    User->joinGuild("test");
    ExpectFalse(weapon->equip("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeDoesNotBlockWeaponsNotOfTypeSpecified()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "axe");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("weapon type", ({ "long sword" })));
    User->joinGuild("test");
    ExpectTrue(weapon->equip("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeAllowsWeaponTypeIfAnyJoinedGuildDoes()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("weapon type", ({ "long sword" })));
    User->joinGuild("test");

    object guild = load_object("/lib/tests/support/guilds/fighterGuild.c");
    User->joinGuild("fake fighter");
    ExpectTrue(weapon->equip("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeAffectedByDamageType()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("damage type", ({ "slash" })));
    User->joinGuild("test");
    ExpectFalse(weapon->equip("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypentDoesNotBlockDamageNotOfTypeSpecified()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "axe");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("damage type", ({ "thrust" })));
    User->joinGuild("test");
    ExpectTrue(weapon->equip("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeDoesNotAllowDamageTypeEvenIfAnyJoinedGuildDoes()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("damage type", ({ "slash" })));
    User->joinGuild("test");

    object guild = load_object("/lib/tests/support/guilds/fighterGuild.c");
    User->joinGuild("fake fighter");
    ExpectFalse(weapon->equip("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeAffectedByMaterialType()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("material type", ({ "metal" })));
    User->joinGuild("test");
    ExpectFalse(weapon->equip("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypentDoesNotBlockMaterialNotOfTypeSpecified()
{
    Guild->resetProhibitions();
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "axe");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("material type", ({ "crystal" })));
    User->joinGuild("test");
    ExpectTrue(weapon->equip("blah"));
    Guild->resetProhibitions();
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeDoesNotAllowMaterialTypeEvenIfAnyJoinedGuildDoes()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("material type", ({ "metal" })));
    User->joinGuild("test");

    object guild = load_object("/lib/tests/support/guilds/fighterGuild.c");
    User->joinGuild("fake fighter");
    ExpectFalse(weapon->equip("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeAffectedByMaterial()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("material", ({ "galvorn" })));
    User->joinGuild("test");
    ExpectFalse(weapon->equip("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypentDoesNotBlockMaterialNotSpecified()
{
    Guild->resetProhibitions();

    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "axe");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("material", ({ "iron" })));
    User->joinGuild("test");
    ExpectTrue(weapon->equip("blah"));
    Guild->resetProhibitions();
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeDoesNotAllowMaterialEvenIfAnyJoinedGuildDoes()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("name", "blah");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);
    move_object(weapon, User);

    ExpectTrue(Guild->testAddEquipmentProhibition("material", ({ "galvorn" })));
    User->joinGuild("test");

    object guild = load_object("/lib/tests/support/guilds/fighterGuild.c");
    User->joinGuild("fake fighter");
    ExpectFalse(weapon->equip("blah"));
}

/////////////////////////////////////////////////////////////////////////////
void LevelUpMessageDisplayedWhenEnoughExperienceToLevelIsAdded()
{
    ExpectTrue(User->joinGuild("test"));
    ExpectTrue(User->addExperience(1000), "experience added");
    ExpectSubStringMatch("You have enough experience to level up", 
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DistributeExperienceCorrectlyHandlesExperienceInCorrectGuildClasses()
{
    ExpectTrue(User->joinGuild("test"));
    ExpectTrue(User->distributeExperience(1000), "experience added");
    ExpectTrue(User->advanceLevel("test"), "level advanced");
    ExpectTrue(User->joinGuild("fake mage"));
    ExpectTrue(User->joinGuild("fake smith"));

    ExpectEq(0, User->guildExperience("test"), "initial test guild experience");
    ExpectEq(0, User->guildExperience("fake mage"), "initial mage guild experience");
    ExpectEq(0, User->guildExperience("fake smith"), "initial smith guild experience");

    ExpectTrue(User->distributeExperience(300), "experience added");
    ExpectEq(200, User->guildExperience("test"), "new test guild experience");
    ExpectEq(100, User->guildExperience("fake mage"), "new mage guild experience");
    ExpectEq(0, User->guildExperience("fake smith"), "new smith guild experience");

    object dict = load_object("/lib/dictionaries/guildsDictionary.c");

    ExpectTrue(User->distributeExperience(500, dict->guildsInClass("smithing")), 
        "experience added");
    ExpectEq(200, User->guildExperience("test"), "new test guild experience");
    ExpectEq(100, User->guildExperience("fake mage"), "new mage guild experience");
    ExpectEq(500, User->guildExperience("fake smith"), "new smith guild experience");
}
