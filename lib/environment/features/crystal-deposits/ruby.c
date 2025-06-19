//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("ruby deposit");

    addAdjectives(({
        "brilliant red ruby with fiery brilliance",
        "vein of ruby with crystalline clusters",
        "rough ruby outcrop with jagged edges",
        "hidden ruby seam barely visible in the wall",
        "ruby deposit with deep, blood-red hues",
        "vein of ruby with glossy, polished surfaces",
        "ruby with a glassy luster and subtle inclusions",
        "deposit of ruby with flecks of gold mineral",
        "irregular ruby vein with pockets of pure color",
        "ruby seam with a mix of rough and smooth stone",
        "ruby with a luminous, inner glow",
        "vein of ruby with sparkling red crystals"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit ruby deposit, where only the outline of the stone can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit ruby deposit, its red color blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible ruby deposit, its vibrant color and fiery brilliance "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("ruby", 8, "/lib/instances/items/materials/crystal/ruby.c",
        "A vein of ruby runs through the rock here. Some ruby remains.",
        ({ "ruby", "stone", "deposit", "gem" }));
    harvestRequiresTool("ruby", "pickaxe");
}
