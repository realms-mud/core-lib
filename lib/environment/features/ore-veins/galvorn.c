//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("galvorn ore vein");

    addAdjectives(({
        "black galvorn vein with a faint metallic shimmer",
        "broad streak of galvorn ore embedded in stone",
        "vein of galvorn with silvery inclusions",
        "narrow ribbon of galvorn ore winding through the rock",
        "patchy galvorn deposit with a subtle blue sheen",
        "hidden galvorn seam barely visible in the wall",
        "vein of galvorn with crystalline inclusions",
        "rough galvorn outcrop with jagged protrusions",
        "vein of galvorn ore coated in a thin layer of dust",
        "solid band of galvorn running through fractured stone",
        "vein of galvorn with a subtle luster",
        "irregular galvorn deposit with pockets of pure metal"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit galvorn ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit galvorn ore vein, its black color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible galvorn ore vein, its metallic luster and blue sheen "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("galvorn ore", 6, "/lib/instances/items/materials/metal-ores/galvorn.c",
        "A vein of galvorn ore runs through the rock here. Some galvorn remains.",
        ({ "ore", "galvorn", "galvorn ore", "vein", "deposit" }));
    harvestRequiresTool("galvorn ore", "pickaxe");
}
