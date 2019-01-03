//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/backgrounds/baseBackground.c";

private object stateMachine;

/////////////////////////////////////////////////////////////////////////////
protected nomask void Setup()
{
    setStartingLocation("/lib/tutorial/rooms/battleScene.c");

    stateMachine = clone_object("/lib/tutorial/stateMachines/introStateMachine.c");
}

/////////////////////////////////////////////////////////////////////////////
public void displayIntro(object player)
{
    stateMachine->beginIntroduction(player);
}