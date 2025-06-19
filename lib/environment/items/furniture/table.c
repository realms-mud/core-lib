//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("table");
    addAlias("dining table");
    addAlias("work table");
    addAlias("wooden table");

    addAdjectives(({ "sturdy", "wooden", "long", "plain", "carved",
        "old", "worn", "polished", "broad", "rectangular", "round", "functional" }));

    addDescriptionTemplate("a ##Adjective## table set in the center of the room");

    addItemTemplate("This table is crafted from solid wood, its surface marked by "
        "years of use. The legs are thick and stable, with simple carvings along the "
        "edges. Scratches and stains hint at countless meals, meetings, and tasks "
        "performed here. It is large enough to seat several people comfortably.");

    addSomeLightDescriptionTemplate("a wooden table stands in the center of the room, "
        "its surface showing the marks of long use");

    addDimLightDescriptionTemplate("a sturdy table is visible in the gloom, its outline "
        "broad and inviting");

    addLowLightDescriptionTemplate("a faint shape of a table can be made out, little more "
        "than a shadow in the room");

    addNearDarkDescriptionTemplate("a vague shadow suggests a table is present, but "
        "details are lost in the darkness");
}
