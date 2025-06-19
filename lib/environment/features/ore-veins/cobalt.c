//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cobalt ore vein");

    addAdjectives(({
        "bluish cobalt vein with metallic luster",
        "broad streak of cobalt ore embedded in stone",
        "vein of cobalt with crystalline inclusions",
        "narrow ribbon of cobalt ore winding through the rock",
        "patchy cobalt deposit with a faint blue sheen",
        "hidden cobalt seam barely visible in the wall",
        "vein of cobalt with quartz inclusions",
        "rough cobalt outcrop with jagged protrusions",
        "vein of cobalt ore coated in a thin layer of dust",
        "solid band of cobalt running through fractured stone",
        "vein of cobalt with a subtle metallic shine",
        "irregular cobalt deposit with pockets of pure ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit cobalt ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit cobalt ore vein, its bluish color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible cobalt ore vein, its metallic luster and blue sheen "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("cobalt ore", 10, "/lib/instances/items/materials/metal-ores/cobalt.c",
        "A vein of cobalt ore runs through the rock here. Some cobalt remains.",
        ({ "ore", "cobalt", "cobalt ore", "vein", "deposit" }));
    harvestRequiresTool("cobalt ore", "pickaxe");
}
