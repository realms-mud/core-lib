//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("brick floor");
    suppressEntryMessage();
    addAlias("floor");
    addAlias("brick");
    addAlias("bricks");

    addAdjectives(({ "of reddish clay bricks laid in neat rows",
        "with mortar joints creating a grid pattern",
        "that shows scorch marks from intense heat",
        "made from hard-fired terra cotta bricks",
        "with some bricks cracked or chipped from use",
        "laid in an attractive herringbone pattern",
        "that feels cool and solid underfoot",
        "with whitish salt stains on some bricks" }));

    addDescriptionTemplate("the floor is paved with brick "
        "##Adjective##. The fired clay creates a practical "
        "and heat-resistant surface");
    addSomeLightDescriptionTemplate("the floor is paved with brick "
        "##Adjective##");
    addNearDarkDescriptionTemplate("the floor is made of what feels like "
        "fired clay. Regular joints suggest brick construction");
    addLowLightDescriptionTemplate("the floor consists of fitted bricks. "
        "The mortar lines create a geometric pattern");
    addDimLightDescriptionTemplate("the floor is laid with clay bricks. "
        "The surface shows signs of heat and heavy use");

    addItemTemplate("The floor is constructed of carefully laid bricks, "
        "each piece of fired clay fitted with mortar joints that create "
        "regular patterns across the surface. The bricks show the characteristic "
        "reddish color of fired earth, with variations that speak to their "
        "handmade origins and practical durability.");
}
