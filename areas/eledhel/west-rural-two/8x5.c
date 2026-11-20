//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail east-west");
    setShortDescription("The buckthorn glen");
    addFeature("/lib/environment/features/landforms/glen.c", "southeast");
    addFeature("/lib/environment/features/trees/buckthorn-stand.c", "southeast");

    addExit("east", "/areas/eledhel/west-rural-two/9x5.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/west-rural-two/7x5.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
