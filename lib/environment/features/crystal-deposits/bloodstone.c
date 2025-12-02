//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bloodstone deposit");

    addAdjectives(({
        "dark green bloodstone with red flecks",
        "vein of bloodstone with crystalline clusters",
        "rough bloodstone outcrop with jagged points",
        "hidden bloodstone seam barely visible in the wall",
        "bloodstone deposit with swirling green and red hues",
        "vein of bloodstone with quartz inclusions",
        "bloodstone deposit with a glossy surface",
        "vein of bloodstone with deep, earthy color",
        "bloodstone seam with a mix of rough and polished stone",
        "deposit of bloodstone with sparkling inclusions",
        "irregular bloodstone vein with pockets of clear crystal",
        "translucent bloodstone seam glowing softly"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit bloodstone deposit, where only the outline of the crystals can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit bloodstone deposit, its green and red colors blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible bloodstone deposit, its vibrant colors and red flecks "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## embedded in the rock wall");

    harvestableResource("bloodstone", 10, "/lib/instances/items/materials/crystal/bloodstone.c",
        "A deposit of bloodstone runs through the rock here. Some bloodstone remains.",
        ({ "crystal", "bloodstone crystal", "vein", "deposit" }));
    harvestRequiresTool("bloodstone", "pick axe");
}
