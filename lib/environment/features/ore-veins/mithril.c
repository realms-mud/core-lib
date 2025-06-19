//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("mithril ore vein");

    addAdjectives(({
        "silvery mithril vein with a faint magical shimmer",
        "broad streak of mithril ore embedded in stone",
        "vein of mithril with crystalline inclusions",
        "narrow ribbon of mithril ore winding through the rock",
        "patchy mithril deposit with a subtle blue sheen",
        "hidden mithril seam barely visible in the wall",
        "vein of mithril with sparkling inclusions",
        "rough mithril outcrop with jagged protrusions",
        "vein of mithril ore coated in a thin layer of dust",
        "solid band of mithril running through fractured stone",
        "vein of mithril with a subtle luster",
        "irregular mithril deposit with pockets of pure metal"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit mithril ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit mithril ore vein, its silvery color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible mithril ore vein, its magical luster and blue sheen "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("mithril ore", 4, "/lib/instances/items/materials/metal-ores/mithril.c",
        "A vein of mithril ore runs through the rock here. Some mithril remains.",
        ({ "ore", "mithril", "vein", "deposit" }));
    harvestRequiresTool("mithril ore", "pick axe");
}
