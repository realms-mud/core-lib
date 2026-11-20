//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("forest trail south-east");
    setShortDescription("A concealed path through the game woods");
    addFeature("/lib/environment/features/trees/pine-stand.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("south", "/areas/evenholt/grounds/19x2.c");
    addExit("east", "/areas/evenholt/grounds/20x1.c");
    addRandomCreature(({ "red fox", "white-tail deer", "timber wolf" }));
}
