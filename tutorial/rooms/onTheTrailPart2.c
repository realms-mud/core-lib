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
    addFeature("/lib/environment/features/trees/sycamore-stand.c", "north");

    // First test
    addExit("south", "/tutorial/rooms/onTheTrailPart1.c", "on the trail");
    addExit("northwest", "/tutorial/rooms/onTheTrailPart3.c", "on the trail");

    setStateMachine("/tutorial/stateMachines/introStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
public void continueOnTrail()
{
    tell_room(this_object(),
        "A flash of black can be seen to the northwest.\n");
    StateMachine->moveSquad("northwest",
        "/tutorial/rooms/onTheTrailPart3.c");
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
