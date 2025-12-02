//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("kirdarium ore vein");

    addAdjectives(({
        "bluish kirdarium vein with a faint metallic shimmer",
        "broad streak of kirdarium ore embedded in stone",
        "vein of kirdarium with silvery inclusions",
        "narrow ribbon of kirdarium ore winding through the rock",
        "patchy kirdarium deposit with a subtle blue sheen",
        "hidden kirdarium seam barely visible in the wall",
        "vein of kirdarium with crystalline inclusions",
        "rough kirdarium outcrop with jagged protrusions",
        "vein of kirdarium ore coated in a thin layer of dust",
        "solid band of kirdarium running through fractured stone",
        "vein of kirdarium with a subtle luster",
        "irregular kirdarium deposit with pockets of pure metal"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit kirdarium ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit kirdarium ore vein, its bluish color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible kirdarium ore vein, its metallic luster and blue sheen "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("kirdarium ore", 3, "/lib/instances/items/materials/metal-ores/kirdarium.c",
        "A vein of kirdarium ore runs through the rock here. Some kirdarium remains.",
        ({ "ore", "kirdarium", "vein", "deposit" }));
    harvestRequiresTool("kirdarium ore", "pick axe");
}
