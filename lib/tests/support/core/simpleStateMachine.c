//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/stateMachine.c";

private string *events = ({});

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addState("default", "");

    addState("blah", "");
    addTransition("default", "blah", "blahTransition");

    addState("blah2", "");
    addTransition("blah", "blah2", "blahTwoTransition");

    setInitialState("default");
}

/////////////////////////////////////////////////////////////////////////////
void testOverrideCurrentState(string newState)
{
    CurrentState = newState;
}
