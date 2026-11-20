//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    setShortDescription("The hedge track skirts a quiet copse");
    addDecorator("village tree");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/eledhel/southwest-rural-five/4x3.c");
    addExit("south", "/areas/eledhel/southwest-rural-five/3x2.c");
}
