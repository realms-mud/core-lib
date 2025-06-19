//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("game table");
    addAlias("table");
    addAlias("playing table");
    addAlias("wooden game table");

    addAdjectives(({ "wooden", "broad", "carved", "old", "sturdy", "plain",
        "polished", "rectangular", "round", "functional" }));

    addDescriptionTemplate("a ##Adjective## game table with an inlaid board");

    addItemTemplate(
        "This game table is made from polished wood, its surface inlaid with "
        "a board for chess, draughts, or other games. The legs are sturdy, "
        "and the edges are carved with simple patterns."
    );

    addSomeLightDescriptionTemplate(
        "a wooden game table stands in the center of the room, its board ready"
    );
    addDimLightDescriptionTemplate(
        "a game table is visible in the gloom, its outline broad and plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a game table can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a game table is present, but details are lost "
        "in the darkness"
    );
}
