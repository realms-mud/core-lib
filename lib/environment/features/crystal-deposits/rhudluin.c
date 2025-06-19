//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rhudluin deposit");

    addAdjectives(({
        "dark red rhudluin with a mythic shimmer",
        "vein of rhudluin with crystalline clusters",
        "rough rhudluin outcrop with jagged edges",
        "hidden rhudluin seam barely visible in the wall",
        "rhudluin deposit with swirling crimson hues",
        "vein of rhudluin with sparkling inclusions",
        "rhudluin with a glossy, magical surface",
        "deposit of rhudluin with mythic radiance",
        "irregular rhudluin vein with pockets of clear crystal",
        "rhudluin seam with a mix of rough and polished stone",
        "rhudluin with a luminous, ancient glow",
        "vein of rhudluin with deep, shifting color"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit rhudluin deposit, where only the outline of the crystal can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit rhudluin deposit, its red color blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible rhudluin deposit, its mythic shimmer and deep color "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("rhudluin", 6, "/lib/instances/items/materials/crystal/rhudluin.c",
        "A vein of rhudluin runs through the rock here. Some rhudluin remains.",
        ({ "rhudluin deposit", "crystal", "deposit", "gem" }));
    harvestRequiresTool("rhudluin", "pick axe");
}
