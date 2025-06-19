//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("graphite ore vein");

    addAdjectives(({
        "dull black graphite vein with a greasy sheen",
        "broad streak of graphite embedded in stone",
        "vein of graphite with silvery-gray inclusions",
        "narrow ribbon of graphite winding through the rock",
        "patchy graphite deposit with a faint metallic sheen",
        "hidden graphite seam barely visible in the wall",
        "vein of graphite with crystalline inclusions",
        "rough graphite outcrop with jagged protrusions",
        "vein of graphite coated in a thin layer of dust",
        "solid band of graphite running through fractured stone",
        "vein of graphite with a subtle luster",
        "irregular graphite deposit with pockets of darker ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit graphite vein, where only the outline of the mineral can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit graphite vein, its black color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible graphite vein, its greasy luster and dark color "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("graphite ore", 10, "/lib/instances/items/materials/metal-ores/graphite.c",
        "A vein of graphite runs through the rock here. Some graphite remains.",
        ({ "ore", "graphite", "graphite ore", "vein", "deposit" }));
    harvestRequiresTool("graphite ore", "pickaxe");
}
