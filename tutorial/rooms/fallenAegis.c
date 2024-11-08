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
    addFeature("/lib/environment/features/trees/oak-stand.c", "north");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "south");

    // First test
    addExit("east", "/tutorial/rooms/battleScene.c", "on the trail");
    addExit("west", "/tutorial/rooms/onTheTrailPart1.c", "on the trail");

    addObject("/tutorial/characters/haldor.c", "on the trail");

    setStateMachine("/tutorial/stateMachines/introStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
public void moveCharactersToOnTheTrailPartOne()
{
    StateMachine->moveSquad("west",
        "/tutorial/rooms/onTheTrailPart1.c");
}

/////////////////////////////////////////////////////////////////////////////
public void continueOnTrail()
{
    StateMachine->beginConversation("haldor is dead");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();

    if (this_player()->isRealizationOfPlayer() &&
        (StateMachine->getCurrentState() == "on the trail") &&
        present("galadhel"))
    {
        present("galadhel")->registerEvent(this_object());
        call_out("continueOnTrail", 0);
    }
}
