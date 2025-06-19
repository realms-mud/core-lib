//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("jade deposit");
    addAdjectives(({
        "deep green jade with waxy luster",
        "vein of jade with swirling inclusions",
        "jade seam with mottled patterns",
        "rough jade outcrop with jagged edges",
        "hidden jade seam barely visible in the wall",
        "jade deposit with vibrant, grassy hues",
        "jade with a glossy, polished surface",
        "vein of jade with sparkling brilliance",
        "jade seam with a mix of rough and polished stone",
        "deposit of jade with flecks of gold",
        "irregular jade vein with pockets of clear stone",
        "jade with a luminous, verdant glow"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit jade deposit, where only the outline of the green stone can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit jade deposit, its green color blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible jade deposit, its vibrant green and waxy luster "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## deposit of jade embedded in the rock wall, green stone visible where the rock has fractured or worn away");

    harvestableResource("jade", 10, "/lib/instances/items/materials/crystal/jade.c",
        "A vein of jade runs through the rock here. Some jade remains.",
        ({ "stone", "deposit", "gem" }));
    harvestRequiresTool("jade", "pick axe");
}
