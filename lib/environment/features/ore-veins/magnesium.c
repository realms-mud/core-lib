//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("magnesium ore vein");

    addAdjectives(({
        "chalky white magnesium vein with powdery residue",
        "broad streak of magnesium ore embedded in stone",
        "vein of magnesium with pale inclusions",
        "narrow ribbon of magnesium ore winding through the rock",
        "patchy magnesium deposit with a faint silvery sheen",
        "hidden magnesium seam barely visible in the wall",
        "vein of magnesium with crystalline inclusions",
        "rough magnesium outcrop with jagged protrusions",
        "vein of magnesium ore coated in a thin layer of dust",
        "solid band of magnesium running through fractured stone",
        "vein of magnesium with a subtle luster",
        "irregular magnesium deposit with pockets of pure ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit magnesium ore vein, where only the outline of the mineral can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit magnesium ore vein, its pale color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible magnesium ore vein, its chalky luster and white color "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("magnesium ore", 10, "/lib/instances/items/materials/metal-ores/magnesium.c",
        "A vein of magnesium ore runs through the rock here. Some magnesium remains.",
        ({ "ore", "magnesium", "vein", "deposit" }));
    harvestRequiresTool("magnesium ore", "pick axe");
}
