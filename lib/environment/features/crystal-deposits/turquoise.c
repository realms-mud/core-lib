//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("turquoise deposit");

    addAdjectives(({
        "vivid blue-green turquoise with intricate veining",
        "vein of turquoise with swirling patterns",
        "rough turquoise outcrop with jagged edges",
        "hidden turquoise seam barely visible in the wall",
        "turquoise deposit with earthy, matte tones",
        "vein of turquoise with glossy, polished surfaces",
        "turquoise with a waxy luster and subtle inclusions",
        "deposit of turquoise with flecks of white mineral",
        "irregular turquoise vein with pockets of pure color",
        "turquoise seam with a mix of rough and smooth stone",
        "turquoise with a luminous, ancient glow",
        "vein of turquoise with sparkling blue-green crystals"
        }));

    addNearDarkDescriptionTemplate(
        "a shadowy mineral deposit barely discernible in the darkness"
    );
    addLowLightDescriptionTemplate(
        "a barely-lit turquoise deposit, where only the outline of the stone can be "
        "seen against the rock"
    );
    addDimLightDescriptionTemplate(
        "a dimly-lit turquoise deposit, its blue-green color blending with the "
        "surrounding stone"
    );
    addSomeLightDescriptionTemplate(
        "a clearly visible turquoise deposit, its vibrant color and veining "
        "standing out in the stone"
    );

    addDescriptionTemplate("a ##Adjective##");

    harvestableResource("turquoise", 10, "/lib/instances/items/materials/crystal/turquoise.c",
        "A vein of turquoise runs through the rock here. Some turquoise remains.",
        ({ "turquoise crystal", "stone", "deposit", "gem" }));
    harvestRequiresTool("turquoise", "pick axe");
}
