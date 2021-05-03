//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

object Owner;

/////////////////////////////////////////////////////////////////////////////
public void SetOwner(object owner)
{
    Owner = owner;
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("issueCommand", "issueCommand");
    add_action("triggerSecond", "triggerSecond");
    add_action("triggerThird", "triggerThird");
}

/////////////////////////////////////////////////////////////////////////////
public int issueCommand()
{
    object stateMachine = load_object("/lib/tests/support/core/testStateMachine.c");
    stateMachine.registerEvent(this_player());
    stateMachine.testStartStateMachine();
    stateMachine.receiveEvent(this_player(), "meetTheKing", this_player());
    stateMachine.receiveEvent(this_player(), "serveTheKing", this_player());
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public int triggerSecond()
{
    object stateMachine = load_object("/lib/tests/support/core/testStateMachine.c");
    stateMachine.registerEvent(this_player());
    stateMachine.testStartStateMachine();
    stateMachine.receiveEvent(this_player(), "meetTheKing", this_player());
    stateMachine.receiveEvent(this_player(), "serveTheKing", this_player());
    stateMachine.receiveEvent(this_player(), "maybeNobodyWillNotice", this_player());
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public int triggerThird()
{
    object stateMachine = load_object("/lib/tests/support/core/testStateMachine.c");
    stateMachine.registerEvent(this_player());
    stateMachine.testStartStateMachine();
    stateMachine.receiveEvent(this_player(), "meetTheKing", this_player());
    stateMachine.receiveEvent(this_player(), "serveTheKing", this_player());
    stateMachine.receiveEvent(this_player(), "hailToTheKing", this_player());
    return 1;
}
