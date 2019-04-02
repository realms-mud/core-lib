//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/oakStand.c", "west");
    addFeature("/lib/environment/features/oakStand.c", "south");

    // First test
    addExit("east", "/lib/tutorial/rooms/onTheTrailPart5.c", "on the trail");
    addExit("west", "/lib/tutorial/rooms/onTheTrailPart7.c", "on the trail");

    setStateMachine("/lib/tutorial/stateMachines/introStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
public void continueOnTrail()
{
    tell_room(this_object(),
        "The sound of a heated conversation can be heard to the west.\n");

    StateMachine->moveSquad("west",
        "/lib/tutorial/rooms/onTheTrailPart7.c");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();

    if (this_player()->isRealizationOfPlayer() &&
        (StateMachine->getCurrentState() == "on the trail") &&
        present("alberich"))
    {
        call_out("continueOnTrail", 0);
    }
}
