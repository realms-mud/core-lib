//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("gladiator gate");
    addAlias("gate");
    addAlias("entry gate");
    addAlias("combat entrance");

    addAdjectives(({ "heavy", "iron-reinforced", "ominous", "blood-stained",
        "creaking" }));

    addDescriptionTemplate("##Adjective## wooden gate through which gladiators "
        "enter the arena");

    addItemTemplate("The gate bears countless scratches and marks, some likely "
        "made by fighters reluctant to meet their fate in the ring");

    addSomeLightDescriptionTemplate("a sturdy wooden gate set into the barrier "
        "wall, reinforced with iron bands and heavy hinges");

    addDimLightDescriptionTemplate("a gate or doorway leading into the combat "
        "area");

    addLowLightDescriptionTemplate("what appears to be an entrance into the "
        "arena");

    addNearDarkDescriptionTemplate("a darker shape in the barrier that might "
        "be an entrance");
}
