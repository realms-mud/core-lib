//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    ExpectEq("\x1b[0;36mCharacter creation - \x1b[0m\x1b[0;37;1mChoose a class of skills to advance\x1b[0m:\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mCombat              \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mCrafting            \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mErudite             \x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mGeneral             \x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mLanguage            \x1b[0m\n"
        "\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mMagic               \x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m] - \x1b[0;32mSubterfuge          \x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 7. You may also undo or reset.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1mYou have 14 skills left to assign.\n\x1b[0m",
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
                sprintf("You have %d skills* left", 14 - i))));
        }
    }
    ExpectEq(1, subscriber->TimesEventReceived(), "event received once");
}
