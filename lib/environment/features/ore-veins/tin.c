//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tin ore vein");

    addAdjectives(({
        "dull gray tin vein with a faint metallic sheen",
        "broad streak of tin ore embedded in stone",
        "vein of tin with cassiterite inclusions",
        "narrow ribbon of tin ore winding through the rock",
        "patchy tin deposit with a subtle white tint",
        "hidden tin seam barely visible in the wall",
        "vein of tin with crystalline inclusions",
        "rough tin outcrop with jagged protrusions",
        "vein of tin ore coated in a thin layer of dust",
        "solid band of tin running through fractured stone",
        "vein of tin with a subtle luster",
        "irregular tin deposit with pockets of pure ore"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral vein barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit tin ore vein, where only the outline of the metal can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit tin ore vein, its gray color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible tin ore vein, its metallic luster and white tint "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("tin ore", 10, "/lib/instances/items/materials/metal-ores/tin.c",
        "A vein of tin ore runs through the rock here. Some tin remains.",
        ({ "ore", "tin", "vein", "deposit" }));
    harvestRequiresTool("tin ore", "pick axe");
}
