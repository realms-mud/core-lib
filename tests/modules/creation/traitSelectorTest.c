//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void AnswerPersonalityQuestionsTakeFirstChoice(object selector)
{
    while (objectp(selector) && !selector->testTaken())
    {
        selector->applySelection("1");
    }
}

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "AnswerPersonalityQuestionsTakeFirstChoice" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/creation/traitSelector.c");
    Selector->init();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User->Name("Bob");
    User->Race("human");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void InitialCreationDisplayIsCorrect()
{
    Selector->initiateSelector(User);
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mFrom this menu, you can choose your character's traits[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mTake Personality Test[0m\n"
        "\t[[0;31;1m2[0m] - [0;32mEducational Traits  [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mGenetic Traits      [0m\n"
        "\t[[0;31;1m4[0m] - [0;32mHealth Traits       [0m\n"
        "\t[[0;31;1m5[0m] - [0;32mSexuality Traits    [0m\n"
        "\t[[0;31;1m6[0m] - [0;32mExit Trait Selection   [0;31;1m(You will lose unspent trait points!)[0m[0m\n"
        "[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou have 6 trait points left to assign.\nYou have not yet taken the personality test.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingExitFiresOnSelectorCompletedEvent()
{
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(User);
    ExpectEq(0, subscriber->TimesEventReceived());

    Selector->applySelection("6");
    ExpectEq(1, subscriber->TimesEventReceived());
}

/////////////////////////////////////////////////////////////////////////////
void TakingPersonalityTestShowsThatTestIsCompleted()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");

    object personalityTest =
        present_clone("/lib/modules/creation/personalityTraitSelector.c", User);

    ExpectTrue(objectp(personalityTest), "The personality test was added to the player");
    AnswerPersonalityQuestionsTakeFirstChoice(personalityTest);
    ExpectFalse(objectp(personalityTest), "The personality test was cleaned up");

    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mFrom this menu, you can choose your character's traits[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mTake Personality Test[0m[0;34;1m  (Completed)[0m\n"
        "\t[[0;31;1m2[0m] - [0;32mEducational Traits  [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mGenetic Traits      [0m\n"
        "\t[[0;31;1m4[0m] - [0;32mHealth Traits       [0m\n"
        "\t[[0;31;1m5[0m] - [0;32mSexuality Traits    [0m\n"
        "\t[[0;31;1m6[0m] - [0;32mExit Trait Selection   [0;31;1m(You will lose unspent trait points!)[0m[0m\n"
        "[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou have 6 trait points left to assign.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotTakePersonalityTestTwice()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");

    object personalityTest =
        present_clone("/lib/modules/creation/personalityTraitSelector.c", User);

    ExpectTrue(objectp(personalityTest), "The personality test was added to the player");
    AnswerPersonalityQuestionsTakeFirstChoice(personalityTest);
    ExpectFalse(objectp(personalityTest), "The personality test was cleaned up");

    Selector->applySelection("1");
    ExpectFalse(objectp(personalityTest), "The personality test was not created");
}

