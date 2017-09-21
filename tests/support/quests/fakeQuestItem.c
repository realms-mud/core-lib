//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/quests/questItem.c";

private string *events = ({});

/////////////////////////////////////////////////////////////////////////////
void reset(int arg)
{
    if (!arg)
    {
        questItem::reset(arg);
        setName("Hail to the king, baby!");
        addState("meet the king", "I've been asked to meet the king!");

        addState("met the king",
            "I met King Tantor the Unclean of Thisplace. He seems to like me.");
        addTransition("meet the king", "met the king", "meetTheKing");

        addState("serve the king",
            "The king asked me - ME - to be his personal manservant. Yay me!");
        addTransition("met the king", "serve the king", "serveTheKing");

        addState("ignore the king",
            "I told the king to piss off. I have socks to fold.");
        addTransition("met the king", "ignore the king", "ignoreTheKing");
        addEntryAction("ignore the king", "killTheKing");
        addFinalState("ignore the king", "failure");

        addState("save the king",
            "Earl the Grey tried to kill the king but I gutted him like a fish.");
        addTransition("serve the king", "save the king", "hailToTheKing");
        addFinalState("save the king", "success");

        addState("king is dead",
            "I must lay off the sauce - and the wenches. King Tantor is dead because of my night of debauchery.");
        addTransition("serve the king", "king is dead", "maybeNobodyWillNotice");
        addFinalState("king is dead", "failure");

        setInitialState("meet the king");
    }
}

/////////////////////////////////////////////////////////////////////////////
public varargs string testSetInitialState(string state)
{
    return questItem::setInitialState(state);
}

/////////////////////////////////////////////////////////////////////////////
public varargs int testAddPrerequisite(string key, mapping prerequisite, string grouping)
{
    return prerequisites::addPrerequisite(key, prerequisite, grouping);
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
