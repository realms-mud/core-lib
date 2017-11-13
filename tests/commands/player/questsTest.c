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
    Player->executeCommand("quests");

    ExpectEq("[0;36mQuest - [0m[0;37;1mFrom this menu, you can view your character's available quests[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mBackground          [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m2[0m] - [0;32mGuild               [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m3[0m] - [0;32mPrimary             [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m4[0m] - [0;32mResearch            [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m5[0m] - [0;32mSecondary           [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m6[0m] - [0;32mTask                [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m7[0m] - [0;32mCompleted           [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m8[0m] - [0;32mExit Quest Menu     [0m\n"
        "[0;32;1mYou must select a number from 1 to 8.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingExitExitsCommand()
{
    Player->executeCommand("quests");
    command("8", Player);
    ExpectSubStringMatch("You have selected 'Exit Quest Menu'",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingOptionWithNoQuestsReturnsToMainMenu()
{
    Player->executeCommand("quests");
    command("6", Player);

    ExpectEq("[0;36mQuest - [0m[0;37;1mFrom this menu, you can view your character's available quests[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mBackground          [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m2[0m] - [0;32mGuild               [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m3[0m] - [0;32mPrimary             [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m4[0m] - [0;32mResearch            [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m5[0m] - [0;32mSecondary           [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m6[0m] - [0;32mTask                [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m7[0m] - [0;32mCompleted           [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m8[0m] - [0;32mExit Quest Menu     [0m\n"
        "[0;32;1mYou must select a number from 1 to 8.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EntriesWithActiveQuestsDoNotShowNoQuests()
{
    Player->beginQuest("lib/tests/support/quests/anotherQuest.c");
    Player->beginQuest("lib/tests/support/quests/fakeQuestItem.c");
    Player->executeCommand("quests");

    ExpectEq("[0;36mQuest - [0m[0;37;1mFrom this menu, you can view your character's available quests[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mBackground          [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m2[0m] - [0;32mGuild               [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m3[0m] - [0;32mPrimary             [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m4[0m] - [0;32mResearch            [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m5[0m] - [0;32mSecondary           [0m\n"
        "\t[[0;31;1m6[0m] - [0;32mTask                [0m[0;31m(No quests)[0m\n"
        "\t[[0;31;1m7[0m] - [0;32mCompleted           [0m\n"
        "\t[[0;31;1m8[0m] - [0;32mExit Quest Menu     [0m\n"
        "[0;32;1mYou must select a number from 1 to 8.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingOptionWithQuestsDisplaysSubmenu()
{
    Player->beginQuest("lib/tests/support/quests/anotherQuest.c");
    Player->beginQuest("lib/tests/support/quests/fakeQuestItem.c");
    Player->executeCommand("quests");
    command("5", Player);

    ExpectEq("[0;36mQuest - [0m[0;37;1mSelect a quest to view in more detail[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mHail to the king,...[0m[0;35m (!)[0m"
        "\t[[0;31;1m2[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 2.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescriptionOfQuestChangesWithStateAdvancement()
{
    Player->beginQuest("lib/tests/support/quests/anotherQuest.c");
    Player->beginQuest("lib/tests/support/quests/fakeQuestItem.c");
    Player->executeCommand("quests");
    command("5", Player);
    command("1", Player);

    ExpectEq("[0;36mQuest - [0m[0;37;1mDetails:[0m\n"
        "[0;33mName[0m:  [0;33;1mHail to the king, baby![0m\n"
        "[0;36m[0;36mI've been asked to meet the king![0m[0m\n[0m\n"
        "\t[[0;31;1m1[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 1.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());

    Player->advanceQuestState("lib/tests/support/quests/fakeQuestItem.c", "met the king");
    Player->advanceQuestState("lib/tests/support/quests/fakeQuestItem.c", "serve the king");

    command("1", Player);
    command("1", Player);
    ExpectEq("[0;36mQuest - [0m[0;37;1mDetails:[0m\n"
        "[0;33mName[0m:  [0;33;1mHail to the king, baby![0m\n"
        "[0;36m[0;36mI've been asked to meet the king! I met King Tantor the Unclean\n"
        "of Thisplace. He seems to like me. The king asked me - ME - to be his personal\n"
        "manservant. Yay me![0m[0m\n[0m\n"
        "\t[[0;31;1m1[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 1.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanViewCompletedTests()
{
    Player->beginQuest("lib/tests/support/quests/anotherQuest.c");
    Player->beginQuest("lib/tests/support/quests/fakeQuestItem.c");
    Player->advanceQuestState("lib/tests/support/quests/fakeQuestItem.c", "met the king");
    Player->advanceQuestState("lib/tests/support/quests/fakeQuestItem.c", "ignore the king");
    Player->executeCommand("quests");
    command("7", Player);

    ExpectEq("[0;36mQuest - [0m[0;37;1mSelect a quest to view in more detail[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mAnother quest       [0m[0;34;1m (*)[0m"
        "\t[[0;31;1m2[0m] - [0;32mHail to the king,...[0m[0;31m (X)[0m\n"
        "\t[[0;31;1m3[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 3.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanViewDetails()
{
    Player->beginQuest("lib/tests/support/quests/anotherQuest.c");
    Player->beginQuest("lib/tests/support/quests/fakeQuestItem.c");
    Player->advanceQuestState("lib/tests/support/quests/fakeQuestItem.c", "met the king");
    Player->advanceQuestState("lib/tests/support/quests/fakeQuestItem.c", "ignore the king");
    Player->executeCommand("quests");
    command("7", Player);
    command("describe 2", Player);

    ExpectSubStringMatch("Hail.*This is the description.*Thisplace.*Failure",
        Player->caughtMessage());
}