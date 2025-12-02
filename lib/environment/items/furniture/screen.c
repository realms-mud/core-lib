//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("screen");
    addAlias("divider");
    addAlias("folding screen");
    addAlias("wooden screen");

    addAdjectives(({ "wooden", "carved", "tall", "broad", "ornate", "painted",
        "folding", "old", "decorative", "panelled" }));

    addDescriptionTemplate("a ##Adjective## screen used to divide the room");

    addItemTemplate(
        "This screen is made from several wooden panels joined by hinges. The "
        "panels are carved or painted with simple designs, and the screen can "
        "be folded or moved to provide privacy or block drafts."
    );

    addSomeLightDescriptionTemplate(
        "a wooden screen stands unfolded, dividing part of the room"
    );
    addDimLightDescriptionTemplate(
        "a screen is visible in the gloom, its outline tall and broad"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a screen can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a screen is present, but details are lost in "
        "the darkness"
    );
}
