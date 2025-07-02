//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wood block floor");
    suppressEntryMessage();
    addAlias("floor");
    addAlias("wood");
    addAlias("wooden");
    addAlias("block");
    addAlias("blocks");

    addAdjectives(({ "of small rectangular blocks fitted tightly together",
        "arranged in an intricate herringbone pattern",
        "with end grain exposed creating a textured surface",
        "that has been polished to a rich, warm sheen",
        "showing subtle color variations between different blocks",
        "with some blocks slightly raised or sunken",
        "that provides excellent grip underfoot",
        "displaying the natural beauty of cut timber ends" }));

    addDescriptionTemplate("the floor is made of wood blocks "
        "##Adjective##. The small pieces create an attractive "
        "and durable surface");
    addSomeLightDescriptionTemplate("the floor is made of wood blocks "
        "##Adjective##");
    addNearDarkDescriptionTemplate("the floor appears to be constructed of "
        "small wooden pieces. The surface feels textured underfoot");
    addLowLightDescriptionTemplate("the floor consists of fitted wooden "
        "blocks. Their regular pattern is barely visible in the light");
    addDimLightDescriptionTemplate("the floor is made of wooden blocks. "
        "The end grain creates an interesting textured appearance");

    addItemTemplate("The floor is constructed of small wooden blocks cut "
        "from the ends of timber, with the end grain facing upward to create "
        "a naturally textured surface. Each block fits snugly against its "
        "neighbors, forming intricate patterns that highlight the natural "
        "beauty of the wood grain while providing excellent durability.");
}
