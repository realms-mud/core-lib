//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The outer yard of Aladain Keep");
    addDecorator("farm track intersection");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExitWithDoor("north",
        "/areas/eledhel/estates/aladain/keep-interior/2x0.c",
        "/lib/environment/doors/plank-door.c");
    addExit("south", "/areas/eledhel/estates/aladain/grounds/3x3.c");
    addExit("west", "/areas/eledhel/estates/aladain/grounds/2x4.c");
    addExit("east", "/areas/eledhel/estates/aladain/grounds/4x4.c");
    addObject("/areas/eledhel/estates/aladain/characters/steward.c");
}
