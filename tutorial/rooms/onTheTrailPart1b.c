//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "north");

    // First test
    addExit("north", "/tutorial/rooms/onTheTrailPart1.c", "on the trail");

    setStateMachine("/tutorial/stateMachines/introStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
public void prodThePlayer()
{
    StateMachine->prodPlayer(this_player(), "thomas", "get moving", "north");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();

    if (this_player()->isRealizationOfPlayer() && 
        StateMachine->getCurrentState() == "on the trail")
    {
        call_out("prodThePlayer", 1);
    }
}
