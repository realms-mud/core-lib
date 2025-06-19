//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("amethyst deposit");

    addAdjectives(({
        "deep purple amethyst with sparkling facets",
        "vein of amethyst with crystalline clusters",
        "rough amethyst outcrop with jagged points",
        "hidden amethyst seam barely visible in the wall",
        "amethyst deposit with swirling violet hues",
        "vein of amethyst with quartz inclusions",
        "amethyst deposit with a glossy surface",
        "vein of amethyst with rich, royal color",
        "amethyst seam with a mix of rough and polished stone",
        "deposit of amethyst with sparkling inclusions",
        "irregular amethyst vein with pockets of clear crystal",
        "translucent amethyst seam glowing softly"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit amethyst deposit, where only the outline of the crystals can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit amethyst deposit, its purple color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible amethyst deposit, its vibrant crystals and color "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## embedded in the rock wall");

    harvestableResource("amethyst", 10, "/lib/instances/items/materials/crystal/amethyst.c",
        "A deposit of amethyst runs through the rock here. Some amethyst remains.",
        ({ "crystal", "amethyst", "amethyst crystal", "vein", "deposit" }));
    harvestRequiresTool("amethyst", "pickaxe");
}
