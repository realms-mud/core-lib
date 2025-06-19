//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("nurilium ore vein");

    addAdjectives(({
        "crimson nurilium vein with a faint magical shimmer",
        "broad streak of nurilium ore embedded in stone",
        "vein of nurilium with crystalline inclusions",
        "narrow ribbon of nurilium ore winding through the rock",
        "patchy nurilium deposit with a subtle red sheen",
        "hidden nurilium seam barely visible in the wall",
        "vein of nurilium with sparkling inclusions",
        "rough nurilium outcrop with jagged protrusions",
        "vein of nurilium ore coated in a thin layer of dust",
        "solid band of nurilium running through fractured stone",
        "vein of nurilium with a subtle luster",
        "irregular nurilium deposit with pockets of pure metal"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit nurilium ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit nurilium ore vein, its crimson color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible nurilium ore vein, its magical luster and red sheen "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("nurilium ore", 2, "/lib/instances/items/materials/metal-ores/nurilium.c",
        "A vein of nurilium ore runs through the rock here. Some nurilium remains.",
        ({ "ore", "nurilium", "vein", "deposit" }));
    harvestRequiresTool("nurilium ore", "pick axe");
}
