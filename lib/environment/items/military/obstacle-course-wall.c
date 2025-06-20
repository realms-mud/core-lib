//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("obstacle course wall");
    addAlias("wall");
    addAlias("training wall");

    addAdjectives(({ "tall", "wooden", "climbable", "training", "sturdy" }));
    addDescriptionTemplate("a ##Adjective## obstacle course wall for climbing practice");

    addItemTemplate(
        "The obstacle course wall is a tall, sturdy structure of rough-hewn "
        "timbers. Its surface is scarred by countless boots and hands, and "
        "ropes hang from the top to aid in climbing."
    );

    addNearDarkDescriptionTemplate(
        "the outline of an obstacle course wall is barely visible, its height "
        "lost in the darkness"
    );
    addLowLightDescriptionTemplate(
        "an obstacle course wall looms in the gloom, its ropes just visible"
    );
    addDimLightDescriptionTemplate(
        "the obstacle course wall is faintly illuminated, its rough surface "
        "just visible"
    );
    addSomeLightDescriptionTemplate(
        "the obstacle course wall is clearly visible, its ropes and timbers "
        "standing out"
    );
    addDescriptionTemplate(
        "sunlight shines on the obstacle course wall, making every handhold "
        "and rope stand out"
    );
}
