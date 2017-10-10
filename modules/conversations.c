//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";
#include "/lib/modules/secure/conversations.h"

/////////////////////////////////////////////////////////////////////////////
private varargs int opinionWithoutModifier(object target, int modifier)
{
    string targetKey = sprintf("%s#%s", program_name(target),
        target->Name());
    if (!member(opinions, targetKey))
    {
        opinions[targetKey] = 0;
    }

    if (modifier)
    {
        opinions[targetKey] += modifier;
    }
    return opinions[targetKey];
}

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

        ret += opinionWithoutModifier(target);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int alterOpinionOf(object target, int value)
{
    int ret = 0;
    if (objectp(target))
    {
        ret = opinionWithoutModifier(target, value);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void responseFromConversation(object actor, string response)
{

}

