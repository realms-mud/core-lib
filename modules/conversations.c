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

        string targetKey = sprintf("%s#%s", program_name(target),
            target->Name());
        if (!member(opinions, targetKey))
        {
            opinions[targetKey] = 0;
        }
        ret += opinions[targetKey];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void responseFromConversation(object actor, string response)
{

}

