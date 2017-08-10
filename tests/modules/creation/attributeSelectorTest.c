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
mapping Data;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/creation/attributeSelector.c");
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
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mChoose your starting attributes[0m:\n	[[0;31m1[0m] - [0;32mStrength            [0m[0;35;1m(current Str is 2)[0m\n	[[0;31m2[0m] - [0;32mIntelligence        [0m[0;35;1m(current Int is 2)[0m\n	[[0;31m3[0m] - [0;32mDexterity           [0m[0;35;1m(current Dex is 2)[0m\n	[[0;31m4[0m] - [0;32mWisdom              [0m[0;35;1m(current Wis is 2)[0m\n	[[0;31m5[0m] - [0;32mConstitution        [0m[0;35;1m(current Con is 2)[0m\n	[[0;31m6[0m] - [0;32mCharisma            [0m[0;35;1m(current Cha is 2)[0m\n[0;32;1mYou must select a number from 1 to 6.\n[0m[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1mYou have 18 points left to spend on attributes.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfStrengthUpdatesStrengthValueAndDecreasesAvailablePoints()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mChoose your starting attributes[0m:\n	[[0;31m1[0m] - [0;32mStrength            [0m[0;35;1m(current Str is 3)[0m\n	[[0;31m2[0m] - [0;32mIntelligence        [0m[0;35;1m(current Int is 2)[0m\n	[[0;31m3[0m] - [0;32mDexterity           [0m[0;35;1m(current Dex is 2)[0m\n	[[0;31m4[0m] - [0;32mWisdom              [0m[0;35;1m(current Wis is 2)[0m\n	[[0;31m5[0m] - [0;32mConstitution        [0m[0;35;1m(current Con is 2)[0m\n	[[0;31m6[0m] - [0;32mCharisma            [0m[0;35;1m(current Cha is 2)[0m\n[0;32;1mYou must select a number from 1 to 6.\n[0m[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1mYou have 17 points left to spend on attributes.\n[0m",
        User->caughtMessage());
    ExpectEq(3, User->Str());
    ExpectEq(17, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfIntelligenceUpdatesIntelligenceValueAndDecreasesAvailablePoints()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mChoose your starting attributes[0m:\n	[[0;31m1[0m] - [0;32mStrength            [0m[0;35;1m(current Str is 2)[0m\n	[[0;31m2[0m] - [0;32mIntelligence        [0m[0;35;1m(current Int is 3)[0m\n	[[0;31m3[0m] - [0;32mDexterity           [0m[0;35;1m(current Dex is 2)[0m\n	[[0;31m4[0m] - [0;32mWisdom              [0m[0;35;1m(current Wis is 2)[0m\n	[[0;31m5[0m] - [0;32mConstitution        [0m[0;35;1m(current Con is 2)[0m\n	[[0;31m6[0m] - [0;32mCharisma            [0m[0;35;1m(current Cha is 2)[0m\n[0;32;1mYou must select a number from 1 to 6.\n[0m[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1mYou have 17 points left to spend on attributes.\n[0m",
        User->caughtMessage());
    ExpectEq(3, User->Int());
    ExpectEq(17, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfDexterityUpdatesDexterityValueAndDecreasesAvailablePoints()
{
    Selector->initiateSelector(User);
    Selector->applySelection("3");
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mChoose your starting attributes[0m:\n	[[0;31m1[0m] - [0;32mStrength            [0m[0;35;1m(current Str is 2)[0m\n	[[0;31m2[0m] - [0;32mIntelligence        [0m[0;35;1m(current Int is 2)[0m\n	[[0;31m3[0m] - [0;32mDexterity           [0m[0;35;1m(current Dex is 3)[0m\n	[[0;31m4[0m] - [0;32mWisdom              [0m[0;35;1m(current Wis is 2)[0m\n	[[0;31m5[0m] - [0;32mConstitution        [0m[0;35;1m(current Con is 2)[0m\n	[[0;31m6[0m] - [0;32mCharisma            [0m[0;35;1m(current Cha is 2)[0m\n[0;32;1mYou must select a number from 1 to 6.\n[0m[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1mYou have 17 points left to spend on attributes.\n[0m",
        User->caughtMessage());
    ExpectEq(3, User->Dex());
    ExpectEq(17, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfWisdomUpdatesWisdomValueAndDecreasesAvailablePoints()
{
    Selector->initiateSelector(User);
    Selector->applySelection("4");
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mChoose your starting attributes[0m:\n	[[0;31m1[0m] - [0;32mStrength            [0m[0;35;1m(current Str is 2)[0m\n	[[0;31m2[0m] - [0;32mIntelligence        [0m[0;35;1m(current Int is 2)[0m\n	[[0;31m3[0m] - [0;32mDexterity           [0m[0;35;1m(current Dex is 2)[0m\n	[[0;31m4[0m] - [0;32mWisdom              [0m[0;35;1m(current Wis is 3)[0m\n	[[0;31m5[0m] - [0;32mConstitution        [0m[0;35;1m(current Con is 2)[0m\n	[[0;31m6[0m] - [0;32mCharisma            [0m[0;35;1m(current Cha is 2)[0m\n[0;32;1mYou must select a number from 1 to 6.\n[0m[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1mYou have 17 points left to spend on attributes.\n[0m",
        User->caughtMessage());
    ExpectEq(3, User->Wis());
    ExpectEq(17, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfConstitutionUpdatesConstitutionValueAndDecreasesAvailablePoints()
{
    Selector->initiateSelector(User);
    Selector->applySelection("5");
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mChoose your starting attributes[0m:\n	[[0;31m1[0m] - [0;32mStrength            [0m[0;35;1m(current Str is 2)[0m\n	[[0;31m2[0m] - [0;32mIntelligence        [0m[0;35;1m(current Int is 2)[0m\n	[[0;31m3[0m] - [0;32mDexterity           [0m[0;35;1m(current Dex is 2)[0m\n	[[0;31m4[0m] - [0;32mWisdom              [0m[0;35;1m(current Wis is 2)[0m\n	[[0;31m5[0m] - [0;32mConstitution        [0m[0;35;1m(current Con is 3)[0m\n	[[0;31m6[0m] - [0;32mCharisma            [0m[0;35;1m(current Cha is 2)[0m\n[0;32;1mYou must select a number from 1 to 6.\n[0m[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1mYou have 17 points left to spend on attributes.\n[0m",
        User->caughtMessage());
    ExpectEq(3, User->Con());
    ExpectEq(17, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfCharismaUpdatesCharismaValueAndDecreasesAvailablePoints()
{
    Selector->initiateSelector(User);
    Selector->applySelection("6");
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mChoose your starting attributes[0m:\n	[[0;31m1[0m] - [0;32mStrength            [0m[0;35;1m(current Str is 2)[0m\n	[[0;31m2[0m] - [0;32mIntelligence        [0m[0;35;1m(current Int is 2)[0m\n	[[0;31m3[0m] - [0;32mDexterity           [0m[0;35;1m(current Dex is 2)[0m\n	[[0;31m4[0m] - [0;32mWisdom              [0m[0;35;1m(current Wis is 2)[0m\n	[[0;31m5[0m] - [0;32mConstitution        [0m[0;35;1m(current Con is 2)[0m\n	[[0;31m6[0m] - [0;32mCharisma            [0m[0;35;1m(current Cha is 3)[0m\n[0;32;1mYou must select a number from 1 to 6.\n[0m[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1mYou have 17 points left to spend on attributes.\n[0m",
        User->caughtMessage());
    ExpectEq(3, User->Chr());
    ExpectEq(17, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void CannotSelectValueHigherThan10ForAttribute()
{
    string expectedFmt = "[0;36mCharacter creation - [0m[0;37;1mChoose your starting attributes[0m:\n	[[0;31m1[0m] - [0;32mStrength            [0m[0;35;1m(current Str is %d)[0m\n	[[0;31m2[0m] - [0;32mIntelligence        [0m[0;35;1m(current Int is 2)[0m\n	[[0;31m3[0m] - [0;32mDexterity           [0m[0;35;1m(current Dex is 2)[0m\n	[[0;31m4[0m] - [0;32mWisdom              [0m[0;35;1m(current Wis is 2)[0m\n	[[0;31m5[0m] - [0;32mConstitution        [0m[0;35;1m(current Con is 2)[0m\n	[[0;31m6[0m] - [0;32mCharisma            [0m[0;35;1m(current Cha is 2)[0m\n[0;32;1mYou must select a number from 1 to 6.\n[0m[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1mYou have %d points left to spend on attributes.\n[0m";
    Selector->initiateSelector(User);

    Selector->applySelection("1");
    ExpectEq(sprintf(expectedFmt, 3, 17), User->caughtMessage());
    Selector->applySelection("1");
    ExpectEq(sprintf(expectedFmt, 4, 16), User->caughtMessage());
    Selector->applySelection("1");
    ExpectEq(sprintf(expectedFmt, 5, 15), User->caughtMessage());
    Selector->applySelection("1");
    ExpectEq(sprintf(expectedFmt, 6, 14), User->caughtMessage());
    Selector->applySelection("1");
    ExpectEq(sprintf(expectedFmt, 7, 13), User->caughtMessage());
    Selector->applySelection("1");
    ExpectEq(sprintf(expectedFmt, 8, 12), User->caughtMessage());
    Selector->applySelection("1");
    ExpectEq(sprintf(expectedFmt, 9, 11), User->caughtMessage());

    expectedFmt = "[0;36mCharacter creation - [0m[0;37;1mChoose your starting attributes[0m:\n	[[0;31m1[0m] - [0;32mStrength            [0m[0;31;1m(current Str is at maximum of %d)[0m\n	[[0;31m2[0m] - [0;32mIntelligence        [0m[0;35;1m(current Int is 2)[0m\n	[[0;31m3[0m] - [0;32mDexterity           [0m[0;35;1m(current Dex is 2)[0m\n	[[0;31m4[0m] - [0;32mWisdom              [0m[0;35;1m(current Wis is 2)[0m\n	[[0;31m5[0m] - [0;32mConstitution        [0m[0;35;1m(current Con is 2)[0m\n	[[0;31m6[0m] - [0;32mCharisma            [0m[0;35;1m(current Cha is 2)[0m\n[0;32;1mYou must select a number from 1 to 6.\n[0m[0;32mFor details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n[0m[0;32;1mYou have %d points left to spend on attributes.\n[0m";
    Selector->applySelection("1");
    ExpectEq(sprintf(expectedFmt, 10, 10), User->caughtMessage());
    Selector->applySelection("1");
    ExpectEq(sprintf(expectedFmt, 10, 10), User->caughtMessage());

    ExpectEq(10, User->Str());
    ExpectEq(10, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void SelectorDestroysItselfWhenAllPointsSpent()
{
    Selector->initiateSelector(User);

    for (int i = 0; i < 18; i++)
    {
        ExpectNotEq("cleanUp", call_out_info()[0][1]);
        Selector->applySelection(to_string((i % 6) + 1));
        ExpectEq(17 - i, User->attributePoints());
    }

    ExpectEq("cleanUp", call_out_info()[0][1]);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUpDeletesSelector()
{
    ExpectTrue(objectp(Selector));
    Selector->cleanUp();
    ExpectFalse(objectp(Selector));
}