//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("platinum ore vein");

    addAdjectives(({
        "silvery platinum vein with a faint metallic shimmer",
        "broad streak of platinum ore embedded in stone",
        "vein of platinum with crystalline inclusions",
        "narrow ribbon of platinum ore winding through the rock",
        "patchy platinum deposit with a subtle white sheen",
        "hidden platinum seam barely visible in the wall",
        "vein of platinum with sparkling inclusions",
        "rough platinum outcrop with jagged protrusions",
        "vein of platinum ore coated in a thin layer of dust",
        "solid band of platinum running through fractured stone",
        "vein of platinum with a subtle luster",
        "irregular platinum deposit with pockets of pure metal"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit platinum ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit platinum ore vein, its silvery color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible platinum ore vein, its metallic luster and white sheen "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("platinum ore", 3, "/lib/instances/items/materials/metal-ores/platinum.c",
        "A vein of platinum ore runs through the rock here. Some platinum remains.",
        ({ "ore", "platinum", "vein", "deposit" }));
    harvestRequiresTool("platinum ore", "pick axe");
}
