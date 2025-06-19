//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("gold ore vein");

    addAdjectives(({
        "gleaming gold vein with bright yellow flecks",
        "broad streak of gold ore embedded in stone",
        "vein of gold with sparkling inclusions",
        "narrow ribbon of gold ore winding through the rock",
        "patchy gold deposit with a faint metallic sheen",
        "hidden gold seam barely visible in the wall",
        "vein of gold with quartz inclusions",
        "rough gold outcrop with jagged protrusions",
        "vein of gold ore coated in a thin layer of dust",
        "solid band of gold running through fractured stone",
        "vein of gold with a subtle luster",
        "irregular gold deposit with pockets of pure metal"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit gold ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit gold ore vein, its yellow color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible gold ore vein, its metallic luster and bright flecks "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("gold ore", 8, "/lib/instances/items/materials/metal-ores/gold.c",
        "A vein of gold ore runs through the rock here. Some gold remains.",
        ({ "ore", "gold", "vein", "deposit" }));
    harvestRequiresTool("gold ore", "pick axe");
}
