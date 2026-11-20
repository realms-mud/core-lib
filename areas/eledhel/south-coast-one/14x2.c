//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");
    setShortDescription("The fishers' common green");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("west", "/areas/eledhel/south-coast-one/13x2.c");
    addExit("east", "/areas/eledhel/south-coast-one/15x2.c");
    addExit("north", "/areas/eledhel/south-coast-one/14x1.c");
    addExit("south", "/areas/eledhel/south-coast-one/14x3.c");
    addObject("/areas/eledhel/south-coast-one/characters/fisher.c");
}
