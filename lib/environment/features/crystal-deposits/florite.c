//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("florite deposit");
    addAdjectives(({
        "violet florite with glassy clarity",
        "vein of florite with cubic crystals",
        "florite seam with swirling color bands",
        "rough florite outcrop with jagged edges",
        "hidden florite seam barely visible in the wall",
        "florite deposit with pastel hues",
        "florite with a glossy, translucent surface",
        "vein of florite with sparkling brilliance",
        "florite seam with a mix of rough and polished stone",
        "deposit of florite with rainbow inclusions",
        "irregular florite vein with pockets of clear crystal",
        "florite with a luminous, shifting glow"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit florite deposit, where only the outline of the crystals can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit florite deposit, its violet and pastel colors blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible florite deposit, its vibrant colors and cubic crystals "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## deposit of florite embedded in the rock wall, colorful stone visible where the rock has fractured or worn away");

    harvestableResource("florite", 10, "/lib/instances/items/materials/crystal/florite.c",
        "A vein of florite runs through the rock here. Some florite remains.",
        ({ "florite", "stone", "deposit", "gem" }));
    harvestRequiresTool("florite", "pickaxe");
}
