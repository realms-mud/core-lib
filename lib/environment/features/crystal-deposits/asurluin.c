//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("asurluin deposit");

    addAdjectives(({
        "deep blue asurluin with a magical shimmer",
        "vein of asurluin with crystalline clusters",
        "rough asurluin outcrop with jagged points",
        "hidden asurluin seam barely visible in the wall",
        "asurluin deposit with swirling blue hues",
        "vein of asurluin with sparkling inclusions",
        "asurluin deposit with a glossy surface",
        "vein of asurluin with rich, mythic color",
        "asurluin seam with a mix of rough and polished stone",
        "deposit of asurluin with magical inclusions",
        "irregular asurluin vein with pockets of clear crystal",
        "translucent asurluin seam glowing softly"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit asurluin deposit, where only the outline of the crystals can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit asurluin deposit, its blue color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible asurluin deposit, its vibrant crystals and magical shimmer "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## embedded in the rock wall");

    harvestableResource("asurluin", 8, "/lib/instances/items/materials/crystal/asurluin.c",
        "A deposit of asurluin runs through the rock here. Some asurluin remains.",
        ({ "crystal", "asurluin", "asurluin crystal", "vein", "deposit" }));
    harvestRequiresTool("asurluin", "pickaxe");
}
