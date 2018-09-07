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
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your subrace\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mHalf elf            \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mHillgarathi elf     \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mMoon elf            \x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mDo not add a subrace\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 4.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHalfHighElfAddsTrait()
{
    User->Race("high elf");
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectEq("\x1b[0;36mYou have selected 'Half elf'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/deityTouchedElf.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHillgarathiHighElfAddsTrait()
{
    User->Race("high elf");
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectEq("\x1b[0;36mYou have selected 'Hillgarathi elf'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/hillgarathElf.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfMoonHighElfAddsTrait()
{
    User->Race("high elf");
    Selector->initiateSelector(User);
    Selector->applySelection("3");
    ExpectEq("\x1b[0;36mYou have selected 'Moon elf'.\n\x1b[0m", User->caughtMessage());
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
    Selector->applySelection("4");
    ExpectEq(1, subscriber->TimesEventReceived());
}

/////////////////////////////////////////////////////////////////////////////
void InitialCreationDisplayIsCorrectForElf()
{
    User->Race("elf");
    Selector->initiateSelector(User);
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your subrace\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mDark elf            \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mGrey elf            \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mSea elf             \x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWood elf            \x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mDo not add a subrace\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 5.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfDarkElfAddsTrait()
{
    User->Race("elf");
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectEq("\x1b[0;36mYou have selected 'Dark elf'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/darkElf.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfGreyElfAddsTrait()
{
    User->Race("elf");
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectEq("\x1b[0;36mYou have selected 'Grey elf'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/greyElf.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfSeaElfAddsTrait()
{
    User->Race("elf");
    Selector->initiateSelector(User);
    Selector->applySelection("3");
    ExpectEq("\x1b[0;36mYou have selected 'Sea elf'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/seaElf.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfWoodElfAddsTrait()
{
    User->Race("elf");
    Selector->initiateSelector(User);
    Selector->applySelection("4");
    ExpectEq("\x1b[0;36mYou have selected 'Wood elf'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/woodElf.c"));
}

/////////////////////////////////////////////////////////////////////////////
void InitialCreationDisplayIsCorrectForDwarf()
{
    User->Race("dwarf");
    Selector->initiateSelector(User);
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your subrace\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mKhazurathi dwarf    \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mMirosti dwarf       \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDo not add a subrace\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 3.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfKhazurathiDwarfAddsTrait()
{
    User->Race("dwarf");
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectEq("\x1b[0;36mYou have selected 'Khazurathi dwarf'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/khazurathiDwarf.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfMirostiDwarfAddsTrait()
{
    User->Race("dwarf");
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectEq("\x1b[0;36mYou have selected 'Mirosti dwarf'.\n\x1b[0m", User->caughtMessage());
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
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your subrace\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mAndurathi           \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mCelebnosti          \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mEledhelean          \x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mEndurgish           \x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mHelcarish           \x1b[0m\n"
        "\t[\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mHillgarathi         \x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mIarwathean          \x1b[0m\n"
        "\t[\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mLinmiri             \x1b[0m\n"
        "\t[\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mMenadrosti          \x1b[0m\n"
        "\t[\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mTirnosti            \x1b[0m\n"
        "\t[\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mZhenduli            \x1b[0m\n"
        "\t[\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mDo not add a subrace\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 12.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfAndurathiAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectEq("\x1b[0;36mYou have selected 'Andurathi'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/andurathHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfCelebnostiAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectEq("\x1b[0;36mYou have selected 'Celebnosti'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/celebnostHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfEledheleanAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("3");
    ExpectEq("\x1b[0;36mYou have selected 'Eledhelean'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/eledhelHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfEndurgishAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("4");
    ExpectEq("\x1b[0;36mYou have selected 'Endurgish'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/endurghulHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHelcarishAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("5");
    ExpectEq("\x1b[0;36mYou have selected 'Helcarish'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/helcarionHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHillgarathiAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("6");
    ExpectEq("\x1b[0;36mYou have selected 'Hillgarathi'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/hillgarathHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfIarwatheanAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("7");
    ExpectEq("\x1b[0;36mYou have selected 'Iarwathean'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/iarwathHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfLinmiriAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("8");
    ExpectEq("\x1b[0;36mYou have selected 'Linmiri'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/linmirHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfMenadrostiAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("9");
    ExpectEq("\x1b[0;36mYou have selected 'Menadrosti'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/menadrostHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfTirnostiAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("10");
    ExpectEq("\x1b[0;36mYou have selected 'Tirnosti'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/tirnostHuman.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfZhenduliAddsTrait()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("11");
    ExpectEq("\x1b[0;36mYou have selected 'Zhenduli'.\n\x1b[0m", User->caughtMessage());
    ExpectTrue(User->isTraitOf("/lib/modules/traits/racial/zhendulachHuman.c"));
}
