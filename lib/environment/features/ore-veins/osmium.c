//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("osmium ore vein");

    addAdjectives(({
        "bluish-gray osmium vein with a faint metallic shimmer",
        "broad streak of osmium ore embedded in stone",
        "vein of osmium with crystalline inclusions",
        "narrow ribbon of osmium ore winding through the rock",
        "patchy osmium deposit with a subtle blue sheen",
        "hidden osmium seam barely visible in the wall",
        "vein of osmium with sparkling inclusions",
        "rough osmium outcrop with jagged protrusions",
        "vein of osmium ore coated in a thin layer of dust",
        "solid band of osmium running through fractured stone",
        "vein of osmium with a subtle luster",
        "irregular osmium deposit with pockets of pure metal"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit osmium ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit osmium ore vein, its bluish-gray color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible osmium ore vein, its metallic luster and blue sheen "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("osmium ore", 3, "/lib/instances/items/materials/metal-ores/osmium.c",
        "A vein of osmium ore runs through the rock here. Some osmium remains.",
        ({ "ore", "osmium", "osmium ore", "vein", "deposit" }));
    harvestRequiresTool("osmium ore", "pickaxe");
}
