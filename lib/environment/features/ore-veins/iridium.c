//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("iridium ore vein");

    addAdjectives(({
        "silvery-white iridium vein with a brilliant shine",
        "broad streak of iridium ore embedded in stone",
        "vein of iridium with crystalline inclusions",
        "narrow ribbon of iridium ore winding through the rock",
        "patchy iridium deposit with a faint metallic sheen",
        "hidden iridium seam barely visible in the wall",
        "vein of iridium with quartz inclusions",
        "rough iridium outcrop with jagged protrusions",
        "vein of iridium ore coated in a thin layer of dust",
        "solid band of iridium running through fractured stone",
        "vein of iridium with a subtle luster",
        "irregular iridium deposit with pockets of pure ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit iridium ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit iridium ore vein, its silvery color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible iridium ore vein, its metallic luster and white shine "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("iridium ore", 5, "/lib/instances/items/materials/metal-ores/iridium.c",
        "A vein of iridium ore runs through the rock here. Some iridium remains.",
        ({ "ore", "iridium", "iridium ore", "vein", "deposit" }));
    harvestRequiresTool("iridium ore", "pickaxe");
}
