//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The pillared chamber at Phaedra headquarters");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/columns/marble-pillar.c", "north");
    addItem("/lib/environment/items/columns/marble-pillar.c", "south");
    addItem("/lib/environment/items/columns/marble-pillar.c", "east");
    addItem("/lib/environment/items/columns/marble-pillar.c", "west");
    addItem("/lib/environment/items/military/weapon-rack.c", "north");
    addItem("/lib/environment/items/military/training-dummy.c", "south");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addRandomCreature(({ "knight of the storm" }));
    addExit("north",
        "/areas/eledhel/northern-city/phaedra-headquarters/2x3.c");
    addExit("west",
        "/areas/eledhel/northern-city/phaedra-headquarters/1x2.c");
    addExit("east",
        "/areas/eledhel/northern-city/phaedra-headquarters/3x2.c");
}
