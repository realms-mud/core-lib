//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/trees/alder-stand.c", "north");
    addItem("/lib/environment/items/objects/milestone.c", "west");

    addDecorator("village road corner SE");

    addExit("east", "/areas/northern-road/northern-manor/1x0.c");
    addExit("south", "/areas/northern-road/gundil-coast/9x8.c");
}
