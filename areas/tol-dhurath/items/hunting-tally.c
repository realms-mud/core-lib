//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hunting tally");
    addAlias("tally board");
    addAdjectives(({ "weathered", "split", "old" }));
    addDescriptionTemplate("a ##Adjective## hunting tally board");
    addNearDarkDescriptionTemplate("a board fixed to a tree");
    addLowLightDescriptionTemplate("a weathered board with carved marks");
    addDimLightDescriptionTemplate("a tally board beneath the old tower");
    addSomeLightDescriptionTemplate("a hunting tally carved into an oak board");
    addItemTemplate("The old notches count hare, boar, and deer. A final "
        "line records that the tower was abandoned after its stair rotted "
        "through; no later marks have been added.");
}
