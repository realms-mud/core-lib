//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/quests/questItem.c";

/////////////////////////////////////////////////////////////////////////////
public varargs string testInitialState(string state)
{
    return questItem::initialState(state);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddEntryAction(string state, string action)
{
    return questItem::addEntryAction(state, action);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddExitAction(string state, string action)
{
    return questItem::addExitAction(state, action);
}

/////////////////////////////////////////////////////////////////////////////
public varargs void testAddFinalState(string state, string result)
{
    questItem::addFinalState(state, result);
}

/////////////////////////////////////////////////////////////////////////////
public varargs void testAddState(string state, string description, string entryEvent, string isFinalState)
{
    questItem::addState(state, description, entryEvent, isFinalState);
}

/////////////////////////////////////////////////////////////////////////////
public varargs void testRegisterQuestActor(object actor)
{
    questItem::registerQuestActor(actor);
}

/////////////////////////////////////////////////////////////////////////////
public varargs void testAddTransition(string state, string newState, string eventName, string initiator)
{
    questItem::addTransition(state, newState, eventName, initiator);
}

/////////////////////////////////////////////////////////////////////////////
public void killTheKing()
{
}