//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("aluminum ore vein");

    addAdjectives(({
        "dull bauxite vein with reddish-brown patches",
        "broad streak of aluminum ore embedded in stone",
        "vein of bauxite with pale, earthy tones",
        "narrow ribbon of aluminum ore winding through the rock",
        "patchy bauxite deposit with a faint metallic sheen",
        "hidden aluminum seam barely visible in the wall",
        "vein of aluminum ore with clay-like inclusions",
        "rough bauxite outcrop with jagged protrusions",
        "vein of aluminum ore coated in a thin layer of dust",
        "solid band of bauxite running through fractured stone",
        "vein of aluminum ore with a subtle luster",
        "irregular bauxite deposit with pockets of darker ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit aluminum ore vein, where only the outline of the ore can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit aluminum ore vein, its reddish-brown color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible aluminum ore vein, its earthy luster and rough texture "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("aluminum ore", 12, "/lib/instances/items/materials/metal-ores/aluminum.c",
        "A vein of aluminum ore runs through the rock here. Some aluminum remains.",
        ({ "ore", "aluminum", "aluminum ore", "bauxite", "vein", "deposit" }));
    harvestRequiresTool("aluminum ore", "pickaxe");
}