/////////////////////////////////////////////////////////////////////////////
void EducationalTraitsMenuIsCorrect()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");

    object educationalTraits =
        present_clone("/lib/modules/creation/educationalTraitSelector.c", User);

    ExpectTrue(objectp(educationalTraits), "The educational trait selector was added to the player");

    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mSelect a trait to add[0m:\n"
        "\t[[0;31;1m1[0m]  - [0;32mArcane knowledge    [0m"
        "\t[[0;31;1m2[0m]  - [0;32mArchitect           [0m\n"
        "\t[[0;31;1m3[0m]  - [0;32mArticulate          [0m"
        "\t[[0;31;1m4[0m]  - [0;32mArtisan             [0m\n"
        "\t[[0;31;1m5[0m]  - [0;32mBotanist            [0m"
        "\t[[0;31;1m6[0m]  - [0;32mCultured            [0m\n"
        "\t[[0;31;1m7[0m]  - [0;32mDiplomatic          [0m"
        "\t[[0;31;1m8[0m]  - [0;32mEducated            [0m\n"
        "\t[[0;31;1m9[0m]  - [0;32mErudite             [0m"
        "\t[[0;31;1m10[0m] - [0;32mHunter              [0m\n"
        "\t[[0;31;1m11[0m] - [0;32mMagically barren    [0m"
        "\t[[0;31;1m12[0m] - [0;32mMastermind          [0m\n"
        "\t[[0;31;1m13[0m] - [0;32mPoetic              [0m"
        "\t[[0;31;1m14[0m] - [0;32mPolitician          [0m\n"
        "\t[[0;31;1m15[0m] - [0;32mPoor fighter        [0m"
        "\t[[0;31;1m16[0m] - [0;32mSchemer             [0m\n"
        "\t[[0;31;1m17[0m] - [0;32mScholarly           [0m"
        "\t[[0;31;1m18[0m] - [0;32mSoldier             [0m\n"
        "\t[[0;31;1m19[0m] - [0;32mStrategist          [0m"
        "\t[[0;31;1m20[0m] - [0;32mTactician           [0m\n"
        "\t[[0;31;1m21[0m] - [0;32mTheologian          [0m"
        "\t[[0;31;1m22[0m] - [0;32mThespian            [0m\n"
        "\t[[0;31;1m23[0m] - [0;32mUneducated          [0m"
        "\t[[0;31;1m24[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 24.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou may only select a trait once. [0;34;1m(*)[0m [0;32;1mdenotes an already-chosen trait.\n[0m",
        User->caughtMessage());

    educationalTraits->applySelection("1");
    ExpectTrue(User->isTraitOf("lib/modules/traits/educational/arcane.c"));
}

