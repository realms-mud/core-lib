//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;

string EndBar = "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-+-=-=-=-=-=-=-=-=-=-=-=-=-+-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m";
string TraitsRow = "\x1b[0;31m| \x1b[0m%s%23s\x1b[0m \x1b[0;31m| \x1b[0m%s%23s\x1b[0m \x1b[0;31m| \x1b[0m%s%23s\x1b[0m \x1b[0;31m|\n\x1b[0m";

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
void TopLevelMenuDisplaysCorrectly()
{
    Player->executeCommand("quests");

    ExpectEq("\x1b[0;36mQuest - \x1b[0m\x1b[0;37;1mFrom this menu, you can view your character's available quests\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mBackground          \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mGuild               \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mPrimary             \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mResearch            \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mSecondary           \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mTask                \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m] - \x1b[0;32mCompleted           \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m8\x1b[0m] - \x1b[0;32mExit Quest Menu     \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 8.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
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

    ExpectEq("\x1b[0;36mQuest - \x1b[0m\x1b[0;37;1mFrom this menu, you can view your character's available quests\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mBackground          \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mGuild               \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mPrimary             \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mResearch            \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mSecondary           \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mTask                \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m] - \x1b[0;32mCompleted           \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m8\x1b[0m] - \x1b[0;32mExit Quest Menu     \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 8.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EntriesWithActiveQuestsDoNotShowNoQuests()
{
    Player->beginQuest("lib/tests/support/quests/anotherQuest.c");
    Player->beginQuest("lib/tests/support/quests/fakeQuestItem.c");
    Player->executeCommand("quests");

    ExpectEq("\x1b[0;36mQuest - \x1b[0m\x1b[0;37;1mFrom this menu, you can view your character's available quests\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mBackground          \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mGuild               \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mPrimary             \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mResearch            \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mSecondary           \x1b[0m\n"
        "\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mTask                \x1b[0m\x1b[0;31m(No quests)\x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m] - \x1b[0;32mCompleted           \x1b[0m\n"
        "\t[\x1b[0;31;1m8\x1b[0m] - \x1b[0;32mExit Quest Menu     \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 8.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingOptionWithQuestsDisplaysSubmenu()
{
    Player->beginQuest("lib/tests/support/quests/anotherQuest.c");
    Player->beginQuest("lib/tests/support/quests/fakeQuestItem.c");
    Player->executeCommand("quests");
    command("5", Player);

    ExpectEq("\x1b[0;36mQuest - \x1b[0m\x1b[0;37;1mSelect a quest to view in more detail\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mHail to the king,...\x1b[0m\x1b[0;35m (!)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 2.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
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

    ExpectEq("\x1b[0;36mQuest - \x1b[0m\x1b[0;37;1mDetails:\n"
        "\x1b[0;33mName:  \x1b[0m\x1b[0;33;1mHail to the king, baby!\x1b[0m\n"
        "\x1b[0;36m\x1b[0;36mI've been asked to meet the king!\n\x1b[0m\x1b[0m\n\x1b[0m\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 1.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());

    Player->advanceQuestState("lib/tests/support/quests/fakeQuestItem.c", "met the king");
    Player->advanceQuestState("lib/tests/support/quests/fakeQuestItem.c", "serve the king");

    command("1", Player);
    command("1", Player);
    ExpectEq("\x1b[0;36mQuest - \x1b[0m\x1b[0;37;1mDetails:\n"
        "\x1b[0;33mName:  \x1b[0m\x1b[0;33;1mHail to the king, baby!\x1b[0m\n"
        "\x1b[0;36m\x1b[0;36mI've been asked to meet the king! I met King Tantor the Unclean of\n"
        "Thisplace. He seems to like me. The king asked me - ME - to be his personal\n"
        "manservant. Yay me!\n\x1b[0m\x1b[0m\n\x1b[0m\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 1.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
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

    ExpectEq("\x1b[0;36mQuest - \x1b[0m\x1b[0;37;1mSelect a quest to view in more detail\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mAnother quest       \x1b[0m\x1b[0;34;1m (*)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mHail to the king,...\x1b[0m\x1b[0;31m (X)\x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
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

/////////////////////////////////////////////////////////////////////////////
void CanDisplayUnicode()
{
    Player->charsetConfiguration("unicode");
    Player->colorConfiguration("8-bit");
    Player->beginQuest("lib/tests/support/quests/anotherQuest.c");
    Player->beginQuest("lib/tests/support/quests/fakeQuestItem.c");
    Player->advanceQuestState("lib/tests/support/quests/fakeQuestItem.c", "met the king");
    Player->advanceQuestState("lib/tests/support/quests/fakeQuestItem.c", "ignore the king");
    Player->executeCommand("quests");
    command("7", Player);

    ExpectEq("\x1b[0;38;5;80mQuest - \x1b[0m\x1b[0;38;5;15;1mSelect a quest to view in more detail\x1b[0m:\n"
        "\t[\x1b[0;38;5;9;1m1\x1b[0m] - \x1b[0;38;5;2mAnother quest       \x1b[0m\x1b[0;38;5;20;1m (\xe2\x98\x85)\x1b[0m"
        "\t[\x1b[0;38;5;9;1m2\x1b[0m] - \x1b[0;38;5;2mHail to the king,...\x1b[0m\x1b[0;38;5;124m (\xe2\x95\xb3)\x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m3\x1b[0m] - \x1b[0;38;5;2mReturn to previous menu\x1b[0m\n"
        "\x1b[0;38;5;2;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;38;5;144mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;38;5;144mFor details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n\x1b[0m\x1b[0;38;5;2;1m\x1b[0m",
        Player->caughtMessage());
}