//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "health");
    addSpecification("name", "disfigured");
    addSpecification("description", "You have been horribly disfigured. Imagine, if you will, the offspring of an unholy marriage between a goblin and a dorian. Now, imagine if that thing was shoved in a blender and allowed to rot for a week. You look worse than that.");
    addSpecification("root", "sickly");
    addSpecification("opposing root", "hale");
    addSpecification("opinion", -25);
    addSpecification("penalty to dexterity", 2);
    addSpecification("penalty to constitution", 2);
    addSpecification("penalty to charisma", 4);
    addSpecification("penalty to heal hit points rate", 15);
    addSpecification("penalty to heal stamina rate", 15);
    addSpecification("cost", -3);
}
