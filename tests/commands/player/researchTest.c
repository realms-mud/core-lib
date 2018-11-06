//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

string EndBar = "\x1b[0;31m+-=-=-=-=-=-=-=-=-=-=-=-=-+-=-=-=-=-=-=-=-=-=-=-=-=-+-=-=-=-=-=-=-=-=-=-=-=-=-+\n\x1b[0m";
string TraitsRow = "\x1b[0;31m| \x1b[0m%s%23s\x1b[0m \x1b[0;31m| \x1b[0m%s%23s\x1b[0m \x1b[0;31m| \x1b[0m%s%23s\x1b[0m \x1b[0;31m|\n\x1b[0m";

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->Str(20);
    Player->addSkillPoints(100);
    Player->advanceSkill("long sword", 10);
    Player->addCommands();
    Player->addResearchTree("lib/tests/support/research/testDeepResearchTree.c");

    Selector = clone_object("/lib/modules/research/researchSelector.c");
    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Selector);
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelResearchMenuDisplaysCorrectly()
{
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testLimitedByIntoxResearchItem.c"), "b");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearch.c"), "c");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearchTimed.c"), "d");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"));
    Selector->initiateSelector(Player);

    ExpectEq("\x1b[0;36mResearch - \x1b[0m\x1b[0;37;1mFrom this menu, you can view your character's known research\nas well as initiate new research\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mFighter guild       \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mMage guild          \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mQuests              \x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mExit Research Menu  \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 4.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchSubmenuDisplaysCorrectly()
{
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testLimitedByIntoxResearchItem.c"), "b");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearch.c"), "c");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearchTimed.c"), "d");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"));
    Selector->initiateSelector(Player);

    command("2", Player);

    ExpectEq("\x1b[0;36mResearch - \x1b[0m\x1b[0;37;1mSelect a research item to view in more detail\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mMock research       \x1b[0m\x1b[0;35m (!)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mIntox research      \x1b[0m\x1b[0;34;1m (*)\x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mSpiffy tree root    \x1b[0m\x1b[0;34;1m (*)\x1b[0m"
        "\t[\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mTree of researchi...\x1b[0m\x1b[0;34;1m (*)\x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mFlambe-maker        \x1b[0m\x1b[0;31m (X)\x1b[0m"
        "\t[\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mGrebe of obstinance \x1b[0m\x1b[0;31m (X)\x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mGrog's revenge      \x1b[0m\x1b[0;31m (X)\x1b[0m"
        "\t[\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mHand of fist        \x1b[0m\n"
        "\t[\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mTurnip seclusion    \x1b[0m"
        "\t[\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mWeasel inversion    \x1b[0m\n"
        "\t[\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mZap thingy          \x1b[0m\x1b[0;31m (X)\x1b[0m"
        "\t[\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mZorlak's revenge    \x1b[0m\n"
        "\t[\x1b[0;31;1m13\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 13.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m"
        "\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes already-chosen research while "
        "\x1b[0;35m(!)\x1b[0m\x1b[0;32m denotes research in progress.\nResearch denoted "
        "\x1b[0;31m(X)\x1b[0m\x1b[0;32m cannot yet be learned - view description for details.\x1b[0m\n\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchDetailsAreShownWhenResearchItemWithModifierIsSelected()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("12", Player);

    ExpectEq("\x1b[0;36mResearch - \x1b[0m\x1b[0;37;1mDetails:\x1b[0m\n"
        "\x1b[0;36mResearch Name  \x1b[0m : \x1b[0;33mZorlak's revenge\x1b[0m\n"
        "\x1b[0;33mThis is limited active research\n"
        "\x1b[0m\x1b[0;33mLearning this costs 1 research points.\n"
        "\x1b[0m\x1b[0;36mResearch Type  \x1b[0m : \x1b[0;33mActive\x1b[0m\n"
        "\x1b[0;36mScope          \x1b[0m : \x1b[0;33mTargeted\x1b[0m\n"
        "\x1b[0;36mCost to use    \x1b[0m : \x1b[0;33m1 spell points\x1b[0m\n"
        "\x1b[0;36mUsage cooldown \x1b[0m : \x1b[0;33m4 seconds\x1b[0m\n"
        "\x1b[0;36mCommand syntax \x1b[0m : \x1b[0;36mthrow turnip [at \x1b[0;33m<Target>\x1b[0m\x1b[0;36m]\x1b[0m\n"
        "                  \x1b[0;36mhurl turnip [at \x1b[0;33m<Target>\x1b[0m\x1b[0;36m]\x1b[0m\n"
        "\x1b[0;36mUsage effect   \x1b[0m : \x1b[0;33m80% chance to increase hit points 25 - 50\x1b[0m\n"
        "                  \x1b[0;32mModified -> \x1b[0;34;1m1.25 * your long sword skill\x1b[0m \x1b[0;31;1m(additive)\x1b[0m\n"
        "                  \x1b[0;32mModified -> \x1b[0;34;1m0.25 * your strength attribute\x1b[0m \x1b[0;31;1m(subtractive)\x1b[0m\n"
        "\x1b[0;36mUsage effect   \x1b[0m : \x1b[0;33m20% chance to increase hit points 35 - 60\x1b[0m\n"
        "                  \x1b[0;32mModified -> \x1b[0;34;1m1.25 * your long sword skill\x1b[0m \x1b[0;31;1m(additive)\x1b[0m\n"
        "                  \x1b[0;32mModified -> \x1b[0;34;1m0.25 * your strength attribute\x1b[0m \x1b[0;31;1m(subtractive)\x1b[0m\n"
        "\x1b[0;36mThis is only applied when you're using: long sword.\x1b[0m\n"
        "\x1b[0;36mPrerequisites:\x1b[0m\n"
        "	\x1b[0;36mSkill\x1b[0m: \x1b[0;35mLong sword of 10\x1b[0m\n"
        "\x1b[0;36mResearch Prereqs\x1b[0m : \x1b[0;34;1mSpiffy tree root\x1b[0m\n"
        "\x1b[0m\n"
        "	[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 1.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "\x1b[0m\x1b[0;32;1m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes already-chosen research while \x1b[0;35m(!)\x1b[0m\x1b[0;32m denotes research in progress.\n"
        "Research denoted \x1b[0;31m(X)\x1b[0m\x1b[0;32m cannot yet be learned - view description for details.\x1b[0m\n"
        "\x1b[0m", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void OptionToBeginResearchShownWhenLearningIsPossible()
{
    Player->addResearchPoints(1);
    Selector->initiateSelector(Player);
    command("1", Player);
    command("12", Player);

    ExpectSubStringMatch("You have 1 research points left to assign.",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeAsQuestionMarkShowsResearchDetails()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("? 12", Player);

    ExpectEq("\x1b[0;36m\x1b[0;36mResearch Name  \x1b[0m : \x1b[0;33mZorlak's revenge\x1b[0m\n"
        "\x1b[0;33mThis is limited active research\n"
        "\x1b[0m\x1b[0;33mLearning this costs 1 research points.\n"
        "\x1b[0m\x1b[0;36mResearch Type  \x1b[0m : \x1b[0;33mActive\x1b[0m\n"
        "\x1b[0;36mScope          \x1b[0m : \x1b[0;33mTargeted\x1b[0m\n"
        "\x1b[0;36mCost to use    \x1b[0m : \x1b[0;33m1 spell points\x1b[0m\n"
        "\x1b[0;36mUsage cooldown \x1b[0m : \x1b[0;33m4 seconds\x1b[0m\n"
        "\x1b[0;36mCommand syntax \x1b[0m : \x1b[0;36mthrow turnip [at \x1b[0;33m<Target>\x1b[0m\x1b[0;36m]\x1b[0m\n"
        "                  \x1b[0;36mhurl turnip [at \x1b[0;33m<Target>\x1b[0m\x1b[0;36m]\x1b[0m\n"
        "\x1b[0;36mUsage effect   \x1b[0m : \x1b[0;33m80% chance to increase hit points 25 - 50\x1b[0m\n"
        "                  \x1b[0;32mModified -> \x1b[0;34;1m1.25 * your long sword skill\x1b[0m \x1b[0;31;1m(additive)\x1b[0m\n"
        "                  \x1b[0;32mModified -> \x1b[0;34;1m0.25 * your strength attribute\x1b[0m \x1b[0;31;1m(subtractive)\x1b[0m\n"
        "\x1b[0;36mUsage effect   \x1b[0m : \x1b[0;33m20% chance to increase hit points 35 - 60\x1b[0m\n"
        "                  \x1b[0;32mModified -> \x1b[0;34;1m1.25 * your long sword skill\x1b[0m \x1b[0;31;1m(additive)\x1b[0m\n"
        "                  \x1b[0;32mModified -> \x1b[0;34;1m0.25 * your strength attribute\x1b[0m \x1b[0;31;1m(subtractive)\x1b[0m\n"
        "\x1b[0;36mThis is only applied when you're using: long sword.\x1b[0m\n"
        "\x1b[0;36mPrerequisites:\x1b[0m\n"
        "	\x1b[0;36mSkill\x1b[0m: \x1b[0;35mLong sword of 10\x1b[0m\n"
        "\x1b[0;36mResearch Prereqs\x1b[0m : \x1b[0;34;1mSpiffy tree root\x1b[0m\n\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeShowsResearchDetails()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("5", Player);

    ExpectEq("\x1b[0;36mResearch - \x1b[0m\x1b[0;37;1mDetails:\x1b[0m\n"
        "\x1b[0;36mResearch Name  \x1b[0m : \x1b[0;33mGrog's revenge\x1b[0m\n"
        "\x1b[0;33mThis is a description\n"
        "\x1b[0m\x1b[0;33mLearning this costs 1 research points.\n"
        "\x1b[0m\x1b[0;36mResearch Type  \x1b[0m : \x1b[0;33mPassive\x1b[0m\n"
        "\x1b[0;36mScope          \x1b[0m : \x1b[0;33mSelf\x1b[0m\n"
        "\x1b[0;34;1m(+2)\x1b[0m \x1b[0;33mBonus Long sword\x1b[0m\n"
        "\x1b[0;36mResearch Prereqs\x1b[0m : \x1b[0;31mZap thingy\x1b[0m\x1b[0;33m and \x1b[0;31mGrebe of obstinance\x1b[0m\n"
        "\x1b[0m\n"
        "	[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 1.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "\x1b[0m\x1b[0;32;1m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes already-chosen research while \x1b[0;35m(!)\x1b[0m\x1b[0;32m denotes research in progress.\n"
        "Research denoted \x1b[0;31m(X)\x1b[0m\x1b[0;32m cannot yet be learned - view description for details.\x1b[0m\n"
        "\x1b[0m", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchInProcessOfBeingResearchedShowsTimeLeft()
{
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearchTimed.c"), "d");
    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);

    ExpectSubStringMatch("You still have another 9 seconds before research is completed.",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchTreesAreProperlyDisplayed()
{
    Player->addResearchPoints(1);
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearchTimed.c"), "d");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/itemWithModifier.c"), "d");
    Selector->initiateSelector(Player);
    command("1", Player);
    command("4", Player);

    ExpectEq("\x1b[0;36mResearch - \x1b[0m\x1b[0;37;1mDetails:\x1b[0m\n"
        "\x1b[0;36mResearch Tree  \x1b[0m : \x1b[0;33mTree of researchiness\x1b[0m\n"
        "\x1b[0;33mthis is the land-loving mother pigeon of all research trees\x1b[0m\n"
        "\x1b[0;33mThe tree offers the following research items:\x1b[0m\n"
        "\x1b[0;30;1m\x1b[0;34;1mSpiffy tree root\x1b[0m\n"
        "\x1b[0;30;1m  |-- \x1b[0;33mIntox research\x1b[0m\n"
        "\x1b[0;30;1m        |-- \x1b[0;31mHand of fist\x1b[0m\n"
        "\x1b[0;30;1m        |-- \x1b[0;31mGrebe of obstinance\x1b[0m\n"
        "\x1b[0;30;1m              |-- \x1b[0;31mGrog's revenge\x1b[0m\n"
        "\x1b[0;30;1m  |-- \x1b[0;34;1mZorlak's revenge\x1b[0m\n"
        "\x1b[0;30;1m  |-- \x1b[0;35mMock research\x1b[0m\n"
        "\x1b[0;30;1m  |-- \x1b[0;33mWeasel inversion\x1b[0m\n"
        "\x1b[0;30;1m  |-- \x1b[0;33mTurnip seclusion\x1b[0m\n"
        "\x1b[0;30;1m        |-- \x1b[0;31mGrebe of obstinance\x1b[0m\n"
        "\x1b[0;30;1m              |-- \x1b[0;31mGrog's revenge\x1b[0m\n"
        "\x1b[0;30;1m        |-- \x1b[0;31mZap thingy\x1b[0m\n"
        "\x1b[0;30;1m              |-- \x1b[0;31mFlambe-maker\x1b[0m\n"
        "\x1b[0;30;1m              |-- \x1b[0;31mGrog's revenge\x1b[0m\n"
        "\x1b[0m\n"
        "	[\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mSpiffy tree root    \x1b[0m\x1b[0;34;1m (*)\x1b[0m	[\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mFlambe-maker        \x1b[0m\x1b[0;31m (X)\x1b[0m\n"
        "	[\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mGrebe of obstinance \x1b[0m\x1b[0;31m (X)\x1b[0m	[\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mGrog's revenge      \x1b[0m\x1b[0;31m (X)\x1b[0m\n"
        "	[\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mHand of fist        \x1b[0m\x1b[0;31m (X)\x1b[0m	[\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mIntox research      \x1b[0m\n"
        "	[\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mMock research       \x1b[0m\x1b[0;35m (!)\x1b[0m	[\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mTurnip seclusion    \x1b[0m\n"
        "	[\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mWeasel inversion    \x1b[0m	[\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mZap thingy          \x1b[0m\x1b[0;31m (X)\x1b[0m\n"
        "	[\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mZorlak's revenge    \x1b[0m\x1b[0;34;1m (*)\x1b[0m	[\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 12.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "\x1b[0m\x1b[0;32;1m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes already-chosen research while \x1b[0;35m(!)\x1b[0m\x1b[0;32m denotes research in progress.\n"
        "Research denoted \x1b[0;31m(X)\x1b[0m\x1b[0;32m cannot yet be learned - view description for details.\x1b[0m\n"
        "\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingToLearnResearchWhenPointsAvailableResearchesItem()
{
    Player->addResearchPoints(1);
    Selector->initiateSelector(Player);
    command("1", Player);
    command("12", Player);
    ExpectFalse(Player->isResearched("lib/tests/support/research/itemWithModifier.c"));
    ExpectEq(1, Player->researchPoints());
    command("1", Player);
    ExpectTrue(Player->isResearched("lib/tests/support/research/itemWithModifier.c"));
    ExpectEq(0, Player->researchPoints());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingToReturnDoesNotInitiateResearch()
{
    Player->addResearchPoints(1);
    Selector->initiateSelector(Player);
    command("1", Player);
    command("12", Player);
    ExpectFalse(Player->isResearched("lib/tests/support/research/itemWithModifier.c"));
    ExpectEq(1, Player->researchPoints());
    command("2", Player);
    ExpectFalse(Player->isResearched("lib/tests/support/research/itemWithModifier.c"));
    ExpectEq(1, Player->researchPoints());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingToLearnTimedResearchDoesNotUsePointsAndInitiatesResearching()
{
    Player->addResearchPoints(1);
    Selector->initiateSelector(Player);
    command("1", Player);
    command("9", Player);
    ExpectFalse(Player->isResearched("lib/tests/support/research/testResearchB.c"));
    ExpectFalse(Player->isResearching("lib/tests/support/research/testResearchB.c"));
    ExpectEq(1, Player->researchPoints());
    command("1", Player);
    ExpectFalse(Player->isResearched("lib/tests/support/research/testResearchB.c"));
    ExpectTrue(Player->isResearching("lib/tests/support/research/testResearchB.c"));
    ExpectEq(1, Player->researchPoints());
}

/////////////////////////////////////////////////////////////////////////////
void InvalidResearchDoesNotInterfereWithCommand()
{
    Player->initiateResearch("lib/tests/support/research/doesNotExist.c");
    Player->initiateResearch("lib/tests/support/research/mockResearch.c");
    Selector->initiateSelector(Player);

    command("2", Player);

    ExpectSubStringMatch("Mock research", Player->caughtMessage());
}
