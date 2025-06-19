//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("admantite ore vein");

    addAdjectives(({
        "dark admantite vein with a faint metallic shimmer",
        "broad streak of admantite ore embedded in stone",
        "vein of admantite with silvery inclusions",
        "narrow ribbon of admantite ore winding through the rock",
        "patchy admantite deposit with a subtle blue sheen",
        "hidden admantite seam barely visible in the wall",
        "vein of admantite with crystalline inclusions",
        "rough admantite outcrop with jagged protrusions",
        "vein of admantite ore coated in a thin layer of dust",
        "solid band of admantite running through fractured stone",
        "vein of admantite with a subtle luster",
        "irregular admantite deposit with pockets of pure metal"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit admantite ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit admantite ore vein, its dark color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible admantite ore vein, its metallic luster and blue sheen "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("admantite ore", 6, "/lib/instances/items/materials/metal-ores/admantite.c",
        "A vein of admantite ore runs through the rock here. Some admantite remains.",
        ({ "ore", "vein", "deposit", "admantite", "admantite vein", "admantite deposit" }));
    harvestRequiresTool("admantite ore", "pick axe");
}
