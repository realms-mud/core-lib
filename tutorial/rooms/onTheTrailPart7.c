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
    addFeature("/lib/environment/features/sugarMapleStand.c", "north");
    addFeature("/lib/tutorial/features/obedience-temple-far.c", "west");

    // First test
    addExit("east", "/lib/tutorial/rooms/onTheTrailPart6.c", "on the trail");
    addExit("west", "/lib/tutorial/rooms/onTheTrailPart8.c", "on the trail");

    StateMachine = load_object("/lib/tutorial/stateMachines/introStateMachine.c");
    setStateMachine(StateMachine);
}

/////////////////////////////////////////////////////////////////////////////
public void followDonaldIntoTheFray()
{
    StateMachine->moveSquad("west",
        "/lib/tutorial/rooms/onTheTrailPart8.c");
}

/////////////////////////////////////////////////////////////////////////////
public void continueOnTrail()
{
    StateMachine->beginConversation("whisper about dead to Donald");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();

    if (this_player()->isRealizationOfPlayer() &&
        (StateMachine->getCurrentState() == "on the trail") &&
        present("alberich"))
    {
        present("alberich")->registerEvent(this_object());
        call_out("continueOnTrail", 1);
    }
}
