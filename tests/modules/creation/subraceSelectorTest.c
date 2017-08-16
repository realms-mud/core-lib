//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    Selector = clone_object("/lib/modules/creation/subraceSelector.c");
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
void InitialCreationDisplayIsCorrectForHighElf()
{
    User->Race("high elf");
    Selector->initiateSelector(User);
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mChoose your subrace[0m:\n"
        "\t[[0;31m1[0m] - [0;32mHillgarathi elf     [0m\n"
        "\t[[0;31m2[0m] - [0;32mMoon elf            [0m\n"
        "\t[[0;31m3[0m] - [0;32mDo not add a subrace[0m\n"
        "[0;32;1mYou must select a number from 1 to 3.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHillgarathiHighElfAddsTrait()
{
    User->Race("high elf");
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectEq("[0;36mYou have selected 'Hillgarathi elf'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/hillgarathElf.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfMoonHighElfAddsTrait()
{
    User->Race("high elf");
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectEq("[0;36mYou have selected 'Moon elf'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/echorluinElf.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfNoneDoesNotAddTraitButFiresOnSelectorCompleted()
{
    User->Race("high elf");
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(User);

    ExpectEq(0, subscriber->TimesEventReceived());
    Selector->applySelection("3");
    ExpectEq(1, subscriber->TimesEventReceived());
}

/////////////////////////////////////////////////////////////////////////////
void InitialCreationDisplayIsCorrectForElf()
{
    User->Race("elf");
    Selector->initiateSelector(User);
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mChoose your subrace[0m:\n"
        "\t[[0;31m1[0m] - [0;32mDark elf            [0m\n"
        "\t[[0;31m2[0m] - [0;32mGrey elf            [0m\n"
        "\t[[0;31m3[0m] - [0;32mSea elf             [0m\n"
        "\t[[0;31m4[0m] - [0;32mWood elf            [0m\n"
        "\t[[0;31m5[0m] - [0;32mDo not add a subrace[0m\n"
        "[0;32;1mYou must select a number from 1 to 5.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfDarkElfAddsTrait()
{
    User->Race("elf");
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectEq("[0;36mYou have selected 'Dark elf'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/darkElf.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfGreyElfAddsTrait()
{
    User->Race("elf");
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectEq("[0;36mYou have selected 'Grey elf'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/greyElf.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfSeaElfAddsTrait()
{
    User->Race("elf");
    Selector->initiateSelector(User);
    Selector->applySelection("3");
    ExpectEq("[0;36mYou have selected 'Sea elf'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/seaElf.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfWoodElfAddsTrait()
{
    User->Race("elf");
    Selector->initiateSelector(User);
    Selector->applySelection("4");
    ExpectEq("[0;36mYou have selected 'Wood elf'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/woodElf.c"));
}

/////////////////////////////////////////////////////////////////////////////
void InitialCreationDisplayIsCorrectForDwarf()
{
    User->Race("dwarf");
    Selector->initiateSelector(User);
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mChoose your subrace[0m:\n"
        "\t[[0;31m1[0m] - [0;32mKhazurathi dwarf    [0m\n"
        "\t[[0;31m2[0m] - [0;32mMirosti dwarf       [0m\n"
        "\t[[0;31m3[0m] - [0;32mDo not add a subrace[0m\n"
        "[0;32;1mYou must select a number from 1 to 3.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfKhazurathiDwarfAddsTrait()
{
    User->Race("dwarf");
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectEq("[0;36mYou have selected 'Khazurathi dwarf'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/khazurathiDwarf.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfMirostiDwarfAddsTrait()
{
    User->Race("dwarf");
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectEq("[0;36mYou have selected 'Mirosti dwarf'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/mirostiDwarf.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfDraconidRaceFiresOnSelectorCompletedWithoutShowingSubraces()
{
    User->Race("draconid");
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(User);

    ExpectEq(1, subscriber->TimesEventReceived());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalfilngRaceFiresOnSelectorCompletedWithoutShowingSubraces()
{
    User->Race("halfling");
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(User);

    ExpectEq(1, subscriber->TimesEventReceived());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfGnomeRaceFiresOnSelectorCompletedWithoutShowingSubraces()
{
    User->Race("gnome");
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(User);

    ExpectEq(1, subscriber->TimesEventReceived());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalfElfRaceFiresOnSelectorCompletedWithoutShowingSubraces()
{
    User->Race("half elf");
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(User);

    ExpectEq(1, subscriber->TimesEventReceived());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalfOrcRaceFiresOnSelectorCompletedWithoutShowingSubraces()
{
    User->Race("half orc");
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(User);

    ExpectEq(1, subscriber->TimesEventReceived());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalfTrollRaceFiresOnSelectorCompletedWithoutShowingSubraces()
{
    User->Race("half troll");
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(User);

    ExpectEq(1, subscriber->TimesEventReceived());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfFaerieRaceFiresOnSelectorCompletedWithoutShowingSubraces()
{
    User->Race("faerie");
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(User);

    ExpectEq(1, subscriber->TimesEventReceived());
}

/////////////////////////////////////////////////////////////////////////////
void InitialCreationDisplayIsCorrectForHuman()
{
    User->Race("human");
    Selector->initiateSelector(User);
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mChoose your subrace[0m:\n"
        "\t[[0;31m1[0m] - [0;32mAndurathi           [0m\n"
        "\t[[0;31m2[0m] - [0;32mCelebnosti          [0m\n"
        "\t[[0;31m3[0m] - [0;32mEledhelean          [0m\n"
        "\t[[0;31m4[0m] - [0;32mEndurgish           [0m\n"
        "\t[[0;31m5[0m] - [0;32mHelcarish           [0m\n"
        "\t[[0;31m6[0m] - [0;32mHillgarathi         [0m\n"
        "\t[[0;31m7[0m] - [0;32mIarwathean          [0m\n"
        "\t[[0;31m8[0m] - [0;32mLinmiri             [0m\n"
        "\t[[0;31m9[0m] - [0;32mMenadrosti          [0m\n"
        "\t[[0;31m10[0m] - [0;32mTirnosti            [0m\n"
        "\t[[0;31m11[0m] - [0;32mZhenduli            [0m\n"
        "\t[[0;31m12[0m] - [0;32mDo not add a subrace[0m\n"
        "[0;32;1mYou must select a number from 1 to 12.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfAndurathiAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectEq("[0;36mYou have selected 'Andurathi'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/andurathHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfCelebnostiAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectEq("[0;36mYou have selected 'Celebnosti'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/celebnostHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfEledheleanAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("3");
    ExpectEq("[0;36mYou have selected 'Eledhelean'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/eledhelHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfEndurgishAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("4");
    ExpectEq("[0;36mYou have selected 'Endurgish'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/endurghulHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHelcarishAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("5");
    ExpectEq("[0;36mYou have selected 'Helcarish'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/helcarionHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHillgarathiAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("6");
    ExpectEq("[0;36mYou have selected 'Hillgarathi'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/hillgarathHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfIarwatheanAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("7");
    ExpectEq("[0;36mYou have selected 'Iarwathean'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/iarwathHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfLinmiriAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("8");
    ExpectEq("[0;36mYou have selected 'Linmiri'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/linmirHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfMenadrostiAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("9");
    ExpectEq("[0;36mYou have selected 'Menadrosti'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/menadrostHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfTirnostiAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("10");
    ExpectEq("[0;36mYou have selected 'Tirnosti'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/tirnostHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfZhenduliAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("11");
    ExpectEq("[0;36mYou have selected 'Zhenduli'.\n[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/zhendulachHuman.c"));
}