//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("titanium ore vein");

    addAdjectives(({
        "silvery titanium vein with a faint metallic shimmer",
        "broad streak of titanium ore embedded in stone",
        "vein of titanium with rutile inclusions",
        "narrow ribbon of titanium ore winding through the rock",
        "patchy titanium deposit with a subtle blue tint",
        "hidden titanium seam barely visible in the wall",
        "vein of titanium with crystalline inclusions",
        "rough titanium outcrop with jagged protrusions",
        "vein of titanium ore coated in a thin layer of dust",
        "solid band of titanium running through fractured stone",
        "vein of titanium with a subtle luster",
        "irregular titanium deposit with pockets of pure ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit titanium ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit titanium ore vein, its silvery color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible titanium ore vein, its metallic luster and blue tint "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("titanium ore", 6, "/lib/instances/items/materials/metal-ores/titanium.c",
        "A vein of titanium ore runs through the rock here. Some titanium remains.",
        ({ "ore", "titanium", "vein", "deposit" }));
    harvestRequiresTool("titanium ore", "pick axe");
}
