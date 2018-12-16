//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/oakStand.c", "east");

    // First test
    addExit("east", "/lib/tutorial/rooms/battleScene.c", "on the trail");

    object stateMachine = load_object("/lib/tutorial/stateMachines/introStateMachine.c");
    setStateMachine(stateMachine);
}
