//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("stretching frame");
    addAlias("frame");
    addAlias("leather frame");
    addAlias("hide frame");

    addAdjectives(({ "wooden", "large", "pegged", "stained", "sturdy",
        "well-used", "adjustable", "square", "heavy", "functional" }));

    addDescriptionTemplate("a ##Adjective## stretching frame for working leather");

    addItemTemplate(
        "The stretching frame is a square wooden structure with adjustable "
        "pegs along each side, used to stretch and hold leather while it "
        "is scraped, oiled, or worked. The wood is deeply stained from "
        "years of contact with hides and tanning agents, and leather "
        "thongs dangle from the pegs."
    );

    addSomeLightDescriptionTemplate(
        "a leather stretching frame stands with thongs dangling from its pegs"
    );
    addDimLightDescriptionTemplate(
        "a square wooden frame with pegs is visible"
    );
    addLowLightDescriptionTemplate(
        "a large square frame stands against the wall"
    );
    addNearDarkDescriptionTemplate(
        "a large frame of some kind is barely perceptible"
    );
}
