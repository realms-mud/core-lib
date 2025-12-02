//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("citrine deposit");

    addAdjectives(({
        "golden citrine with sparkling facets",
        "vein of citrine with crystalline clusters",
        "rough citrine outcrop with jagged points",
        "hidden citrine seam barely visible in the wall",
        "citrine deposit with swirling yellow hues",
        "vein of citrine with quartz inclusions",
        "citrine deposit with a glossy surface",
        "vein of citrine with bright, sunny color",
        "citrine seam with a mix of rough and polished stone",
        "deposit of citrine with sparkling inclusions",
        "irregular citrine vein with pockets of clear crystal",
        "translucent citrine seam glowing softly"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit citrine deposit, where only the outline of the crystals can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit citrine deposit, its golden color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible citrine deposit, its vibrant crystals and color "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## embedded in the rock wall");

    harvestableResource("citrine", 10, "/lib/instances/items/materials/crystal/citrine.c",
        "A deposit of citrine runs through the rock here. Some citrine remains.",
        ({ "crystal", "citrine crystal", "vein", "deposit" }));
    harvestRequiresTool("citrine", "pick axe");
}
