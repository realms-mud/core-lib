//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("garnet deposit");
    addAdjectives(({
        "deep red garnet with glassy facets",
        "vein of garnet with crystalline clusters",
        "garnet seam with swirling inclusions",
        "rough garnet outcrop with jagged edges",
        "hidden garnet seam barely visible in the wall",
        "garnet deposit with wine-colored hues",
        "garnet with a glossy, translucent surface",
        "vein of garnet with sparkling brilliance",
        "garnet seam with a mix of rough and polished stone",
        "deposit of garnet with flecks of gold",
        "irregular garnet vein with pockets of clear crystal",
        "garnet with a luminous, ruby glow"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit garnet deposit, where only the outline of the red stone can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit garnet deposit, its red color blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible garnet deposit, its vibrant red and crystalline facets "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## deposit of garnet embedded in the rock wall, red stone visible where the rock has fractured or worn away");

    harvestableResource("garnet", 10, "/lib/instances/items/materials/crystal/garnet.c",
        "A vein of garnet runs through the rock here. Some garnet remains.",
        ({ "garnet", "stone", "deposit", "gem" }));
    harvestRequiresTool("garnet", "pickaxe");
}
