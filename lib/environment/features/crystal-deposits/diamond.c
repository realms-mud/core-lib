//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("diamond deposit");

    addAdjectives(({
        "brilliant diamond with dazzling facets",
        "vein of diamond with crystalline clusters",
        "rough diamond outcrop with jagged points",
        "hidden diamond seam barely visible in the wall",
        "diamond deposit with sparkling clarity",
        "vein of diamond with quartz inclusions",
        "diamond deposit with a glossy surface",
        "vein of diamond with pure, icy color",
        "diamond seam with a mix of rough and polished stone",
        "deposit of diamond with sparkling inclusions",
        "irregular diamond vein with pockets of clear crystal",
        "translucent diamond seam glowing softly"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit diamond deposit, where only the outline of the crystals can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit diamond deposit, its icy color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible diamond deposit, its dazzling facets and clarity "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## embedded in the rock wall");

    harvestableResource("diamond", 5, "/lib/instances/items/materials/crystal/diamond.c",
        "A deposit of diamond runs through the rock here. Some diamond remains.",
        ({ "crystal", "diamond crystal", "vein", "deposit" }));
    harvestRequiresTool("diamond", "pick axe");
}
