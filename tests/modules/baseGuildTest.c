//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object User;
object Guild;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Guild = clone_object("/lib/tests/support/guilds/fakeGuild.c");

    User = clone_object("/lib/tests/support/services/researchWithMockServices");
    User->Name("Bob");
    User->Str(20);
    User->Dex(20);
    User->Con(20);
    User->Int(20);
    User->Wis(20);
    User->ToggleMockGuilds();
    User->SetGuild("fake mage");
    User->SetLevel(1);
    User->SetExperience(35000);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(Guild);
}

/////////////////////////////////////////////////////////////////////////////
void GuildNameSetsAndGetsNameOfGuild()
{
    ExpectEq("BaseGuild", Guild->guildName(), "initial name is 'BaseGuild'");
    ExpectEq("fake mage", Guild->guildName("fake mage"), "name set to mage");
    ExpectEq("fake mage", Guild->guildName(), "subsequent queries return 'mage'");
}

/////////////////////////////////////////////////////////////////////////////
void AddLevelPrerequisitesAddPrerequisites()
{
    mapping prerequisites = ([
        "orc":(["type":"combat statistic", "value": 2]),
        "wisdom" : (["type":"attribute", "value": 10]),
        "fetch a pencil": (["type":"quest"]),
        "long sword": (["type":"skill", "value": 10])
    ]);
    
    ExpectTrue(Guild->testAddLevelPrerequisite(10, prerequisites));
    ExpectEq((["level 10":prerequisites ]), Guild->getPrerequisites());
}

/////////////////////////////////////////////////////////////////////////////
void AddRankInsertsRank()
{
    mapping rank = ([
        "name": "grand master squid",
        "title": "the title of titliness",
        "pretitle": "Grand Master Squid",
        "previous rank": "lesser squid",
        "next rank": "squid divine",
        "delay for next promotion": 1800
    ]);

    ExpectTrue(Guild->testAddRank("grand master squid", rank));
}

/////////////////////////////////////////////////////////////////////////////
void AddRankPrerequisitesFailsIfRankNotPresent()
{
    mapping prerequisites = ([
        "orc":(["type":"combat statistic", "value" : 2]),
        "wisdom" : (["type":"attribute", "value" : 10]),
        "fetch a pencil" : (["type":"quest"]),
        "long sword" : (["type":"skill", "value" : 10])
    ]);

    ExpectFalse(Guild->testAddRankPrerequisite("grand master squid", prerequisites));
}

/////////////////////////////////////////////////////////////////////////////
void AddRankPrerequisitesAddPrerequisitesIfRankExits()
{
    mapping rank = ([
        "name": "grand master squid",
        "title": "the title of titliness",
        "pretitle": "Grand Master Squid",
        "previous rank": "lesser squid",
        "next rank": "squid divine",
        "delay for next promotion": 1800
    ]);

    ExpectTrue(Guild->testAddRank("grand master squid", rank));
    rank["name"] = "high squid of highness";
    ExpectTrue(Guild->testAddRank("high squid of highness", rank));

    mapping prerequisites = ([
        "orc":(["type":"combat statistic", "value": 2]),
        "wisdom" : (["type":"attribute", "value": 10]),
        "fetch a pencil": (["type":"quest"]),
        "long sword": (["type":"skill", "value": 10])
    ]);
    mapping fullPrereq = (["grand master squid":prerequisites]);

    ExpectTrue(Guild->testAddRankPrerequisite("grand master squid", prerequisites));
    
    prerequisites = ([
        "orc":(["type":"combat statistic", "value" : 5]),
        "wisdom" : (["type":"attribute", "value" : 14]),
        "fetch a mechanical pencil" : (["type":"quest"]),
        "long sword" : (["type":"skill", "value" : 16])
    ]);
    fullPrereq += (["high squid of highness":prerequisites]);

    ExpectTrue(Guild->testAddRankPrerequisite("high squid of highness", prerequisites));
    ExpectEq(fullPrereq, Guild->getPrerequisites());
}

/////////////////////////////////////////////////////////////////////////////
void ModifierCriteriaWithXEveryLevelWithinRangeOfLevelsStartingAtOneCanBeAdded()
{
    mapping criteria = ([
        "type": "modifier",
        "apply": "5 every level",
        "begin at level": 1,
        "end at level": 10
    ]);
    ExpectTrue(Guild->testAddCriteria("hit points", criteria));
    ExpectEq(5, Guild->queryBonus("bonus hit points", 1, "default"));
    ExpectEq(10, Guild->queryBonus("bonus hit points", 2, "default"));
    ExpectEq(15, Guild->queryBonus("bonus hit points", 3, "default"));
    ExpectEq(20, Guild->queryBonus("bonus hit points", 4, "default"));
    ExpectEq(25, Guild->queryBonus("bonus hit points", 5, "default"));
    ExpectEq(30, Guild->queryBonus("bonus hit points", 6, "default"));
    ExpectEq(35, Guild->queryBonus("bonus hit points", 7, "default"));
    ExpectEq(40, Guild->queryBonus("bonus hit points", 8, "default"));
    ExpectEq(45, Guild->queryBonus("bonus hit points", 9, "default"));
    ExpectEq(50, Guild->queryBonus("bonus hit points", 10, "default"));
    ExpectEq(50, Guild->queryBonus("bonus hit points", 11, "default"));
    ExpectEq(50, Guild->queryBonus("bonus hit points", 25, "default"));
}

