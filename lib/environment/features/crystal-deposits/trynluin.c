//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("trynluin deposit");

    addAdjectives(({
        "deep blue trynluin with a magical shimmer",
        "vein of trynluin with crystalline clusters",
        "rough trynluin outcrop with jagged edges",
        "hidden trynluin seam barely visible in the wall",
        "trynluin deposit with swirling blue hues",
        "vein of trynluin with sparkling inclusions",
        "trynluin with a glossy, enchanted surface",
        "deposit of trynluin with mythic radiance",
        "irregular trynluin vein with pockets of clear crystal",
        "trynluin seam with a mix of rough and polished stone",
        "trynluin with a luminous, otherworldly glow",
        "vein of trynluin with deep, shifting color"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit trynluin deposit, where only the outline of the crystal can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit trynluin deposit, its blue color blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible trynluin deposit, its magical shimmer and deep color "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("trynluin", 6, "/lib/instances/items/materials/crystal/trynluin.c",
        "A vein of trynluin runs through the rock here. Some trynluin remains.",
        ({ "trynluin", "crystal", "deposit", "gem" }));
    harvestRequiresTool("trynluin", "pickaxe");
}
