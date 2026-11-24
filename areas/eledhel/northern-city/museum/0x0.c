//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/hallway.c");
    setShortDescription("The museum's modest entrance gallery");
    addItem("/lib/environment/items/architecture/museum-display-case.c",
        "north");
    addItem("/lib/environment/items/architecture/museum-display-case.c",
        "east");
    addObject("/areas/eledhel/northern-city/characters/museum-curator.c");
    addExit("south", "/areas/eledhel/northern-city/17x8.c");
    addExit("east", "/areas/eledhel/northern-city/museum/1x0.c");
    addExit("down", "/areas/eledhel/under-city/museum-branch/17x8.c");
}