/////////////////////////////////////////////////////////////////////////////
void ModifierCriteriaWithXEveryLevelWithinRangeOnlyAppliesIfProperRank()
{
    mapping criteria = ([
        "type":"modifier",
        "apply" : "5 every level",
        "begin at level" : 1,
        "begin at rank": "grand master squid",
        "end at level" : 10
    ]);
    ExpectTrue(Guild->testAddCriteria("hit points", criteria));
    ExpectEq(0, Guild->queryBonus("bonus hit points", 1, "default"));
    ExpectEq(5, Guild->queryBonus("bonus hit points", 1, "grand master squid"));
    ExpectEq(0, Guild->queryBonus("bonus hit points", 2, "default"));
    ExpectEq(10, Guild->queryBonus("bonus hit points", 2, "grand master squid"));
    ExpectEq(0, Guild->queryBonus("bonus hit points", 5, "default"));
    ExpectEq(25, Guild->queryBonus("bonus hit points", 5, "grand master squid"));
    ExpectEq(0, Guild->queryBonus("bonus hit points", 16, "default"));
    ExpectEq(50, Guild->queryBonus("bonus hit points", 16, "grand master squid"));
}
/////////////////////////////////////////////////////////////////////////////
void ModifierCriteriaWithXEveryLevelWithinRangeOfLevelsCanBeAdded()
{
    mapping criteria = ([
        "type":"modifier",
        "apply" : "5 every level",
        "begin at level" : 11,
        "end at level" : 20
    ]);
    ExpectTrue(Guild->testAddCriteria("hit points", criteria));
    ExpectEq(0, Guild->queryBonus("bonus hit points", 1, ""));
    ExpectEq(0, Guild->queryBonus("bonus hit points", 9, ""));
    ExpectEq(5, Guild->queryBonus("bonus hit points", 11, ""));
    ExpectEq(25, Guild->queryBonus("bonus hit points", 15, ""));
    ExpectEq(50, Guild->queryBonus("bonus hit points", 20, ""));
    ExpectEq(50, Guild->queryBonus("bonus hit points", 25, ""));
}

/////////////////////////////////////////////////////////////////////////////
void ModifierCriteriaWithXEveryLevelWithoutRangesGoesFromOneToMaxLevel()
{
    mapping criteria = ([
        "type":"modifier",
        "apply": "5 every level",
    ]);
    ExpectTrue(Guild->testAddCriteria("hit points", criteria));
    ExpectEq(5, Guild->queryBonus("bonus hit points", 1, ""));
    ExpectEq(100, Guild->queryBonus("bonus hit points", 20, ""));
    ExpectEq(500, Guild->queryBonus("bonus hit points", 100, ""));
    ExpectEq(2500, Guild->queryBonus("bonus hit points", 500, ""));
    ExpectEq(5000, Guild->queryBonus("bonus hit points", 1000, ""));
}

/////////////////////////////////////////////////////////////////////////////
void ModifierCriteriaWithAtLevelAppliesAtCorrectLevel()
{
    mapping criteria = ([
        "type":"modifier",
        "apply" : "at level 5",
    ]);
    ExpectTrue(Guild->testAddCriteria("hit points", criteria));
    ExpectEq(0, Guild->queryBonus("bonus hit points", 1, ""));
    ExpectEq(1, Guild->queryBonus("bonus hit points", 5, ""));
    ExpectEq(1, Guild->queryBonus("bonus hit points", 15, ""));
}

/////////////////////////////////////////////////////////////////////////////
void ModifierCriteriaWithAtRankAppliesAtCorrectRank()
{
    mapping rank = ([
        "name":"grand master squid",
            "title" : "the title of titliness",
            "pretitle" : "Grand Master Squid",
            "previous rank" : "lesser squid",
            "next rank" : "squid divine",
            "delay for next promotion" : 1800
    ]);
    ExpectTrue(Guild->testAddRank("grand master squid", rank));

    mapping criteria = ([
        "type":"modifier",
        "apply" : "at rank grand master squid",
    ]);
    ExpectTrue(Guild->testAddCriteria("hit points", criteria));
    ExpectEq(0, Guild->queryBonus("bonus hit points", 1, ""));
    ExpectEq(1, Guild->queryBonus("bonus hit points", 1, "grand master squid"));
}

/////////////////////////////////////////////////////////////////////////////
void ModifierCriteriaWithMultipleCriteriaIsCumulative()
{
    mapping criteria = ([
        "type":"modifier",
        "apply" : "5 every level",
    ]);
    ExpectTrue(Guild->testAddCriteria("hit points", criteria));

    criteria = ([
        "type":"modifier",
        "apply": "10 every 3 levels",
        "begin at level": 1,
        "end at level": 10
    ]);
    ExpectTrue(Guild->testAddCriteria("hit points", criteria));

    ExpectEq(5, Guild->queryBonus("bonus hit points", 1, ""));
    ExpectEq(10, Guild->queryBonus("bonus hit points", 2, ""));
    ExpectEq(25, Guild->queryBonus("bonus hit points", 3, ""));
    ExpectEq(30, Guild->queryBonus("bonus hit points", 4, ""));
    ExpectEq(35, Guild->queryBonus("bonus hit points", 5, ""));
    ExpectEq(50, Guild->queryBonus("bonus hit points", 6, ""));
    ExpectEq(55, Guild->queryBonus("bonus hit points", 7, ""));
    ExpectEq(60, Guild->queryBonus("bonus hit points", 8, ""));
    ExpectEq(75, Guild->queryBonus("bonus hit points", 9, ""));
    ExpectEq(125, Guild->queryBonus("bonus hit points", 19, ""));
}

/////////////////////////////////////////////////////////////////////////////
void SkillCriteriaWithXEveryLevelIsCorrectlyApplied()
{
    mapping criteria = ([
        "type":"modifier",
        "apply" : "1 every 2 levels",
    ]);

    ExpectTrue(Guild->testAddCriteria("long sword", criteria));
    ExpectEq(0, Guild->queryBonus("bonus long sword", 1, ""), "level 1");
    ExpectEq(1, Guild->queryBonus("bonus long sword", 2, ""), "level 2");
    ExpectEq(1, Guild->queryBonus("bonus long sword", 3, ""), "level 3");
    ExpectEq(2, Guild->queryBonus("bonus long sword", 5, ""), "level 5");
    ExpectEq(4, Guild->queryBonus("bonus long sword", 8, ""), "level 8");
    ExpectEq(6, Guild->queryBonus("bonus long sword", 13, ""), "level 13");
}

