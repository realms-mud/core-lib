//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("amethyst ceiling");
    suppressEntryMessage();

    addDescriptionTemplate("the ceiling is hard to discern from this distance, "
        "but it appears to be solid amethyst");

    addItemTemplate("The ceiling appears to be made of solid amethyst, but "
        "from this distance, it is impossible to tell for sure");
}
