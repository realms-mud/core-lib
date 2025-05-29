//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("long table");
    addAlias("table");
    addAlias("great table");
    addAlias("hall table");

    addAdjectives(({ "massive", "oak", "ornate", "weathered", "ancient",
        "scarred", "long", "grand" }));

    addDescriptionTemplate("a ##Adjective## table that dominates the center of "
        "the great hall");

    addItemTemplate("The table stretches down much of the hall's length, its "
        "surface bearing the marks of countless feasts and gatherings. "
        "Despite years of neglect, the craftsmanship is evident in the "
        "intricate carvings along its sides and legs");

    addSomeLightDescriptionTemplate("a long wooden table with benches along its "
        "sides, able to seat dozens of people");

    addDimLightDescriptionTemplate("a large table running down the center of "
        "the hall, its surface reflecting the dim light");

    addLowLightDescriptionTemplate("a long, dark shape in the center of the "
        "room that appears to be a substantial table");

    addNearDarkDescriptionTemplate("a shadowy rectangular form suggesting a "
        "large table occupying the center of the space");
}
