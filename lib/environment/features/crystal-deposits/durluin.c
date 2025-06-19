//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("durluin deposit");

    addAdjectives(({
        "dark grey durluin with a mythic shimmer",
        "vein of durluin with crystalline clusters",
        "rough durluin outcrop with jagged points",
        "hidden durluin seam barely visible in the wall",
        "durluin deposit with swirling grey hues",
        "vein of durluin with sparkling inclusions",
        "durluin deposit with a glossy surface",
        "vein of durluin with deep, mythic color",
        "durluin seam with a mix of rough and polished stone",
        "deposit of durluin with magical inclusions",
        "irregular durluin vein with pockets of clear crystal",
        "translucent durluin seam glowing softly"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit durluin deposit, where only the outline of the crystals can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit durluin deposit, its grey color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible durluin deposit, its vibrant crystals and mythic shimmer "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## embedded in the rock wall");

    harvestableResource("durluin", 6, "/lib/instances/items/materials/crystal/durluin.c",
        "A deposit of durluin runs through the rock here. Some durluin remains.",
        ({ "crystal", "durluin crystal", "vein", "deposit" }));
    harvestRequiresTool("durluin", "pick axe");
}
