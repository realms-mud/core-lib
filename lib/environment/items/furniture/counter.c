//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("counter");
    addAlias("bar");
    addAlias("serving counter");
    addAlias("wooden counter");

    addAdjectives(({ "long", "wooden", "polished", "worn", "broad",
        "sturdy", "plain", "old", "scratched", "functional" }));

    addDescriptionTemplate("a ##Adjective## counter runs along one side of the room");

    addItemTemplate("This counter is made from polished wood, its surface worn smooth "
        "by countless hands and mugs. The edges are rounded, and the base is reinforced "
        "for stability. It serves as a place for serving, working, or gathering.");

    addSomeLightDescriptionTemplate("a wooden counter runs along the wall, its surface "
        "showing the marks of long use");

    addDimLightDescriptionTemplate("a sturdy counter is visible in the gloom, its "
        "broad top reflecting faint light");

    addLowLightDescriptionTemplate("a faint shape of a counter can be made out, little "
        "more than a shadow in the room");

    addNearDarkDescriptionTemplate("a vague shadow suggests a counter is present, but "
        "details are lost in the darkness");
}
