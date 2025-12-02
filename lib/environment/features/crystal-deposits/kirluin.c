//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("kirluin deposit");
    addAdjectives(({
        "brilliant white kirluin with mythic shimmer",
        "vein of kirluin with crystalline clusters",
        "kirluin seam with swirling patterns",
        "rough kirluin outcrop with jagged edges",
        "hidden kirluin seam barely visible in the wall",
        "kirluin deposit with radiant, pure hues",
        "kirluin with a glossy, magical surface",
        "vein of kirluin with sparkling inclusions",
        "kirluin seam with a mix of rough and polished stone",
        "deposit of kirluin with magical inclusions",
        "irregular kirluin vein with pockets of clear crystal",
        "kirluin with a luminous, ethereal glow"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit kirluin deposit, where only the outline of the crystal can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit kirluin deposit, its white color blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible kirluin deposit, its mythic shimmer and pure hues "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## deposit of kirluin embedded in the rock wall, white crystal visible where the rock has fractured or worn away");

    harvestableResource("kirluin", 4, "/lib/instances/items/materials/crystal/kirluin.c",
        "A vein of kirluin runs through the rock here. Some kirluin remains.",
        ({ "crystal", "deposit", "gem" }));
    harvestRequiresTool("kirluin", "pick axe");
}
