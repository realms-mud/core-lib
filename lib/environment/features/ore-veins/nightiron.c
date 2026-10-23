//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("obsynite ore vein");

    addAdjectives(({
        "black obsynite vein with a faint metallic shimmer",
        "broad streak of obsynite ore embedded in stone",
        "vein of obsynite with silvery inclusions",
        "narrow ribbon of obsynite ore winding through the rock",
        "patchy obsynite deposit with a subtle blue sheen",
        "hidden obsynite seam barely visible in the wall",
        "vein of obsynite with crystalline inclusions",
        "rough obsynite outcrop with jagged protrusions",
        "vein of obsynite ore coated in a thin layer of dust",
        "solid band of obsynite running through fractured stone",
        "vein of obsynite with a subtle luster",
        "irregular obsynite deposit with pockets of pure metal"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit obsynite ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit obsynite ore vein, its black color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible obsynite ore vein, its metallic luster and blue sheen "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("obsynite ore", 6, "/lib/instances/items/materials/metal-ores/obsynite.c",
        "A vein of obsynite ore runs through the rock here. Some obsynite remains.",
        ({ "ore", "obsynite", "vein", "deposit" }));
    harvestRequiresTool("obsynite ore", "pick axe");
}
