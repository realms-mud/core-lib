//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("workbench");
    addAlias("bench");
    addAlias("wooden workbench");
    addAlias("work table");

    addAdjectives(({ "sturdy", "wooden", "battered", "broad", "scarred",
        "old", "worn", "functional", "heavy", "well-used" }));

    addDescriptionTemplate("a ##Adjective## workbench pushed against the wall");

    addItemTemplate("This workbench is constructed from thick planks, its surface "
        "scarred and stained from years of labor. Tools and scraps are often found "
        "on or beneath it, and the legs are reinforced for stability.");

    addSomeLightDescriptionTemplate("a wooden workbench stands against the wall, its "
        "surface covered in marks and stains");

    addDimLightDescriptionTemplate("a sturdy workbench is visible in the gloom, its "
        "broad top cluttered with tools");

    addLowLightDescriptionTemplate("a faint outline of a workbench can be seen, little "
        "more than a shadow in the room");

    addNearDarkDescriptionTemplate("a vague shadow suggests a workbench is present, but "
        "details are lost in the darkness");
}