/////////////////////////////////////////////////////////////////////////////
void AttackCriteriaWithXEveryLevelIsCorrectlyApplied()
{
    mapping criteria = ([
        "type":"attack",
        "apply": "1 every 15 levels",
    ]);

    ExpectTrue(Guild->testAddCriteria("weapon attack", criteria));
    ExpectEq("", Guild->getExtraAttacks(1, ""), "level 1 - no extra attacks");
    ExpectEq("", Guild->getExtraAttacks(12, ""), "level 12 - no extra attacks");
    ExpectEq(({ (["attack type":"weapon"]), }), Guild->getExtraAttacks(23, ""), "level 23 - one extra attack");
    ExpectEq(({ (["attack type":"weapon"]), (["attack type":"weapon"]), }), Guild->getExtraAttacks(35, ""), "level 35 - two extra attacks");
}

/////////////////////////////////////////////////////////////////////////////
void AttackCriteriaWithLevelAndRankAppliedCorrectly()
{
    mapping criteria = ([
        "type":"attack",
        "apply": "1 every 15 levels",
        "begin at rank": "grand master squid"
    ]);

    ExpectTrue(Guild->testAddCriteria("weapon attack", criteria));
    ExpectEq("", Guild->getExtraAttacks(1, ""), "level 1 - no extra attacks");
    ExpectEq("", Guild->getExtraAttacks(1, "grand master squid"), "level 1 - no extra attacks");
    ExpectEq("", Guild->getExtraAttacks(23, "default"), "level 23 - one extra attack");
    ExpectEq(({ (["attack type":"weapon"]), }), Guild->getExtraAttacks(23, "grand master squid"), "level 23 - one extra attack");
    ExpectEq("", Guild->getExtraAttacks(35, "default"), "level 35 - two extra attacks");
    ExpectEq(({ (["attack type":"weapon"]), (["attack type":"weapon"]), }), 
        Guild->getExtraAttacks(35, "grand master squid"), "level 35 - two extra attacks");
}

