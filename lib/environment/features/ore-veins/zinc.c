//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("zinc ore vein");

    addAdjectives(({
        "dull gray zinc vein with rough, uneven edges",
        "broad streak of metallic zinc embedded in stone",
        "vein of zinc with flecks of white mineral",
        "narrow ribbon of zinc ore winding through the rock",
        "patchy zinc deposit with a faint bluish sheen",
        "hidden zinc seam barely visible in the wall",
        "vein of zinc with crystalline inclusions",
        "rough zinc outcrop with jagged protrusions",
        "vein of zinc ore coated in a thin layer of dust",
        "solid band of zinc running through fractured stone",
        "vein of zinc with a subtle metallic luster",
        "irregular zinc deposit with pockets of darker ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit zinc ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit zinc ore vein, its dull gray color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible zinc ore vein, its metallic luster and rough texture "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("zinc ore", 15, "/lib/instances/items/materials/metal-ores/zinc.c",
        "A vein of zinc ore runs through the rock here. Some zinc remains.",
        ({ "ore", "zinc", "vein", "deposit" }));
    harvestRequiresTool("zinc ore", "pick axe");
}
