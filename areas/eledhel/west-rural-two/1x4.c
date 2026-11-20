//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-south");
    setShortDescription("The ash mound trail");
    addFeature("/lib/environment/features/trees/ash-stand.c", "northwest");
    addFeature("/lib/environment/features/landforms/mound.c", "northwest");

    addExit("north", "/areas/eledhel/west-rural-two/1x5.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/eledhel/west-rural-two/1x3.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
