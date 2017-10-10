//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
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
public nomask void responseFromConversation(object actor, string response)
{

}

/////////////////////////////////////////////////////////////////////////////
public nomask void addConversation(string conversation)
{
    if (file_size(conversation) > 0)
    {
        object conversationObj = load_object(conversation);
        if (member(inherit_list(conversationObj), BaseConversation) > -1)
        {
            string *topicList = conversationObj->listTopics();
            if (sizeof(topics))
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