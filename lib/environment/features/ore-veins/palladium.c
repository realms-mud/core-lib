//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("palladium ore vein");

    addAdjectives(({
        "silvery-white palladium vein with a brilliant shine",
        "broad streak of palladium ore embedded in stone",
        "vein of palladium with crystalline inclusions",
        "narrow ribbon of palladium ore winding through the rock",
        "patchy palladium deposit with a faint metallic sheen",
        "hidden palladium seam barely visible in the wall",
        "vein of palladium with quartz inclusions",
        "rough palladium outcrop with jagged protrusions",
        "vein of palladium ore coated in a thin layer of dust",
        "solid band of palladium running through fractured stone",
        "vein of palladium with a subtle luster",
        "irregular palladium deposit with pockets of pure ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit palladium ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit palladium ore vein, its silvery color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible palladium ore vein, its metallic luster and white shine "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("palladium ore", 4, "/lib/instances/items/materials/metal-ores/palladium.c",
        "A vein of palladium ore runs through the rock here. Some palladium remains.",
        ({ "ore", "palladium", "palladium ore", "vein", "deposit" }));
    harvestRequiresTool("palladium ore", "pickaxe");
}
