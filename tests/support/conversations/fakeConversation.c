//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
public void testAddTopic(string id, string template)
{
    return addTopic(id, template);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddRepeatableTopic(string id, string template)
{
    return addRepeatableTopic(id, template);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddTopicPrerequisite(string id, mapping prerequisite)
{
    return addTopicPrerequisite(id, prerequisite);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddTopicEvent(string id, string event)
{
    return addTopicEvent(id, event);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddTopicTrigger(string id, string event)
{
    return addTopicTrigger(id, event);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddTopicInterjection(string id, string actor,
    string actorTopic)
{
    return addTopicInterjection(id, actor, actorTopic);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddResponse(string id, string selection, string template)
{
    return addResponse(id, selection, template);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddResponseTopic(string id, string selection, string newMessage)
{
    return addResponseTopic(id, selection, newMessage);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddResponsePrerequisite(string id, string selection, mapping prerequisite)
{
    return addResponsePrerequisite(id, selection, prerequisite);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddResponseEvent(string id, string selection, string event)
{
    return addResponseEvent(id, selection, event);
}

/////////////////////////////////////////////////////////////////////////////
public void testAddResponseEffect(string id, string selection, mapping effect)
{
    return addResponseEffect(id, selection, effect);
}
