//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("flagstone floor");
    suppressEntryMessage();
    addAlias("floor");
    addAlias("flagstone");
    addAlias("flagstones");

    addAdjectives(({ "of large, flat slabs fitted closely together",
        "with irregular edges that interlock naturally",
        "that has been worn smooth by generations of use",
        "with subtle variations in color and texture",
        "showing the natural grain and layers of the stone",
        "with wide joints filled with aged mortar",
        "that rings hollow in places where settling has occurred",
        "with some slabs slightly raised above their neighbors" }));

    addDescriptionTemplate("the floor is laid with flagstone "
        "##Adjective##. The large, flat stones create a durable "
        "surface that speaks of quality craftsmanship");
    addSomeLightDescriptionTemplate("the floor is laid with flagstone "
        "##Adjective##");
    addNearDarkDescriptionTemplate("the floor is made of large, flat stones. "
        "The joints between them create dark lines in the gloom");
    addLowLightDescriptionTemplate("the floor consists of fitted stone slabs. "
        "Their irregular edges are barely visible in the dim light");
    addDimLightDescriptionTemplate("the floor is paved with flagstones. "
        "The natural stone shows signs of age and use");

    addItemTemplate("The floor is constructed of large flagstone slabs, "
        "each piece carefully selected for its flat surface and fitted "
        "with its neighbors. The natural variations in the stone create "
        "subtle patterns, while the wide joints between slabs have been "
        "filled with mortar that has aged to match the stone.");
}
