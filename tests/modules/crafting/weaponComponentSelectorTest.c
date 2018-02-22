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
    Selector = clone_object("/lib/modules/crafting/selectMaterialsSelector.c");
    Selector->setItem("long sword");
    Selector->setType("weapons");
    Selector->setSubType("swords");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();

    Player->Wis(50);
    Player->Str(50);
    Player->Int(50);
    Player->addSkillPoints(500);
    Player->advanceSkill("blacksmithing", 20);
    Player->advanceSkill("metal crafting", 10);
    Player->advanceSkill("weapon smithing", 10);
    Player->advanceSkill("chemistry", 10);
    Player->advanceSkill("physics", 10);
    Player->addResearchPoints(20);

    object material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 5);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material->set("quantity", 6);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/steel.c");
    material->set("quantity", 10);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/iron.c");
    material->set("quantity", 3);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/iron.c");
    material->set("quantity", 5);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/wood/koa.c");
    material->set("quantity", 5);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/leather/pegasus-leather.c");
    material->set("quantity", 5);
    move_object(material, Player);

    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/craftWeapons.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/swords/craftBasicSwords.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/weapons/swords/craftLongSwords.c"));

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void SpecificWeaponMenuDisplaysCorrectly()
{
    Selector->initiateSelector(Player);

    ExpectEq("[0;36mCraft Long sword - [0m[0;37;1mFrom this menu, you will select the\n"
        "components that will be used to craft your long sword. The relative statistics\n"
        "for the item you are creating are:\n"
        "\t[0;36mMaterial: [0;31mnone selected[0m\n"
        "\t[0;36mAttack: [0m[0;33m5 to 105[0m\n"
        "\t[0;36mDamage: [0m[0;33m8 to 11[0m\n"
        "\t[0;36mDefense: [0m[0;33m1 to 2[0m\n"
        "\t[0;36mEncumberance: [0m[0;33m5[0m\n"
        "\t[0;36mWeight: [0m[0;33m5[0m\n[0m\n"
        "\t[[0;31;1m1[0m] - [0;32mSelect Blade        [0m\n"
        "\t[[0;31;1m2[0m] - [0;32mSelect Crossguard   [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mSelect Hilt         [0m\n"
        "\t[[0;31;1m4[0m] - [0;32mSelect Pommel       [0m\n"
        "\t[[0;31;1m5[0m] - [0;31mEnchant Long sword  [0m\n"
        "\t[[0;31;1m6[0m] - [0;31mCraft Selected Long sword[0m\n"
        "\t[[0;31;1m7[0m] - [0;32mExit Craft Long sword Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 7.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35;1m(*)[0m[0;32m denotes that a specific component type has been chosen.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeShowsDetailsAboutComponent()
{
    Selector->initiateSelector(Player);
    command("? 1", Player);

    ExpectSubStringMatch("This option lets you craft the blade for your long sword",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingComponentDisplaysComponentMenu()
{
    Selector->initiateSelector(Player);
    command("1", Player);

    ExpectEq("[0;36mCraft Blade - [0m[0;37;1mSelect materials and the type of blade you will craft[0m:\n"
        "    [[0;31;1m1[0m]  - [0;32mSelect metal        [0m[0;35;1mnone[0m     "
        "    [[0;31;1m2[0m]  - [0;32mFlamberge           [0m         \n"
        "    [[0;31;1m3[0m]  - [0;32mSerrated            [0m         "
        "    [[0;31;1m4[0m]  - [0;32mType X              [0m         \n"
        "    [[0;31;1m5[0m]  - [0;32mType XI             [0m         "
        "    [[0;31;1m6[0m]  - [0;32mType XIII           [0m         \n"
        "    [[0;31;1m7[0m]  - [0;32mType XIIa           [0m         "
        "    [[0;31;1m8[0m]  - [0;32mType XIV            [0m         \n"
        "    [[0;31;1m9[0m]  - [0;32mType XIX            [0m         "
        "    [[0;31;1m10[0m] - [0;32mType XIa            [0m         \n"
        "    [[0;31;1m11[0m] - [0;32mType XV             [0m         "
        "    [[0;31;1m12[0m] - [0;32mType XVI            [0m         \n"
        "    [[0;31;1m13[0m] - [0;32mType XVII           [0m         "
        "    [[0;31;1m14[0m] - [0;32mType XVIII          [0m         \n"
        "    [[0;31;1m15[0m] - [0;32mType XVIIIa         [0m         "
        "    [[0;31;1m16[0m] - [0;32mType XVIIIb         [0m         \n"
        "    [[0;31;1m17[0m] - [0;32mType XVIIIc         [0m         "
        "    [[0;31;1m18[0m] - [0;32mType XVIIId         [0m         \n"
        "    [[0;31;1m19[0m] - [0;32mType XVIIIe         [0m         "
        "    [[0;31;1m20[0m] - [0;32mType XVa            [0m         \n"
        "    [[0;31;1m21[0m] - [0;32mType XX             [0m         "
        "    [[0;31;1m22[0m] - [0;32mType XXI            [0m         \n"
        "    [[0;31;1m23[0m] - [0;32mType XXII           [0m         "
        "    [[0;31;1m24[0m] - [0;32mType Xa             [0m         \n"
        "    [[0;31;1m25[0m] - [0;31mConfirm Selection   [0m         "
        "    [[0;31;1m26[0m] - [0;32mCancel Selection    [0m         \n"
        "[0;32;1mYou must select a number from 1 to 26.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35;1m<material>[0m[0;32m denotes a selected material.\n"
        "[0;35;1m(*)[0m[0;32m denotes that a specific component type has been chosen.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingMaterialChangesSelectedComponentInMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftCommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftUncommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftAlloy.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftRareMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftPreciousMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftMythicMetal.c"));
    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);

    ExpectEq("[0;36mCraft Blade - [0m[0;37;1mSelect materials and the type of blade you will craft[0m:\n"
        "    [[0;31;1m1[0m]  - [0;32mSelect metal        [0m[0;35;1madmantite[0m"
        "    [[0;31;1m2[0m]  - [0;32mFlamberge           [0m         \n"
        "    [[0;31;1m3[0m]  - [0;32mSerrated            [0m         "
        "    [[0;31;1m4[0m]  - [0;32mType X              [0m         \n"
        "    [[0;31;1m5[0m]  - [0;32mType XI             [0m         "
        "    [[0;31;1m6[0m]  - [0;32mType XIII           [0m         \n"
        "    [[0;31;1m7[0m]  - [0;32mType XIIa           [0m         "
        "    [[0;31;1m8[0m]  - [0;32mType XIV            [0m         \n"
        "    [[0;31;1m9[0m]  - [0;32mType XIX            [0m         "
        "    [[0;31;1m10[0m] - [0;32mType XIa            [0m         \n"
        "    [[0;31;1m11[0m] - [0;32mType XV             [0m         "
        "    [[0;31;1m12[0m] - [0;32mType XVI            [0m         \n"
        "    [[0;31;1m13[0m] - [0;32mType XVII           [0m         "
        "    [[0;31;1m14[0m] - [0;32mType XVIII          [0m         \n"
        "    [[0;31;1m15[0m] - [0;32mType XVIIIa         [0m         "
        "    [[0;31;1m16[0m] - [0;32mType XVIIIb         [0m         \n"
        "    [[0;31;1m17[0m] - [0;32mType XVIIIc         [0m         "
        "    [[0;31;1m18[0m] - [0;32mType XVIIId         [0m         \n"
        "    [[0;31;1m19[0m] - [0;32mType XVIIIe         [0m         "
        "    [[0;31;1m20[0m] - [0;32mType XVa            [0m         \n"
        "    [[0;31;1m21[0m] - [0;32mType XX             [0m         "
        "    [[0;31;1m22[0m] - [0;32mType XXI            [0m         \n"
        "    [[0;31;1m23[0m] - [0;32mType XXII           [0m         "
        "    [[0;31;1m24[0m] - [0;32mType Xa             [0m         \n"
        "    [[0;31;1m25[0m] - [0;31mConfirm Selection   [0m         "
        "    [[0;31;1m26[0m] - [0;32mCancel Selection    [0m         \n"
        "[0;32;1mYou must select a number from 1 to 26.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35;1m<material>[0m[0;32m denotes a selected material.\n"
        "[0;35;1m(*)[0m[0;32m denotes that a specific component type has been chosen.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingTypeFlagsChosenTypeInComponentMenu()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("6", Player);

    ExpectEq("[0;36mCraft Blade - [0m[0;37;1mSelect materials and the type of blade you will craft[0m:\n"
        "    [[0;31;1m1[0m]  - [0;32mSelect metal        [0m[0;35;1mnone[0m     "
        "    [[0;31;1m2[0m]  - [0;32mFlamberge           [0m         \n"
        "    [[0;31;1m3[0m]  - [0;32mSerrated            [0m         "
        "    [[0;31;1m4[0m]  - [0;32mType X              [0m         \n"
        "    [[0;31;1m5[0m]  - [0;32mType XI             [0m         "
        "    [[0;31;1m6[0m]  - [0;32mType XIII           [0m[0;35;1m   (*)[0m   \n"
        "    [[0;31;1m7[0m]  - [0;32mType XIIa           [0m         "
        "    [[0;31;1m8[0m]  - [0;32mType XIV            [0m         \n"
        "    [[0;31;1m9[0m]  - [0;32mType XIX            [0m         "
        "    [[0;31;1m10[0m] - [0;32mType XIa            [0m         \n"
        "    [[0;31;1m11[0m] - [0;32mType XV             [0m         "
        "    [[0;31;1m12[0m] - [0;32mType XVI            [0m         \n"
        "    [[0;31;1m13[0m] - [0;32mType XVII           [0m         "
        "    [[0;31;1m14[0m] - [0;32mType XVIII          [0m         \n"
        "    [[0;31;1m15[0m] - [0;32mType XVIIIa         [0m         "
        "    [[0;31;1m16[0m] - [0;32mType XVIIIb         [0m         \n"
        "    [[0;31;1m17[0m] - [0;32mType XVIIIc         [0m         "
        "    [[0;31;1m18[0m] - [0;32mType XVIIId         [0m         \n"
        "    [[0;31;1m19[0m] - [0;32mType XVIIIe         [0m         "
        "    [[0;31;1m20[0m] - [0;32mType XVa            [0m         \n"
        "    [[0;31;1m21[0m] - [0;32mType XX             [0m         "
        "    [[0;31;1m22[0m] - [0;32mType XXI            [0m         \n"
        "    [[0;31;1m23[0m] - [0;32mType XXII           [0m         "
        "    [[0;31;1m24[0m] - [0;32mType Xa             [0m         \n"
        "    [[0;31;1m25[0m] - [0;31mConfirm Selection   [0m         "
        "    [[0;31;1m26[0m] - [0;32mCancel Selection    [0m         \n"
        "[0;32;1mYou must select a number from 1 to 26.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35;1m<material>[0m[0;32m denotes a selected material.\n"
        "[0;35;1m(*)[0m[0;32m denotes that a specific component type has been chosen.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingComponentTypeAndRequiredMaterialEnablesConfirm()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftCommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftUncommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftAlloy.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftRareMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftPreciousMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftMythicMetal.c"));
    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("6", Player);

    ExpectEq("[0;36mCraft Blade - [0m[0;37;1mSelect materials and the type of blade you will craft[0m:\n"
        "    [[0;31;1m1[0m]  - [0;32mSelect metal        [0m[0;35;1madmantite[0m"
        "    [[0;31;1m2[0m]  - [0;32mFlamberge           [0m         \n"
        "    [[0;31;1m3[0m]  - [0;32mSerrated            [0m         "
        "    [[0;31;1m4[0m]  - [0;32mType X              [0m         \n"
        "    [[0;31;1m5[0m]  - [0;32mType XI             [0m         "
        "    [[0;31;1m6[0m]  - [0;32mType XIII           [0m[0;35;1m   (*)[0m   \n"
        "    [[0;31;1m7[0m]  - [0;32mType XIIa           [0m         "
        "    [[0;31;1m8[0m]  - [0;32mType XIV            [0m         \n"
        "    [[0;31;1m9[0m]  - [0;32mType XIX            [0m         "
        "    [[0;31;1m10[0m] - [0;32mType XIa            [0m         \n"
        "    [[0;31;1m11[0m] - [0;32mType XV             [0m         "
        "    [[0;31;1m12[0m] - [0;32mType XVI            [0m         \n"
        "    [[0;31;1m13[0m] - [0;32mType XVII           [0m         "
        "    [[0;31;1m14[0m] - [0;32mType XVIII          [0m         \n"
        "    [[0;31;1m15[0m] - [0;32mType XVIIIa         [0m         "
        "    [[0;31;1m16[0m] - [0;32mType XVIIIb         [0m         \n"
        "    [[0;31;1m17[0m] - [0;32mType XVIIIc         [0m         "
        "    [[0;31;1m18[0m] - [0;32mType XVIIId         [0m         \n"
        "    [[0;31;1m19[0m] - [0;32mType XVIIIe         [0m         "
        "    [[0;31;1m20[0m] - [0;32mType XVa            [0m         \n"
        "    [[0;31;1m21[0m] - [0;32mType XX             [0m         "
        "    [[0;31;1m22[0m] - [0;32mType XXI            [0m         \n"
        "    [[0;31;1m23[0m] - [0;32mType XXII           [0m         "
        "    [[0;31;1m24[0m] - [0;32mType Xa             [0m         \n"
        "    [[0;31;1m25[0m] - [0;32mConfirm Selection   [0m         "
        "    [[0;31;1m26[0m] - [0;32mCancel Selection    [0m         \n"
        "[0;32;1mYou must select a number from 1 to 26.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35;1m<material>[0m[0;32m denotes a selected material.\n"
        "[0;35;1m(*)[0m[0;32m denotes that a specific component type has been chosen.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CancelDoesNotSetValuesForWeaponCraftingMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftCommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftUncommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftAlloy.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftRareMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftPreciousMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftMythicMetal.c"));
    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("6", Player);
    command("26", Player);

    ExpectEq("[0;36mCraft Long sword - [0m[0;37;1mFrom this menu, you will select the\n"
        "components that will be used to craft your long sword. The relative statistics\n"
        "for the item you are creating are:\n"
        "\t[0;36mMaterial: [0;31mnone selected[0m\n"
        "\t[0;36mAttack: [0m[0;33m5 to 105[0m\n"
        "\t[0;36mDamage: [0m[0;33m8 to 11[0m\n"
        "\t[0;36mDefense: [0m[0;33m1 to 2[0m\n"
        "\t[0;36mEncumberance: [0m[0;33m5[0m\n"
        "\t[0;36mWeight: [0m[0;33m5[0m\n[0m\n"
        "\t[[0;31;1m1[0m] - [0;32mSelect Blade        [0m\n"
        "\t[[0;31;1m2[0m] - [0;32mSelect Crossguard   [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mSelect Hilt         [0m\n"
        "\t[[0;31;1m4[0m] - [0;32mSelect Pommel       [0m\n"
        "\t[[0;31;1m5[0m] - [0;31mEnchant Long sword  [0m\n"
        "\t[[0;31;1m6[0m] - [0;31mCraft Selected Long sword[0m\n"
        "\t[[0;31;1m7[0m] - [0;32mExit Craft Long sword Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 7.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35;1m(*)[0m[0;32m denotes that a specific component type has been chosen.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ConfirmSetsValuesForWeaponCraftingMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftCommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftUncommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftAlloy.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftRareMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftPreciousMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftMythicMetal.c"));
    Selector->initiateSelector(Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);
    command("6", Player);
    command("25", Player);

    ExpectEq("[0;36mCraft Long sword - [0m[0;37;1mFrom this menu, you will select the\n"
        "components that will be used to craft your long sword. The relative statistics\n"
        "for the item you are creating are:\n"
        "\t[0;36mMaterial: [0m[0;33mAdmantite[0m\n"
        "\t[0;36mAttack: [0m[0;33m8 to 108[0m\n"
        "\t[0;36mDamage: [0m[0;33m13 to 16[0m[0;31m [+2 magical][0m\n"
        "\t[0;36mDefense: [0m[0;33m1 to 2[0m\n"
        "\t[0;36mEncumberance: [0m[0;33m5[0m\n"
        "\t[0;36mWeight: [0m[0;33m5[0m\n[0m\n"
        "\t[[0;31;1m1[0m] - [0;32mSelect Blade        [0m[0;35;1m   (*)[0m\n"
        "\t[[0;31;1m2[0m] - [0;32mSelect Crossguard   [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mSelect Hilt         [0m\n"
        "\t[[0;31;1m4[0m] - [0;32mSelect Pommel       [0m\n"
        "\t[[0;31;1m5[0m] - [0;31mEnchant Long sword  [0m\n"
        "\t[[0;31;1m6[0m] - [0;31mCraft Selected Long sword[0m\n"
        "\t[[0;31;1m7[0m] - [0;32mExit Craft Long sword Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 7.\n[0m"
        "[0;32mType 'abort' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m"
        "[0;32;1m[0;35;1m(*)[0m[0;32m denotes that a specific component type has been chosen.\n[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ConfirmDoesNothingWhenDisabled()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("25", Player);

    ExpectSubStringMatch("31mConfirm Selection",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ComponentsWithAdditionalPrerequisitesAreDisabledWhenPrerequisitesNotMet()
{
    Selector->initiateSelector(Player);
    command("2", Player);

    ExpectSubStringMatch("31mDracolich Form.*",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CannotSelectDisabledComponents()
{
    Selector->initiateSelector(Player);
    command("2", Player);
    command("11", Player);

    ExpectSubStringMatch("31mDracolich Form[^*]*Dragon",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ComponentsAreEnabledWhenPrerequisitesAreMet()
{
    object material = clone_object("/lib/instances/items/materials/crystal/ruby.c");
    material->set("quantity", 5);
    move_object(material, Player);

    Player->advanceSkill("gem crafting", 10);
    Player->advanceSkill("sculpture", 15);

    Selector->initiateSelector(Player);
    command("2", Player);
    command("11", Player);

    ExpectSubStringMatch("32mDracolich Form.*[*].*Dragon",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ComponentDescriptionsShowPrerequisitesAndMaterialsNeeded()
{
    Selector->initiateSelector(Player);
    command("2", Player);
    command("? 11", Player);

    ExpectSubStringMatch("This is an ornate metal knuckleguard that has been sculpted to appear as\nthough a "
        "dracolich with crystal eyes is protecting the user's hand.*Prerequisites.*Gem crafting of 5.*"
        "Sculpture of 15.*Materials.*Crystal needed.*2",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void OnCraftingStartedIsEmittedWhenCraftingBegins()
{
    object eventSubscriber = clone_object("/lib/tests/support/events/craftingEventsSubscriber.c");
    Player->registerEvent(eventSubscriber);

    ExpectEq(([]), eventSubscriber->events());
    Selector->initiateSelector(Player);
    ExpectEq((["onCraftingStarted": "lib/instances/items/weapons/swords/long-sword.c"]), eventSubscriber->events());
}

/////////////////////////////////////////////////////////////////////////////
void OnCraftingAbortedIsEmittedWhenCraftingIsExited()
{
    object eventSubscriber = clone_object("/lib/tests/support/events/craftingEventsSubscriber.c");
    Player->registerEvent(eventSubscriber);

    ExpectEq(([]), eventSubscriber->events());
    Selector->initiateSelector(Player);
    eventSubscriber->clearEvents();

    command("7", Player);
    ExpectEq((["onCraftingAborted":1]), eventSubscriber->events());
}

/////////////////////////////////////////////////////////////////////////////
void OnCraftingAbortedIsEmittedWhenCraftingIsAborted()
{
    object eventSubscriber = clone_object("/lib/tests/support/events/craftingEventsSubscriber.c");
    Player->registerEvent(eventSubscriber);

    ExpectEq(([]), eventSubscriber->events());
    Selector->initiateSelector(Player);
    eventSubscriber->clearEvents();

    command("1", Player);
    command("abort", Player);
    ExpectEq((["onCraftingAborted":1]), eventSubscriber->events());
}

/////////////////////////////////////////////////////////////////////////////
void OnCraftingCompletedIsEmittedWhenCraftingIsCompleted()
{
    object material = clone_object("/lib/instances/items/materials/metal/gold.c");
    material->set("quantity", 3);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/platinum.c");
    material->set("quantity", 3);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/galvorn.c");
    material->set("quantity", 3);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/crystal/ruby.c");
    material->set("quantity", 5);
    move_object(material, Player);

    object eventSubscriber = clone_object("/lib/tests/support/events/craftingEventsSubscriber.c");
    Player->registerEvent(eventSubscriber);

    ExpectEq(([]), eventSubscriber->events());
    Selector->initiateSelector(Player);
    eventSubscriber->clearEvents();

    object sword = Player->itemBeingCrafted();
    sword->set("crafting materials", ([
        "blade": ([ "description": "a broad, flat, metal blade with parallel edges and a lenticular cross-section. The fuller is narrow and runs half of the length of the blade, ending in a rounded point.", 
                    "metal": "admantite", 
                    "type": "Type XIII",
                    "value": 110 
        ]), 
        "crossguard": ([ "crystal": "ruby", 
                    "description": "an ornate metal knuckleguard that has been sculpted to appear as though a dracolich with crystal eyes is protecting the user's hand.", 
                    "metal": "galvorn", 
                    "type": "Dracolich Form", 
                    "value": 325 
        ]), 
        "hilt": ([ "description": "a hilt of metal covered with a slightly ovular grip made out of wood and wrapped in spiraled metal wire.", 
                    "leather": "pegasus leather", 
                    "metal": "gold", 
                    "type": "Spiral Grip", "value": 15, 
                    "wood": "koa" 
        ]), 
        "pommel": ([ "crystal": "ruby", 
                    "description": "an exquisite metal pommel that has been intricately sculpted to resemble a dragon's talon. Clutched in its grip is a beautifully cut crystal.", 
                    "metal": "platinum", 
                    "type": "Dragon Talon", 
                    "value": 50
        ])
    ]));
    sword->set("material", "admantite");

    command("1", Player);
    command("25", Player);
    command("6", Player);

    ExpectEq((["onCraftingCompleted":"lib/instances/items/weapons/swords/long-sword.c"]), eventSubscriber->events());
}