//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "east");

    addExit("east", "/areas/tol-dhurath/northern-trail/1x4.c");
    addExit("west", "/areas/northern-road/hrondil-approaches/24x4.c");

    addRandomCreature(({"gray fox","outlaw","white-tail deer"}));
}
