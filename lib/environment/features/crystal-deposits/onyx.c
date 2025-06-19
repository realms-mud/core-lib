//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("onyx deposit");

    addAdjectives(({
        "deep black onyx with a glassy sheen",
        "vein of onyx with crystalline clusters",
        "rough onyx outcrop with jagged edges",
        "hidden onyx seam barely visible in the wall",
        "onyx deposit with swirling dark patterns",
        "vein of onyx with sparkling inclusions",
        "onyx with a glossy, polished surface",
        "deposit of onyx with flecks of silver mineral",
        "irregular onyx vein with pockets of pure stone",
        "onyx seam with a mix of rough and smooth stone",
        "onyx with a luminous, shadowy glow",
        "vein of onyx with deep, mysterious color"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit onyx deposit, where only the outline of the stone can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit onyx deposit, its black color blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible onyx deposit, its glassy sheen and deep color "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("onyx", 8, "/lib/instances/items/materials/crystal/onyx.c",
        "A vein of onyx runs through the rock here. Some onyx remains.",
        ({ "stone", "deposit", "gem" }));
    harvestRequiresTool("onyx", "pick axe");
}
