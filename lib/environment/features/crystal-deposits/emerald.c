//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("emerald deposit");
    addAdjectives(({
        "deep green emerald with radiant clarity",
        "vein of emerald with crystalline facets",
        "emerald seam with swirling inclusions",
        "rough emerald outcrop with jagged edges",
        "hidden emerald seam barely visible in the wall",
        "emerald deposit with vibrant, grassy hues",
        "emerald with a glossy, glass-like surface",
        "vein of emerald with sparkling brilliance",
        "emerald seam with a mix of rough and polished stone",
        "deposit of emerald with flecks of gold",
        "irregular emerald vein with pockets of clear crystal",
        "emerald with a luminous, verdant glow"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit emerald deposit, where only the outline of the green stone can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit emerald deposit, its green color blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible emerald deposit, its vibrant green and crystalline facets "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## deposit of emerald embedded in the rock wall, green stone visible where the rock has fractured or worn away");

    harvestableResource("emerald", 8, "/lib/instances/items/materials/crystal/emerald.c",
        "A vein of emerald runs through the rock here. Some emerald remains.",
        ({ "crystal", "stone", "deposit", "gem" }));
    harvestRequiresTool("emerald", "pick axe");
}
