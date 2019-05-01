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
    addFeature("/lib/dictionaries/domains/features/southeast-castle-tower-exterior.c", "northwest");

    addConditionalExit("/lib/dictionaries/domains/layouts/moat.c",
        "none", "north", "/lib/dictionaries/domains/rooms/keep-2x17.c");
    addConditionalExit("/lib/dictionaries/domains/layouts/moat.c",
        "none", "west", "/lib/dictionaries/domains/rooms/keep-1x16.c");

    setCoordinates("keep", 1, 17);

    setStateMachine("/lib/dictionaries/domains/stateMachine/domainStateMachine.c");
}
