//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/paths/dirt-road.c", "west");
    addFeature("/lib/environment/features/trees/alder-stand.c", "north");
    addItem("/lib/environment/items/objects/signPost.c", "southeast");

    addDecorator("village road T-south");

    addExit("east", "/areas/northern-road/northern-manor/20x6.c");
    addExit("south", "/areas/argalen-keep/patrol-coast/24x4.c");
    addExit("west", "/areas/northern-road/northern-manor/18x6.c");
}
