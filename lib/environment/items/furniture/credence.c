//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("credence");
    addAlias("side table");
    addAlias("serving table");
    addAlias("wooden credence");

    addAdjectives(({ "small", "wooden", "carved", "plain", "old", "sturdy",
        "polished", "functional", "broad", "worn" }));

    addDescriptionTemplate("a ##Adjective## credence set against the wall");

    addItemTemplate(
        "This credence is a small wooden table, often used for holding food or "
        "drink before serving. The surface is polished and the legs are carved "
        "with simple designs."
    );

    addSomeLightDescriptionTemplate(
        "a small wooden credence stands against the wall, its surface polished"
    );
    addDimLightDescriptionTemplate(
        "a credence is visible in the gloom, its outline small and plain"
    );
    addLowLightDescriptionTemplate(
        "a faint shape of a credence can be made out, little more than a shadow"
    );
    addNearDarkDescriptionTemplate(
        "a vague shadow suggests a credence is present, but details are lost in "
        "the darkness"
    );
}
