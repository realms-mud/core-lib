//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/crafting/craftItemSelector.c");
    Selector->setType("armor");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithoutAnyPrereqsMetDisplaysCorrectly()
{
    Selector->initiateSelector(Player);

    ExpectEq("\x1b[0;36mCraft Armor - \x1b[0m\x1b[0;37;1mFrom this menu, you can craft items\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mAccessory           \x1b[0m\n"
        "    [\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mClothing            \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mHeavy armor         \x1b[0m\n"
        "    [\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mLight armor         \x1b[0m\n"
        "    [\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mMedium armor        \x1b[0m\n"
        "    [\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mExit Craft Armor Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 6.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingAccessoryDisplaysAccessoryMenu()
{
    Selector->initiateSelector(Player);
    command("1", Player);

    ExpectSubStringMatch("36mCraft Accessory.*Exit Craft Accessory",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingClothingDisplaysClothingMenu()
{
    Selector->initiateSelector(Player);
    command("2", Player);

    ExpectSubStringMatch("36mCraft Clothing.*Exit Craft Clothing",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingHeavyArmorDisplaysHeavyArmorMenu()
{
    Selector->initiateSelector(Player);
    command("3", Player);

    ExpectSubStringMatch("36mCraft Heavy armor.*Exit Craft Heavy armor",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingLightArmorDisplaysLightArmorMenu()
{
    Selector->initiateSelector(Player);
    command("4", Player);

    ExpectSubStringMatch("36mCraft Light armor.*Exit Craft Light armor",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingMediumArmorDisplaysMediumArmorMenu()
{
    Selector->initiateSelector(Player);
    command("5", Player);

    ExpectSubStringMatch("36mCraft Medium armor.*Exit Craft Medium armor",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingExitReturnsToTopLevelMenu()
{
    Selector->initiateSelector(Player);
    command("6", Player);

    ExpectSubStringMatch("You have selected 'Exit Craft Armor Menu'",
        Player->caughtMessage());
}