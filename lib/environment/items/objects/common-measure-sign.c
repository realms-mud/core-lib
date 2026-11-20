//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Common Measure sign");
    addAlias("inn sign");
    addAlias("painted sign");
    addAdjectives(({ "painted", "weathered", "oak", "three-colored" }));
    addDescriptionTemplate(
        "a ##Adjective## sign showing a grain measure between an apple branch "
        "and a millstone");
    addItemTemplate(
        "The old wheel-shaped sign carries three small marks: an apple branch, "
        "a grain measure, and a millstone. The paint is touched up often, but "
        "the lower edge bears the pale groove of a hundred winter reins."
    );
}
