//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/crafting/craftItemSelector.c");
    Selector.setType("weapons");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();

    Player.Wis(50);
    Player.Str(50);
    Player.Int(50);
    Player.addSkillPoints(500);
    Player.advanceSkill("blacksmithing", 20);
    Player.advanceSkill("bowyer and fletcher", 10);
    Player.advanceSkill("metal crafting", 10);
    Player.advanceSkill("wood crafting", 10);
    Player.advanceSkill("weapon smithing", 10);
    Player.advanceSkill("chemistry", 10);
    Player.advanceSkill("physics", 10);
    Player.advanceSkill("engineering", 10);
    Player.addResearchPoints(20);

    object material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material.set("quantity", 5);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/admantite.c");
    material.set("quantity", 6);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/steel.c");
    material.set("quantity", 10);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/iron.c");
    material.set("quantity", 3);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/metal/iron.c");
    material.set("quantity", 5);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/wood/koa.c");
    material.set("quantity", 15);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/textile/linen.c");
    material.set("quantity", 15);
    move_object(material, Player);

    material = clone_object("/lib/instances/items/materials/leather/pegasus-leather.c");
    material.set("quantity", 5);
    move_object(material, Player);

    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/weapons/craftWeapons.c"));

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectAxeCrafting()
{
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/weapons/axes/craftBasicAxe.c"));
    Selector.initiateSelector(Player);
    command("1", Player);
    command("1", Player);
    command("1", Player);

    ExpectSubStringMatch("Craft Axe head",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectBowCrafting()
{
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/weapons/bows/craftBow.c"));
    Selector.initiateSelector(Player);
    command("2", Player);
    command("5", Player);
    command("2", Player);

    ExpectSubStringMatch("Lattice Grip",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectCrossbowCrafting()
{
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/weapons/crossbows/craftCrossbow.c"));
    Selector.initiateSelector(Player);
    command("3", Player);
    command("2", Player);
    command("2", Player);

    ExpectSubStringMatch("Full Stock",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectFlailCrafting()
{
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/weapons/flails/craftBasicFlail.c"));
    Selector.initiateSelector(Player);
    command("5", Player);
    command("2", Player);
    command("2", Player);

    ExpectSubStringMatch("Ring Flail",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectHammerCrafting()
{
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/weapons/hammers/craftBasicHammer.c"));
    Selector.initiateSelector(Player);
    command("6", Player);
    command("4", Player);
    command("3", Player);

    ExpectSubStringMatch("Offset Wedge Hammer",
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CanSelectPoleArmCrafting()
{
    ExpectTrue(Player.initiateResearch("/lib/instances/research/crafting/weapons/pole-arms/craftBasicPoleArm.c"));
    Selector.initiateSelector(Player);
    command("8", Player);
    command("4", Player);
    command("1", Player);

    ExpectSubStringMatch("Spiked Bill Head",
        Player.caughtMessage());
}