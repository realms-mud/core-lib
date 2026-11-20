//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The Oeldhen manor yard");
    addDecorator("farm track intersection");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/estates/oeldhen/grounds/1x2.c");
    addExit("north", "/areas/eledhel/estates/oeldhen/grounds/2x1.c");
    addExit("east", "/areas/eledhel/estates/oeldhen/grounds/3x2.c");
    addExitWithDoor("north",
        "/areas/eledhel/estates/oeldhen/manor-interior/2x0.c",
        "/lib/environment/doors/plank-door.c");
}
