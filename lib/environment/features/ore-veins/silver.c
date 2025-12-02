//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("silver ore vein");

    addAdjectives(({
        "shiny silver vein with bright metallic flecks",
        "broad streak of silver ore embedded in stone",
        "vein of silver with crystalline inclusions",
        "narrow ribbon of silver ore winding through the rock",
        "patchy silver deposit with a faint metallic sheen",
        "hidden silver seam barely visible in the wall",
        "vein of silver with quartz inclusions",
        "rough silver outcrop with jagged protrusions",
        "vein of silver ore coated in a thin layer of dust",
        "solid band of silver running through fractured stone",
        "vein of silver with a subtle luster",
        "irregular silver deposit with pockets of pure ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit silver ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit silver ore vein, its shiny color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible silver ore vein, its metallic luster and bright flecks "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("silver ore", 8, "/lib/instances/items/materials/metal-ores/silver.c",
        "A vein of silver ore runs through the rock here. Some silver remains.",
        ({ "ore", "silver", "vein", "deposit" }));
    harvestRequiresTool("silver ore", "pick axe");
}
