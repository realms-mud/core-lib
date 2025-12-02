//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("small table");
    addAlias("side table");
    addAlias("end table");
    addAlias("wooden table");

    addAdjectives(({ "small", "wooden", "round", "square", "plain",
        "polished", "worn", "sturdy", "old", "functional" }));

    addDescriptionTemplate("a ##Adjective## small table set near the wall");

    addItemTemplate("This small table is crafted from wood, with a simple design "
        "and a smooth top. Its legs are sturdy, and the surface is just large enough "
        "for a lamp, a book, or a mug. It fits easily in a corner or beside a chair.");

    addSomeLightDescriptionTemplate("a small wooden table stands near the wall, its "
        "surface showing the marks of long use");

    addDimLightDescriptionTemplate("a sturdy small table is visible in the gloom, its "
        "outline plain but serviceable");

    addLowLightDescriptionTemplate("a faint shape of a small table can be made out, "
        "little more than a shadow");

    addNearDarkDescriptionTemplate("a vague shadow suggests a small table is present, "
        "but details are lost in the darkness");
}
