//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("gwyrluin deposit");
    addAdjectives(({
        "pale grey-brown gwyrluin with mythic shimmer",
        "vein of gwyrluin with crystalline clusters",
        "gwyrluin seam with swirling patterns",
        "rough gwyrluin outcrop with jagged edges",
        "hidden gwyrluin seam barely visible in the wall",
        "gwyrluin deposit with earthy, muted hues",
        "gwyrluin with a glossy, magical surface",
        "vein of gwyrluin with sparkling inclusions",
        "gwyrluin seam with a mix of rough and polished stone",
        "deposit of gwyrluin with magical inclusions",
        "irregular gwyrluin vein with pockets of clear crystal",
        "gwyrluin with a luminous, spectral glow"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit gwyrluin deposit, where only the outline of the crystal can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit gwyrluin deposit, its pale color blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible gwyrluin deposit, its mythic shimmer and pale hues "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## deposit of gwyrluin embedded in the rock wall, pale crystal visible where the rock has fractured or worn away");

    harvestableResource("gwyrluin", 6, "/lib/instances/items/materials/crystal/gwyrluin.c",
        "A vein of gwyrluin runs through the rock here. Some gwyrluin remains.",
        ({ "crystal", "deposit", "gem" }));
    harvestRequiresTool("gwyrluin", "pick axe");
}
