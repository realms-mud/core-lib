//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/backgrounds/baseBackground.c";

private object stateMachine;
private object StateMachineDictionary =
    load_object("/lib/dictionaries/stateMachineDictionary.c");

/////////////////////////////////////////////////////////////////////////////
protected nomask void Setup()
{
    setStartingLocation("/tutorial/rooms/entryPoint.c");

    stateMachine = StateMachineDictionary->getStateMachine(
        "/tutorial/stateMachines/introStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
public void displayIntro(object player)
{
    stateMachine->beginIntroduction(player);
}