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
    Player->advanceSkill("metal crafting", 50);
    Player->advanceSkill("gem crafting", 20);
    Player->advanceSkill("armorer", 10);
    Player->advanceSkill("blacksmithing", 10);
    Player->advanceSkill("chemistry", 10);
    Player->advanceSkill("physics", 10);
    Player->advanceSkill("sculpture", 10);
    Player->addResearchPoints(20);

    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftJewelry.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftCommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftUncommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftAlloy.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftRareMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftPreciousMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftMythicMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftGems.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftRareGems.c"));

    object material = clone_object("/lib/instances/items/materials/textile/silk.c");
    material->set("quantity", 15);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 15);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/gold.c");
    material->set("quantity", 15);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/crystal/ruby.c");
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
    Selector->initiateSelector(Player);
    command("1", Player);

    ExpectEq("[0;36mCraft Accessory - [0m[0;37;1mFrom this menu, you can craft items[0m:\n"
        "    [[0;31;1m1[0m]  - [0;32mAmulet              [0m     "
        "    [[0;31;1m2[0m]  - [0;31mBelt                [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m3[0m]  - [0;31mBoots               [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m4[0m]  - [0;31mBracelet            [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m5[0m]  - [0;31mBracers             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m6[0m]  - [0;32mCirclet             [0m     \n"
        "    [[0;31;1m7[0m]  - [0;31mCoif                [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m8[0m]  - [0;32mCrown               [0m     \n"
        "    [[0;31;1m9[0m]  - [0;32mDiadem              [0m     "
        "    [[0;31;1m10[0m] - [0;31mGauntlets           [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m11[0m] - [0;31mGloves              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m12[0m] - [0;31mHat                 [0m[0;34;1m([0;35mP[0;34;1m)[0m  \n"
        "    [[0;31;1m13[0m] - [0;31mHelm                [0m[0;34;1m([0;35mP,M[0;34;1m)[0m"
        "    [[0;31;1m14[0m] - [0;31mHelmet              [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m15[0m] - [0;32mNecklace            [0m     "
        "    [[0;31;1m16[0m] - [0;32mRing                [0m     \n"
        "    [[0;31;1m17[0m] - [0;31mSabaton             [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m18[0m] - [0;31mSandals             [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m19[0m] - [0;31mSash                [0m[0;34;1m([0;35mP[0;34;1m)[0m  "
        "    [[0;31;1m20[0m] - [0;31mShoes               [0m[0;34;1m([0;35mP,M[0;34;1m)[0m\n"
        "    [[0;31;1m21[0m] - [0;32mTiara               [0m     "
        "    [[0;31;1m22[0m] - [0;32mExit Craft Accessory Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 22.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that proper quantities of the material requirements are missing.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingRingDisplaysRingMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/armor/craftClothing.c"));
    Selector->initiateSelector(Player);
    command("1", Player);
    command("16", Player);

    ExpectEq("[0;36mCraft Ring - [0m[0;37;1mFrom this menu, you will select the\n"
        "components that will be used to craft your ring. The relative statistics\n"
        "for the item you are creating are:\n"
        "\t[0;36mMaterial: [0;31mnone selected[0m\n[0m\n"
        "\t[[0;31;1m1[0m] - [0;32mSelect Metal        [0m\n"
        "\t[[0;31;1m2[0m] - [0;32mSelect Ring design  [0m\n"
        "\t[[0;31;1m3[0m] - [0;31mEnchant Ring        [0m\n"
        "\t[[0;31;1m4[0m] - [0;31mCraft Selected Ring [0m\n"
        "\t[[0;31;1m5[0m] - [0;32mExit Craft Ring Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 5.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
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
    command("1", Player);
    command("16", Player);
    command("1", Player);

    ExpectSubStringMatch("32mAdmantite.*31mAluminum.*Exit Select Metal",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingMaterialUpdatesRingMenu()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("16", Player);
    command("1", Player);
    command("1", Player);

    ExpectEq("[0;36mCraft Ring - [0m[0;37;1mFrom this menu, you will select the\n"
        "components that will be used to craft your ring. The relative statistics\n"
        "for the item you are creating are:\n"
        "\t[0;36mMaterial: [0m[0;33mAdmantite[0m\n[0m\n"
        "\t[[0;31;1m1[0m] - [0;32mSelect Metal        [0m[0;35;1m   (*)[0m\n"
        "\t[[0;31;1m2[0m] - [0;32mSelect Ring design  [0m\n"
        "\t[[0;31;1m3[0m] - [0;31mEnchant Ring        [0m\n"
        "\t[[0;31;1m4[0m] - [0;31mCraft Selected Ring [0m\n"
        "\t[[0;31;1m5[0m] - [0;32mExit Craft Ring Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 5.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35;1m(*)[0m[0;32m denotes that a specific component type has been chosen.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanAddComponentThatDoesNotModifyMaterials()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("16", Player);
    command("2", Player);
    command("10", Player);
    command("19", Player);

    ExpectEq("[0;36mCraft Ring - [0m[0;37;1mFrom this menu, you will select the\n"
        "components that will be used to craft your ring. The relative statistics\n"
        "for the item you are creating are:\n"
        "\t[0;36mMaterial: [0;31mnone selected[0m\n[0m\n"
        "\t[[0;31;1m1[0m] - [0;32mSelect Metal        [0m\n"
        "\t[[0;31;1m2[0m] - [0;32mSelect Ring design  [0m[0;35;1m   (*)[0m\n"
        "\t[[0;31;1m3[0m] - [0;31mEnchant Ring        [0m\n"
        "\t[[0;31;1m4[0m] - [0;31mCraft Selected Ring [0m\n"
        "\t[[0;31;1m5[0m] - [0;32mExit Craft Ring Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 5.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35;1m(*)[0m[0;32m denotes that a specific component type has been chosen.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotSelectComponentUntilMaterialsChosen()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("16", Player);
    command("2", Player);
    command("7", Player);

    ExpectSubStringMatch("31mConfirm", Player->caughtMessage());

    command("1", Player);
    command("25", Player);
    ExpectSubStringMatch("31mConfirm", Player->caughtMessage());

    command("2", Player);
    command("16", Player);
    ExpectSubStringMatch("32mConfirm", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectComponentIfUnusedMaterialTypeNotSelected()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("16", Player);
    command("2", Player);
    command("3", Player);

    ExpectSubStringMatch("31mConfirm", Player->caughtMessage());

    command("2", Player);
    command("16", Player);
    ExpectSubStringMatch("32mConfirm", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanCraftItemWithBothPrimaryMaterialAndComponent()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("16", Player);
    command("2", Player);
    command("7", Player);
    command("1", Player);
    command("25", Player);
    command("2", Player);
    command("16", Player);
    command("19", Player);
    command("1", Player);
    command("1", Player);
    command("4", Player);

    ExpectSubStringMatch("The ring design is a ring of gold and admantite that has been intricately\n"
        "carved into the shape of an eagle's talon embossed with gold. It is clutching\n"
        "a large ruby.", present("ring", Player)->long());
}
