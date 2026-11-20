//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("The King's Road meets Anor's market lane");
    addDecorator("village road T-west");
    addFeature("/lib/environment/features/paths/cobblestone-road.c",
        "north");
    addFeature("/lib/environment/features/paths/cobblestone-road.c",
        "south");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addExit("north", "/areas/anor/12x1.c");
    addExit("south", "/areas/anor/12x3.c");
    addExit("west", "/areas/anor/11x2.c");
}