/////////////////////////////////////////////////////////////////////////////
void EducationalTraitsCanBeSelected()
{
    Selector->initiateSelector(User);

    ExpectSubStringMatch("You have 6 trait points left to assign",
        User->caughtMessage());

    Selector->applySelection("2");

    object educationalTraits =
        present_clone("/lib/modules/creation/educationalTraitSelector.c", User);

    ExpectTrue(objectp(educationalTraits), "The educational trait selector was added to the player");
    educationalTraits->applySelection("1");
    ExpectTrue(User->isTraitOf("lib/modules/traits/educational/arcane.c"));
    ExpectFalse(objectp(educationalTraits), "The educational trait selector test was cleaned up");

    ExpectSubStringMatch("You have 4 trait points left to assign",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GeneticTraitsMenuIsCorrect()
{
    Selector->initiateSelector(User);
    Selector->applySelection("3");

    object geneticTraits =
        present_clone("/lib/modules/creation/geneticTraitSelector.c", User);

    ExpectTrue(objectp(geneticTraits), "The genetic trait selector was added to the player");

    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mSelect a trait to add[0m:\n"
        "\t[[0;31;1m1[0m]  - [0;32mAttractive          [0m"
        "\t[[0;31;1m2[0m]  - [0;32mBastard             [0m\n"
        "\t[[0;31;1m3[0m]  - [0;32mCunning             [0m"
        "\t[[0;31;1m4[0m]  - [0;32mGenius              [0m\n"
        "\t[[0;31;1m5[0m]  - [0;32mHomely              [0m"
        "\t[[0;31;1m6[0m]  - [0;32mImbecile            [0m\n"
        "\t[[0;31;1m7[0m]  - [0;32mImposing            [0m"
        "\t[[0;31;1m8[0m]  - [0;32mInbred              [0m\n"
        "\t[[0;31;1m9[0m]  - [0;32mKeen                [0m"
        "\t[[0;31;1m10[0m] - [0;32mLisp                [0m\n"
        "\t[[0;31;1m11[0m] - [0;32mMaimed              [0m"
        "\t[[0;31;1m12[0m] - [0;32mSenile              [0m\n"
        "\t[[0;31;1m13[0m] - [0;32mSlow                [0m"
        "\t[[0;31;1m14[0m] - [0;32mSmart               [0m\n"
        "\t[[0;31;1m15[0m] - [0;32mStrong              [0m"
        "\t[[0;31;1m16[0m] - [0;32mUgly                [0m\n"
        "\t[[0;31;1m17[0m] - [0;32mVapid               [0m"
        "\t[[0;31;1m18[0m] - [0;32mWeak                [0m\n"
        "\t[[0;31;1m19[0m] - [0;32mWise                [0m"
        "\t[[0;31;1m20[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 20.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou may only select a trait once. [0;34;1m(*)[0m [0;32;1mdenotes an already-chosen trait.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GeneticTraitsCanBeSelected()
{
    Selector->initiateSelector(User);

    ExpectSubStringMatch("You have 6 trait points left to assign",
        User->caughtMessage());

    Selector->applySelection("3");

    object geneticTraits =
        present_clone("/lib/modules/creation/geneticTraitSelector.c", User);

    ExpectTrue(objectp(geneticTraits), "The genetic trait selector was added to the player");
    geneticTraits->applySelection("1");
    ExpectTrue(User->isTraitOf("lib/modules/traits/genetic/attractive.c"));
    ExpectFalse(objectp(geneticTraits), "The genetic trait selector test was cleaned up");

    ExpectSubStringMatch("You have 5 trait points left to assign",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HealthTraitsMenuIsCorrect()
{
    Selector->initiateSelector(User);
    Selector->applySelection("4");

    object healthTraits =
        present_clone("/lib/modules/creation/healthTraitSelector.c", User);

    ExpectTrue(objectp(healthTraits), "The educational trait selector was added to the player");

    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mSelect a trait to add[0m:\n"
        "\t[[0;31;1m1[0m]  - [0;32mClubfooted          [0m"
        "\t[[0;31;1m2[0m]  - [0;32mDepressed           [0m\n"
        "\t[[0;31;1m3[0m]  - [0;32mDisfigured          [0m"
        "\t[[0;31;1m4[0m]  - [0;32mDrunkard            [0m\n"
        "\t[[0;31;1m5[0m]  - [0;32mFrail               [0m"
        "\t[[0;31;1m6[0m]  - [0;32mHale                [0m\n"
        "\t[[0;31;1m7[0m]  - [0;32mHunchback           [0m"
        "\t[[0;31;1m8[0m]  - [0;32mInsane              [0m\n"
        "\t[[0;31;1m9[0m]  - [0;32mLeper               [0m"
        "\t[[0;31;1m10[0m] - [0;32mOne-eyed            [0m\n"
        "\t[[0;31;1m11[0m] - [0;32mSickly              [0m"
        "\t[[0;31;1m12[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 12.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou may only select a trait once. [0;34;1m(*)[0m [0;32;1mdenotes an already-chosen trait.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HealthTraitsCanBeSelected()
{
    Selector->initiateSelector(User);

    ExpectSubStringMatch("You have 6 trait points left to assign",
        User->caughtMessage());

    Selector->applySelection("4");

    object healthTraits =
        present_clone("/lib/modules/creation/healthTraitSelector.c", User);

    ExpectTrue(objectp(healthTraits), "The health trait selector was added to the player");
    healthTraits->applySelection("1");
    ExpectTrue(User->isTraitOf("lib/modules/traits/health/clubfooted.c"));
    ExpectFalse(objectp(healthTraits), "The health trait selector test was cleaned up");

    ExpectSubStringMatch("You have 7 trait points left to assign",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SexualityTraitsMenuIsCorrect()
{
    Selector->initiateSelector(User);
    Selector->applySelection("5");

    object sexualityTraits =
        present_clone("/lib/modules/creation/sexualityTraitSelector.c", User);

    ExpectTrue(objectp(sexualityTraits), "The sexuality trait selector was added to the player");

    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mSelect a trait to add[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mAsexual             [0m"
        "\t[[0;31;1m2[0m] - [0;32mBisexual            [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mHomosexual          [0m"
        "\t[[0;31;1m4[0m] - [0;32mTransgender         [0m\n"
        "\t[[0;31;1m5[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 5.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou may only select a trait once. [0;34;1m(*)[0m [0;32;1mdenotes an already-chosen trait.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SexualityTraitsCanBeSelected()
{
    Selector->initiateSelector(User);

    Selector->applySelection("5");

    object sexualityTraits =
        present_clone("/lib/modules/creation/sexualityTraitSelector.c", User);

    ExpectTrue(objectp(sexualityTraits), "The sexuality trait selector was added to the player");
    sexualityTraits->applySelection("1");
    ExpectTrue(User->isTraitOf("lib/modules/traits/sexuality/asexual.c"));
    ExpectFalse(objectp(sexualityTraits), "The sexuality trait selector test was cleaned up");
}