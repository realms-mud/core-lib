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
    addFeature("/lib/environment/features/plants/barley-field.c",
        "north");
    addFeature("/lib/environment/features/water/field-drain.c", "northeast");
    addItem("/lib/environment/items/objects/boundary-stone.c", "northwest");
    setEncounterLevel(4);
    addRandomCreature(({ "red fox", "white-tail deer", "outlaw" }));

    addDecorator("village road corner SE");

    addExit("east", "/areas/eledhel/estates/eolach/approach/1x0.c");
    addExit("south", "/areas/northern-road/belathon-eolach/5x4.c");
}
