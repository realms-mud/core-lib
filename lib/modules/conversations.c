//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/conversations.h"

private nosave mapping actorConversations = ([]);
private nosave mapping observedTopics = ([]);
private nosave mapping startedTopics = ([]);

/////////////////////////////////////////////////////////////////////////////
private nomask void cleanActorConversations()
{
    foreach(mixed actor in m_indices(actorConversations))
    {
        if (!objectp(actor))
        {
            m_delete(actorConversations, actor);
        }
    }
    foreach(mixed actor in m_indices(observedTopics))
    {
        if (!objectp(actor))
        {
            m_delete(observedTopics, actor);
        }
    }
    foreach(mixed actor in m_indices(startedTopics))
    {
        if (!objectp(actor))
        {
            m_delete(startedTopics, actor);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int opinionOf(object target)
{
    int ret = 0;
    
    if (objectp(target))
    {
        object traits = getModule("traits");
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
        object conversationObj = clone_object(conversation);
        if (member(inherit_list(conversationObj), BaseConversation) > -1)
        {
            string *topicList = conversationObj->listTopics();
            conversationObj->registerConversationEvents(this_object());

            if (sizeof(topicList))
            {
                foreach(string topic in topicList)
                {
                    topics[topic] = conversationObj;
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
public nomask int userHasHadConversation(string playerName, string topic)
{
    return member(spokenTopics, playerName) && 
        (member(spokenTopics[playerName], topic) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void updateSpokenTopic(object caller, string topic)
{
    if (objectp(caller) && member(topics, topic))
    {
        if (!member(spokenTopics, caller->RealName()))
        {
            spokenTopics[caller->RealName()] = ({ topic });
        }
        else if(member(spokenTopics[caller->RealName()], topic) < 0)
        {
            spokenTopics[caller->RealName()] += ({ topic });
        }
    }
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
    if (this_player())
    {
        this_player()->characterState(this_object(), "first conversation");
        m_delete(spokenTopics, this_player()->RealName());
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void initializeResponses(object actor)
{
    object conversation = actorConversations[actor];
    string *responses = objectp(conversation) ?
        conversation->responses(actor) : ({});
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
private int startConversation(object actor, int observeStart)
{
    int ret = 0;

    cleanActorConversations();
    if (objectp(actor) && actor->has("state"))
    {
        string actorState = actor->stateFor(this_object());
        string topic = actorState ? actorState : "first conversation";

        if (member(topics, topic))
        {
            actorConversations[actor] = topics[topic];
            ret = topics[topic]->speakMessage(topic, actor, this_object());
            if (ret && observeStart &&
                environment(actor) &&
                function_exists("recordObservation", actor))
            {
                if (startedTopics[actor] != topic)
                {
                    startedTopics[actor] = topic;
                    actor->recordObservation(([
                        "type":"conversation.started",
                        "subject":program_name(this_object()),
                        "participants":({ this_object() }),
                        "context":([ "topic":topic ])
                    ]));
                }
                if (observedTopics[actor] != topic)
                {
                    observedTopics[actor] = topic;
                    actor->recordObservation(([
                        "type":"conversation.topic",
                        "actor":actor,
                        "subject":program_name(this_object()),
                        "participants":({ actor, this_object() }),
                        "location":environment(actor),
                        "context":([
                            "topic":topic,
                            "explicit":1
                        ])
                    ]));
                }
            }
            if (ret)
            {
                initializeResponses(actor);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int beginConversation(object actor)
{
    return startConversation(actor, 1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void responseFromConversation(object actor, string response)
{
    if (objectp(actor))
    {
        actor->characterState(this_object(), response);
        if (response != "default")
        {
            startConversation(actor, 0);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int respondToConversation(string choice)
{
    int ret = 0;
    cleanActorConversations();
    object actor = this_player();
    object conversation = actorConversations[actor];
    if (objectp(actor) && objectp(conversation))
    {
        ret = conversation->displayResponse(query_command(),
            actor, this_object());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onTriggerConversation(object caller,
    string conversation)
{
    cleanActorConversations();
    if (objectp(caller) && member(topics, conversation))
    {
        object actor = caller->isRealizationOfPlayer() ? caller : this_player();
        actorConversations[actor] = topics[conversation];

        int spoken = topics[conversation]->speakMessage(conversation, actor,
            this_object());
        if (spoken && objectp(actor) &&
            startedTopics[actor] != conversation && environment(actor) &&
            function_exists("recordObservation", actor))
        {
            startedTopics[actor] = conversation;
            actor->recordObservation(([
                "type": "conversation.started",
                "subject": program_name(this_object()),
                "participants": ({ this_object() }),
                "context": ([ "topic": conversation ])
            ]));
        }
        if (spoken && present(this_object(), environment(caller)))
        {
            initializeResponses(actor);
        }
    }
}
