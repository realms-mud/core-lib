//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/village.c");
    setShortDescription("A low shed stores salt and cleaned nets");
    addDecorator("village cottage");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("north", "/areas/eledhel/south-coast-one/14x2.c");
}
