//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("antimony ore vein");

    addAdjectives(({
        "silvery antimony vein with metallic luster",
        "broad streak of antimony ore embedded in stone",
        "vein of antimony with crystalline inclusions",
        "narrow ribbon of antimony ore winding through the rock",
        "patchy antimony deposit with a faint blue sheen",
        "hidden antimony seam barely visible in the wall",
        "vein of antimony with quartz inclusions",
        "rough antimony outcrop with jagged protrusions",
        "vein of antimony ore coated in a thin layer of dust",
        "solid band of antimony running through fractured stone",
        "vein of antimony with a subtle metallic shine",
        "irregular antimony deposit with pockets of pure ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit antimony ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit antimony ore vein, its silvery color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible antimony ore vein, its metallic luster and blue sheen "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("antimony ore", 8, "/lib/instances/items/materials/metal-ores/antimony.c",
        "A vein of antimony ore runs through the rock here. Some antimony remains.",
        ({ "ore", "antimony", "vein", "deposit" }));
    harvestRequiresTool("antimony ore", "pick axe");
}
