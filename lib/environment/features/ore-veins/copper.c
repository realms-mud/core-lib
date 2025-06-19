//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("copper ore vein");

    addAdjectives(({
        "greenish copper vein with oxidized patches",
        "broad streak of copper ore embedded in stone",
        "vein of copper with blue-green inclusions",
        "narrow ribbon of copper ore winding through the rock",
        "patchy copper deposit with a faint metallic sheen",
        "hidden copper seam barely visible in the wall",
        "vein of copper with malachite inclusions",
        "rough copper outcrop with jagged protrusions",
        "vein of copper ore coated in a thin layer of dust",
        "solid band of copper running through fractured stone",
        "vein of copper with a subtle luster",
        "irregular copper deposit with pockets of pure metal"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit copper ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit copper ore vein, its greenish color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible copper ore vein, its metallic luster and greenish hue "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("copper ore", 15, "/lib/instances/items/materials/metal-ores/copper.c",
        "A vein of copper ore runs through the rock here. Some copper remains.",
        ({ "ore", "copper", "copper ore", "vein", "deposit" }));
    harvestRequiresTool("copper ore", "pickaxe");
}
