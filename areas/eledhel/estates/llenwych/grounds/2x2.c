//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The Llenwych manor yard");
    addDecorator("farm track intersection");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("east", "/areas/eledhel/estates/llenwych/grounds/1x2.c");
    addExit("north", "/areas/eledhel/estates/llenwych/grounds/2x1.c");
    addExit("west", "/areas/eledhel/estates/llenwych/grounds/3x2.c");
    addExitWithDoor("north",
        "/areas/eledhel/estates/llenwych/manor-interior/2x0.c",
        "/lib/environment/doors/plank-door.c");
}
