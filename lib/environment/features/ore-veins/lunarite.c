//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lunarite ore vein");

    addAdjectives(({
        "silvery lunarite vein with a faint magical shimmer",
        "broad streak of lunarite ore embedded in stone",
        "vein of lunarite with crystalline inclusions",
        "narrow ribbon of lunarite ore winding through the rock",
        "patchy lunarite deposit with a subtle blue sheen",
        "hidden lunarite seam barely visible in the wall",
        "vein of lunarite with sparkling inclusions",
        "rough lunarite outcrop with jagged protrusions",
        "vein of lunarite ore coated in a thin layer of dust",
        "solid band of lunarite running through fractured stone",
        "vein of lunarite with a subtle luster",
        "irregular lunarite deposit with pockets of pure metal"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit lunarite ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit lunarite ore vein, its silvery color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible lunarite ore vein, its magical luster and blue sheen "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("lunarite ore", 4, "/lib/instances/items/materials/metal-ores/lunarite.c",
        "A vein of lunarite ore runs through the rock here. Some lunarite remains.",
        ({ "ore", "lunarite", "vein", "deposit" }));
    harvestRequiresTool("lunarite ore", "pick axe");
}
