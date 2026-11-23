//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addFeature("/lib/environment/features/paths/dirt-road.c", "east");
    addFeature("/lib/environment/features/paths/dirt-road.c", "south");
    addFeature("/lib/environment/features/plants/barley-field.c", "north");
    addFeature("/lib/environment/features/water/field-drain.c", "west");
    addItem("/lib/environment/items/objects/signPost.c", "southeast");
    setEncounterLevel(4);
    addRandomCreature(({ "red fox", "white-tail deer", "outlaw" }));

    addDecorator("village road corner SE");

    addExit("east", "/areas/northern-road/belathon-eolach/1x0.c");
    addExit("south", "/areas/northern-road/northern-manor/24x8.c");
}
