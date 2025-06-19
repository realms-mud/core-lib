//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sapphire deposit");

    addAdjectives(({
        "deep blue sapphire with dazzling facets",
        "vein of sapphire with crystalline clusters",
        "rough sapphire outcrop with jagged edges",
        "hidden sapphire seam barely visible in the wall",
        "sapphire deposit with royal, velvety hues",
        "vein of sapphire with glossy, polished surfaces",
        "sapphire with a glassy luster and subtle inclusions",
        "deposit of sapphire with flecks of silver mineral",
        "irregular sapphire vein with pockets of pure color",
        "sapphire seam with a mix of rough and smooth stone",
        "sapphire with a luminous, starlit glow",
        "vein of sapphire with sparkling blue crystals"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit sapphire deposit, where only the outline of the stone can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit sapphire deposit, its blue color blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible sapphire deposit, its vibrant color and dazzling facets "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("sapphire", 8, "/lib/instances/items/materials/crystal/sapphire.c",
        "A vein of sapphire runs through the rock here. Some sapphire remains.",
        ({ "sapphire crystal", "stone", "deposit", "gem" }));
    harvestRequiresTool("sapphire", "pick axe");
}
