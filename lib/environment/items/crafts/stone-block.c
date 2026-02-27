//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stone block");
    addAlias("quarried stone");
    addAlias("dressed stone");
    addAlias("cut stone");

    addAdjectives(({ "massive", "squared", "grey", "heavy", "dressed",
        "rough-cut", "chisel-marked", "granite", "limestone", "stacked" }));

    addDescriptionTemplate("a ##Adjective## stone block awaiting transport");

    addItemTemplate(
        "The stone block is a massive rectangular piece of quarried rock, "
        "its faces cut roughly square by wedge and chisel. Tool marks "
        "score the surface in parallel lines, and one face has been "
        "dressed smooth for fitting. It sits on a wooden sledge, waiting "
        "to be hauled to a building site."
    );

    addSomeLightDescriptionTemplate(
        "a massive stone block sits on a sledge, its chisel marks clearly "
        "visible"
    );
    addDimLightDescriptionTemplate(
        "a large rectangular stone sits on a wooden frame"
    );
    addLowLightDescriptionTemplate(
        "a large pale rectangular mass sits on the ground"
    );
    addNearDarkDescriptionTemplate(
        "something massive and immovable occupies part of the area"
    );
}
