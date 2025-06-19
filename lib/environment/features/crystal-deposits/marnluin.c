//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("marnluin deposit");
    addAdjectives(({
        "pale ice-blue marnluin with mythic shimmer",
        "vein of marnluin with crystalline clusters",
        "marnluin seam with swirling patterns",
        "rough marnluin outcrop with jagged edges",
        "hidden marnluin seam barely visible in the wall",
        "marnluin deposit with radiant, icy hues",
        "marnluin with a glossy, magical surface",
        "vein of marnluin with sparkling inclusions",
        "marnluin seam with a mix of rough and polished stone",
        "deposit of marnluin with magical inclusions",
        "irregular marnluin vein with pockets of clear crystal",
        "marnluin with a luminous, ethereal glow"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit marnluin deposit, where only the outline of the crystal can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit marnluin deposit, its ice-blue color blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible marnluin deposit, its mythic shimmer and icy hues "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## deposit of marnluin embedded in the rock wall, ice-blue crystal visible where the rock has fractured or worn away");

    harvestableResource("marnluin", 6, "/lib/instances/items/materials/crystal/marnluin.c",
        "A vein of marnluin runs through the rock here. Some marnluin remains.",
        ({ "marnluin", "crystal", "deposit", "gem" }));
    harvestRequiresTool("marnluin", "pickaxe");
}
