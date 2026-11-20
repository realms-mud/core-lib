//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addDecorator("village tree");
    setShortDescription("The upper spring hollow");
    setEncounterLevel(3);
    addRandomCreature(({ "white-tail deer", "red fox" }));
    addFeature("/lib/environment/features/water/spring.c", "east");
    addFeature("/lib/environment/features/landforms/hollow.c", "north");
    addFeature("/lib/environment/features/paths/path.c", "west");
    addClue("clear spring", "roots-by-the-stream", "inspectClearSpring",
        "The upper spring remains clear. Quarry runoff reaches "
        "the stream below it through the blocked settling ditch.");
    addExit("west", "/areas/minlach/surrounding/3x3.c");
}
