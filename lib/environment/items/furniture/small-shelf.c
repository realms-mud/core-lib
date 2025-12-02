//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseContainer.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("small shelf");
    addAlias("shelf");
    addAlias("wooden shelf");
    addAlias("wall shelf");

    addAdjectives(({ "small", "wooden", "plain", "sturdy", "short",
        "functional", "old", "simple", "carved" }));

    addDescriptionTemplate("a ##Adjective## small shelf mounted on the wall");

    addItemTemplate(
        "This small shelf is made from a single plank of wood, "
        "supported by simple brackets. It is just large enough to hold a few "
        "candles, jars, or trinkets."
    );

    addSomeLightDescriptionTemplate(
        "a small wooden shelf is mounted on the wall, holding a few items"
    );
    addDimLightDescriptionTemplate(
        "a small shelf is visible in the gloom, its outline barely noticeable"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a small shelf can be made out, little more than a "
        "shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a small shelf is present, but details are "
        "lost in the darkness"
    );
}
