//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    setShortDescription("The timber watch platform beside the barracks");
    addDecorator("village keep tower");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("south", "/areas/eledhel/hadrath/grounds/3x2.c");
}
