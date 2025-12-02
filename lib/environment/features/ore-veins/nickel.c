//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("nickel ore vein");

    addAdjectives(({
        "dull silver nickel vein with rough, uneven edges",
        "broad streak of nickel ore embedded in stone",
        "vein of nickel with flecks of white mineral",
        "narrow ribbon of nickel ore winding through the rock",
        "patchy nickel deposit with a faint metallic sheen",
        "hidden nickel seam barely visible in the wall",
        "vein of nickel with crystalline inclusions",
        "rough nickel outcrop with jagged protrusions",
        "vein of nickel ore coated in a thin layer of dust",
        "solid band of nickel running through fractured stone",
        "vein of nickel with a subtle metallic luster",
        "irregular nickel deposit with pockets of darker ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit nickel ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit nickel ore vein, its dull silver color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible nickel ore vein, its metallic luster and rough texture "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("nickel ore", 8, "/lib/instances/items/materials/metal-ores/nickel.c",
        "A vein of nickel ore runs through the rock here. Some nickel remains.",
        ({ "ore", "nickel", "vein", "deposit" }));
    harvestRequiresTool("nickel ore", "pick axe");
}
