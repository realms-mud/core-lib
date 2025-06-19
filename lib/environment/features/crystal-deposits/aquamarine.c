//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("aquamarine deposit");

    addAdjectives(({
        "pale blue aquamarine with sparkling facets",
        "vein of aquamarine with crystalline clusters",
        "rough aquamarine outcrop with jagged points",
        "hidden aquamarine seam barely visible in the wall",
        "aquamarine deposit with swirling blue-green hues",
        "vein of aquamarine with quartz inclusions",
        "aquamarine deposit with a glossy surface",
        "vein of aquamarine with clear, watery color",
        "aquamarine seam with a mix of rough and polished stone",
        "deposit of aquamarine with sparkling inclusions",
        "irregular aquamarine vein with pockets of clear crystal",
        "translucent aquamarine seam glowing softly"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit aquamarine deposit, where only the outline of the crystals can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit aquamarine deposit, its blue color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible aquamarine deposit, its vibrant crystals and color "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## embedded in the rock wall");

    harvestableResource("aquamarine", 10, "/lib/instances/items/materials/crystal/aquamarine.c",
        "A deposit of aquamarine runs through the rock here. Some aquamarine remains.",
        ({ "crystal", "aquamarine", "aquamarine crystal", "vein", "deposit" }));
    harvestRequiresTool("aquamarine", "pickaxe");
}
