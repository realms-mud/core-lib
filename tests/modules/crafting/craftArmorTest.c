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

    ExpectEq("[0;36mCraft Clothing - [0m[0;37;1mFrom this menu, you can craft items[0m:\n"
        "    [[0;31;1m1[0m]  - [0;31mCloak               [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m2[0m]  - [0;31mDress               [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m3[0m]  - [0;31mGown                [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m4[0m]  - [0;31mKilt                [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m5[0m]  - [0;31mOrnate robes        [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m6[0m]  - [0;31mPants               [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m7[0m]  - [0;32mRobes               [0m     "
        "    [[0;31;1m8[0m]  - [0;31mShirt               [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m9[0m]  - [0;31mShorts              [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m10[0m] - [0;31mSkirt               [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m11[0m] - [0;32mExit Craft Clothing Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 11.\n[0m"
        "[0;32mType 'exit' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that proper quantities of the material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingRobesDisplaysRobesMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftClothing.c"));
    Selector->initiateSelector(Player);
    command("2", Player);
    command("7", Player);

    ExpectEq("[0;36mCraft Robes - [0m[0;37;1mFrom this menu, you will select the\n"
        "components that will be used to craft your robes. The relative statistics\n"
        "for the item you are creating are:\n"
        "\t[0;36mMaterial: [0;31mnone selected[0m\n"
        "\t[0;36mDamage Protection: [0m[0;33m1[0m\n"
        "\t[0;36mEncumberance: [0m[0;33m6[0m\n"
        "\t[0;36mWeight: [0m[0;33m4[0m\n[0m\n"
        "\t[[0;31;1m1[0m] - [0;32mSelect Textile      [0m\n"
        "\t[[0;31;1m2[0m] - [0;31mEnchant Robes       [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mGive robes a name   [0m\n"
        "\t[[0;31;1m4[0m] - [0;32mGive robes a special description[0m\n"
        "\t[[0;31;1m5[0m] - [0;31mCraft Selected Robes[0m\n"
        "\t[[0;31;1m6[0m] - [0;32mExit Craft Robes Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 6.\n[0m"
        "[0;32mType 'exit' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35;1m(*)[0m[0;32m denotes that a specific component type has been chosen.\n[0m",
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

    ExpectEq("[0;36mCraft Robes - [0m[0;37;1mFrom this menu, you will select the\n"
        "components that will be used to craft your robes. The relative statistics\n"
        "for the item you are creating are:\n"
        "\t[0;36mMaterial: [0m[0;33mSilk[0m\n"
        "\t[0;36mDamage Protection: [0m[0;33m2[0m\n"
        "\t[0;36mEncumberance: [0m[0;33m5[0m\n"
        "\t[0;36mWeight: [0m[0;33m3[0m\n[0m\n"
        "\t[[0;31;1m1[0m] - [0;32mSelect Textile      [0m[0;35;1m   (*)[0m\n"
        "\t[[0;31;1m2[0m] - [0;31mEnchant Robes       [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mGive robes a name   [0m\n"
        "\t[[0;31;1m4[0m] - [0;32mGive robes a special description[0m\n"
        "\t[[0;31;1m5[0m] - [0;32mCraft Selected Robes[0m\n"
        "\t[[0;31;1m6[0m] - [0;32mExit Craft Robes Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 6.\n[0m"
        "[0;32mType 'exit' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35;1m(*)[0m[0;32m denotes that a specific component type has been chosen.\n[0m",
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
    command("3", Player);
    command("12", Player);
    command("23", Player);
    command("7", Player);

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
    command("3", Player);
    command("12", Player);
    command("23", Player);
    command("7", Player);
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
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftPlateArmor.c"));
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
