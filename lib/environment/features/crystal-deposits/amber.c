//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("amber deposit");

    addAdjectives(({
        "golden amber with ancient plant inclusions",
        "translucent amber seam glowing with warm light",
        "vein of amber with fossilized insects",
        "rough amber outcrop with jagged edges",
        "hidden amber seam barely visible in the wall",
        "amber deposit with swirling honeyed patterns",
        "vein of amber with glossy, resinous layers",
        "amber deposit with a rich, orange hue",
        "vein of amber with sparkling flecks",
        "amber seam with a mix of rough and polished resin",
        "deposit of amber with trapped air bubbles",
        "irregular amber vein with pockets of clear resin"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit amber deposit, where only the outline of the resin can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit amber deposit, its golden color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible amber deposit, its warm glow and inclusions "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## embedded in the rock wall");

    harvestableResource("amber", 10, "/lib/instances/items/materials/crystal/amber.c",
        "A deposit of amber runs through the rock here. Some amber remains.",
        ({ "crystal", "amber", "amber crystal", "vein", "deposit" }));
    harvestRequiresTool("amber", "pickaxe");
}
