//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

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
    Selector->showTreeElements();
    Selector->initiateSelector(Player);

    command("2", Player);

    ExpectEq("\x1b[0;36mResearch - \x1b[0m\x1b[0;37;1mSelect a research item to view in more detail\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mTree of researchi...\x1b[0m\x1b[0;32;1m (T)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mFlambe-maker        \x1b[0m\x1b[0;31m (X)\x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mGrebe of obstinance \x1b[0m\x1b[0;31m (X)\x1b[0m"
        "\t[\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mGrog's revenge      \x1b[0m\x1b[0;31m (X)\x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mHand of fist        \x1b[0m"
        "\t[\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mTurnip seclusion    \x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mWeasel inversion    \x1b[0m"
        "\t[\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mZap thingy          \x1b[0m\x1b[0;31m (X)\x1b[0m\n"
        "\t[\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mZorlak's revenge    \x1b[0m"
        "\t[\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mMock research       \x1b[0m\x1b[0;35m (!)\x1b[0m\n"
        "\t[\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mIntox research      \x1b[0m\x1b[0;34;1m (*)\x1b[0m"
        "\t[\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mSpiffy tree root    \x1b[0m\x1b[0;34;1m (*)\x1b[0m\n"
        "\t[\x1b[0;31;1m13\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 13.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m"
        "\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes already-chosen research, "
        "\x1b[0m\x1b[0;32;1m(T)\x1b[0m\x1b[0;32m denotes an available research tree,\n"
        "\x1b[0m\x1b[0;35m(!)\x1b[0m\x1b[0;32m denotes research in progress, and "
        "\x1b[0m\x1b[0;31m(X)\x1b[0m\x1b[0;32m indicates that learning this research\n"
        "requires prerequisites that are missing - view description for details.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchDetailsAreShownWhenResearchItemWithModifierIsSelected()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);
    command("11", Player);

    ExpectEq("\x1b[0;36mResearch - \x1b[0m\x1b[0;37;1mDetails:\n"
        "\x1b[0;36mResearch Name   : \x1b[0m\x1b[0;33mZorlak's revenge\n"
        "\x1b[0m\x1b[0;33mThis is limited active research\n\n"
        "\x1b[0m\x1b[0;33mLearning this costs 1 research point.\n"
        "\x1b[0m\x1b[0;36mResearch Type   : \x1b[0m\x1b[0;33mActive\n"
        "\x1b[0m\x1b[0;36mScope           : \x1b[0m\x1b[0;33mTargeted\n"
        "\x1b[0m\x1b[0;36mCost to use     : \x1b[0m\x1b[0;33m1 spell points\n"
        "\x1b[0m\x1b[0;36mUsage cooldown  : \x1b[0m\x1b[0;33m4 seconds\n"
        "\x1b[0m\x1b[0;36mCommand syntax  : \x1b[0m\x1b[0;33m\x1b[0;36mthrow turnip [at \x1b[0;33m<Target>\x1b[0m\x1b[0;36m]\x1b[0m\x1b[0m\n"
        "                  \x1b[0;36mhurl turnip [at \x1b[0;33m<Target>\x1b[0m\x1b[0;36m]\x1b[0m\x1b[0m\n"
        "\x1b[0m\x1b[0;36mUsage effect    : \x1b[0m\x1b[0;33m80% chance to increase hit points 25 - 50\n"
        "\x1b[0m\x1b[0;36mUsage effect    : \x1b[0m\x1b[0;33m20% chance to increase hit points 35 - 60\n"
        "\x1b[0m\x1b[0;33m                  Modified -> \x1b[0m\x1b[0;34;1m1.25 * your long sword skill \x1b[0m\x1b[0;31;1m(additive)\n"
        "\x1b[0m\x1b[0;33m                  Modified -> \x1b[0m\x1b[0;34;1m0.25 * your strength attribute \x1b[0m\x1b[0;31;1m(subtractive)\n"
        "\x1b[0m\x1b[0;36mThis is only applied when you're using: long sword.\n\x1b[0m"
        "\x1b[0;36mPrerequisites:\n\x1b[0m"
        "\x1b[0;33m          Skill: \x1b[0m\x1b[0;35mLong sword of 10\n\x1b[0m"
        "\x1b[0;36mResearch Prereqs : \x1b[0;34;1mSpiffy tree root\x1b[0m\n"
        "\x1b[0m\x1b[0m\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 1.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "\x1b[0m\x1b[0;32;1m"
        "\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes already-chosen research, "
        "\x1b[0m\x1b[0;32;1m(T)\x1b[0m\x1b[0;32m denotes an available research tree,\n"
        "\x1b[0m\x1b[0;35m(!)\x1b[0m\x1b[0;32m denotes research in progress, and "
        "\x1b[0m\x1b[0;31m(X)\x1b[0m\x1b[0;32m indicates that learning this research\n"
        "requires prerequisites that are missing - view description for details.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void OptionToBeginResearchShownWhenLearningIsPossible()
{
    Player->addResearchPoints(1);
    Selector->initiateSelector(Player);
    command("1", Player);
    command("12", Player);

    ExpectSubStringMatch("You have 1 research point left to assign.",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeAsQuestionMarkShowsResearchDetails()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);
    command("? 11", Player);

    ExpectEq("\x1b[0;36m\x1b[0;36mResearch Name   : \x1b[0m\x1b[0;33mZorlak's revenge\n"
        "\x1b[0m\x1b[0;33mThis is limited active research\n\n"
        "\x1b[0m\x1b[0;33mLearning this costs 1 research point.\n"
        "\x1b[0m\x1b[0;36mResearch Type   : \x1b[0m\x1b[0;33mActive\n"
        "\x1b[0m\x1b[0;36mScope           : \x1b[0m\x1b[0;33mTargeted\n"
        "\x1b[0m\x1b[0;36mCost to use     : \x1b[0m\x1b[0;33m1 spell points\n"
        "\x1b[0m\x1b[0;36mUsage cooldown  : \x1b[0m\x1b[0;33m4 seconds\n"
        "\x1b[0m\x1b[0;36mCommand syntax  : \x1b[0m\x1b[0;33m\x1b[0;36mthrow turnip [at \x1b[0;33m<Target>\x1b[0m\x1b[0;36m]\x1b[0m\x1b[0m\n"
        "                  \x1b[0;36mhurl turnip [at \x1b[0;33m<Target>\x1b[0m\x1b[0;36m]\x1b[0m\x1b[0m\n"
        "\x1b[0m\x1b[0;36mUsage effect    : \x1b[0m\x1b[0;33m80% chance to increase hit points 25 - 50\n"
        "\x1b[0m\x1b[0;36mUsage effect    : \x1b[0m\x1b[0;33m20% chance to increase hit points 35 - 60\n"
        "\x1b[0m\x1b[0;33m                  Modified -> \x1b[0m\x1b[0;34;1m1.25 * your long sword skill \x1b[0m\x1b[0;31;1m(additive)\n"
        "\x1b[0m\x1b[0;33m                  Modified -> \x1b[0m\x1b[0;34;1m0.25 * your strength attribute \x1b[0m\x1b[0;31;1m(subtractive)\n"
        "\x1b[0m\x1b[0;36mThis is only applied when you're using: long sword.\n\x1b[0m"
        "\x1b[0;36mPrerequisites:\n\x1b[0m"
        "\x1b[0;33m          Skill: \x1b[0m\x1b[0;35mLong sword of 10\n\x1b[0m"
        "\x1b[0;36mResearch Prereqs : \x1b[0;34;1mSpiffy tree root\x1b[0m\n"
        "\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeShowsResearchDetails()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);
    command("4", Player);

    ExpectEq("\x1b[0;36mResearch - \x1b[0m\x1b[0;37;1mDetails:\n"
        "\x1b[0;36mResearch Name   : \x1b[0m\x1b[0;33mGrog's revenge\n"
        "\x1b[0m\x1b[0;33mThis is a description\n\n"
        "\x1b[0m\x1b[0;33mLearning this costs 1 research point.\n"
        "\x1b[0m\x1b[0;36mResearch Type   : \x1b[0m\x1b[0;33mPassive\n"
        "\x1b[0m\x1b[0;36mScope           : \x1b[0m\x1b[0;33mSelf\n"
        "\x1b[0m\x1b[0;34;1m                  (+2) \x1b[0m\x1b[0;33mBonus long sword\n"
        "\x1b[0m\x1b[0;36mResearch Prereqs : \x1b[0;31mZap thingy\x1b[0m\x1b[0;33m and \x1b[0m\x1b[0;31mGrebe of obstinance\x1b[0m\n"
        "\x1b[0m\x1b[0m\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 1.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "\x1b[0m\x1b[0;32;1m"
        "\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes already-chosen research, "
        "\x1b[0m\x1b[0;32;1m(T)\x1b[0m\x1b[0;32m denotes an available research tree,\n"
        "\x1b[0m\x1b[0;35m(!)\x1b[0m\x1b[0;32m denotes research in progress, and "
        "\x1b[0m\x1b[0;31m(X)\x1b[0m\x1b[0;32m indicates that learning this research\n"
        "requires prerequisites that are missing - view description for details.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchInProcessOfBeingResearchedShowsTimeLeft()
{
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearchTimed.c"), "d");
    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);
    command("7", Player);

    ExpectSubStringMatch("You still have another 9 seconds before research is completed.",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchTreesAreProperlyDisplayed()
{
    Player->addResearchPoints(1);
    Player->charsetConfiguration("unicode");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearchTimed.c"), "d");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/itemWithModifier.c"), "d");
    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);

    ExpectEq("\x1b[0;36mResearch - \x1b[0m\x1b[0;37;1mDetails:\n"
        "\x1b[0;36mResearch Tree   : \x1b[0m\x1b[0;33mTree of researchiness\n"
        "\x1b[0m\x1b[0;33mthis is the land-loving mother pigeon of all research trees\n\n"
        "\x1b[0m\x1b[0;33mThe tree offers the following research items:\n"
        "\x1b[0m\x1b[0;30;1m\x1b[0m\x1b[0;34;1mSpiffy tree root\n"
        "\x1b[0m\x1b[0;30;1m\xe2\x95\x98\xe2\x95\x90\xe2\x87\x92 \x1b[0m\x1b[0;33mIntox research\n"
        "\x1b[0m\x1b[0;30;1m  \xe2\x95\x98\xe2\x95\x90\xe2\x87\x92 \x1b[0m\x1b[0;31mHand of fist\n"
        "\x1b[0m\x1b[0;30;1m  \xe2\x95\x98\xe2\x95\x90\xe2\x87\x92 \x1b[0m\x1b[0;31mGrebe of obstinance\n"
        "\x1b[0m\x1b[0;30;1m        \xe2\x95\x98\xe2\x95\x90\xe2\x87\x92 \x1b[0m\x1b[0;31mGrog's revenge\n"
        "\x1b[0m\x1b[0;30;1m\xe2\x95\x98\xe2\x95\x90\xe2\x87\x92 \x1b[0m\x1b[0;34;1mZorlak's revenge\n"
        "\x1b[0m\x1b[0;30;1m\xe2\x95\x98\xe2\x95\x90\xe2\x87\x92 \x1b[0m\x1b[0;35mMock research\n"
        "\x1b[0m\x1b[0;30;1m\xe2\x95\x98\xe2\x95\x90\xe2\x87\x92 \x1b[0m\x1b[0;33mWeasel inversion\n"
        "\x1b[0m\x1b[0;30;1m\xe2\x95\x98\xe2\x95\x90\xe2\x87\x92 \x1b[0m\x1b[0;33mTurnip seclusion\n"
        "\x1b[0m\x1b[0;30;1m  \xe2\x95\x98\xe2\x95\x90\xe2\x87\x92 \x1b[0m\x1b[0;31mGrebe of obstinance\n"
        "\x1b[0m\x1b[0;30;1m        \xe2\x95\x98\xe2\x95\x90\xe2\x87\x92 \x1b[0m\x1b[0;31mGrog's revenge\n"
        "\x1b[0m\x1b[0;30;1m  \xe2\x95\x98\xe2\x95\x90\xe2\x87\x92 \x1b[0m\x1b[0;31mZap thingy\n"
        "\x1b[0m\x1b[0;30;1m        \xe2\x95\x98\xe2\x95\x90\xe2\x87\x92 \x1b[0m\x1b[0;31mFlambe-maker\n"
        "\x1b[0m\x1b[0;30;1m        \xe2\x95\x98\xe2\x95\x90\xe2\x87\x92 \x1b[0m\x1b[0;31mGrog's revenge\n"
        "\x1b[0m\x1b[0m\n"
        "\t[\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mSpiffy tree root    \x1b[0m\x1b[0;34;1m (\xe2\x98\x85)\x1b[0m\t[\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mFlambe-maker        \x1b[0m\x1b[0;31m (\xe2\x95\xb3)\x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mGrebe of obstinance \x1b[0m\x1b[0;31m (\xe2\x95\xb3)\x1b[0m\t[\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mGrog's revenge      \x1b[0m\x1b[0;31m (\xe2\x95\xb3)\x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mHand of fist        \x1b[0m\x1b[0;31m (\xe2\x95\xb3)\x1b[0m\t[\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mIntox research      \x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mMock research       \x1b[0m\x1b[0;35m (\xe2\x8c\x9b)\x1b[0m\t[\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mTurnip seclusion    \x1b[0m\n"
        "\t[\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mWeasel inversion    \x1b[0m\t[\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mZap thingy          \x1b[0m\x1b[0;31m (\xe2\x95\xb3)\x1b[0m\n"
        "\t[\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mZorlak's revenge    \x1b[0m\x1b[0;34;1m (\xe2\x98\x85)\x1b[0m\t[\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 12.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "\x1b[0m\x1b[0;32;1m"
        "\x1b[0;34;1m(\xe2\x98\x85)\x1b[0m\x1b[0;32m denotes already-chosen research, "
        "\x1b[0m\x1b[0;32;1m(\xe2\x87\xa8)\x1b[0m\x1b[0;32m denotes an available research tree,\n"
        "\x1b[0m\x1b[0;35m(\xe2\x8c\x9b)\x1b[0m\x1b[0;32m denotes research in progress, and "
        "\x1b[0m\x1b[0;31m(\xe2\x95\xb3)\x1b[0m\x1b[0;32m indicates that learning this research\n"
        "requires prerequisites that are missing - view description for details.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingToLearnResearchWhenPointsAvailableResearchesItem()
{
    Player->addResearchPoints(1);
    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);
    command("11", Player);
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
    command("1", Player);
    command("8", Player);
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

    command("1", Player);
    command("1", Player);

    ExpectSubStringMatch("Mock research", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchDisplaysNoColorCorrectly()
{
    Player->colorConfiguration("none");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testLimitedByIntoxResearchItem.c"), "b");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearch.c"), "c");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearchTimed.c"), "d");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"));
    Selector->showTreeElements();
    Selector->initiateSelector(Player);

    command("2", Player);

    ExpectEq("Research - Select a research item to view in more detail:\n"
        "\t[1]  - Tree of researchi... (T)"
        "\t[2]  - Flambe-maker         (X)\n"
        "\t[3]  - Grebe of obstinance  (X)"
        "\t[4]  - Grog's revenge       (X)\n"
        "\t[5]  - Hand of fist        "
        "\t[6]  - Turnip seclusion    \n"
        "\t[7]  - Weasel inversion    "
        "\t[8]  - Zap thingy           (X)\n"
        "\t[9]  - Zorlak's revenge    "
        "\t[10] - Mock research        (!)\n"
        "\t[11] - Intox research       (*)"
        "\t[12] - Spiffy tree root     (*)\n"
        "\t[13] - Return to previous menu\n"
        "You must select a number from 1 to 13.\n"
        "Type 'exit' if you do not wish to make a selection at this time.\n"
        "For details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n"
        "(*) denotes already-chosen research, "
        "(T) denotes an available research tree,\n"
        "(!) denotes research in progress, and "
        "(X) indicates that learning this research\n"
        "requires prerequisites that are missing - view description for details.\n",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchDisplaysThreeBitColorCorrectly()
{
    Player->colorConfiguration("3-bit");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testLimitedByIntoxResearchItem.c"), "b");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearch.c"), "c");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearchTimed.c"), "d");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"));
    Selector->showTreeElements();
    Selector->initiateSelector(Player);

    command("2", Player);

    ExpectEq("\x1b[0;36mResearch - \x1b[0m\x1b[0;37;1mSelect a research item to view in more detail\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mTree of researchi...\x1b[0m\x1b[0;32;1m (T)\x1b[0m"
        "\t[\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mFlambe-maker        \x1b[0m\x1b[0;31m (X)\x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mGrebe of obstinance \x1b[0m\x1b[0;31m (X)\x1b[0m"
        "\t[\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mGrog's revenge      \x1b[0m\x1b[0;31m (X)\x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mHand of fist        \x1b[0m"
        "\t[\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mTurnip seclusion    \x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mWeasel inversion    \x1b[0m"
        "\t[\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mZap thingy          \x1b[0m\x1b[0;31m (X)\x1b[0m\n"
        "\t[\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mZorlak's revenge    \x1b[0m"
        "\t[\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mMock research       \x1b[0m\x1b[0;35m (!)\x1b[0m\n"
        "\t[\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mIntox research      \x1b[0m\x1b[0;34;1m (*)\x1b[0m"
        "\t[\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mSpiffy tree root    \x1b[0m\x1b[0;34;1m (*)\x1b[0m\n"
        "\t[\x1b[0;31;1m13\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 13.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m"
        "\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes already-chosen research, "
        "\x1b[0m\x1b[0;32;1m(T)\x1b[0m\x1b[0;32m denotes an available research tree,\n"
        "\x1b[0m\x1b[0;35m(!)\x1b[0m\x1b[0;32m denotes research in progress, and "
        "\x1b[0m\x1b[0;31m(X)\x1b[0m\x1b[0;32m indicates that learning this research\n"
        "requires prerequisites that are missing - view description for details.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchDisplaysEightBitColorCorrectly()
{
    Player->colorConfiguration("8-bit");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testLimitedByIntoxResearchItem.c"), "b");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearch.c"), "c");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearchTimed.c"), "d");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"));
    Selector->showTreeElements();
    Selector->initiateSelector(Player);

    command("2", Player);

    ExpectEq("\x1b[0;38;5;80mResearch - \x1b[0m\x1b[0;38;5;15;1mSelect a research item to view in more detail\x1b[0m:\n"
        "\t[\x1b[0;38;5;9;1m1\x1b[0m]  - \x1b[0;38;5;2mTree of researchi...\x1b[0m\x1b[0;38;5;149;1m (T)\x1b[0m"
        "\t[\x1b[0;38;5;9;1m2\x1b[0m]  - \x1b[0;38;5;2mFlambe-maker        \x1b[0m\x1b[0;38;5;9m (X)\x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m3\x1b[0m]  - \x1b[0;38;5;2mGrebe of obstinance \x1b[0m\x1b[0;38;5;9m (X)\x1b[0m"
        "\t[\x1b[0;38;5;9;1m4\x1b[0m]  - \x1b[0;38;5;2mGrog's revenge      \x1b[0m\x1b[0;38;5;9m (X)\x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m5\x1b[0m]  - \x1b[0;38;5;2mHand of fist        \x1b[0m"
        "\t[\x1b[0;38;5;9;1m6\x1b[0m]  - \x1b[0;38;5;2mTurnip seclusion    \x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m7\x1b[0m]  - \x1b[0;38;5;2mWeasel inversion    \x1b[0m"
        "\t[\x1b[0;38;5;9;1m8\x1b[0m]  - \x1b[0;38;5;2mZap thingy          \x1b[0m\x1b[0;38;5;9m (X)\x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m9\x1b[0m]  - \x1b[0;38;5;2mZorlak's revenge    \x1b[0m"
        "\t[\x1b[0;38;5;9;1m10\x1b[0m] - \x1b[0;38;5;2mMock research       \x1b[0m\x1b[0;38;5;31m (!)\x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m11\x1b[0m] - \x1b[0;38;5;2mIntox research      \x1b[0m\x1b[0;38;5;20;1m (*)\x1b[0m"
        "\t[\x1b[0;38;5;9;1m12\x1b[0m] - \x1b[0;38;5;2mSpiffy tree root    \x1b[0m\x1b[0;38;5;20;1m (*)\x1b[0m\n"
        "\t[\x1b[0;38;5;9;1m13\x1b[0m] - \x1b[0;38;5;2mReturn to previous menu\x1b[0m\n"
        "\x1b[0;38;5;2;1mYou must select a number from 1 to 13.\n\x1b[0m"
        "\x1b[0;38;5;144mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;38;5;144mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;38;5;2;1m"
        "\x1b[0;38;5;20;1m(*)\x1b[0m\x1b[0;38;5;144m denotes already-chosen research, "
        "\x1b[0m\x1b[0;38;5;149;1m(T)\x1b[0m\x1b[0;38;5;144m denotes an available research tree,\n"
        "\x1b[0m\x1b[0;38;5;31m(!)\x1b[0m\x1b[0;38;5;144m denotes research in progress, and "
        "\x1b[0m\x1b[0;38;5;9m(X)\x1b[0m\x1b[0;38;5;144m indicates that learning this research\n"
        "requires prerequisites that are missing - view description for details.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchDisplaysTwentyFourBitColorCorrectly()
{
    Player->colorConfiguration("24-bit");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testLimitedByIntoxResearchItem.c"), "b");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearch.c"), "c");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/mockResearchTimed.c"), "d");
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/testGrantedResearchItem.c"));
    Selector->showTreeElements();
    Selector->initiateSelector(Player);

    command("2", Player);

    ExpectEq("\x1b[0;38;2;180;180;190mResearch - \x1b[0m\x1b[0;38;2;255;255;255;1mSelect a research item to view in more detail\x1b[0m:\n"
        "\t[\x1b[0;38;2;220;40;0;1m1\x1b[0m]  - \x1b[0;38;2;170;180;110mTree of researchi...\x1b[0m\x1b[0;38;2;100;220;150;1m (T)\x1b[0m"
        "\t[\x1b[0;38;2;220;40;0;1m2\x1b[0m]  - \x1b[0;38;2;170;180;110mFlambe-maker        \x1b[0m\x1b[0;38;2;200;0;0m (X)\x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m3\x1b[0m]  - \x1b[0;38;2;170;180;110mGrebe of obstinance \x1b[0m\x1b[0;38;2;200;0;0m (X)\x1b[0m"
        "\t[\x1b[0;38;2;220;40;0;1m4\x1b[0m]  - \x1b[0;38;2;170;180;110mGrog's revenge      \x1b[0m\x1b[0;38;2;200;0;0m (X)\x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m5\x1b[0m]  - \x1b[0;38;2;170;180;110mHand of fist        \x1b[0m"
        "\t[\x1b[0;38;2;220;40;0;1m6\x1b[0m]  - \x1b[0;38;2;170;180;110mTurnip seclusion    \x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m7\x1b[0m]  - \x1b[0;38;2;170;180;110mWeasel inversion    \x1b[0m"
        "\t[\x1b[0;38;2;220;40;0;1m8\x1b[0m]  - \x1b[0;38;2;170;180;110mZap thingy          \x1b[0m\x1b[0;38;2;200;0;0m (X)\x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m9\x1b[0m]  - \x1b[0;38;2;170;180;110mZorlak's revenge    \x1b[0m"
        "\t[\x1b[0;38;2;220;40;0;1m10\x1b[0m] - \x1b[0;38;2;170;180;110mMock research       \x1b[0m\x1b[0;38;2;80;155;175m (!)\x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m11\x1b[0m] - \x1b[0;38;2;170;180;110mIntox research      \x1b[0m\x1b[0;38;2;0;0;220;1m (*)\x1b[0m"
        "\t[\x1b[0;38;2;220;40;0;1m12\x1b[0m] - \x1b[0;38;2;170;180;110mSpiffy tree root    \x1b[0m\x1b[0;38;2;0;0;220;1m (*)\x1b[0m\n"
        "\t[\x1b[0;38;2;220;40;0;1m13\x1b[0m] - \x1b[0;38;2;170;180;110mReturn to previous menu\x1b[0m\n"
        "\x1b[0;38;2;160;220;60;1mYou must select a number from 1 to 13.\n\x1b[0m"
        "\x1b[0;38;2;100;180;150mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;38;2;100;180;150mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;38;2;160;220;60;1m"
        "\x1b[0;38;2;0;0;220;1m(*)\x1b[0m\x1b[0;38;2;100;180;150m denotes already-chosen research, "
        "\x1b[0m\x1b[0;38;2;100;220;150;1m(T)\x1b[0m\x1b[0;38;2;100;180;150m denotes an available research tree,\n"
        "\x1b[0m\x1b[0;38;2;80;155;175m(!)\x1b[0m\x1b[0;38;2;100;180;150m denotes research in progress, and "
        "\x1b[0m\x1b[0;38;2;200;0;0m(X)\x1b[0m\x1b[0;38;2;100;180;150m indicates that learning this research\n"
        "requires prerequisites that are missing - view description for details.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}