/////////////////////////////////////////////////////////////////////////////
void RecurringAttributePointsCriteriaAppliedCorrectly()
{
    mapping criteria = ([
        "type":"attribute points",
        "apply": "1 every level"
    ]);

    ExpectTrue(Guild->testAddCriteria("attribute points", criteria), "criteria added");

    Guild->guildName("fake mage");

    ExpectTrue(Guild->advanceLevel(User), "advance to level 2");
    ExpectEq(1, User->attributePoints());

    ExpectTrue(Guild->advanceLevel(User), "advance to level 3");
    ExpectEq(2, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void AttributePointsCriteriaAppliedCorrectly()
{
    mapping criteria = ([
        "type":"attribute points",
        "apply": "at level 5"
    ]);

    ExpectTrue(Guild->testAddCriteria("attribute points", criteria), "criteria added");

    Guild->guildName("fake mage");

    ExpectTrue(Guild->advanceLevel(User), "advance to level 2");
    ExpectEq(0, User->attributePoints());

    User->SetLevel(4);
    User->SetExperience(5000);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 5");
    ExpectEq(1, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void MultipleAttributePointCriteriaWithBeginAtLevelAddedCumulatively()
{
    mapping criteria = ([
        "type":"attribute points",
        "apply": "1 every level",
        "begin at level": 2,
        "end at level": 5
    ]);
    ExpectTrue(Guild->testAddCriteria("attribute points", criteria), "criteria added");

    criteria = ([
        "type":"attribute points",
        "apply": "2 every 3 levels"
    ]);
    ExpectTrue(Guild->testAddCriteria("more attribute points", criteria), "more criteria added");

    criteria = ([
        "type":"attribute points",
        "apply": "3 every 5 levels",
        "begin at level": 4
    ]);
    ExpectTrue(Guild->testAddCriteria("yet more attribute points", criteria), "more criteria added");

    Guild->guildName("fake mage");

    User->SetLevel(0);
    ExpectFalse(User->attributePoints());
    ExpectTrue(Guild->advanceLevel(User), "advance to level 1");
    ExpectEq(2, User->attributePoints(), "level 1");

    User->SetLevel(1);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 2");
    ExpectEq(3, User->attributePoints(), "level 2");

    User->SetLevel(2);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 3");
    ExpectEq(4, User->attributePoints(), "level 3");

    User->SetLevel(3);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 4");
    ExpectEq(10, User->attributePoints(), "level 4");

    User->SetLevel(4);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 5");
    ExpectEq(11, User->attributePoints(), "level 5");

    User->SetLevel(5);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 6");
    ExpectEq(11, User->attributePoints(), "level 6");

    User->SetLevel(6);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 7");
    ExpectEq(13, User->attributePoints(), "level 7");

    User->SetLevel(7);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 8");
    ExpectEq(13, User->attributePoints(), "level 8");
}

/////////////////////////////////////////////////////////////////////////////
void AttributePointsForRankCriteriaAppliedCorrectly()
{
    mapping rank = ([
        "name":"lesser squid",
        "title" : "the title of titliness",
        "pretitle" : "Squid",
        "next rank" : "grand master squid"
    ]);
    ExpectTrue(Guild->testAddRank("lesser squid", rank));

    rank = ([
        "name":"grand master squid",
        "title" : "the title of titliness",
        "pretitle" : "Grand Master Squid",
        "previous rank" : "lesser squid",
        "next rank" : "squid divine",
        "delay for next promotion" : 1800
    ]);
    ExpectTrue(Guild->testAddRank("grand master squid", rank));

    mapping criteria = ([
        "type":"attribute points",
        "apply": "at rank grand master squid"
    ]);

    ExpectTrue(Guild->testAddCriteria("attribute points", criteria), "criteria added");

    Guild->guildName("fake mage");

    ExpectTrue(Guild->advanceRank(User, "lesser squid"), "advance to new rank");
    ExpectEq(1, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void SkillPointsCriteriaAppliedCorrectly()
{
    mapping criteria = ([
        "type":"skill points",
        "apply": "3 every level"
    ]);

    ExpectTrue(Guild->testAddCriteria("skill points", criteria), "criteria added");

    Guild->guildName("fake mage");

    ExpectTrue(Guild->advanceLevel(User), "advance to level 2");
    ExpectEq(3, User->AvailableSkillPoints());

    ExpectTrue(Guild->advanceLevel(User), "advance to level 3");
    ExpectEq(6, User->AvailableSkillPoints());
}

/////////////////////////////////////////////////////////////////////////////
void MultipleSkillPointCriteriaWithBeginAtLevelAddedCumulatively()
{
    mapping criteria = ([
        "type":"skill points",
        "apply": "1 every level",
        "begin at level": 2,
        "end at level": 5
    ]);
    ExpectTrue(Guild->testAddCriteria("skill points", criteria), "criteria added");

    criteria = ([
        "type":"skill points",
        "apply": "2 every 3 levels"
    ]);
    ExpectTrue(Guild->testAddCriteria("more skill points", criteria), "more criteria added");

    criteria = ([
        "type":"skill points",
        "apply": "3 every 5 levels",
        "begin at level": 4
    ]);
    ExpectTrue(Guild->testAddCriteria("yet more skill points", criteria), "more criteria added");

    Guild->guildName("fake mage");

    User->SetLevel(0);
    ExpectFalse(User->AvailableSkillPoints());
    ExpectTrue(Guild->advanceLevel(User), "advance to level 1");
    ExpectEq(2, User->AvailableSkillPoints(), "level 1");

    User->SetLevel(1);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 2");
    ExpectEq(3, User->AvailableSkillPoints(), "level 2");

    User->SetLevel(2);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 3");
    ExpectEq(4, User->AvailableSkillPoints(), "level 3");

    User->SetLevel(3);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 4");
    ExpectEq(10, User->AvailableSkillPoints(), "level 4");

    User->SetLevel(4);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 5");
    ExpectEq(11, User->AvailableSkillPoints(), "level 5");

    User->SetLevel(5);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 6");
    ExpectEq(11, User->AvailableSkillPoints(), "level 6");

    User->SetLevel(6);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 7");
    ExpectEq(13, User->AvailableSkillPoints(), "level 7");

    User->SetLevel(7);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 8");
    ExpectEq(13, User->AvailableSkillPoints(), "level 8");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchPointsCriteriaAppliedCorrectly()
{
    User->addSkillPoints(100);
    User->advanceSkill("long sword", 10);
    mapping criteria = ([
        "type":"research points",
        "apply": "1 every level"
    ]);

    ExpectTrue(Guild->testAddCriteria("research points", criteria), "criteria added");

    Guild->guildName("fake mage");

    ExpectFalse(User->initiateResearch("lib/tests/support/research/testPointsResearchItem.c"), "initiate research");
    ExpectTrue(Guild->advanceLevel(User), "advance to level 2");

    ExpectTrue(User->initiateResearch("lib/tests/support/research/testPointsResearchItem.c"), "initiate research");
    ExpectTrue(User->isResearched("lib/tests/support/research/testPointsResearchItem.c"), "isResearched");
}

/////////////////////////////////////////////////////////////////////////////
void MultipleResearchPointCriteriaAddedCumulatively()
{
    mapping criteria = ([
        "type":"research points",
        "apply": "1 every level"
    ]);
    ExpectTrue(Guild->testAddCriteria("research points", criteria), "criteria added");

    criteria = ([
        "type":"research points",
        "apply": "2 every 3 levels"
    ]);
    ExpectTrue(Guild->testAddCriteria("more research points", criteria), "more criteria added");

    Guild->guildName("fake mage");

    User->SetLevel(0);
    ExpectFalse(User->researchPoints());
    ExpectTrue(Guild->advanceLevel(User), "advance to level 1");
    ExpectEq(3, User->researchPoints(), "level 1");

    User->SetLevel(1);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 2");
    ExpectEq(4, User->researchPoints(), "level 2");

    User->SetLevel(2);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 3");
    ExpectEq(5, User->researchPoints(), "level 3");

    User->SetLevel(3);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 4");
    ExpectEq(8, User->researchPoints(), "level 4");

    User->SetLevel(4);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 5");
    ExpectEq(9, User->researchPoints(), "level 5");

    User->SetLevel(5);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 6");
    ExpectEq(10, User->researchPoints(), "level 6");

    User->SetLevel(6);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 7");
    ExpectEq(13, User->researchPoints(), "level 7");

    User->SetLevel(7);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 8");
    ExpectEq(14, User->researchPoints(), "level 8");
}

/////////////////////////////////////////////////////////////////////////////
void MultipleResearchPointCriteriaWithBeginAtLevelAddedCumulatively()
{
    mapping criteria = ([
        "type":"research points",
        "apply": "1 every level",
        "begin at level": 2,
        "end at level": 5
    ]);
    ExpectTrue(Guild->testAddCriteria("research points", criteria), "criteria added");

    criteria = ([
        "type":"research points",
        "apply": "2 every 3 levels"
    ]);
    ExpectTrue(Guild->testAddCriteria("more research points", criteria), "more criteria added");

    criteria = ([
        "type":"research points",
        "apply": "3 every 5 levels",
        "begin at level": 4
    ]);
    ExpectTrue(Guild->testAddCriteria("yet more research points", criteria), "more criteria added");

    Guild->guildName("fake mage");

    User->SetLevel(0);
    ExpectFalse(User->researchPoints());
    ExpectTrue(Guild->advanceLevel(User), "advance to level 1");
    ExpectEq(2, User->researchPoints(), "level 1");

    User->SetLevel(1);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 2");
    ExpectEq(3, User->researchPoints(), "level 2");

    User->SetLevel(2);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 3");
    ExpectEq(4, User->researchPoints(), "level 3");

    User->SetLevel(3);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 4");
    ExpectEq(10, User->researchPoints(), "level 4");

    User->SetLevel(4);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 5");
    ExpectEq(11, User->researchPoints(), "level 5");

    User->SetLevel(5);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 6");
    ExpectEq(11, User->researchPoints(), "level 6");

    User->SetLevel(6);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 7");
    ExpectEq(13, User->researchPoints(), "level 7");

    User->SetLevel(7);
    ExpectTrue(Guild->advanceLevel(User), "advance to level 8");
    ExpectEq(13, User->researchPoints(), "level 8");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchCriteriaAppliedCorrectly()
{
    User->addSkillPoints(100);
    User->advanceSkill("long sword", 10);
    mapping criteria = ([
        "type":"research",
        "apply": "at level 5",
        "research object": "lib/tests/support/research/testGrantedResearchItem.c"
    ]);
    User->SetLevel(4);
    User->SetExperience(5000);
    ExpectTrue(Guild->testAddCriteria("research", criteria), "criteria added");

    Guild->guildName("fake mage");

    ExpectFalse(User->isResearched("lib/tests/support/research/testGrantedResearchItem.c"), "research is not completed");
    ExpectTrue(Guild->advanceLevel(User), "advance to level 5");

    ExpectTrue(User->isResearched("lib/tests/support/research/testGrantedResearchItem.c"), "research is completed");
}

/////////////////////////////////////////////////////////////////////////////
void ResearchTreeCriteriaAppliedCorrectly()
{
    User->addSkillPoints(100);
    User->advanceSkill("long sword", 10);
    mapping criteria = ([
        "type":"research tree",
        "apply" : "at level 5",
        "research tree": "lib/tests/support/guilds/testGuildResearchTree.c"
    ]);
    User->SetLevel(4);
    User->SetExperience(5000);
    ExpectTrue(Guild->testAddCriteria("research tree", criteria), "criteria added");

    Guild->guildName("fake mage");

    ExpectFalse(User->isResearched("lib/tests/support/guilds/testGuildTreeRoot.c"), "research is not completed");
    ExpectEq(({}), User->availableResearchTrees(), "no research trees available");

    ExpectTrue(Guild->advanceLevel(User), "advance to level 5");
    ExpectTrue(User->isResearched("lib/tests/support/guilds/testGuildTreeRoot.c"), "research is completed");
    ExpectEq(({ "lib/tests/support/guilds/testGuildResearchTree.c" }), User->availableResearchTrees(), "no research trees available");
}

/////////////////////////////////////////////////////////////////////////////
void TraitCriteriaAppliedCorrectly()
{
    mapping criteria = ([
        "type":"trait",
        "apply": "at level 5",
        "trait object": "lib/modules/traits/personality/abrasive.c"
    ]);
    User->SetLevel(4);
    User->SetExperience(5000);
    ExpectTrue(Guild->testAddCriteria("abrasive", criteria), "criteria added");

    Guild->guildName("fake mage");

    ExpectFalse(User->isTraitOf("lib/modules/traits/personality/abrasive.c"), "user does not have the trait");
    ExpectTrue(Guild->advanceLevel(User), "advance to level 5");

    ExpectTrue(User->isTraitOf("lib/modules/traits/personality/abrasive.c"), "user has the trait");
}

/////////////////////////////////////////////////////////////////////////////
void ApplyIfChosenResearchTreeCriteriaNotAppliedIfCriteriaNotMet()
{
    User->addSkillPoints(100);
    User->advanceSkill("long sword", 10);
    mapping criteria = ([
        "type":"research tree",
        "apply" : "at level 5",
        "research tree": "lib/tests/support/guilds/testGuildResearchTree.c",
        "apply if chosen": ({ "lib/tests/support/research/testGrantedResearchItem.c" })
    ]);
    User->SetLevel(4);
    User->SetExperience(5000);
    ExpectTrue(Guild->testAddCriteria("research tree", criteria), "criteria added");

    Guild->guildName("fake mage");

    ExpectFalse(User->isResearched("lib/tests/support/guilds/testGuildTreeRoot.c"), "research is not completed");
    ExpectEq(({}), User->availableResearchTrees(), "no research trees available");

    ExpectTrue(Guild->advanceLevel(User), "advance to level 5");
    ExpectFalse(User->isResearched("lib/tests/support/guilds/testGuildTreeRoot.c"), "research is completed");
    ExpectEq(({  }), User->availableResearchTrees(), "no research trees available");
}

/////////////////////////////////////////////////////////////////////////////
void ApplyIfChosenResearchTreeCriteriaAppliedIfCriteriaMet()
{
    User->addSkillPoints(100);
    User->advanceSkill("long sword", 10);
    mapping criteria = ([
        "type":"research tree",
        "apply" : "at level 5",
        "research tree" : "lib/tests/support/guilds/testGuildResearchTree.c",
        "apply if chosen" : ({ "lib/tests/support/research/testGrantedResearchItem.c" })
    ]);
    User->SetLevel(4);
    User->SetExperience(5000);
    ExpectTrue(Guild->testAddCriteria("research tree", criteria), "criteria added");

    Guild->guildName("fake mage");
    User->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c");
    ExpectFalse(User->isResearched("lib/tests/support/guilds/testGuildTreeRoot.c"), "research is not completed");
    ExpectEq(({}), User->availableResearchTrees(), "no research trees available");

    ExpectTrue(Guild->advanceLevel(User), "advance to level 5");
    ExpectTrue(User->isResearched("lib/tests/support/guilds/testGuildTreeRoot.c"), "research is completed");
    ExpectEq(({ "lib/tests/support/guilds/testGuildResearchTree.c" }), User->availableResearchTrees(), "no research trees available");
}

/////////////////////////////////////////////////////////////////////////////
void ApplyIfChosenResearchCriteriaNotAppliedIfCriteriaNotMet()
{
    User->addSkillPoints(100);
    User->advanceSkill("long sword", 10);
    mapping criteria = ([
        "type":"research",
        "apply": "at level 5",
        "research object": "lib/tests/support/research/testGrantedResearchItem.c",
        "apply if chosen" : ({ "lib/tests/support/guilds/testGuildResearchTree.c" })
    ]);
    User->SetLevel(4);
    User->SetExperience(5000);
    ExpectTrue(Guild->testAddCriteria("research", criteria), "criteria added");

    Guild->guildName("fake mage");

    ExpectFalse(User->isResearched("lib/tests/support/research/testGrantedResearchItem.c"), "research is not completed");
    ExpectTrue(Guild->advanceLevel(User), "advance to level 5");

    ExpectFalse(User->isResearched("lib/tests/support/research/testGrantedResearchItem.c"), "research is completed");
}

/////////////////////////////////////////////////////////////////////////////
void ApplyIfChosenResearchCriteriaAppliedIfCriteriaMet()
{
    User->addSkillPoints(100);
    User->advanceSkill("long sword", 10);
    mapping criteria = ([
        "type":"research",
        "apply": "at level 5",
        "research object": "lib/tests/support/research/testGrantedResearchItem.c",
        "apply if chosen" : ({ "lib/tests/support/guilds/testGuildResearchTree.c" })
    ]);
    User->SetLevel(4);
    User->SetExperience(5000);
    ExpectTrue(Guild->testAddCriteria("research", criteria), "criteria added");
    User->addResearchTree("lib/tests/support/guilds/testGuildResearchTree.c");

    Guild->guildName("fake mage");

    ExpectFalse(User->isResearched("lib/tests/support/research/testGrantedResearchItem.c"), "research is not completed");
    ExpectTrue(Guild->advanceLevel(User), "advance to level 5");

    ExpectTrue(User->isResearched("lib/tests/support/research/testGrantedResearchItem.c"), "research is completed");
}

/////////////////////////////////////////////////////////////////////////////
void DemoteRankCorrectlyPlacesMemberAtPreviousRank()
{
    mapping rank = ([
        "name":"lesser squid",
        "title" : "the title of titliness",
        "pretitle" : "Squid",
        "next rank" : "grand master squid"
    ]);
    ExpectTrue(Guild->testAddRank("lesser squid", rank));

    rank = ([
        "name":"grand master squid",
        "title" : "the title of titliness",
        "pretitle" : "Grand Master Squid",
        "previous rank" : "lesser squid",
        "next rank" : "squid divine",
        "delay for next promotion" : 1800
    ]);

    mapping criteria = ([
        "type":"attribute points",
        "apply": "at rank grand master squid"
    ]);

    ExpectTrue(Guild->testAddRank("grand master squid", rank));
    ExpectTrue(Guild->testAddCriteria("attribute points", criteria), "criteria added");

    Guild->guildName("fake mage");

    ExpectEq("grand master squid", Guild->advanceRank(User, "lesser squid"), "advance to new rank");
    ExpectEq("lesser squid", Guild->demoteRank(User, "grand master squid"), "advance to grand master squid rank");
}

/////////////////////////////////////////////////////////////////////////////
void RankNameReturnsTheNameDefinedInRank()
{
    mapping rank = ([
        "name":"lesser squidling",
        "title" : "the title of titliness",
        "pretitle" : "Squid",
        "next rank" : "grand master squid"
    ]);
    ExpectTrue(Guild->testAddRank("lesser squid", rank));
    ExpectEq("lesser squidling", Guild->rankName("lesser squid"));
}

/////////////////////////////////////////////////////////////////////////////
void DefaultRankCanBeSet()
{
    Guild->guildName("fake mage");
    mapping rank = ([
        "name":"lesser squidling",
        "title" : "the title of titliness",
        "pretitle" : "Squid",
        "next rank" : "grand master squid"
    ]);
    ExpectTrue(Guild->testAddRank("lesser squid", rank));
    ExpectTrue(Guild->testSetDefaultRank("lesser squid"));

    mapping criteria = ([
        "type":"attribute points",
            "apply" : "at rank lesser squid"
    ]);
    ExpectTrue(Guild->testAddCriteria("attribute points", criteria), "criteria added");

    ExpectEq("lesser squid", Guild->advanceRank(User, "default"), "advance to new rank");
}

/////////////////////////////////////////////////////////////////////////////
void SkillCostsAppliedCorrectlyForEruditeSkills()
{
    Guild->guildName("fake mage");
    User->SetGuildObject(Guild);
    User->addSkillPoints(100);

    // Erudite should always be 1
    ExpectEq(1, User->advanceSkillCost("perception", 1));
}

/////////////////////////////////////////////////////////////////////////////
void SkillCostsAppliedCorrectlyForGeneralSkills()
{
    Guild->guildName("fake mage");
    User->SetGuildObject(Guild);
    User->addSkillPoints(100);

    // General should always be 1
    ExpectEq(1, User->advanceSkillCost("agriculture", 1));
}

/////////////////////////////////////////////////////////////////////////////
void SkillCostsAppliedCorrectlyForLanguageSkills()
{
    Guild->guildName("fake mage");
    User->SetGuildObject(Guild);
    User->addSkillPoints(100);

    // Language should always be 1
    ExpectEq(1, User->advanceSkillCost("dwarven", 1));
}

/////////////////////////////////////////////////////////////////////////////
void SkillCostsAppliedCorrectlyForCombatSkills()
{
    Guild->guildName("fake mage");
    User->SetGuildObject(Guild);
    User->addSkillPoints(100);

    // Combat should be 2 by default
    ExpectEq(2, User->advanceSkillCost("long sword", 1));

    ExpectTrue(Guild->testAddPreferredSkillType("combat"));

    // Preferred skills should only cost 1
    ExpectEq(1, User->advanceSkillCost("long sword", 1));
}

/////////////////////////////////////////////////////////////////////////////
void SkillCostsAppliedCorrectlyForCraftingSkills()
{
    Guild->guildName("fake mage");
    User->SetGuildObject(Guild);
    User->addSkillPoints(100);

    // Crafting should be 2 by default
    ExpectEq(2, User->advanceSkillCost("weapon smithing", 1));

    ExpectTrue(Guild->testAddPreferredSkillType("crafting"));

    // Preferred skills should only cost 1
    ExpectEq(1, User->advanceSkillCost("weapon smithing", 1));
}

/////////////////////////////////////////////////////////////////////////////
void SkillCostsAppliedCorrectlyForSubterfugeSkills()
{
    Guild->guildName("fake mage");
    User->SetGuildObject(Guild);
    User->addSkillPoints(100);

    // Subterfuge should be 2 by default
    ExpectEq(2, User->advanceSkillCost("disguise", 1));

    ExpectTrue(Guild->testAddPreferredSkillType("subterfuge"));

    // Preferred skills should only cost 1
    ExpectEq(1, User->advanceSkillCost("disguise", 1));
}

/////////////////////////////////////////////////////////////////////////////
void SkillCostsAppliedCorrectlyForMagicSkills()
{
    Guild->guildName("fake mage");
    User->SetGuildObject(Guild);
    User->addSkillPoints(100);

    // Magic should be 2 by default
    ExpectEq(2, User->advanceSkillCost("evocation", 1));

    ExpectTrue(Guild->testAddPreferredSkillType("magic"));

    // Preferred skills should only cost 1
    ExpectEq(1, User->advanceSkillCost("evocation", 1));
}

/////////////////////////////////////////////////////////////////////////////
void ResearchChoiceCriteriaAppliedCorrectly()
{
    User->SetLevel(1);
    User->SetExperience(1000);

    mapping criteria = ([
        "type": "research choice",
        "name": "blah",
        "description": "blah blah",
        "apply" : "at level 2",
        "research objects" : ({ "lib/tests/support/research/testLimitedActiveResearchItem.c",
            "lib/tests/support/research/testGrantedResearchItem.c" })
    ]);

    ExpectTrue(Guild->testAddCriteria("research choice", criteria), "criteria added");
    Guild->guildName("fake mage");

    ExpectEq(([]), User->getResearchChoices());
    ExpectTrue(Guild->advanceLevel(User), "advance to level 2");
    ExpectEq(([ "blah": ([ 
        "1": ([ 
            "choice": "blah", 
            "description": "This is limited active research", 
            "key": "lib/tests/support/research/testLimitedActiveResearchItem.c", 
            "name": "Active research", 
            "type": "research object"
        ]), 
        "2": ([ 
            "choice": "blah", 
            "description": "This is granted research", 
            "key": "lib/tests/support/research/testGrantedResearchItem.c", 
            "name": "Granted research", 
            "type": "research object"
        ])
    ])]), User->getResearchChoices());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchPathCriteriaAppliedCorrectly()
{
    User->SetLevel(1);
    User->SetExperience(1000);

    mapping criteria = ([
        "type": "research path",
        "name": "blah",
        "description": "blah blah",
        "apply" : "at level 2",
        "research objects" : ({ "lib/tests/support/guilds/testGuildResearchTree.c",
            "lib/tests/support/research/testSecondResearchTree.c" })
    ]);

    ExpectTrue(Guild->testAddCriteria("research choice", criteria), "criteria added");
    Guild->guildName("fake mage");

    ExpectEq(([]), User->getResearchChoices());
    ExpectTrue(Guild->advanceLevel(User), "advance to level 2");
    ExpectEq(([ "blah": ([ 
        "1": ([ 
            "choice": "blah", 
            "description": "this is the land-loving mother pigeon of all research trees", 
            "key": "lib/tests/support/guilds/testGuildResearchTree.c", 
            "name": "tree of guild researchiness",
            "obsoletes": ({ "lib/tests/support/research/testSecondResearchTree.c" }),
            "type": "research tree"
        ]), 
        "2": ([ 
            "choice": "blah", 
            "description": "this is the land-loving mother pigeon of all research trees", 
            "key": "lib/tests/support/research/testSecondResearchTree.c", 
            "name": "tree of guild researchiness", 
            "obsoletes": ({ "lib/tests/support/guilds/testGuildResearchTree.c" }),
            "type": "research tree"
        ])
    ])]), User->getResearchChoices());
}

/////////////////////////////////////////////////////////////////////////////
void CanLeaveGuildReturnsFalseWhenProhibitLeavingGuildCalled()
{
    ExpectTrue(Guild->canLeaveGuild(User), "can leave guild before prohibition");
    Guild->testProhibitLeavingGuild();
    ExpectFalse(Guild->canLeaveGuild(User), "cannot leave guild after prohibition");
}

/////////////////////////////////////////////////////////////////////////////
void CanLeaveGuildReturnsFalseWhenMemberIsAnathema()
{
    ExpectTrue(Guild->canLeaveGuild(User), "can leave guild before prohibition");
    Guild->guildName("test");
    User->SetGuild("test");
    ExpectFalse(Guild->canLeaveGuild(User), "cannot leave guild after prohibition");
}

/////////////////////////////////////////////////////////////////////////////
void InvalidGuildsPrunedFromProhibitionList()
{
    object mageGuild = clone_object("/lib/tests/support/guilds/mageGuild.c");
    object fighterGuild = clone_object("/lib/tests/support/guilds/fighterGuild.c");

    Guild->testProhibitedGuildCombinations(({ "fake fighter", "fake mage", "blarg", "blumfrub", "fake" }));
    ExpectEq(({ "fake mage", "fake fighter" }), Guild->prohibitedGuilds());
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidEquipmentProhibition()
{
    string err = catch (Guild->testAddEquipmentProhibition("blah", ({ "stuff" })));
    string expectedError = "*baseGuild::addEquipmentProhibition - an invalid prohibition was supplied.";
    ExpectEq(expectedError, err, "The correct exception is thrown");
}

/////////////////////////////////////////////////////////////////////////////
void CanAddMaterialEquipmentProhibition()
{
    ExpectTrue(Guild->testAddEquipmentProhibition("material", ({ "iron" })));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidMaterialToEquipmentProhibition()
{
    string err = catch (Guild->testAddEquipmentProhibition("material",
        ({ "iron", "stuff" })));

    string expectedError = "*baseGuild::addEquipmentProhibition - an invalid prohibition was supplied.";
    ExpectEq(expectedError, err, "The correct exception is thrown");
}

/////////////////////////////////////////////////////////////////////////////
void CanAddMaterialTypeEquipmentProhibition()
{
    ExpectTrue(Guild->testAddEquipmentProhibition("material type", ({ "metal" })));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidMaterialTypeToEquipmentProhibition()
{
    string err = catch (Guild->testAddEquipmentProhibition("material type",
        ({ "metal", "felt" })));

    string expectedError = "*baseGuild::addEquipmentProhibition - an invalid prohibition was supplied.";
    ExpectEq(expectedError, err, "The correct exception is thrown");
}

/////////////////////////////////////////////////////////////////////////////
void CanAddArmorTypeEquipmentProhibition()
{
    ExpectTrue(Guild->testAddEquipmentProhibition("armor type", ({ "chainmail" })));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidArmorTypeToEquipmentProhibition()
{
    string err = catch (Guild->testAddEquipmentProhibition("armor type",
        ({ "chainmail", "felt" })));

    string expectedError = "*baseGuild::addEquipmentProhibition - an invalid prohibition was supplied.";
    ExpectEq(expectedError, err, "The correct exception is thrown");
}

/////////////////////////////////////////////////////////////////////////////
void CanAddArmorLocationEquipmentProhibition()
{
    ExpectTrue(Guild->testAddEquipmentProhibition("armor location", ({ "cloak" })));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidArmorLocationToEquipmentProhibition()
{
    string err = catch (Guild->testAddEquipmentProhibition("armor location",
        ({ "cloak", "felt" })));

    string expectedError = "*baseGuild::addEquipmentProhibition - an invalid prohibition was supplied.";
    ExpectEq(expectedError, err, "The correct exception is thrown");
}

/////////////////////////////////////////////////////////////////////////////
void CanAddWeaponTypeEquipmentProhibition()
{
    ExpectTrue(Guild->testAddEquipmentProhibition("weapon type", ({ "long sword", "axe" })));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidWeaponTypeToEquipmentProhibition()
{
    string err = catch (Guild->testAddEquipmentProhibition("weapon type",
        ({ "axe", "felt" })));

    string expectedError = "*baseGuild::addEquipmentProhibition - an invalid prohibition was supplied.";
    ExpectEq(expectedError, err, "The correct exception is thrown");
}

/////////////////////////////////////////////////////////////////////////////
void CanAddDamageTypeEquipmentProhibition()
{
    ExpectTrue(Guild->testAddEquipmentProhibition("damage type", ({ "slash" })));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidDamageTypeToEquipmentProhibition()
{
    string err = catch (Guild->testAddEquipmentProhibition("damage type",
        ({ "thrust", "felt" })));

    string expectedError = "*baseGuild::addEquipmentProhibition - an invalid prohibition was supplied.";
    ExpectEq(expectedError, err, "The correct exception is thrown");
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeNotAffectedByMaterial()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);

    ExpectTrue(Guild->testAddEquipmentProhibition("material", ({ "galvorn" })));
    ExpectTrue(Guild->canUseEquipmentOfType(weapon));
}

/////////////////////////////////////////////////////////////////////////////
void isProhibitedEquipmentAffectedByMaterial()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);

    ExpectTrue(Guild->testAddEquipmentProhibition("material", ({ "galvorn" })));
    ExpectTrue(Guild->isProhibitedEquipment(weapon));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeNotAffectedByMaterialType()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);

    ExpectTrue(Guild->testAddEquipmentProhibition("material type", ({ "metal" })));
    ExpectTrue(Guild->canUseEquipmentOfType(weapon));
}

/////////////////////////////////////////////////////////////////////////////
void isProhibitedEquipmentAffectedByMaterialType()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);

    ExpectTrue(Guild->testAddEquipmentProhibition("material type", ({ "metal" })));
    ExpectTrue(Guild->isProhibitedEquipment(weapon));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeAffectedByArmorType()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("material", "galvorn");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);

    ExpectTrue(Guild->testAddEquipmentProhibition("armor type", ({ "chainmail" })));
    ExpectFalse(Guild->canUseEquipmentOfType(armor));
}

/////////////////////////////////////////////////////////////////////////////
void isProhibitedEquipmentNotAffectedByArmorType()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("material", "galvorn");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", Armor);

    ExpectTrue(Guild->testAddEquipmentProhibition("armor type", ({ "chainmail" })));
    ExpectFalse(Guild->isProhibitedEquipment(armor));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeAffectedByArmorLocation()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("material", "galvorn");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", ArmGreaves | LegGreaves | Armor);

    ExpectTrue(Guild->testAddEquipmentProhibition("armor location", ({ "leg greaves" })));
    ExpectFalse(Guild->canUseEquipmentOfType(armor));
}

/////////////////////////////////////////////////////////////////////////////
void isProhibitedEquipmentNotAffectedByArmorLocation()
{
    object armor = clone_object("/lib/items/armor");
    armor->set("material", "galvorn");
    armor->set("armor type", "chainmail");
    armor->set("equipment locations", OnehandedWeapon);

    ExpectTrue(Guild->testAddEquipmentProhibition("armor location", ({ "arm greaves" })));
    ExpectFalse(Guild->isProhibitedEquipment(armor));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeAffectedByWeaponType()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);

    ExpectTrue(Guild->testAddEquipmentProhibition("weapon type", ({ "long sword" })));
    ExpectFalse(Guild->canUseEquipmentOfType(weapon));
}

/////////////////////////////////////////////////////////////////////////////
void isProhibitedEquipmentNotAffectedByWeaponType()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);

    ExpectTrue(Guild->testAddEquipmentProhibition("weapon type", ({ "long sword" })));
    ExpectFalse(Guild->isProhibitedEquipment(weapon));
}

/////////////////////////////////////////////////////////////////////////////
void CanUseEquipmentOfTypeNotAffectedByDamageType()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);

    ExpectTrue(Guild->testAddEquipmentProhibition("damage type", ({ "slash" })));
    ExpectTrue(Guild->canUseEquipmentOfType(weapon));
}

/////////////////////////////////////////////////////////////////////////////
void isProhibitedEquipmentAffectedByDamageType()
{
    object weapon = clone_object("/lib/items/weapon");
    weapon->set("material", "galvorn");
    weapon->set("weapon type", "long sword");
    weapon->set("equipment locations", OnehandedWeapon);

    ExpectTrue(Guild->testAddEquipmentProhibition("damage type", ({ "slash" })));
    ExpectTrue(Guild->isProhibitedEquipment(weapon));
}

/////////////////////////////////////////////////////////////////////////////
void isNonCombatGuildReturnsTrueOnlyForNonCombatGuilds()
{
    ExpectFalse(Guild->isNonCombatGuild());

    object nonCombat = clone_object("/lib/tests/support/guilds/nonCombatGuild.c");
    ExpectTrue(nonCombat->isNonCombatGuild());
    destruct(nonCombat);
}
