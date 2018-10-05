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

    ExpectEq("\x1b[0;36mCraft Long sword - \x1b[0m\x1b[0;37;1mFrom this menu, you will select the\n"
        "components that will be used to craft your long sword. The relative statistics\n"
        "for the item you are creating are:\n"
        "\t\x1b[0;36mMaterial: \x1b[0;31mnone selected\x1b[0m\n"
        "\t\x1b[0;36mAttack: \x1b[0m\x1b[0;33m5 to 105\x1b[0m\n"
        "\t\x1b[0;36mDamage: \x1b[0m\x1b[0;33m8 to 11\x1b[0m\n"
        "\t\x1b[0;36mDefense: \x1b[0m\x1b[0;33m1 to 2\x1b[0m\n"
        "\t\x1b[0;36mEncumberance: \x1b[0m\x1b[0;33m5\x1b[0m\n"
        "\t\x1b[0;36mWeight: \x1b[0m\x1b[0;33m5\x1b[0m\n\x1b[0m\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mSelect Blade        \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mSelect Crossguard   \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mSelect Hilt         \x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mSelect Pommel       \x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;31mEnchant Long sword  \x1b[0m\n"
        "\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mGive long sword a name\x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m] - \x1b[0;32mGive long sword a special description\x1b[0m\n"
        "\t[\x1b[0;31;1m8\x1b[0m] - \x1b[0;31mCraft Selected Long sword\x1b[0m\n"
        "\t[\x1b[0;31;1m9\x1b[0m] - \x1b[0;32mExit Craft Long sword Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 9.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes that a specific component type has been chosen.\n\x1b[0m\x1b[0m",
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

    ExpectEq("\x1b[0;36mCraft Blade - \x1b[0m\x1b[0;37;1mSelect materials and the type of blade you will craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mSelect metal        \x1b[0m\x1b[0;34;1mnone\x1b[0m     "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mFlamberge           \x1b[0m         \n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mSerrated            \x1b[0m         "
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mType X              \x1b[0m         \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mType XI             \x1b[0m         "
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mType XIII           \x1b[0m         \n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mType XIIa           \x1b[0m         "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mType XIV            \x1b[0m         \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mType XIX            \x1b[0m         "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mType XIa            \x1b[0m         \n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mType XV             \x1b[0m         "
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mType XVI            \x1b[0m         \n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;32mType XVII           \x1b[0m         "
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;32mType XVIII          \x1b[0m         \n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;32mType XVIIIa         \x1b[0m         "
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;32mType XVIIIb         \x1b[0m         \n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;32mType XVIIIc         \x1b[0m         "
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;32mType XVIIId         \x1b[0m         \n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;32mType XVIIIe         \x1b[0m         "
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;32mType XVa            \x1b[0m         \n"
        "    [\x1b[0;31;1m21\x1b[0m] - \x1b[0;32mType XX             \x1b[0m         "
        "    [\x1b[0;31;1m22\x1b[0m] - \x1b[0;32mType XXI            \x1b[0m         \n"
        "    [\x1b[0;31;1m23\x1b[0m] - \x1b[0;32mType XXII           \x1b[0m         "
        "    [\x1b[0;31;1m24\x1b[0m] - \x1b[0;32mType Xa             \x1b[0m         \n"
        "    [\x1b[0;31;1m25\x1b[0m] - \x1b[0;31mConfirm Selection   \x1b[0m         "
        "    [\x1b[0;31;1m26\x1b[0m] - \x1b[0;32mCancel Selection    \x1b[0m         \n"
        "\x1b[0;32;1mYou must select a number from 1 to 26.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;34;1m<material>\x1b[0m\x1b[0;32m denotes a selected material.\n"
        "\x1b[0m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes that a specific component type has been chosen.\n\x1b[0m\x1b[0m",
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

    ExpectEq("\x1b[0;36mCraft Blade - \x1b[0m\x1b[0;37;1mSelect materials and the type of blade you will craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mSelect metal        \x1b[0m\x1b[0;34;1madmantite\x1b[0m"
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mFlamberge           \x1b[0m         \n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mSerrated            \x1b[0m         "
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mType X              \x1b[0m         \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mType XI             \x1b[0m         "
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mType XIII           \x1b[0m         \n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mType XIIa           \x1b[0m         "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mType XIV            \x1b[0m         \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mType XIX            \x1b[0m         "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mType XIa            \x1b[0m         \n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mType XV             \x1b[0m         "
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mType XVI            \x1b[0m         \n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;32mType XVII           \x1b[0m         "
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;32mType XVIII          \x1b[0m         \n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;32mType XVIIIa         \x1b[0m         "
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;32mType XVIIIb         \x1b[0m         \n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;32mType XVIIIc         \x1b[0m         "
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;32mType XVIIId         \x1b[0m         \n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;32mType XVIIIe         \x1b[0m         "
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;32mType XVa            \x1b[0m         \n"
        "    [\x1b[0;31;1m21\x1b[0m] - \x1b[0;32mType XX             \x1b[0m         "
        "    [\x1b[0;31;1m22\x1b[0m] - \x1b[0;32mType XXI            \x1b[0m         \n"
        "    [\x1b[0;31;1m23\x1b[0m] - \x1b[0;32mType XXII           \x1b[0m         "
        "    [\x1b[0;31;1m24\x1b[0m] - \x1b[0;32mType Xa             \x1b[0m         \n"
        "    [\x1b[0;31;1m25\x1b[0m] - \x1b[0;31mConfirm Selection   \x1b[0m         "
        "    [\x1b[0;31;1m26\x1b[0m] - \x1b[0;32mCancel Selection    \x1b[0m         \n"
        "\x1b[0;32;1mYou must select a number from 1 to 26.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;34;1m<material>\x1b[0m\x1b[0;32m denotes a selected material.\n"
        "\x1b[0m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes that a specific component type has been chosen.\n\x1b[0m\x1b[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingTypeFlagsChosenTypeInComponentMenu()
{
    Selector->initiateSelector(Player);
    command("1", Player);
    command("6", Player);

    ExpectEq("\x1b[0;36mCraft Blade - \x1b[0m\x1b[0;37;1mSelect materials and the type of blade you will craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mSelect metal        \x1b[0m\x1b[0;34;1mnone\x1b[0m     "
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mFlamberge           \x1b[0m         \n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mSerrated            \x1b[0m         "
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mType X              \x1b[0m         \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mType XI             \x1b[0m         "
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mType XIII           \x1b[0m\x1b[0;34;1m   (*)\x1b[0m   \n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mType XIIa           \x1b[0m         "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mType XIV            \x1b[0m         \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mType XIX            \x1b[0m         "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mType XIa            \x1b[0m         \n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mType XV             \x1b[0m         "
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mType XVI            \x1b[0m         \n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;32mType XVII           \x1b[0m         "
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;32mType XVIII          \x1b[0m         \n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;32mType XVIIIa         \x1b[0m         "
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;32mType XVIIIb         \x1b[0m         \n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;32mType XVIIIc         \x1b[0m         "
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;32mType XVIIId         \x1b[0m         \n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;32mType XVIIIe         \x1b[0m         "
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;32mType XVa            \x1b[0m         \n"
        "    [\x1b[0;31;1m21\x1b[0m] - \x1b[0;32mType XX             \x1b[0m         "
        "    [\x1b[0;31;1m22\x1b[0m] - \x1b[0;32mType XXI            \x1b[0m         \n"
        "    [\x1b[0;31;1m23\x1b[0m] - \x1b[0;32mType XXII           \x1b[0m         "
        "    [\x1b[0;31;1m24\x1b[0m] - \x1b[0;32mType Xa             \x1b[0m         \n"
        "    [\x1b[0;31;1m25\x1b[0m] - \x1b[0;31mConfirm Selection   \x1b[0m         "
        "    [\x1b[0;31;1m26\x1b[0m] - \x1b[0;32mCancel Selection    \x1b[0m         \n"
        "\x1b[0;32;1mYou must select a number from 1 to 26.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;34;1m<material>\x1b[0m\x1b[0;32m denotes a selected material.\n"
        "\x1b[0m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes that a specific component type has been chosen.\n\x1b[0m\x1b[0m",
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

    ExpectEq("\x1b[0;36mCraft Blade - \x1b[0m\x1b[0;37;1mSelect materials and the type of blade you will craft\x1b[0m:\n"
        "    [\x1b[0;31;1m1\x1b[0m]  - \x1b[0;32mSelect metal        \x1b[0m\x1b[0;34;1madmantite\x1b[0m"
        "    [\x1b[0;31;1m2\x1b[0m]  - \x1b[0;32mFlamberge           \x1b[0m         \n"
        "    [\x1b[0;31;1m3\x1b[0m]  - \x1b[0;32mSerrated            \x1b[0m         "
        "    [\x1b[0;31;1m4\x1b[0m]  - \x1b[0;32mType X              \x1b[0m         \n"
        "    [\x1b[0;31;1m5\x1b[0m]  - \x1b[0;32mType XI             \x1b[0m         "
        "    [\x1b[0;31;1m6\x1b[0m]  - \x1b[0;32mType XIII           \x1b[0m\x1b[0;34;1m   (*)\x1b[0m   \n"
        "    [\x1b[0;31;1m7\x1b[0m]  - \x1b[0;32mType XIIa           \x1b[0m         "
        "    [\x1b[0;31;1m8\x1b[0m]  - \x1b[0;32mType XIV            \x1b[0m         \n"
        "    [\x1b[0;31;1m9\x1b[0m]  - \x1b[0;32mType XIX            \x1b[0m         "
        "    [\x1b[0;31;1m10\x1b[0m] - \x1b[0;32mType XIa            \x1b[0m         \n"
        "    [\x1b[0;31;1m11\x1b[0m] - \x1b[0;32mType XV             \x1b[0m         "
        "    [\x1b[0;31;1m12\x1b[0m] - \x1b[0;32mType XVI            \x1b[0m         \n"
        "    [\x1b[0;31;1m13\x1b[0m] - \x1b[0;32mType XVII           \x1b[0m         "
        "    [\x1b[0;31;1m14\x1b[0m] - \x1b[0;32mType XVIII          \x1b[0m         \n"
        "    [\x1b[0;31;1m15\x1b[0m] - \x1b[0;32mType XVIIIa         \x1b[0m         "
        "    [\x1b[0;31;1m16\x1b[0m] - \x1b[0;32mType XVIIIb         \x1b[0m         \n"
        "    [\x1b[0;31;1m17\x1b[0m] - \x1b[0;32mType XVIIIc         \x1b[0m         "
        "    [\x1b[0;31;1m18\x1b[0m] - \x1b[0;32mType XVIIId         \x1b[0m         \n"
        "    [\x1b[0;31;1m19\x1b[0m] - \x1b[0;32mType XVIIIe         \x1b[0m         "
        "    [\x1b[0;31;1m20\x1b[0m] - \x1b[0;32mType XVa            \x1b[0m         \n"
        "    [\x1b[0;31;1m21\x1b[0m] - \x1b[0;32mType XX             \x1b[0m         "
        "    [\x1b[0;31;1m22\x1b[0m] - \x1b[0;32mType XXI            \x1b[0m         \n"
        "    [\x1b[0;31;1m23\x1b[0m] - \x1b[0;32mType XXII           \x1b[0m         "
        "    [\x1b[0;31;1m24\x1b[0m] - \x1b[0;32mType Xa             \x1b[0m         \n"
        "    [\x1b[0;31;1m25\x1b[0m] - \x1b[0;32mConfirm Selection   \x1b[0m         "
        "    [\x1b[0;31;1m26\x1b[0m] - \x1b[0;32mCancel Selection    \x1b[0m         \n"
        "\x1b[0;32;1mYou must select a number from 1 to 26.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;34;1m<material>\x1b[0m\x1b[0;32m denotes a selected material.\n"
        "\x1b[0m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes that a specific component type has been chosen.\n\x1b[0m\x1b[0m",
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

    ExpectEq("\x1b[0;36mCraft Long sword - \x1b[0m\x1b[0;37;1mFrom this menu, you will select the\n"
        "components that will be used to craft your long sword. The relative statistics\n"
        "for the item you are creating are:\n"
        "\t\x1b[0;36mMaterial: \x1b[0;31mnone selected\x1b[0m\n"
        "\t\x1b[0;36mAttack: \x1b[0m\x1b[0;33m5 to 105\x1b[0m\n"
        "\t\x1b[0;36mDamage: \x1b[0m\x1b[0;33m8 to 11\x1b[0m\n"
        "\t\x1b[0;36mDefense: \x1b[0m\x1b[0;33m1 to 2\x1b[0m\n"
        "\t\x1b[0;36mEncumberance: \x1b[0m\x1b[0;33m5\x1b[0m\n"
        "\t\x1b[0;36mWeight: \x1b[0m\x1b[0;33m5\x1b[0m\n\x1b[0m\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mSelect Blade        \x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mSelect Crossguard   \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mSelect Hilt         \x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mSelect Pommel       \x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;31mEnchant Long sword  \x1b[0m\n"
        "\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mGive long sword a name\x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m] - \x1b[0;32mGive long sword a special description\x1b[0m\n"
        "\t[\x1b[0;31;1m8\x1b[0m] - \x1b[0;31mCraft Selected Long sword\x1b[0m\n"
        "\t[\x1b[0;31;1m9\x1b[0m] - \x1b[0;32mExit Craft Long sword Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 9.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes that a specific component type has been chosen.\n\x1b[0m\x1b[0m",
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

    ExpectEq("\x1b[0;36mCraft Long sword - \x1b[0m\x1b[0;37;1mFrom this menu, you will select the\n"
        "components that will be used to craft your long sword. The relative statistics\n"
        "for the item you are creating are:\n"
        "\t\x1b[0;36mMaterial: \x1b[0m\x1b[0;33mAdmantite\x1b[0m\n"
        "\t\x1b[0;36mAttack: \x1b[0m\x1b[0;33m8 to 108\x1b[0m\n"
        "\t\x1b[0;36mDamage: \x1b[0m\x1b[0;33m13 to 16\x1b[0m\x1b[0;31m [+2 magical]\x1b[0m\n"
        "\t\x1b[0;36mDefense: \x1b[0m\x1b[0;33m1 to 2\x1b[0m\n"
        "\t\x1b[0;36mEncumberance: \x1b[0m\x1b[0;33m5\x1b[0m\n"
        "\t\x1b[0;36mWeight: \x1b[0m\x1b[0;33m5\x1b[0m\n\x1b[0m\n"
        "\t[\x1b[0;31;1m1\x1b[0m] - \x1b[0;32mSelect Blade        \x1b[0m\x1b[0;35;1m   (*)\x1b[0m\n"
        "\t[\x1b[0;31;1m2\x1b[0m] - \x1b[0;32mSelect Crossguard   \x1b[0m\n"
        "\t[\x1b[0;31;1m3\x1b[0m] - \x1b[0;32mSelect Hilt         \x1b[0m\n"
        "\t[\x1b[0;31;1m4\x1b[0m] - \x1b[0;32mSelect Pommel       \x1b[0m\n"
        "\t[\x1b[0;31;1m5\x1b[0m] - \x1b[0;31mEnchant Long sword  \x1b[0m\n"
        "\t[\x1b[0;31;1m6\x1b[0m] - \x1b[0;32mGive long sword a name\x1b[0m\n"
        "\t[\x1b[0;31;1m7\x1b[0m] - \x1b[0;32mGive long sword a special description\x1b[0m\n"
        "\t[\x1b[0;31;1m8\x1b[0m] - \x1b[0;31mCraft Selected Long sword\x1b[0m\n"
        "\t[\x1b[0;31;1m9\x1b[0m] - \x1b[0;32mExit Craft Long sword Menu\x1b[0m\n"
        "\x1b[0;32;1mYou must select a number from 1 to 9.\n\x1b[0m"
        "\x1b[0;32mType 'exit' if you do not wish to make a selection at this time.\n\x1b[0m"
        "\x1b[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n\x1b[0m"
        "\x1b[0;32;1m\x1b[0;34;1m(*)\x1b[0m\x1b[0;32m denotes that a specific component type has been chosen.\n\x1b[0m\x1b[0m",
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

    command("9", Player);
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
    command("exit", Player);
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
    command("8", Player);

    ExpectEq((["onCraftingCompleted":"lib/instances/items/weapons/swords/long-sword.c"]), eventSubscriber->events());
}

/////////////////////////////////////////////////////////////////////////////
void OptionalComponentsAreInitiallyDisabledAndEnabledWhenRequired()
{
    object material = clone_object("/lib/instances/items/materials/crystal/ruby.c");
    material->set("quantity", 5);
    move_object(material, Player);

    Player->advanceSkill("gem crafting", 10);
    Player->advanceSkill("sculpture", 15);

    Selector->initiateSelector(Player);
    command("2", Player);

    ExpectSubStringMatch("31mSelect crystal",
        Player->caughtMessage());

    command("11", Player);

    ExpectSubStringMatch("32mSelect crystal",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanOnlySelectOptionalMaterialWhenEnabled()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftGems.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftRareGems.c"));

    object material = clone_object("/lib/instances/items/materials/crystal/ruby.c");
    material->set("quantity", 5);
    move_object(material, Player);

    Player->advanceSkill("gem crafting", 20);
    Player->advanceSkill("chemistry", 5);
    Player->advanceSkill("physics", 5);
    Player->advanceSkill("sculpture", 15);

    Selector->initiateSelector(Player);
    command("2", Player);

    ExpectSubStringMatch("31mSelect crystal.*none",
        Player->caughtMessage());

    command("1", Player);

    ExpectSubStringMatch("31mSelect crystal.*none",
        Player->caughtMessage());

    command("11", Player);
    command("1", Player);
    command("25", Player);
    ExpectSubStringMatch("32mSelect crystal.*ruby",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingComponentThatDoesNotUseOptionalResetsOptional()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftGems.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/materials/craftRareGems.c"));

    object material = clone_object("/lib/instances/items/materials/crystal/ruby.c");
    material->set("quantity", 5);
    move_object(material, Player);

    Player->advanceSkill("gem crafting", 20);
    Player->advanceSkill("chemistry", 5);
    Player->advanceSkill("physics", 5);
    Player->advanceSkill("sculpture", 15);

    Selector->initiateSelector(Player);
    command("2", Player);

    command("11", Player);
    command("1", Player);
    command("25", Player);
    ExpectSubStringMatch("32mSelect crystal.*ruby",
        Player->caughtMessage());

    command("5", Player);

    ExpectSubStringMatch("31mSelect crystal.*none",
        Player->caughtMessage());
}
