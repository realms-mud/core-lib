//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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

    Player->Wis(50);
    Player->Str(50);
    Player->Int(50);
    Player->addSkillPoints(500);
    Player->advanceSkill("sewing", 10);
    Player->advanceSkill("metal crafting", 10);
    Player->advanceSkill("armorer", 10);
    Player->advanceSkill("blacksmithing", 10);
    Player->advanceSkill("chemistry", 10);
    Player->advanceSkill("physics", 10);
    Player->addResearchPoints(20);

    object material = clone_object("/lib/instances/items/materials/textile/silk.c");
    material->set("quantity", 15);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/iron.c");
    material->set("quantity", 15);
    move_object(material, Player);

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingClothingDisplaysClothingMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftClothing.c"));
    Selector->initiateSelector(Player);
    command("2", Player);

    ExpectEq("\x1b[0;36mCraft Clothing - \x1b[0m\x1b[0;37;1mFrom this menu, you can craft items\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;31mCloak               \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;31mDress               \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;31mGown                \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;31mKilt                \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;31mOrnate robes        \x1b[0m\x1b[0;35m(P,M)\x1b[0m"
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;31mPants               \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mRobes               \x1b[0m     "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;31mShirt               \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;31mShorts              \x1b[0m\x1b[0;35m(P)\x1b[0m  "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;31mSkirt               \x1b[0m\x1b[0;35m(P)\x1b[0m  \n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mExit Craft Clothing Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 11.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;35mP\x1b[0m\x1b[0;32m denotes unrealized prerequisites.\n"
        "\x1b[0m\x1b[0;35mM\x1b[0m\x1b[0;32m denotes that proper quantities of the material requirements are missing.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingRobesDisplaysRobesMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftClothing.c"));
    Selector->initiateSelector(Player);
    command("2", Player);
    command("7", Player);

    ExpectEq("\x1b[0;36mCraft Robes - \x1b[0m\x1b[0;37;1mFrom this menu, you "
        "will select the components that will be used\nto craft your robes. "
        "The relative statistics for the item you are creating\nare:\n\n"
        "\x1b[0m\x1b[0;36m    Material: \x1b[0;31mnone selected\x1b[0m\n"
        "\x1b[0;36m    Damage Protection: \x1b[0m\x1b[0;33m1\x1b[0m\n"
        "\x1b[0;36m    Encumberance: \x1b[0m\x1b[0;33m6\x1b[0m\n"
        "\x1b[0;36m    Weight: \x1b[0m\x1b[0;33m4\x1b[0m\n\x1b[0m\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mSelect Textile      \x1b[0m\n"
        "    [\x1b[0;31;1m2\x1b[0m] - \x1b[0;31mEnchant Robes       \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mGive robes a name   \x1b[0m\n"
        "    [\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mGive robes a special description\x1b[0m\n"
        "    [\x1b[0;31;1m5\x1b[0m] - \x1b[0;31mCraft Selected Robes\x1b[0m\n"
        "    [\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mExit Craft Robes Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 6.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes that a specific component type has been chosen.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingSelectMaterialDisplaysMaterialMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftClothing.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftTextiles.c"));
    Player->advanceSkill("weaving and beadwork", 10);
    Selector->initiateSelector(Player);
    command("2", Player);
    command("7", Player);
    command("1", Player);

    ExpectSubStringMatch("31mAsur.*32mSilk.*Exit Select Textile",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingMaterialUpdatesRobesMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftClothing.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftTextiles.c"));
    Player->advanceSkill("weaving and beadwork", 10);
    Selector->initiateSelector(Player);
    command("2", Player);
    command("7", Player);
    command("1", Player);
    command("17", Player);

    ExpectEq("\x1b[0;36mCraft Robes - \x1b[0m\x1b[0;37;1mFrom this menu, you "
        "will select the components that will be used\nto craft your robes. "
        "The relative statistics for the item you are creating\nare:\n\n"
        "\x1b[0m\x1b[0;36m    Material: \x1b[0m\x1b[0;33mSilk\x1b[0m\n"
        "\x1b[0;36m    Damage Protection: \x1b[0m\x1b[0;33m2\x1b[0m\n"
        "\x1b[0;36m    Encumberance: \x1b[0m\x1b[0;33m5\x1b[0m\n"
        "\x1b[0;36m    Weight: \x1b[0m\x1b[0;33m3\x1b[0m\n\x1b[0m\n"
        "    [\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mSelect Textile      \x1b[0m\x1b[0;34;1m   (*)\x1b[0m\n"
        "    [\x1b[0;31;1m2\x1b[0m] - \x1b[0;31mEnchant Robes       \x1b[0m\n"
        "    [\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mGive robes a name   \x1b[0m\n"
        "    [\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mGive robes a special description\x1b[0m\n"
        "    [\x1b[0;31;1m5\x1b[0m] - \x1b[0;32mCraft Selected Robes\x1b[0m\n"
        "    [\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mExit Craft Robes Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 6.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes that a specific component type has been chosen.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CraftingArmorMovesArmorToUserAndConsumesMaterials()
{
    Player->advanceSkill("spellcraft", 20);
    Player->advanceSkill("elemental fire", 20);
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/enchantments/craftEnchantments.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/enchantments/fire/craftFireEnchantment.c"));
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/craftingBonusesResearch.c"));

    ExpectFalse(present("robes", Player));

    object silk = present("silk", Player);
    ExpectEq(15, silk->query("quantity"));

    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftClothing.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftTextiles.c"));
    Player->advanceSkill("weaving and beadwork", 10);
    Selector->initiateSelector(Player);
    command("2", Player);
    command("7", Player);
    command("1", Player);
    command("17", Player);
    command("2", Player);
    command("4", Player);
    command("12", Player);
    command("23", Player);
    command("8", Player);

    ExpectSubStringMatch("Fire resistance .x1", Player->caughtMessage());
    command("5", Player);

    ExpectTrue(present("robes", Player));
    ExpectEq(5, silk->query("quantity"));

    ExpectSubStringMatch("31mRobes", Player->caughtMessage());

    ExpectSubStringMatch("4 fire", present("robes", Player)->long());
}

/////////////////////////////////////////////////////////////////////////////
void CanSetNameAndDescription()
{
    Player->advanceSkill("spellcraft", 20);
    Player->advanceSkill("elemental fire", 20);
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/enchantments/craftEnchantments.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/enchantments/fire/craftFireEnchantment.c"));
    ExpectTrue(Player->initiateResearch("lib/tests/support/research/craftingBonusesResearch.c"));

    ExpectFalse(present("robes", Player));

    object silk = present("silk", Player);
    ExpectEq(15, silk->query("quantity"));

    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftClothing.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftTextiles.c"));
    Player->advanceSkill("weaving and beadwork", 10);
    Selector->initiateSelector(Player);
    command("2", Player);
    command("7", Player);
    command("1", Player);
    command("17", Player);
    command("2", Player);
    command("4", Player);
    command("12", Player);
    command("23", Player);
    command("8", Player);
    ExpectSubStringMatch("Give robes a name +..0m", Player->caughtMessage());
    ExpectSubStringMatch("Give robes a special description..0m", Player->caughtMessage());
    command("3", Player);
    command("Blah", Player);
    command("4", Player);
    command("this is a", Player);
    command("description", Player);
    command("**", Player);
    ExpectSubStringMatch("Give robes a name.*Blah", Player->caughtMessage());
    ExpectSubStringMatch("Give robes a special description.*[*]", Player->caughtMessage());
    command("5", Player);

    object robes = present("robes", Player);
    ExpectTrue(robes);
    ExpectEq("Blah", robes->query("name"));
    ExpectEq("this is a\ndescription\n", robes->query("long"));
}

/////////////////////////////////////////////////////////////////////////////
void CanCraftHeavyArmor()
{
    object admantite = clone_object("/lib/instances/items/materials/metal/admantite.c");
    admantite->set("quantity", 15);
    move_object(admantite, Player);
    ExpectEq(15, admantite->query("quantity"));
    ExpectTrue(present("admantite", Player), "admantite present");

    ExpectFalse(present("plate", Player), "plate not present");

    object silk = present("silk", Player);
    ExpectEq(15, silk->query("quantity"));

    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftArmor.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/heavy-armor/craftHeavyArmor.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/heavy-armor/craftPlateArmor.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftTextiles.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftCommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftUncommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftAlloy.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftRareMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftPreciousMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftMythicMetal.c"));
    Player->advanceSkill("weaving and beadwork", 10);

    Selector->initiateSelector(Player);
    command("3", Player);
    command("6", Player);
    command("1", Player);
    command("1", Player);
    command("2", Player);
    command("17", Player);
    command("6", Player);

    ExpectTrue(present("plate", Player), "plate now present");
    ExpectFalse(present("admantite", Player), "admantite not present");
    ExpectEq(11, silk->query("quantity"));
}
