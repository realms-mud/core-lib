//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("topaz deposit");

    addAdjectives(({
        "golden topaz with sparkling clarity",
        "vein of topaz with crystalline clusters",
        "rough topaz outcrop with jagged edges",
        "hidden topaz seam barely visible in the wall",
        "topaz deposit with warm, amber hues",
        "vein of topaz with glossy, polished surfaces",
        "topaz with a glassy luster and subtle inclusions",
        "deposit of topaz with flecks of orange mineral",
        "irregular topaz vein with pockets of pure color",
        "topaz seam with a mix of rough and smooth stone",
        "topaz with a luminous, sunlit glow",
        "vein of topaz with sparkling golden crystals"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit topaz deposit, where only the outline of the stone can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit topaz deposit, its golden color blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible topaz deposit, its vibrant color and clarity "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("topaz", 10, "/lib/instances/items/materials/crystal/topaz.c",
        "A vein of topaz runs through the rock here. Some topaz remains.",
        ({ "topaz crystal", "stone", "deposit", "gem" }));
    harvestRequiresTool("topaz", "pick axe");
}
