//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tungsten ore vein");

    addAdjectives(({
        "dark tungsten vein with a faint metallic shimmer",
        "broad streak of tungsten ore embedded in stone",
        "vein of tungsten with scheelite inclusions",
        "narrow ribbon of tungsten ore winding through the rock",
        "patchy tungsten deposit with a subtle gray tint",
        "hidden tungsten seam barely visible in the wall",
        "vein of tungsten with crystalline inclusions",
        "rough tungsten outcrop with jagged protrusions",
        "vein of tungsten ore coated in a thin layer of dust",
        "solid band of tungsten running through fractured stone",
        "vein of tungsten with a subtle luster",
        "irregular tungsten deposit with pockets of pure ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit tungsten ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit tungsten ore vein, its dark color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible tungsten ore vein, its metallic luster and gray tint "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("tungsten ore", 5, "/lib/instances/items/materials/metal-ores/tungsten.c",
        "A vein of tungsten ore runs through the rock here. Some tungsten remains.",
        ({ "ore", "tungsten", "tungsten ore", "vein", "deposit" }));
    harvestRequiresTool("tungsten ore", "pickaxe");
}
