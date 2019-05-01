//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/domains/player-holding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setLayout("/lib/dictionaries/domains/layouts/moat.c");
    addFeature("/lib/dictionaries/domains/features/south-castle-tower-exterior.c", "north");

    addConditionalExit("/lib/dictionaries/domains/layouts/moat.c",
        "none", "west", "/lib/dictionaries/domains/rooms/keep-1x8.c");
    addConditionalExit("/lib/dictionaries/domains/layouts/moat.c",
        "none", "east", "/lib/dictionaries/domains/rooms/keep-1x10.c");

    addConditionalExit("/lib/dictionaries/domains/features/south-castle-tower-exterior.c",
        "gatehouse", "north", "/lib/dictionaries/domains/rooms/keep-2x9.c");
    addConditionalExit("/lib/dictionaries/domains/features/south-castle-tower-exterior.c",
        "gatehouse", "south", "/lib/dictionaries/domains/rooms/village/village-10x19.c");

    setCoordinates("keep", 1, 9);

    setStateMachine("/lib/dictionaries/domains/stateMachine/domainStateMachine.c");
}
