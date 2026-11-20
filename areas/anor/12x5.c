//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The harbor road passes sheds and mooring posts");
    addDecorator("village north-south road");
    addFeature("/lib/environment/features/paths/cobblestone-road.c",
        "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c",
        "south");
    addExit("north", "/areas/anor/12x4.c");
    addExit("south", "/areas/anor/12x6.c");
}
