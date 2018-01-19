//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/creation/skillsSelector.c");
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
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mChoose a class of skills to advance[0m:\n"
        "\t[[0;31;1m1[0m] - [0;32mCombat              [0m\n"
        "\t[[0;31;1m2[0m] - [0;32mCrafting            [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mErudite             [0m\n"
        "\t[[0;31;1m4[0m] - [0;32mGeneral             [0m\n"
        "\t[[0;31;1m5[0m] - [0;32mLanguage            [0m\n"
        "\t[[0;31;1m6[0m] - [0;32mMagic               [0m\n"
        "\t[[0;31;1m7[0m] - [0;32mSubterfuge          [0m\n"
        "[0;32;1mYou must select a number from 1 to 7. You may also undo or reset.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1mYou have 14 skills left to assign.\n[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectCombatDisplaysCombatSkillSubmenu()
{
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectTrue(sizeof(regexp(({ User->caughtMessage() }), "Long sword")));
}

/////////////////////////////////////////////////////////////////////////////
void SelectCraftingDisplaysCraftingSkillSubmenu()
{
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectTrue(sizeof(regexp(({ User->caughtMessage() }), "Weapon smithing")));
}

/////////////////////////////////////////////////////////////////////////////
void SelectEruditeDisplaysEruditeSkillSubmenu()
{
    Selector->initiateSelector(User);
    Selector->applySelection("3");
    ExpectTrue(sizeof(regexp(({ User->caughtMessage() }), "Astronomy")));
}

/////////////////////////////////////////////////////////////////////////////
void SelectGeneralDisplaysGeneralSkillSubmenu()
{
    Selector->initiateSelector(User);
    Selector->applySelection("4");
    ExpectTrue(sizeof(regexp(({ User->caughtMessage() }), "Cooking")));
}

/////////////////////////////////////////////////////////////////////////////
void SelectLanguageDisplaysLanguageSkillSubmenu()
{
    Selector->initiateSelector(User);
    Selector->applySelection("5");
    ExpectTrue(sizeof(regexp(({ User->caughtMessage() }), "Elven")));
}

/////////////////////////////////////////////////////////////////////////////
void SelectMagicDisplaysMagicSkillSubmenu()
{
    Selector->initiateSelector(User);
    Selector->applySelection("6");
    ExpectTrue(sizeof(regexp(({ User->caughtMessage() }), "Divination")));
}

/////////////////////////////////////////////////////////////////////////////
void SelectSubterfugeDisplaysSubterfugeSkillSubmenu()
{
    Selector->initiateSelector(User);
    Selector->applySelection("7");
    ExpectTrue(sizeof(regexp(({ User->caughtMessage() }), "Search")));
}

/////////////////////////////////////////////////////////////////////////////
void SelectItemFromSubmenuReturnsToMainAndDecrementsPointsRemaining()
{
    Selector->initiateSelector(User);
    ExpectTrue(sizeof(regexp(({ User->caughtMessage() }), "You have 14 skills left")));

    Selector->applySelection("1");
    ExpectTrue(sizeof(regexp(({ User->caughtMessage() }), "Long sword")));
   
    object subselector = all_inventory(User)[0];
    ExpectTrue(objectp(subselector));
    subselector->applySelection("1");
    ExpectTrue(sizeof(regexp(({ User->caughtMessage() }), "You have 13 skills left")));
}

/////////////////////////////////////////////////////////////////////////////
void SelectAllAvailableSkillsFiresOnSelectorCompleted()
{
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(User);

    for (int i = 1; i < 15; i++)
    {
        Selector->applySelection("1");
        ExpectEq(0, subscriber->TimesEventReceived());

        object subselector = all_inventory(User)[0];
        ExpectTrue(objectp(subselector));
        subselector->applySelection(to_string(i));

        if (i < 14)
        {
            ExpectTrue(sizeof(regexp(({ User->caughtMessage() }),
                sprintf("You have %d skills left", 14 - i))));
        }
    }
    ExpectEq(1, subscriber->TimesEventReceived(), "event received once");
}
