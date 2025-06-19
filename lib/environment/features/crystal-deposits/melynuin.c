//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("melynuin deposit");

    addAdjectives(({
        "pale blue melynuin with a magical shimmer",
        "vein of melynuin with crystalline clusters",
        "rough melynuin outcrop with jagged edges",
        "hidden melynuin seam barely visible in the wall",
        "melynuin deposit with swirling blue-white hues",
        "vein of melynuin with sparkling inclusions",
        "melynuin with a glossy, enchanted surface",
        "deposit of melynuin with mythic radiance",
        "irregular melynuin vein with pockets of clear crystal",
        "melynuin seam with a mix of rough and polished stone",
        "melynuin with a luminous, ethereal glow",
        "vein of melynuin with deep, shifting color"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit melynuin deposit, where only the outline of the crystal can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit melynuin deposit, its pale blue color blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible melynuin deposit, its magical shimmer and pale color "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("melynuin", 6, "/lib/instances/items/materials/crystal/melynuin.c",
        "A vein of melynuin runs through the rock here. Some melynuin remains.",
        ({ "crystal", "deposit", "gem" }));
    harvestRequiresTool("melynuin", "pick axe");
}
