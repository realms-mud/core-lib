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
    addFeature("/lib/environment/features/cottonwoodStand.c", "south");

    // First test
    addExit("east", "/lib/tutorial/rooms/battleScene.c", "on the trail");
    addExit("west", "/lib/tutorial/rooms/onTheTrailPart1.c", "on the trail");

    addObject("/lib/tutorial/characters/haldor.c", "on the trail");

    StateMachine = load_object("/lib/tutorial/stateMachines/introStateMachine.c");
    setStateMachine(StateMachine);
}

/////////////////////////////////////////////////////////////////////////////
public void moveCharactersToOnTheTrailPartOne()
{
    StateMachine->moveSquad("west",
        "/lib/tutorial/rooms/onTheTrailPart1.c");
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
        call_out("continueOnTrail", 1);
    }
}
