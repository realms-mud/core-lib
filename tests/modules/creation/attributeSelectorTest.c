//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 2)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 2)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 18 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfStrengthUpdatesStrengthValueAndDecreasesAvailablePoints()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 3)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 2)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 17 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());
    ExpectEq(3, User->Str());
    ExpectEq(17, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeStrengthDisplaysAttributeDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 1");
    ExpectEq("\x1b[0;36mThe strength attribute represents how strong one is and their overall\nphysical prowess. It is used to determine:\n"
                "\t- How much they can carry\n"
                "\t- How easily they can bear a burden (encumberance)\n"
                "\t- Damage inflicted by physical blows\n"
                "\t- Ability to withstand physical blows\n"
                "\t- Ability to learn certain skills - particularly combat skills\n"
                "\t- Stamina\n"
                "\t- Key abilities in many martial guilds\n\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfIntelligenceUpdatesIntelligenceValueAndDecreasesAvailablePoints()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 2)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 3)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 17 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());
    ExpectEq(3, User->Int());
    ExpectEq(17, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeIntelligenceDisplaysAttributeDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 2");
    ExpectEq("\x1b[0;36mThe intelligence attribute represents one's mental aptitude.\nIt is used to determine:\n"
                "\t- How many skill points they receive\n"
                "\t- Damage inflicted by magical means\n"
                "\t- Ability to land physical attacks in the most ideal locations\n"
                "\t- Ability to learn certain skills - particularly magic, erudite,\n\t  crafting, and language skills\n"
                "\t- Spell Points\n"
                "\t- Key abilities in many thought and magic-based guilds\n\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfDexterityUpdatesDexterityValueAndDecreasesAvailablePoints()
{
    Selector->initiateSelector(User);
    Selector->applySelection("3");
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 2)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 2)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 3)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 17 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());
    ExpectEq(3, User->Dex());
    ExpectEq(17, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeDexterityDisplaysAttributeDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 3");
    ExpectEq("\x1b[0;36mThe dexterity attribute represents one's stealth and nimbleness.\nIt is used to determine:\n"
                "\t- Ability to land physical attacks\n"
                "\t- Ability to avoid attacks\n"
                "\t- Ability to learn certain skills - particularly combat and\n\t  subterfuge skills\n"
                "\t- Key abilities in roguish guilds\n\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfWisdomUpdatesWisdomValueAndDecreasesAvailablePoints()
{
    Selector->initiateSelector(User);
    Selector->applySelection("4");
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 2)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 2)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 3)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 17 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());
    ExpectEq(3, User->Wis());
    ExpectEq(17, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeWisdomDisplaysAttributeDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 4");
    ExpectEq("\x1b[0;36mThe wisdom attribute represents one's intuition, common sense,\nand decision-making. It is used to determine:\n"
                "\t- Damage inflicted\n"
                "\t- Ability to avoid attacks\n"
                "\t- Ability to learn certain skills - particularly magic, general,\n\t  and crafting skills\n"
                "\t- Spell Points\n"
                "\t- Key abilities in many divine-based guilds\n\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfConstitutionUpdatesConstitutionValueAndDecreasesAvailablePoints()
{
    Selector->initiateSelector(User);
    Selector->applySelection("5");
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 2)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 2)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 3)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 17 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());
    ExpectEq(3, User->Con());
    ExpectEq(17, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeConstitutionDisplaysAttributeDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 5");
    ExpectEq("\x1b[0;36mThe constitution attribute represents one's physical toughness.\nIt is used to determine:\n"
                "\t- Hit points\n"
                "\t- Ability to withstand physical blows\n"
                "\t- Many resistances, including magic, poison, and illness\n"
                "\t- Ability to learn certain skills - particularly magic skills\n\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfCharismaUpdatesCharismaValueAndDecreasesAvailablePoints()
{
    Selector->initiateSelector(User);
    Selector->applySelection("6");
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 2)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 2)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 3)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 17 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());
    ExpectEq(3, User->Chr());
    ExpectEq(17, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeCharismaDisplaysAttributeDescription()
{
    Selector->initiateSelector(User);
    Selector->applySelection("describe 6");
    ExpectEq("\x1b[0;36mThe charisma attribute represents one's personality and ability to\nmanipulate others. It is used to determine:\n"
                "\t- Other's default predisposition toward you\n"
                "\t- Ability to manipulate conversations\n"
                "\t- Faction and guild influence\n"
                "\t- Ability to learn certain skills - particularly magic and\n\t  general skills\n"
                "\t- Key abilities in many guilds\n\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotSelectValueHigherThan10ForAttribute()
{
    string expectedFmt = "\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is %d)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 2)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have %d points left to spend on attributes.\n\x1b[0m";
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

    expectedFmt = "\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;31;1m(current Str is at maximum of %d)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 2)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have %d points left to spend on attributes.\n\x1b[0m";
    Selector->applySelection("1");
    ExpectEq(sprintf(expectedFmt, 10, 10), User->caughtMessage());
    Selector->applySelection("1");
    ExpectEq(sprintf(expectedFmt, 10, 10), User->caughtMessage());

    ExpectEq(10, User->Str());
    ExpectEq(10, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void SelectorFiresOnSelectorCompletedWhenAllPointsSpent()
{
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(User);

    for (int i = 0; i < 18; i++)
    {
        ExpectEq(0, subscriber->TimesEventReceived());
        Selector->applySelection(to_string((i % 6) + 1));
        ExpectEq(17 - i, User->attributePoints());
    }

    ExpectEq(1, subscriber->TimesEventReceived());
}

/////////////////////////////////////////////////////////////////////////////
void CleanUpDeletesSelector()
{
    ExpectTrue(objectp(Selector));
    Selector->cleanUp();
    ExpectFalse(objectp(Selector));
}

/////////////////////////////////////////////////////////////////////////////
void UndoProperlyClearsLastAttempt()
{
    string expectedFmt = "\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is %d)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 2)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have %d points left to spend on attributes.\n\x1b[0m";
    Selector->initiateSelector(User);

    Selector->applySelection("1");
    ExpectEq(sprintf(expectedFmt, 3, 17), User->caughtMessage());
    Selector->applySelection("1");
    ExpectEq(sprintf(expectedFmt, 4, 16), User->caughtMessage());
    Selector->applySelection("1");
    ExpectEq(sprintf(expectedFmt, 5, 15), User->caughtMessage());
    Selector->applySelection("undo");
    ExpectEq("\x1b[0;36mYou have reverted your previous selection.\n\x1b[0m" + sprintf(expectedFmt, 4, 16),
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UndoDoesNotCacheFailedActions()
{
    Selector->initiateSelector(User);

    // Try to add beyond the 10 thresshold and make sure that you cannot undo
    // more than 8.
    for(int i = 1; i < 12; i++)
    { 
        Selector->applySelection("1");
    }

    for (int i = 1; i < 12; i++)
    {
        Selector->applySelection("undo");
    }
    ExpectEq(2, User->Str());
    ExpectEq(18, User->attributePoints());
}

/////////////////////////////////////////////////////////////////////////////
void CanDoMultipleUndos()
{
    Selector->initiateSelector(User);

    Selector->applySelection("2");
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 2)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 3)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 17 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());

    Selector->applySelection("1");
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 3)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 3)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 16 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());

    Selector->applySelection("3");
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 3)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 3)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 3)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 15 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());

    Selector->applySelection("undo");
    ExpectEq("\x1b[0;36mYou have reverted your previous selection.\n\x1b[0m\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 3)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 3)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 16 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());

    Selector->applySelection("undo");
    ExpectEq("\x1b[0;36mYou have reverted your previous selection.\n\x1b[0m\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 2)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 3)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 17 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());

    Selector->applySelection("undo");
    ExpectEq("\x1b[0;36mYou have reverted your previous selection.\n\x1b[0m\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 2)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 2)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 18 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotUndoMoreThanWhatHasBeenDone()
{
    Selector->initiateSelector(User);

    Selector->applySelection("2");
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 2)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 3)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 17 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());

    Selector->applySelection("undo");
    ExpectEq("\x1b[0;36mYou have reverted your previous selection.\n\x1b[0m\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 2)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 2)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 18 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());

    Selector->applySelection("undo");
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 2)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 2)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 18 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ResetProperlyClearsAllSettings()
{
    Selector->initiateSelector(User);

    Selector->applySelection("2");
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 2)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 3)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 17 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());

    Selector->applySelection("1");
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 3)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 3)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 16 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());

    Selector->applySelection("3");
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 3)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 3)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 3)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 15 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());

    Selector->applySelection("reset");
    ExpectEq("\x1b[0;36mYou have reset your selections.\n\x1b[0m\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose your starting attributes\x1b[0m:\n\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mStrength            \x1b[0m\x1b[0;34;1m(current Str is 2)\x1b[0m\n\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mIntelligence        \x1b[0m\x1b[0;34;1m(current Int is 2)\x1b[0m\n\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mDexterity           \x1b[0m\x1b[0;34;1m(current Dex is 2)\x1b[0m\n\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mWisdom              \x1b[0m\x1b[0;34;1m(current Wis is 2)\x1b[0m\n\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mConstitution        \x1b[0m\x1b[0;34;1m(current Con is 2)\x1b[0m\n\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mCharisma            \x1b[0m\x1b[0;34;1m(current Cha is 2)\x1b[0m\n\x1b[0;32;1mYou must select a number from 1 to 6. You may also undo or reset.\n\x1b[0m\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1mYou have 18 points left to spend on attributes.\n\x1b[0m",
        User->caughtMessage());
}
