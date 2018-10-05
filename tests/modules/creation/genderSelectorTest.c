//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

#define Block 1
#define Describe 2
#define Success 3

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/creation/genderSelector.c");
    Selector->init();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User->Name("Bob");
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
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your biological sex\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mMale                \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mFemale              \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 2.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mAvailable traits later in character creation cover gender identity concerns.\n\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfMaleSetsGenderToMale()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectEq("\x1b[0;36mYou have selected 'Male'.\n\x1b[0m", User->caughtMessage());
    ExpectEq(1, User->Gender());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeMaleDisplaysMaleDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 1");
    ExpectEq("\x1b[0;36mDo you really need a description?\n\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfFemaleSetsGenderToFemale()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectEq("\x1b[0;36mYou have selected 'Female'.\n\x1b[0m", User->caughtMessage());
    ExpectEq(2, User->Gender());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeFemaleDisplaysFemaleDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 2");
    ExpectEq("\x1b[0;36mDo you really need a description?\n\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectorFiresOnSelectorCompletedWhenRaceChosen()
{
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(User);

    ExpectEq(0, subscriber->TimesEventReceived());
    Selector->applySelection("1");
    ExpectEq(1, subscriber->TimesEventReceived());
}
