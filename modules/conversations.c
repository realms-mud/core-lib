//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/conversations.h"

/////////////////////////////////////////////////////////////////////////////
public nomask int opinionOf(object target)
{
    int ret = 0;
    
    if (objectp(target))
    {
        object traits = getService("traits");
        if (objectp(traits))
        {
            ret += traits->opinionModifier(target);
        }

        ret += target->opinionOfCharacter(this_object());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int alterOpinionOf(object target, int value)
{
    int ret = 0;
    if (objectp(target))
    {
        ret = target->opinionOfCharacter(this_object(), value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int alterOpinionFromEmote(object target, mapping emoteData)
{
    int ret = 0;
    if (objectp(target))
    {
        ret = target->opinionOfCharacter(this_object(), emoteData["value"]);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addConversation(string conversation)
{
    if (file_size(conversation) > 0)
    {
        object conversationObj = load_object(conversation);
        if (member(inherit_list(conversationObj), BaseConversation) > -1)
        {
            string *topicList = conversationObj->listTopics();
            conversationObj->registerConversationEvents(this_object());

            if (sizeof(topicList))
            {
                foreach(string topic in topicList)
                {
                    topics[topic] = conversation;
                }
            }
            else
            {
                raise_error(sprintf("ERROR - conversations.c, addConversation:"
                    " There are no conversations in '%s'", conversation));
            }
        }
        else
        {
            raise_error(sprintf("ERROR - conversations.c, addConversation: "
                "'%s' must inherit /lib/modules/conversations/baseConversation.c",
                conversation));
        }
    }
    else
    {
        raise_error(sprintf("ERROR - conversations.c, addConversation: "
            "'%s' does not exist", conversation));
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasTopic(string topic)
{
    return member(topics, topic);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void updateConversationState(object caller, string newState)
{
    if ((caller != this_object()) && this_player() && member(topics, newState))
    {
        this_player()->characterState(this_object(), newState);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void resetConversationState()
{
    this_player()->characterState(this_object(), "first conversation");
}

/////////////////////////////////////////////////////////////////////////////
private nomask void initializeResponses()
{
    string *responses = CurrentTopic->responses();
    if (sizeof(responses))
    {
        this_object()->init();

        foreach(string response in responses)
        {
            add_action("respondToConversation", response);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canConverse(object actor)
{
    int ret = 0;
    if (objectp(actor))
    {
        string actorState = actor->stateFor(this_object());
        string topic = actorState ? actorState : "first conversation";

        ret = member(topics, topic);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int beginConversation(object actor)
{
    int ret = 0;

    if (objectp(actor) && actor->has("state"))
    {
        string actorState = actor->stateFor(this_object());
        string topic = actorState ? actorState : "first conversation";

        if (member(topics, topic))
        {
            CurrentTopic = load_object(topics[topic]);
            ret = CurrentTopic->speakMessage(topic, actor, this_object());
            initializeResponses();
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void responseFromConversation(object actor, string response)
{
    if (objectp(actor))
    {
        actor->characterState(this_object(), response);
        if (response != "default")
        {
            beginConversation(actor);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int respondToConversation(string choice)
{
    remove_action(1);
    return CurrentTopic && CurrentTopic->displayResponse(query_command(),
        this_player(), this_object());
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onTriggerConversation(object caller,
    string conversation)
{
    if (member(topics, conversation) && this_player())
    {
        call_direct(this_player(), "onStateChanged", this_object(), conversation);
        beginConversation(this_player());
    }
}
