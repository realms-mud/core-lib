//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/services/backgrounds/baseBackground.c";

private object stateMachine;
private object StateMachineService = getService("stateMachine");

/////////////////////////////////////////////////////////////////////////////
protected nomask void Setup()
{
    setStartingLocation("/tutorial/rooms/entryPoint.c");

    stateMachine = StateMachineService->getStateMachine(
        "/tutorial/stateMachines/introStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
public void displayIntro(object player)
{
    stateMachine->beginIntroduction(player);
}
