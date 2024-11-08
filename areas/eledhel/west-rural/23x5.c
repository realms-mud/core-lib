//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/knoll.c", "east");
    addFeature("/lib/environment/features/trees/persimmon-stand.c", "east");

    addExit("south", "/areas/eledhel/west-rural/23x4.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("west", "/areas/eledhel/west-rural/22x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
