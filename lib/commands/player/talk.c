//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";
#include "/lib/include/settings.h"

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Social";
    addCommandTemplate("talk [##Target##]");
    addCommandTemplate("talk to [##Target##]");
    addCommandTemplate("repeat [##Target##]");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object target = getTarget(initiator, command);
        if (target && target->canConverse(initiator))
        {
            ret = target->beginConversation(initiator);
            if (!ret)
            {
                notify_fail(sprintf("%s has nothing to say at the moment.\n",
                    target->Name()));
            }
        }
        else
        {
            object *others = filter(all_inventory(environment(initiator)),
                (: $1->canConverse($2) :), initiator);


            if (sizeof(others))
            {
                ret = others[0]->beginConversation(initiator);
                if (!ret)
                {
                    notify_fail(sprintf("%s has nothing to say at the moment.\n",
                        others[0]->Name()));
                }
            }
            else
            {
                notify_fail("Nobody has anything to say at the moment.\n");
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Initiate a conversation with an NPC.";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Talk initiates a conversation with an NPC provided that "
        "the NPC has something they wish to discuss.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: say";
}
