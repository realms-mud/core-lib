//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("bismuth ore vein");

    addAdjectives(({
        "iridescent bismuth vein with rainbow hues",
        "broad streak of bismuth ore embedded in stone",
        "vein of bismuth with crystalline inclusions",
        "narrow ribbon of bismuth ore winding through the rock",
        "patchy bismuth deposit with a faint metallic sheen",
        "hidden bismuth seam barely visible in the wall",
        "vein of bismuth with geometric inclusions",
        "rough bismuth outcrop with jagged protrusions",
        "vein of bismuth ore coated in a thin layer of dust",
        "solid band of bismuth running through fractured stone",
        "vein of bismuth with a subtle luster",
        "irregular bismuth deposit with pockets of pure ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit bismuth ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit bismuth ore vein, its iridescent color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible bismuth ore vein, its rainbow luster and metallic sheen "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("bismuth ore", 8, "/lib/instances/items/materials/metal-ores/bismuth.c",
        "A vein of bismuth ore runs through the rock here. Some bismuth remains.",
        ({ "ore", "bismuth", "vein", "deposit" }));
    harvestRequiresTool("bismuth ore", "pick axe");
}
