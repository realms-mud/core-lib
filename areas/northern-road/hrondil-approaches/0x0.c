//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/landforms/knoll.c", "north");
    addItem("/lib/environment/items/objects/milestone.c", "southeast");
    setEncounterLevel(5);
    addRandomCreature(({ "red fox", "white-tail deer", "outlaw" }));

    addDecorator("village road corner SE");

    addExit("east", "/areas/northern-road/hrondil-approaches/1x0.c");
    addExit("south", "/areas/northern-road/belathon-eolach/24x8.c");
}
