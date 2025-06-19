//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("opal deposit");

    addAdjectives(({
        "iridescent opal with shifting colors",
        "vein of opal with crystalline clusters",
        "rough opal outcrop with jagged edges",
        "hidden opal seam barely visible in the wall",
        "opal deposit with swirling pastel hues",
        "vein of opal with sparkling inclusions",
        "opal with a glossy, glassy surface",
        "deposit of opal with flecks of rainbow mineral",
        "irregular opal vein with pockets of pure color",
        "opal seam with a mix of rough and smooth stone",
        "opal with a luminous, magical glow",
        "vein of opal with dazzling, shifting light"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit opal deposit, where only the outline of the stone can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit opal deposit, its shifting colors blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible opal deposit, its iridescent colors and magical glow "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("opal", 8, "/lib/instances/items/materials/crystal/opal.c",
        "A vein of opal runs through the rock here. Some opal remains.",
        ({ "opal", "stone", "deposit", "gem" }));
    harvestRequiresTool("opal", "pickaxe");
}
