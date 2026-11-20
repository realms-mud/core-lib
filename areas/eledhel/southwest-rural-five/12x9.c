//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    setShortDescription("The southern road turns east toward Linwaeth");
    addDecorator("village road corner NE");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addExit("north", "/areas/eledhel/southwest-rural-five/12x8.c");
    addExit("east", "/areas/eledhel/southwest-rural-five/13x9.c");
}
