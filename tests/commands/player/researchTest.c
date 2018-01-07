//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

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

    ExpectEq("[0;36mResearch - [0m[0;37;1mFrom this menu, you can view your character's known research\nas well as initiate new research[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mFighter guild       [0m\n"
        "\t[[0;31;1m2[0m] - [0;32mMage guild          [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mQuests              [0m\n"
        "\t[[0;31;1m4[0m] - [0;32mExit Research Menu  [0m\n"
        "[0;32;1mYou must select a number from 1 to 4.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
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

    ExpectEq("[0;36mResearch - [0m[0;37;1mSelect a research item to view in more detail[0m:\n"
        "\t[[0;31;1m1[0m]  - [0;32mMock research       [0m[0;35m (!)[0m"
        "\t[[0;31;1m2[0m]  - [0;32mIntox research      [0m[0;34;1m (*)[0m\n"
        "\t[[0;31;1m3[0m]  - [0;32mSpiffy tree root    [0m[0;34;1m (*)[0m"
        "\t[[0;31;1m4[0m]  - [0;32mTree of researchi...[0m[0;34;1m (*)[0m\n"
        "\t[[0;31;1m5[0m]  - [0;32mFlambe-maker        [0m[0;31m (X)[0m"
        "\t[[0;31;1m6[0m]  - [0;32mGrebe of obstinance [0m[0;31m (X)[0m\n"
        "\t[[0;31;1m7[0m]  - [0;32mGrog's revenge      [0m[0;31m (X)[0m"
        "\t[[0;31;1m8[0m]  - [0;32mHand of fist        [0m\n"
        "\t[[0;31;1m9[0m]  - [0;32mTurnip seclusion    [0m"
        "\t[[0;31;1m10[0m] - [0;32mWeasel inversion    [0m\n"
        "\t[[0;31;1m11[0m] - [0;32mZap thingy          [0m[0;31m (X)[0m"
        "\t[[0;31;1m12[0m] - [0;32mZorlak's revenge    [0m\n"
        "\t[[0;31;1m13[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 13.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m"
        "[0;34;1m(*)[0m[0;32;1m denotes already-chosen research while "
        "[0;35m(!)[0m[0;32;1m denotes research in progress.\nResearch denoted "
        "[0;31m(X)[0m[0;32;1m cannot yet be learned - view description for details.[0m\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ResearchDetailsAreShownWhenResearchItemWithModifierIsSelected()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("12", Player);

    ExpectEq("[0;36mResearch - [0m[0;37;1mDetails:[0m\n"
        "[0;36mResearch Name  [0m : [0;33mZorlak's revenge[0m\n"
        "[0;33mThis is limited active research[0m\n"
        "[0;33mLearning this costs 1 research points.\n"
        "[0m[0;36mResearch Type  [0m : [0;33mActive[0m\n"
        "[0;36mScope          [0m : [0;33mTargeted[0m\n"
        "[0;36mCost to use    [0m : [0;33m1 spell points[0m\n"
        "[0;36mUsage cooldown [0m : [0;33m4 seconds[0m\n"
        "[0;36mCommand syntax [0m : [0;30;1mthrow turnip at <Target>\n"
        "                  hurl turnip at <Target>[0m\n"
        "[0;36mUsage effect   [0m : [0;33m80% chance to increase hit points 25 - 50[0m\n"
        "                  [0;32mModified -> [0;34;1m1.25 * your long sword skill[0m [0;31;1m(additive)[0m\n"
        "                  [0;32mModified -> [0;34;1m0.25 * your strength attribute[0m [0;31;1m(subtractive)[0m\n"
        "[0;36mUsage effect   [0m : [0;33m20% chance to increase hit points 35 - 60[0m\n"
        "                  [0;32mModified -> [0;34;1m1.25 * your long sword skill[0m [0;31;1m(additive)[0m\n"
        "                  [0;32mModified -> [0;34;1m0.25 * your strength attribute[0m [0;31;1m(subtractive)[0m\n"
        "[0;36mThis is only applied when you're using: long sword.[0m\n"
        "[0;36mPrerequisites:[0m\n"
        "	[0;36mSkill[0m: [0;35mLong sword of 10[0m\n"
        "[0;36mResearch Prereqs[0m : [0;34;1mSpiffy tree root[0m\n"
        "[0m\n"
        "	[[0;31;1m1[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 1.\n"
        "[0m[0;32mFor details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "[0m[0;32;1m[0;34;1m(*)[0m[0;32;1m denotes already-chosen research while [0;35m(!)[0m[0;32;1m denotes research in progress.\n"
        "Research denoted [0;31m(X)[0m[0;32;1m cannot yet be learned - view description for details.[0m\n"
        "[0m", Player->caughtMessage());
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

    ExpectEq("[0;36m[0;36mResearch Name  [0m : [0;33mZorlak's revenge[0m\n"
        "[0;33mThis is limited active research[0m\n"
        "[0;33mLearning this costs 1 research points.\n"
        "[0m[0;36mResearch Type  [0m : [0;33mActive[0m\n"
        "[0;36mScope          [0m : [0;33mTargeted[0m\n"
        "[0;36mCost to use    [0m : [0;33m1 spell points[0m\n"
        "[0;36mUsage cooldown [0m : [0;33m4 seconds[0m\n"
        "[0;36mCommand syntax [0m : [0;30;1mthrow turnip at <Target>\n"
        "                  hurl turnip at <Target>[0m\n"
        "[0;36mUsage effect   [0m : [0;33m80% chance to increase hit points 25 - 50[0m\n"
        "                  [0;32mModified -> [0;34;1m1.25 * your long sword skill[0m [0;31;1m(additive)[0m\n"
        "                  [0;32mModified -> [0;34;1m0.25 * your strength attribute[0m [0;31;1m(subtractive)[0m\n"
        "[0;36mUsage effect   [0m : [0;33m20% chance to increase hit points 35 - 60[0m\n"
        "                  [0;32mModified -> [0;34;1m1.25 * your long sword skill[0m [0;31;1m(additive)[0m\n"
        "                  [0;32mModified -> [0;34;1m0.25 * your strength attribute[0m [0;31;1m(subtractive)[0m\n"
        "[0;36mThis is only applied when you're using: long sword.[0m\n"
        "[0;36mPrerequisites:[0m\n"
        "	[0;36mSkill[0m: [0;35mLong sword of 10[0m\n"
        "[0;36mResearch Prereqs[0m : [0;34;1mSpiffy tree root[0m\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeShowsResearchDetails()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("5", Player);

    ExpectEq("[0;36mResearch - [0m[0;37;1mDetails:[0m\n"
        "[0;36mResearch Name  [0m : [0;33mGrog's revenge[0m\n"
        "[0;33mThis is a description[0m\n"
        "[0;33mLearning this costs 1 research points.\n"
        "[0m[0;36mResearch Type  [0m : [0;33mPassive[0m\n"
        "[0;36mScope          [0m : [0;33mSelf[0m\n"
        "[0;34;1m(+2)[0m [0;33mBonus Long sword[0m\n"
        "[0;36mResearch Prereqs[0m : [0;31mZap thingy[0m[0;33m and [0;31mGrebe of obstinance[0m\n"
        "[0m\n"
        "	[[0;31;1m1[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 1.\n"
        "[0m[0;32mFor details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "[0m[0;32;1m[0;34;1m(*)[0m[0;32;1m denotes already-chosen research while [0;35m(!)[0m[0;32;1m denotes research in progress.\n"
        "Research denoted [0;31m(X)[0m[0;32;1m cannot yet be learned - view description for details.[0m\n"
        "[0m", Player->caughtMessage());
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

    ExpectEq("[0;36mResearch - [0m[0;37;1mDetails:[0m\n"
        "[0;36mResearch Tree  [0m : [0;33mTree of researchiness[0m\n"
        "[0;33mthis is the land-loving mother pigeon of all research trees[0m\n"
        "[0;33mThe tree offers the following research items:[0m\n"
        "[0;30;1m[0;34;1mSpiffy tree root[0m\n"
        "[0;30;1m  |-- [0;33mIntox research[0m\n"
        "[0;30;1m        |-- [0;31mHand of fist[0m\n"
        "[0;30;1m        |-- [0;31mGrebe of obstinance[0m\n"
        "[0;30;1m              |-- [0;31mGrog's revenge[0m\n"
        "[0;30;1m  |-- [0;34;1mZorlak's revenge[0m\n"
        "[0;30;1m  |-- [0;35mMock research[0m\n"
        "[0;30;1m  |-- [0;33mWeasel inversion[0m\n"
        "[0;30;1m  |-- [0;33mTurnip seclusion[0m\n"
        "[0;30;1m        |-- [0;31mGrebe of obstinance[0m\n"
        "[0;30;1m              |-- [0;31mGrog's revenge[0m\n"
        "[0;30;1m        |-- [0;31mZap thingy[0m\n"
        "[0;30;1m              |-- [0;31mFlambe-maker[0m\n"
        "[0;30;1m              |-- [0;31mGrog's revenge[0m\n"
        "[0m\n"
        "	[[0;31;1m1[0m]  - [0;32mSpiffy tree root    [0m[0;34;1m (*)[0m	[[0;31;1m2[0m]  - [0;32mFlambe-maker        [0m[0;31m (X)[0m\n"
        "	[[0;31;1m3[0m]  - [0;32mGrebe of obstinance [0m[0;31m (X)[0m	[[0;31;1m4[0m]  - [0;32mGrog's revenge      [0m[0;31m (X)[0m\n"
        "	[[0;31;1m5[0m]  - [0;32mHand of fist        [0m[0;31m (X)[0m	[[0;31;1m6[0m]  - [0;32mIntox research      [0m\n"
        "	[[0;31;1m7[0m]  - [0;32mMock research       [0m[0;35m (!)[0m	[[0;31;1m8[0m]  - [0;32mTurnip seclusion    [0m\n"
        "	[[0;31;1m9[0m]  - [0;32mWeasel inversion    [0m	[[0;31;1m10[0m] - [0;32mZap thingy          [0m[0;31m (X)[0m\n"
        "	[[0;31;1m11[0m] - [0;32mZorlak's revenge    [0m[0;34;1m (*)[0m	[[0;31;1m12[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 12.\n"
        "[0m[0;32mFor details on a given choice, type 'describe X' (or '? X') where\n"
        "X is the option about which you would like further details.\n"
        "[0m[0;32;1m[0;34;1m(*)[0m[0;32;1m denotes already-chosen research while [0;35m(!)[0m[0;32;1m denotes research in progress.\n"
        "Research denoted [0;31m(X)[0m[0;32;1m cannot yet be learned - view description for details.[0m\n"
        "[0m",
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