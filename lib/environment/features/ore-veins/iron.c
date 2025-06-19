//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("iron ore vein");

    addAdjectives(({
        "reddish-brown iron vein with rusty patches",
        "broad streak of iron ore embedded in stone",
        "vein of iron with hematite inclusions",
        "narrow ribbon of iron ore winding through the rock",
        "patchy iron deposit with a faint metallic sheen",
        "hidden iron seam barely visible in the wall",
        "vein of iron with quartz inclusions",
        "rough iron outcrop with jagged protrusions",
        "vein of iron ore coated in a thin layer of dust",
        "solid band of iron running through fractured stone",
        "vein of iron with a subtle luster",
        "irregular iron deposit with pockets of pure ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit iron ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit iron ore vein, its reddish color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible iron ore vein, its metallic luster and rusty hue "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("iron ore", 20, "/lib/instances/items/materials/metal-ores/iron.c",
        "A vein of iron ore runs through the rock here. Some iron remains.",
        ({ "ore", "iron", "vein", "deposit" }));
    harvestRequiresTool("iron ore", "pick axe");
}
