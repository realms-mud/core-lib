//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail north-west");
    setShortDescription("The shaded dell");
    addFeature("/lib/environment/features/landforms/dell.c", "northwest");

    addExit("west", "/areas/eledhel/west-rural-two/2x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/eledhel/west-rural-two/3x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
