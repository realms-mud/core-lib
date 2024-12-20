//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void AnswerPersonalityQuestionsTakeFirstChoice(object selector)
{
    while (objectp(selector) && !selector.testTaken())
    {
        selector.applySelection("1");
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
    Selector.init();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User.Name("Bob");
    User.Race("human");
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
    Selector.initiateSelector(User);
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mFrom this menu, you can choose your character's traits\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mTake Personality Test\x1b[0m\n"
        "    [\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mEducational Traits  \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mGenetic Traits      \x1b[0m\n"
        "    [\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mHealth Traits       \x1b[0m\n"
        "    [\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mSexuality Traits    \x1b[0m\n"
        "    [\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mExit Trait Selection   \x1b[0;31;1m(You will lose unspent trait points!)\x1b[0m\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou have 6 trait points left to assign.\nYou have not yet taken the personality test.\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingExitFiresOnSelectorCompletedEvent()
{
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector.registerEvent(subscriber);
    Selector.initiateSelector(User);
    ExpectEq(0, subscriber.TimesEventReceived());

    Selector.applySelection("6");
    ExpectEq(1, subscriber.TimesEventReceived());
}

/////////////////////////////////////////////////////////////////////////////
void TakingPersonalityTestShowsThatTestIsCompleted()
{
    Selector.initiateSelector(User);
    Selector.applySelection("1");

    object personalityTest =
        present_clone("/lib/modules/creation/personalityTraitSelector.c", User);

    ExpectTrue(objectp(personalityTest), "The personality test was added to the player");
    AnswerPersonalityQuestionsTakeFirstChoice(personalityTest);
    ExpectFalse(objectp(personalityTest), "The personality test was cleaned up");

    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mFrom this menu, you can choose your character's traits\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mTake Personality Test\x1b[0m\x1b[0;34;1m  (Completed)\x1b[0m\n"
        "    [\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mEducational Traits  \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mGenetic Traits      \x1b[0m\n"
        "    [\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mHealth Traits       \x1b[0m\n"
        "    [\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mSexuality Traits    \x1b[0m\n"
        "    [\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mExit Trait Selection   \x1b[0;31;1m(You will lose unspent trait points!)\x1b[0m\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou have 6 trait points left to assign.\n\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotTakePersonalityTestTwice()
{
    Selector.initiateSelector(User);
    Selector.applySelection("1");

    object personalityTest =
        present_clone("/lib/modules/creation/personalityTraitSelector.c", User);

    ExpectTrue(objectp(personalityTest), "The personality test was added to the player");
    AnswerPersonalityQuestionsTakeFirstChoice(personalityTest);
    ExpectFalse(objectp(personalityTest), "The personality test was cleaned up");

    Selector.applySelection("1");
    ExpectFalse(objectp(personalityTest), "The personality test was not created");
}

/////////////////////////////////////////////////////////////////////////////
void EducationalTraitsMenuIsCorrect()
{
    Selector.initiateSelector(User);
    Selector.applySelection("2");

    object educationalTraits =
        present_clone("/lib/modules/creation/educationalTraitSelector.c", User);

    ExpectTrue(objectp(educationalTraits), "The educational trait selector was added to the player");

    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mSelect a trait to add\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mArcane knowledge    \x1b[0m"
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mArchitect           \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mArticulate          \x1b[0m"
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mArtisan             \x1b[0m\n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mBotanist            \x1b[0m"
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mCultured            \x1b[0m\n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mDiplomatic          \x1b[0m"
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mEducated            \x1b[0m\n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mErudite             \x1b[0m"
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mHunter              \x1b[0m\n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mMagically barren    \x1b[0m"
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mMastermind          \x1b[0m\n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;32mPoetic              \x1b[0m"
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;32mPolitician          \x1b[0m\n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;32mPoor fighter        \x1b[0m"
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;32mSchemer             \x1b[0m\n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;32mScholarly           \x1b[0m"
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;32mSoldier             \x1b[0m\n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;32mStrategist          \x1b[0m"
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;32mTactician           \x1b[0m\n"
        "    [\x1b[0;31;1m21\x1b[0m] - \x1b[0;32mTheologian          \x1b[0m"
        "    [\x1b[0;31;1m22\x1b[0m] - \x1b[0;32mThespian            \x1b[0m\n"
        "    [\x1b[0;31;1m23\x1b[0m] - \x1b[0;32mUneducated          \x1b[0m"
        "    [\x1b[0;31;1m24\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 24.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou may only select a trait once. \x1b[0;34;1m(*)\x1b[0m \x1b[0;32;1mdenotes an already-chosen trait.\n\x1b[0m\x1b[0m",
        User.caughtMessage());

    educationalTraits.applySelection("1");
    ExpectTrue(User.isTraitOf("/lib/instances/traits/educational/arcane.c"));
}

/////////////////////////////////////////////////////////////////////////////
void EducationalTraitsCanBeSelected()
{
    Selector.initiateSelector(User);

    ExpectSubStringMatch("You have 6 trait points left to assign",
        User.caughtMessage());

    Selector.applySelection("2");

    object educationalTraits =
        present_clone("/lib/modules/creation/educationalTraitSelector.c", User);

    ExpectTrue(objectp(educationalTraits), "The educational trait selector was added to the player");
    educationalTraits.applySelection("1");
    ExpectTrue(User.isTraitOf("/lib/instances/traits/educational/arcane.c"));
    ExpectFalse(objectp(educationalTraits), "The educational trait selector test was cleaned up");

    ExpectSubStringMatch("You have 4 trait points left to assign",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GeneticTraitsMenuIsCorrect()
{
    Selector.initiateSelector(User);
    Selector.applySelection("3");

    object geneticTraits =
        present_clone("/lib/modules/creation/geneticTraitSelector.c", User);

    ExpectTrue(objectp(geneticTraits), "The genetic trait selector was added to the player");

    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mSelect a trait to add\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mAttractive          \x1b[0m"
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mBastard             \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mCunning             \x1b[0m"
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mGenius              \x1b[0m\n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mHomely              \x1b[0m"
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mImbecile            \x1b[0m\n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mImposing            \x1b[0m"
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mInbred              \x1b[0m\n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mKeen                \x1b[0m"
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mLisp                \x1b[0m\n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mMaimed              \x1b[0m"
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mSenile              \x1b[0m\n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;32mSlow                \x1b[0m"
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;32mSmart               \x1b[0m\n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;32mStrong              \x1b[0m"
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;32mUgly                \x1b[0m\n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;32mVapid               \x1b[0m"
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;32mWeak                \x1b[0m\n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;32mWise                \x1b[0m"
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 20.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou may only select a trait once. \x1b[0;34;1m(*)\x1b[0m \x1b[0;32;1mdenotes an already-chosen trait.\n\x1b[0m\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GeneticTraitsCanBeSelected()
{
    Selector.initiateSelector(User);

    ExpectSubStringMatch("You have 6 trait points left to assign",
        User.caughtMessage());

    Selector.applySelection("3");

    object geneticTraits =
        present_clone("/lib/modules/creation/geneticTraitSelector.c", User);

    ExpectTrue(objectp(geneticTraits), "The genetic trait selector was added to the player");
    geneticTraits.applySelection("1");
    ExpectTrue(User.isTraitOf("/lib/instances/traits/genetic/attractive.c"));
    ExpectFalse(objectp(geneticTraits), "The genetic trait selector test was cleaned up");

    ExpectSubStringMatch("You have 5 trait points left to assign",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HealthTraitsMenuIsCorrect()
{
    Selector.initiateSelector(User);
    Selector.applySelection("4");

    object healthTraits =
        present_clone("/lib/modules/creation/healthTraitSelector.c", User);

    ExpectTrue(objectp(healthTraits), "The educational trait selector was added to the player");

    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mSelect a trait to add\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mClubfooted          \x1b[0m"
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mDepressed           \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mDisfigured          \x1b[0m"
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mDrunkard            \x1b[0m\n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mFrail               \x1b[0m"
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mHale                \x1b[0m\n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mHunchback           \x1b[0m"
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mInsane              \x1b[0m\n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mLeper               \x1b[0m"
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mOne-eyed            \x1b[0m\n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mSickly              \x1b[0m"
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 12.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou may only select a trait once. \x1b[0;34;1m(*)\x1b[0m \x1b[0;32;1mdenotes an already-chosen trait.\n\x1b[0m\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HealthTraitsCanBeSelected()
{
    Selector.initiateSelector(User);

    ExpectSubStringMatch("You have 6 trait points left to assign",
        User.caughtMessage());

    Selector.applySelection("4");

    object healthTraits =
        present_clone("/lib/modules/creation/healthTraitSelector.c", User);

    ExpectTrue(objectp(healthTraits), "The health trait selector was added to the player");
    healthTraits.applySelection("1");
    ExpectTrue(User.isTraitOf("/lib/instances/traits/health/clubfooted.c"));
    ExpectFalse(objectp(healthTraits), "The health trait selector test was cleaned up");

    ExpectSubStringMatch("You have 7 trait points left to assign",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SexualityTraitsMenuIsCorrect()
{
    Selector.initiateSelector(User);
    Selector.applySelection("5");

    object sexualityTraits =
        present_clone("/lib/modules/creation/sexualityTraitSelector.c", User);

    ExpectTrue(objectp(sexualityTraits), "The sexuality trait selector was added to the player");

    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mSelect a trait to add\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mAsexual             \x1b[0m"
        "    [\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mBisexual            \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mHomosexual          \x1b[0m"
        "    [\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mTransgender         \x1b[0m\n"
        "    [\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mReturn to previous menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 5.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou may only select a trait once. \x1b[0;34;1m(*)\x1b[0m \x1b[0;32;1mdenotes an already-chosen trait.\n\x1b[0m\x1b[0m",
        User.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SexualityTraitsCanBeSelected()
{
    Selector.initiateSelector(User);

    Selector.applySelection("5");

    object sexualityTraits =
        present_clone("/lib/modules/creation/sexualityTraitSelector.c", User);

    ExpectTrue(objectp(sexualityTraits), "The sexuality trait selector was added to the player");
    sexualityTraits.applySelection("1");
    ExpectTrue(User.isTraitOf("/lib/instances/traits/sexuality/asexual.c"));
    ExpectFalse(objectp(sexualityTraits), "The sexuality trait selector test was cleaned up");
}
