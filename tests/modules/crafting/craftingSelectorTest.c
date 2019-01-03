//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/crafting/craftingSelector.c");

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

    ExpectEq("\x1b[0;36mCrafting - \x1b[0m\x1b[0;37;1mMain Menu\x1b[0m:\n"
        "[\x1b[0;31;1m1\x1b[0m] - \x1b[0;31mCraft Armor, Clothing, and Jewelry       \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m2\x1b[0m] - \x1b[0;31mCraft Artwork                            \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m3\x1b[0m] - \x1b[0;31mCraft Musical Instrument                 \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m4\x1b[0m] - \x1b[0;31mCraft Weapons                            \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m5\x1b[0m] - \x1b[0;31mBrew Potions                             \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m6\x1b[0m] - \x1b[0;31mBrew Beverages and Prepare Food          \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m7\x1b[0m] - \x1b[0;31mRefine Materials                         \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m8\x1b[0m] - \x1b[0;31mImbue with Magical Effects               \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m9\x1b[0m] - \x1b[0;32mExit Crafting Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 9.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithCraftWeaponPrereqMetDisplaysCorrectly()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/craftWeapons.c"), "added research");
    Selector->initiateSelector(Player);

    ExpectEq("\x1b[0;36mCrafting - \x1b[0m\x1b[0;37;1mMain Menu\x1b[0m:\n"
        "[\x1b[0;31;1m1\x1b[0m] - \x1b[0;31mCraft Armor, Clothing, and Jewelry       \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m2\x1b[0m] - \x1b[0;31mCraft Artwork                            \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m3\x1b[0m] - \x1b[0;31mCraft Musical Instrument                 \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mCraft Weapons\x1b[0m\n"
        "[\x1b[0;31;1m5\x1b[0m] - \x1b[0;31mBrew Potions                             \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m6\x1b[0m] - \x1b[0;31mBrew Beverages and Prepare Food          \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m7\x1b[0m] - \x1b[0;31mRefine Materials                         \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m8\x1b[0m] - \x1b[0;31mImbue with Magical Effects               \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m9\x1b[0m] - \x1b[0;32mExit Crafting Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 9.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectUnavailableOptionReturnsToMainMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/craftWeapons.c"), "added research");
    Selector->initiateSelector(Player);
    command("1", Player);

    ExpectEq("\x1b[0;36mCrafting - \x1b[0m\x1b[0;37;1mMain Menu\x1b[0m:\n"
        "[\x1b[0;31;1m1\x1b[0m] - \x1b[0;31mCraft Armor, Clothing, and Jewelry       \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m2\x1b[0m] - \x1b[0;31mCraft Artwork                            \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m3\x1b[0m] - \x1b[0;31mCraft Musical Instrument                 \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mCraft Weapons\x1b[0m\n"
        "[\x1b[0;31;1m5\x1b[0m] - \x1b[0;31mBrew Potions                             \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m6\x1b[0m] - \x1b[0;31mBrew Beverages and Prepare Food          \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m7\x1b[0m] - \x1b[0;31mRefine Materials                         \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m8\x1b[0m] - \x1b[0;31mImbue with Magical Effects               \x1b[0m\x1b[0;35m(Missing Prerequisites)\x1b[0m\n"
        "[\x1b[0;31;1m9\x1b[0m] - \x1b[0;32mExit Crafting Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 9.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m\x1b[0;32;1m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithCraftArmorPrereqMetDisplaysCorrectly()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftArmor.c"), "added research");
    Selector->initiateSelector(Player);

    ExpectSubStringMatch("32mCraft Armor, Clothing, and Jewelry",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithCraftArtworkPrereqMetDisplaysCorrectly()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftArtwork.c"), "added research");
    Selector->initiateSelector(Player);

    ExpectSubStringMatch("32mCraft Artwork",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithCraftMusicalInstrumentPrereqMetDisplaysCorrectly()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftInstrument.c"), "added research");
    Selector->initiateSelector(Player);

    ExpectSubStringMatch("32mCraft Musical Instrument",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithBrewPotionsPrereqMetDisplaysCorrectly()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/brewPotions.c"), "added research");
    Selector->initiateSelector(Player);

    ExpectSubStringMatch("32mBrew Potions",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithBrewAndCookFoodMetDisplaysCorrectly()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/brewBeveragesAndCookFood.c"), "added research");
    Selector->initiateSelector(Player);

    ExpectSubStringMatch("32mBrew Beverages and Prepare Food",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithImbuePrereqMetDisplaysCorrectly()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/enchantments/imbueItems.c"), "added research");
    Player->Int(10);
    Player->addSkillPoints(20);
    Player->advanceSkill("spellcraft", 10);
    Selector->initiateSelector(Player);

    ExpectSubStringMatch("32mImbue with Magical Effects",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithRefineMaterialPrereqMetDisplaysCorrectly()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/refineMaterials.c"), "added research");
    Selector->initiateSelector(Player);

    ExpectSubStringMatch("32mRefine Materials",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescriptionsAreDisplayed()
{
    Selector->initiateSelector(Player);
    command("? 1", Player);
    ExpectSubStringMatch("This option lets you create armors",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingCraftArmorDisplaysCorrectSubmenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftArmor.c"), "added research");
    Selector->initiateSelector(Player);
    command("1", Player);
    ExpectSubStringMatch("36mCraft Armor.*From this menu, you can craft items",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingExitExitsSelector()
{
    Selector->initiateSelector(Player);
    command("9", Player);
    ExpectSubStringMatch("You have selected 'Exit Crafting Menu'",
        Player->caughtMessage());
}
