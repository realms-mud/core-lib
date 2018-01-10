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
    Selector->setType("weapons");
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

    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftWeapons.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftBasicSwords.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftLongSwords.c"));

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
    command("12", Player);
    command("10", Player);

    ExpectEq("[0;36mCraft Long sword - [0m[0;37;1mFrom this menu, you will select the\n"
        "components that will be used to craft your long sword. The relative statistics\n"
        "for the item you are creating are:\n"
        "\t[0;36mAttack: [0m[0;33m5 to 105[0m\n"
        "\t[0;36mDamage: [0m[0;33m8 to 11[0m\n"
        "\t[0;36mDefense: [0m[0;33m1 to 2[0m\n"
        "\t[0;36mEncumberance: [0m[0;33m5[0m\n"
        "\t[0;36mWeight: [0m[0;33m5[0m\n[0m\n"
        "\t[[0;31;1m1[0m] - [0;32mSelect Blade        [0m\n"
        "\t[[0;31;1m2[0m] - [0;32mSelect Crossguard   [0m\n"
        "\t[[0;31;1m3[0m] - [0;32mSelect Hilt         [0m\n"
        "\t[[0;31;1m4[0m] - [0;32mSelect Pommel       [0m\n"
        "\t[[0;31;1m5[0m] - [0;32mExit Craft Long sword Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 5.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingComponentDisplaysComponentMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftCommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftUncommonMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftAlloy.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftRareMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftPreciousMetal.c"));
    ExpectTrue(Player->initiateResearch("lib/instances/research/crafting/craftMythicMetal.c"));
    Selector->initiateSelector(Player);
    command("12", Player);
    command("10", Player);
    command("1", Player);
//        command("1", Player);
//        command("1", Player);
//        command("6", Player);
//        command("13", Player);

    ExpectSubStringMatch("36mCraft Blade.*Cancel",
        Player->caughtMessage());
}