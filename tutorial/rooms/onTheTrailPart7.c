//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/sugar-maple-stand.c", "north");
    addFeature("/tutorial/features/obedience-temple-far.c", "west");

    // First test
    addExit("east", "/tutorial/rooms/onTheTrailPart6.c", "on the trail");
    addExit("west", "/tutorial/rooms/onTheTrailPart8.c", "on the trail");

    setStateMachine("/tutorial/stateMachines/introStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
public void followDonaldIntoTheFray()
{
    StateMachine->moveSquad("west",
        "/tutorial/rooms/onTheTrailPart8.c");
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
        call_out("continueOnTrail", 0);
    }
}
