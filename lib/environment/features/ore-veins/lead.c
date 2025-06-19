//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lead ore vein");

    addAdjectives(({
        "dull gray lead vein with a faint metallic sheen",
        "broad streak of lead ore embedded in stone",
        "vein of lead with galena inclusions",
        "narrow ribbon of lead ore winding through the rock",
        "patchy lead deposit with a subtle blue tint",
        "hidden lead seam barely visible in the wall",
        "vein of lead with crystalline inclusions",
        "rough lead outcrop with jagged protrusions",
        "vein of lead ore coated in a thin layer of dust",
        "solid band of lead running through fractured stone",
        "vein of lead with a subtle luster",
        "irregular lead deposit with pockets of pure ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit lead ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit lead ore vein, its gray color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible lead ore vein, its metallic luster and blue tint "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("lead ore", 10, "/lib/instances/items/materials/metal-ores/lead.c",
        "A vein of lead ore runs through the rock here. Some lead remains.",
        ({ "ore", "lead", "vein", "deposit" }));
    harvestRequiresTool("lead ore", "pick axe");
}
