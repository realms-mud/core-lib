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
    addFeature("/lib/dictionaries/domains/features/southwest-castle-tower-exterior.c", "north");

    addConditionalExit("/lib/dictionaries/domains/layouts/moat.c",
        "none", "west", "/lib/dictionaries/domains/rooms/keep-1x1.c");
    addConditionalExit("/lib/dictionaries/domains/layouts/moat.c",
        "none", "east", "/lib/dictionaries/domains/rooms/keep-1x3.c");

    setCoordinates("keep", 1, 2);

    setStateMachine("/lib/dictionaries/domains/stateMachine/domainStateMachine.c");
}
