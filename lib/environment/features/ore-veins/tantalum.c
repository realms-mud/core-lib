//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tantalum ore vein");

    addAdjectives(({
        "dark gray tantalum vein with a subtle metallic sheen",
        "broad streak of tantalum ore embedded in stone",
        "vein of tantalum with crystalline inclusions",
        "narrow ribbon of tantalum ore winding through the rock",
        "patchy tantalum deposit with a faint blue tint",
        "hidden tantalum seam barely visible in the wall",
        "vein of tantalum with quartz inclusions",
        "rough tantalum outcrop with jagged protrusions",
        "vein of tantalum ore coated in a thin layer of dust",
        "solid band of tantalum running through fractured stone",
        "vein of tantalum with a subtle luster",
        "irregular tantalum deposit with pockets of pure ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit tantalum ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit tantalum ore vein, its dark gray color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible tantalum ore vein, its metallic luster and blue tint "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("tantalum ore", 4, "/lib/instances/items/materials/metal-ores/tantalum.c",
        "A vein of tantalum ore runs through the rock here. Some tantalum remains.",
        ({ "ore", "tantalum", "vein", "deposit" }));
    harvestRequiresTool("tantalum ore", "pick axe");
}
