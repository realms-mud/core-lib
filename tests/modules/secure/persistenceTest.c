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
    ExpectEq("Gorthaur",Player->Name());
    ExpectEq("male", Player->GenderDesc());
    ExpectEq(1, Player->Age());
    ExpectEq(0, Player->Ghost());
    ExpectEq(10, Player->Str());
    ExpectEq(10, Player->Int());
    ExpectEq(12, Player->Dex());
    ExpectEq(100, Player->hitPoints());
    ExpectEq(170, Player->maxHitPoints());
    ExpectEq(5, Player->Intoxicated());
    ExpectEq(2, Player->Soaked());
    ExpectEq(11, Player->getSkill("long sword"));
    ExpectEq("blah", Player->short());
    ExpectEq(({ "mage" }), Player->memberOfGuilds());
    ExpectTrue(Player->isAnathema("fighter"));
    ExpectEq(({ "lib/tests/support/quests/testQuestItem.c" }), Player->activeQuests());

    object quest = load_object("/lib/tests/support/quests/testQuestItem.c");
    ExpectEq(sprintf("[0;36m%s[0m", "I've been asked to meet the king! I met King Tantor the Unclean of Thisplace. He seems to like me."),
        Player->questStory("lib/tests/support/quests/testQuestItem.c"));
}
