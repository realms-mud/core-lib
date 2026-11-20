//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/meadow.c");
    setShortDescription("A shared trough serves the southern sheep folds");
    addDecorator("village tree");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("north", "/areas/eledhel/southwest-rural-five/9x4.c");
}
