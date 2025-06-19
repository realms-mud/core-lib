//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("crystal deposit");

    addAdjectives(({
        "clear crystal with sparkling facets",
        "vein of crystal with prismatic clusters",
        "rough crystal outcrop with jagged points",
        "hidden crystal seam barely visible in the wall",
        "crystal deposit with swirling patterns",
        "vein of crystal with quartz inclusions",
        "crystal deposit with a glossy surface",
        "vein of crystal with pure, glassy color",
        "crystal seam with a mix of rough and polished stone",
        "deposit of crystal with sparkling inclusions",
        "irregular crystal vein with pockets of clear mineral",
        "translucent crystal seam glowing softly"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit crystal deposit, where only the outline of the crystals can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit crystal deposit, its clear color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible crystal deposit, its sparkling facets and clarity "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## embedded in the rock wall");

    harvestableResource("crystal", 10, "/lib/instances/items/materials/crystal/crystal.c",
        "A deposit of crystal runs through the rock here. Some crystal remains.",
        ({ "crystal", "vein", "deposit" }));
    harvestRequiresTool("crystal", "pickaxe");
}
