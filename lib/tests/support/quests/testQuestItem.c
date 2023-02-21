//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/quests/questItem.c";

private string *events = ({});

/////////////////////////////////////////////////////////////////////////////
public varargs string testSetInitialState(string state)
{
    return questItem::setInitialState(state);
}

/////////////////////////////////////////////////////////////////////////////
public varargs int testAddPrerequisite(string key, mapping prerequisite, string grouping)
{
    return questItem::addPrerequisite(key, prerequisite, grouping);
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
    questItem::registerStateActor(actor);
}

/////////////////////////////////////////////////////////////////////////////
public varargs void testAddTransition(string state, string newState, string eventName, string initiator)
{
    questItem::addTransition(state, newState, eventName, initiator);
}

/////////////////////////////////////////////////////////////////////////////
public void killTheKing()
{
    events += ({ "The king is dead!" });
}

/////////////////////////////////////////////////////////////////////////////
public void doExitStuff()
{
    events += ({"Exit stuff has been done."});
}

/////////////////////////////////////////////////////////////////////////////
public void doEnterStuff()
{
    events += ({"Enter stuff has been done."});
}

/////////////////////////////////////////////////////////////////////////////
public string *actionList()
{
    return events + ({});
}
