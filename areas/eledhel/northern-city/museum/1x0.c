//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    setShortDescription("The museum's local-history gallery");
    addItem("/lib/environment/items/architecture/museum-display-case.c",
        "north");
    addItem("/lib/environment/items/architecture/museum-display-case.c",
        "east");
    addExit("west", "/areas/eledhel/northern-city/museum/0x0.c");
}
