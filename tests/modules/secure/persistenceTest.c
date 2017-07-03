//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/realizations/player.c");
    setRestoreCaller(this_object());
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void PlayerMaterialAttributesRestored()
{
    Player->restore("gorthaur");
    ExpectEq("Gorthaur", Player->Name());
    ExpectEq("male", Player->GenderDesc());
    ExpectEq(1, Player->Age());
    ExpectEq(0, Player->Ghost());
    ExpectEq(0, Player->Invisibility());
    ExpectEq("is now here", Player->MessageIn());
    ExpectEq("leaves", Player->MessageOut());
    ExpectEq("blah", Player->MagicalMessageIn());
    ExpectEq("de-blahs", Player->MagicalMessageOut());
    ExpectEq("blarg", Player->MessageHome());
    ExpectEq("does stuff", Player->MessageClone());
    ExpectEq("the title-less", Player->Title());
    ExpectEq("Weasel Lord", Player->Pretitle());
    ExpectEq("blah", Player->short());
    ExpectEq("This is a long description", Player->description());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerAttributesRestored()
{
    Player->restore("gorthaur");
    ExpectEq(11, Player->Str());
    ExpectEq(12, Player->Int());
    ExpectEq(13, Player->Dex());
    ExpectEq(13, Player->Wis());
    ExpectEq(13, Player->Con());
    ExpectEq(16, Player->Chr());
    ExpectEq(1, Player->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerBiologicalAttributesRestored()
{
    Player->restore("gorthaur");
    ExpectEq(5, Player->Intoxicated());
    ExpectEq(2, Player->Soaked());
    ExpectEq(4, Player->Stuffed());
    ExpectEq(3, Player->Drugged());
    ExpectEq(1, Player->haveHeadache());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerCombatAttributesRestored()
{
    Player->restore("gorthaur");
    ExpectEq(100, Player->hitPoints());
    ExpectEq(188, Player->maxHitPoints());
    ExpectEq(120, Player->spellPoints());
    ExpectEq(230, Player->maxSpellPoints());
    ExpectEq(140, Player->staminaPoints());
    ExpectEq(222, Player->maxStaminaPoints());
    ExpectEq(70, Player->Wimpy());
    ExpectTrue(Player->onKillList());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerGuildsRestored()
{
    Player->restore("gorthaur");
    ExpectEq(({ "mage" }), Player->memberOfGuilds());
    ExpectEq(21, Player->effectiveLevel());
    ExpectEq(120133, Player->effectiveExperience());
    ExpectEq(16, Player->guildLevel("mage"));
    ExpectEq(133, Player->guildExperience("mage"));
    ExpectEq("acolyte", Player->guildRank("mage"));
    ExpectEq("the blah blah", Player->guildTitle("mage"));
    ExpectEq("Mage", Player->guildPretitle("mage"));
    ExpectFalse(Player->isAnathema("mage"));
    ExpectEq(2333, Player->ageWhenRankAdvanced("mage"));

    // Even though the guild level for fighter is 5, since they left,
    // it's effectively 0.
    ExpectEq(0, Player->guildLevel("fighter"));
    ExpectTrue(Player->isAnathema("fighter"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerQuestsRestored()
{
    Player->restore("gorthaur");
    ExpectEq(({ "lib/tests/support/quests/testQuestItem.c" }), Player->activeQuests());

    object quest = load_object("/lib/tests/support/quests/testQuestItem.c");
    ExpectEq(sprintf("[0;36m%s[0m", "I've been asked to meet the king! I met King Tantor the Unclean of Thisplace. He seems to like me."),
        Player->questStory("lib/tests/support/quests/testQuestItem.c"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerRaceRestored()
{
    Player->restore("gorthaur");
    ExpectEq("elf", Player->Race());
}

/////////////////////////////////////////////////////////////////////////////
void PlayerResearchRestored()
{
    Player->restore("gorthaur");
    ExpectEq(3, Player->researchPoints());
    ExpectTrue(Player->isResearched("/lib/tests/support/research/testGrantedResearchItem.c"));
    ExpectEq(({ "/lib/tests/support/research/testSecondResearchTree.c" }), Player->availableResearchTrees());
    ExpectTrue(Player->selectResearchChoice("/lib/tests/support/research/testPersistedActiveTraitResearch.c",
        "Test"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerSkillsRestored()
{
    Player->restore("gorthaur");
    ExpectEq(16, Player->getSkill("long sword"));
}

/////////////////////////////////////////////////////////////////////////////
void PlayerTraitsRestored()
{
    Player->restore("gorthaur");
    ExpectEq(({ "/lib/tests/support/traits/testTrait.c", "/lib/tests/support/traits/testTraitWithDuration.c" }), 
        Player->Traits());
}
