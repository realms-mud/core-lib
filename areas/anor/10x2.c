//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("Anor's market square opens between the harbor and "
        "the inland lanes");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("east", "/areas/anor/11x2.c");
    addExit("north", "/areas/anor/10x1.c");
    addExit("south", "/areas/anor/10x3.c");
}
