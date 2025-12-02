//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "west");
    addFeature("/lib/environment/features/trees/oak-stand.c", "south");

    // First test
    addExit("east", "/tutorial/rooms/onTheTrailPart5.c", "on the trail");
    addExit("west", "/tutorial/rooms/onTheTrailPart7.c", "on the trail");

    setStateMachine("/tutorial/stateMachines/introStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
public void continueOnTrail()
{
    tell_room(this_object(),
        "The sound of a heated conversation can be heard to the west.\n");

    StateMachine->moveSquad("west",
        "/tutorial/rooms/onTheTrailPart7.c");
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
