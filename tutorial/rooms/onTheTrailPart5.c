//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

object StateMachine;

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/cottonwoodStand.c", "north");
    addFeature("/lib/environment/features/sugarMapleStand.c", "south");

    // First test
    addExit("east", "/lib/tutorial/rooms/onTheTrailPart4.c", "on the trail");
    addExit("west", "/lib/tutorial/rooms/onTheTrailPart6.c", "on the trail");

    StateMachine = load_object("/lib/tutorial/stateMachines/introStateMachine.c");
    setStateMachine(StateMachine);
}

/////////////////////////////////////////////////////////////////////////////
public void continueOnTrail()
{
    tell_room(this_object(),
        "A flash of black can be seen to the west.\n");

    StateMachine->moveSquad("west",
        "/lib/tutorial/rooms/onTheTrailPart6.c");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();

    if (this_player()->isRealizationOfPlayer() &&
        (StateMachine->getCurrentState() == "on the trail") &&
        present("alberich"))
    {
        call_out("continueOnTrail", 1);
    }
}
