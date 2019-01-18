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
    addFeature("/lib/environment/features/oakStand.c", "north");
    addFeature("/lib/environment/features/oakStand.c", "west");
    addFeature("/lib/environment/features/oakStand.c", "east");

    // First test
    addExit("south", "/lib/tutorial/rooms/onTheTrailPart3.c", "on the trail");

    StateMachine = load_object("/lib/tutorial/stateMachines/introStateMachine.c");
    setStateMachine(StateMachine);
}

/////////////////////////////////////////////////////////////////////////////
public void prodThePlayer()
{
    StateMachine->prodPlayer(this_player(), "thomas", "get moving", "south");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();

    if (this_player()->isRealizationOfPlayer() && 
        StateMachine->getCurrentState() == "on the trail")
    {
        call_out("prodThePlayer", 2);
    }
}
