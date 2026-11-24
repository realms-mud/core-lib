//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("worn pressure tile");
    addAlias("floor tile");
    addAlias("loose floor tile");
    addAlias("loose tile");
    addAlias("pressure tile");

    addAdjectives(({ "worn", "sunken", "smooth", "loose" }));

    addDescriptionTemplate("a ##Adjective## tile set into the flagstone floor");
    addItemTemplate(
        "This flagstone sits a finger's breadth lower than its neighbors. "
        "The center is polished smooth, but its edge is dark with packed "
        "dust. A thin seam in the west wall is clearest from this spot."
    );

    addSomeLightDescriptionTemplate(
        "a sunken floor tile with a dark line of dust along its edge");
    addDimLightDescriptionTemplate(
        "a single tile worn smoother than the surrounding floor");
    addLowLightDescriptionTemplate(
        "a shallow dip in the flagstone floor");
    addNearDarkDescriptionTemplate(
        "a low stone underfoot");
}
