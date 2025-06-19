//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("magical crystal deposit");
    addAdjectives(({
        "glowing magical crystal with shifting colors",
        "vein of magical crystal with arcane energy",
        "magical crystal seam with swirling patterns",
        "rough magical crystal outcrop with jagged edges",
        "hidden magical crystal seam barely visible in the wall",
        "magical crystal deposit with radiant, prismatic hues",
        "magical crystal with a glossy, enchanted surface",
        "vein of magical crystal with sparkling inclusions",
        "magical crystal seam with a mix of rough and polished stone",
        "deposit of magical crystal with arcane inclusions",
        "irregular magical crystal vein with pockets of pure energy",
        "magical crystal with a luminous, otherworldly glow"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit magical crystal deposit, where only the outline of the crystal can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit magical crystal deposit, its shifting colors blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible magical crystal deposit, its arcane glow and vibrant colors "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## embedded in the rock wall");

    harvestableResource("magical crystal", 6, "/lib/instances/items/materials/crystal/magical-crystal.c",
        "A deposit of magical crystal runs through the rock here. Some remains.",
        ({ "crystal", "magical crystal", "vein", "deposit" }));
    harvestRequiresTool("magical crystal", "pickaxe");
}
