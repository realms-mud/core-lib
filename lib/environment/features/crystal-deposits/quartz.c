//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("quartz deposit");

    addAdjectives(({
        "clear quartz with sparkling facets",
        "vein of quartz with prismatic clusters",
        "rough quartz outcrop with jagged edges",
        "hidden quartz seam barely visible in the wall",
        "quartz deposit with swirling patterns",
        "vein of quartz with glassy inclusions",
        "quartz with a glossy, polished surface",
        "deposit of quartz with flecks of silver mineral",
        "irregular quartz vein with pockets of pure crystal",
        "quartz seam with a mix of rough and smooth stone",
        "quartz with a luminous, icy glow",
        "vein of quartz with sparkling clear crystals"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit quartz deposit, where only the outline of the stone can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit quartz deposit, its clear color blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible quartz deposit, its sparkling facets and clarity "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("quartz", 10, "/lib/instances/items/materials/crystal/quartz.c",
        "A vein of quartz runs through the rock here. Some quartz remains.",
        ({ "quartz", "stone", "deposit", "gem" }));
    harvestRequiresTool("quartz", "pickaxe");
}
