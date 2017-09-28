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
        "\t[[0;31m2[0m] - [0;32mNegative Traits     [0m\n"
        "\t[[0;31m3[0m] - [0;32mPositive Traits     [0m\n"
        "[0;32;1mYou must select a number from 1 to 3. You may also undo or reset.\n[0m"
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
        "\t[[0;31m2[0m] - [0;32mNegative Traits     [0m\n"
        "\t[[0;31m3[0m] - [0;32mPositive Traits     [0m\n"
        "[0;32;1mYou must select a number from 1 to 3. You may also undo or reset.\n[0m"
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