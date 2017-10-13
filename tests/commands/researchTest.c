//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

string EndBar = "[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-+-=-=-=-=-=-=-=-=-=-=-=-=-+-=-=-=-=-=-=-=-=-=-=-=-=-+\n[0m";
string TraitsRow = "[0;31m| [0m%s%23s[0m [0;31m| [0m%s%23s[0m [0;31m| [0m%s%23s[0m [0;31m|\n[0m";

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->Str(20);
    Player->addSkillPoints(100);
    Player->advanceSkill("long sword", 10);
    Player->addCommands();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelResearchMenuDisplaysCorrectly()
{
    ExpectTrue(Player->addResearchTree("lib/tests/support/research/testDeepResearchTree.c"), "a");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testLimitedByIntoxResearchItem.c"), "b");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearch.c"), "c");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearchTimed.c"), "d");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"));

    object selector = clone_object("/lib/modules/research/researchSelector.c");
    selector->initiateSelector(Player);

    ExpectEq("[0;36mResearch - [0m[0;37;1mFrom this menu, you can view your character's known research\nas well as initiate new research[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mFighter guild       [0m\n"
        "\t[[0;31;1m2[0m] - [0;32mMage guild          [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mQuests              [0m\n"
        "\t[[0;31;1m4[0m] - [0;32mExit Research Menu  [0m\n"
        "[0;32;1mYou must select a number from 1 to 4.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchSubmenuDisplaysCorrectly()
{
    ExpectTrue(Player->addResearchTree("lib/tests/support/research/testDeepResearchTree.c"), "a");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testLimitedByIntoxResearchItem.c"), "b");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearch.c"), "c");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearchTimed.c"), "d");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"));

    object selector = clone_object("/lib/modules/research/researchSelector.c");
    selector->initiateSelector(Player);
    move_object(selector, Player);
    command("2", Player);
    object dict = load_object("/lib/dictionaries/researchDictionary.c");

    ExpectEq("[0;36mResearch - [0m[0;37;1mSelect a research item to view in more detail[0m:\n"
        "\t[[0;31;1m1[0m]  - [0;32mIntox research      [0m[0;34;1m (*)[0m"
        "\t[[0;31;1m2[0m]  - [0;32mSpiffy tree root    [0m[0;34;1m (*)[0m\n"
        "\t[[0;31;1m3[0m]  - [0;32mMock research       [0m[0;35m (!)[0m"
        "\t[[0;31;1m4[0m]  - [0;32mTree of researchi...[0m[0;34;1m (*)[0m\n"
        "\t[[0;31;1m5[0m]  - [0;32mFlambe-maker        [0m[0;31m (X)[0m"
        "\t[[0;31;1m6[0m]  - [0;32mGrebe of obstinance [0m[0;31m (X)[0m\n"
        "\t[[0;31;1m7[0m]  - [0;32mGrog's revenge      [0m[0;31m (X)[0m"
        "\t[[0;31;1m8[0m]  - [0;32mHand of fist        [0m\n"
        "\t[[0;31;1m9[0m]  - [0;32mTurnip seclusion    [0m"
        "\t[[0;31;1m10[0m] - [0;32mWeasel inversion    [0m\n"
        "\t[[0;31;1m11[0m] - [0;32mZap thingy          [0m[0;31m (X)[0m"
        "\t[[0;31;1m12[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 12.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1m"
        "[0;34;1m(*)[0m[0;32;1m denotes already-chosen research while "
        "[0;35m(!)[0m[0;32;1m denotes research in progress.\nResearch denoted "
        "[0;31m(X)[0m[0;32;1m cannot yet be learned - view description for details.[0m\n[0m",
        Player->caughtMessage());
}