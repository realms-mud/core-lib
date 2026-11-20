//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");
    setShortDescription("The Drovers' Rest yard");
    addDecorator("village inn");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("east", "/areas/eledhel/southwest-rural-four/11x3.c");
    addExit("north", "/areas/eledhel/southwest-rural-four/10x2.c");
    addExit("south", "/areas/eledhel/southwest-rural-four/10x4.c");
    addObject("/areas/eledhel/southwest-rural-four/characters/innkeeper.c");
}
