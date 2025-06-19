//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("agate deposit");

    addAdjectives(({
        "colorful agate deposit with intricate bands",
        "banded agate seam with swirling patterns",
        "vein of agate with glittering crystals",
        "rough agate outcrop with jagged edges",
        "hidden agate seam barely visible in the wall",
        "agate deposit with earthy tones and subtle hues",
        "vein of agate with translucent layers",
        "agate deposit with a glossy surface",
        "vein of agate with vibrant colors",
        "agate seam with a mix of rough and polished stone",
        "deposit of agate with sparkling inclusions",
        "irregular agate vein with pockets of crystal"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit agate deposit, where only the outline of the bands can be "
        "seen against the stone"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit agate deposit, its bands of color blending with the "
        "surrounding rock"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible agate deposit, its vibrant bands and crystals "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective## embedded in the rock wall");

    harvestableResource("agate", 10, "/lib/instances/items/materials/crystal/agate.c",
        "A vein of agate runs through the rock here. Some agate remains.",
        ({ "crystal", "agate", "agate crystal", "vein", "deposit" }));
    harvestRequiresTool("agate", "pickaxe");
}
