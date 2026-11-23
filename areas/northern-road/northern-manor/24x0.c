//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/trees/oak-stand.c", "north");
    addItem("/lib/environment/items/objects/signPost.c", "southeast");

    addDecorator("village road corner SW");

    addExit("west", "/areas/northern-road/northern-manor/23x0.c");
    addExit("south", "/areas/northern-road/northern-manor/24x1.c");
}
