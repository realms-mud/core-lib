//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "northwest");
    addFeature("/lib/environment/features/trees/willow-stand.c", "northwest");
    addFeature("/lib/environment/features/water/ravine-brook.c", "northwest");

    addExit("north", "/areas/eledhel/west-rural/15x7.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/eledhel/west-rural/15x5.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
