//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "south");
    addFeature("/lib/environment/features/trees/McIntosh-apple-stand.c", "south");
    addFeature("/lib/environment/features/landforms/hollow.c", "south");

    addExit("east", "/areas/eledhel/west-rural/9x6.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/west-rural/7x6.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
