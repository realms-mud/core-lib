//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        "\t[[0;31m1[0m] - [0;32mTake Personality Test[0m\n"
        "\t[[0;31m2[0m] - [0;32mEducational Traits  [0m\n"
        "\t[[0;31m3[0m] - [0;32mGenetic Traits      [0m\n"
        "\t[[0;31m4[0m] - [0;32mHealth Traits       [0m\n"
        "[0;32;1mYou must select a number from 1 to 4. You may also undo or reset.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou have 6 trait points left to assign.\nYou have not yet taken the personality test.\n[0m",
        User->caughtMessage());
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
        "\t[[0;31m1[0m] - [0;32mTake Personality Test[0m[0;34;1m  (Completed)[0m\n"
        "\t[[0;31m2[0m] - [0;32mEducational Traits  [0m\n"
        "\t[[0;31m3[0m] - [0;32mGenetic Traits      [0m\n"
        "\t[[0;31m4[0m] - [0;32mHealth Traits       [0m\n"
        "[0;32;1mYou must select a number from 1 to 4. You may also undo or reset.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m"
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
void EducationalTraitsDoesEdStuff()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");

    object educationalTraits =
        present_clone("/lib/modules/creation/educationalTraitSelector.c", User);

    ExpectTrue(objectp(educationalTraits), "The educational trait selector was added to the player");
//    ExpectFalse(objectp(educationalTraits), "The educational trait selector test was cleaned up");

    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mSelect a trait to add[0m:\n"
        "\t[[0;31m1[0m]  - [0;32mArcane knowledge    [0m"
        "\t[[0;31m2[0m]  - [0;32mArchitect           [0m\n"
        "\t[[0;31m3[0m]  - [0;32mArticulate          [0m"
        "\t[[0;31m4[0m]  - [0;32mArtisan             [0m\n"
        "\t[[0;31m5[0m]  - [0;32mBotanist            [0m"
        "\t[[0;31m6[0m]  - [0;32mCultured            [0m\n"
        "\t[[0;31m7[0m]  - [0;32mDiplomatic          [0m"
        "\t[[0;31m8[0m]  - [0;32mEducated            [0m\n"
        "\t[[0;31m9[0m]  - [0;32mErudite             [0m"
        "\t[[0;31m10[0m] - [0;32mHunter              [0m\n"
        "\t[[0;31m11[0m] - [0;32mMagically barren    [0m"
        "\t[[0;31m12[0m] - [0;32mMastermind          [0m\n"
        "\t[[0;31m13[0m] - [0;32mPoetic              [0m"
        "\t[[0;31m14[0m] - [0;32mPolitician          [0m\n"
        "\t[[0;31m15[0m] - [0;32mPoor fighter        [0m"
        "\t[[0;31m16[0m] - [0;32mSchemer             [0m\n"
        "\t[[0;31m17[0m] - [0;32mScholarly           [0m"
        "\t[[0;31m18[0m] - [0;32mSoldier             [0m\n"
        "\t[[0;31m19[0m] - [0;32mStrategist          [0m"
        "\t[[0;31m20[0m] - [0;32mTactician           [0m\n"
        "\t[[0;31m21[0m] - [0;32mTheologian          [0m"
        "\t[[0;31m22[0m] - [0;32mThespian            [0m\n"
        "\t[[0;31m23[0m] - [0;32mUneducated          [0m"
        "\t[[0;31m24[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 24.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou may only select a trait once. [0;34;1m(*)[0m [0;32;1mdenotes an already-chosen trait.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GeneticTraitsDoesEdStuff()
{
    Selector->initiateSelector(User);
    Selector->applySelection("3");

    object educationalTraits =
        present_clone("/lib/modules/creation/geneticTraitSelector.c", User);

    ExpectTrue(objectp(educationalTraits), "The educational trait selector was added to the player");
    //    ExpectFalse(objectp(educationalTraits), "The educational trait selector test was cleaned up");

    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mSelect a trait to add[0m:\n"
        "\t[[0;31m1[0m]  - [0;32mAttractive          [0m"
        "\t[[0;31m2[0m]  - [0;32mBastard             [0m\n"
        "\t[[0;31m3[0m]  - [0;32mCunning             [0m"
        "\t[[0;31m4[0m]  - [0;32mGenius              [0m\n"
        "\t[[0;31m5[0m]  - [0;32mHomely              [0m"
        "\t[[0;31m6[0m]  - [0;32mImbecile            [0m\n"
        "\t[[0;31m7[0m]  - [0;32mImposing            [0m"
        "\t[[0;31m8[0m]  - [0;32mInbred              [0m\n"
        "\t[[0;31m9[0m]  - [0;32mKeen                [0m"
        "\t[[0;31m10[0m] - [0;32mLisp                [0m\n"
        "\t[[0;31m11[0m] - [0;32mMaimed              [0m"
        "\t[[0;31m12[0m] - [0;32mSenile              [0m\n"
        "\t[[0;31m13[0m] - [0;32mSlow                [0m"
        "\t[[0;31m14[0m] - [0;32mSmart               [0m\n"
        "\t[[0;31m15[0m] - [0;32mStrong              [0m"
        "\t[[0;31m16[0m] - [0;32mUgly                [0m\n"
        "\t[[0;31m17[0m] - [0;32mVapid               [0m"
        "\t[[0;31m18[0m] - [0;32mWeak                [0m\n"
        "\t[[0;31m19[0m] - [0;32mWise                [0m"
        "\t[[0;31m20[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 20.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou may only select a trait once. [0;34;1m(*)[0m [0;32;1mdenotes an already-chosen trait.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HealthTraitsDoesEdStuff()
{
    Selector->initiateSelector(User);
    Selector->applySelection("4");

    object educationalTraits =
        present_clone("/lib/modules/creation/healthTraitSelector.c", User);

    ExpectTrue(objectp(educationalTraits), "The educational trait selector was added to the player");
    //    ExpectFalse(objectp(educationalTraits), "The educational trait selector test was cleaned up");

    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mSelect a trait to add[0m:\n"
        "\t[[0;31m1[0m]  - [0;32mClubfooted          [0m"
        "\t[[0;31m2[0m]  - [0;32mDepressed           [0m\n"
        "\t[[0;31m3[0m]  - [0;32mDisfigured          [0m"
        "\t[[0;31m4[0m]  - [0;32mDrunkard            [0m\n"
        "\t[[0;31m5[0m]  - [0;32mFrail               [0m"
        "\t[[0;31m6[0m]  - [0;32mHale                [0m\n"
        "\t[[0;31m7[0m]  - [0;32mHunchback           [0m"
        "\t[[0;31m8[0m]  - [0;32mInsane              [0m\n"
        "\t[[0;31m9[0m]  - [0;32mLeper               [0m"
        "\t[[0;31m10[0m] - [0;32mOne-eyed            [0m\n"
        "\t[[0;31m11[0m] - [0;32mSickly              [0m"
        "\t[[0;31m12[0m] - [0;32mReturn to previous menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 12.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou may only select a trait once. [0;34;1m(*)[0m [0;32;1mdenotes an already-chosen trait.\n[0m",
        User->caughtMessage());
}