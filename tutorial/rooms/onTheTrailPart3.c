//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "east");
    addFeature("/lib/environment/features/trees/sycamore-stand.c", "south");

    // First test
    addExit("north", "/tutorial/rooms/onTheTrailPart3b.c", "on the trail");
    addExit("southeast", "/tutorial/rooms/onTheTrailPart2.c", "on the trail");
    addExit("west", "/tutorial/rooms/onTheTrailPart4.c", "on the trail");

    setStateMachine("/tutorial/stateMachines/introStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
public void continueOnTrail()
{
    tell_room(this_object(),
        "A flash of black can be seen to the west.\n");
    StateMachine->moveSquad("west",
        "/tutorial/rooms/onTheTrailPart4.c");
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
