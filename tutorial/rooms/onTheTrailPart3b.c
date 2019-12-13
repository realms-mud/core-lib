//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "north");
    addFeature("/lib/environment/features/trees/oak-stand.c", "west");
    addFeature("/lib/environment/features/trees/oak-stand.c", "east");

    // First test
    addExit("south", "/lib/tutorial/rooms/onTheTrailPart3.c", "on the trail");

    setStateMachine("/lib/tutorial/stateMachines/introStateMachine.c");
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
