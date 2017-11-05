//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        addCommandTemplate("look [-b] [(at|in) ##Target##]");
        addCommandTemplate("l [-b] [(at|in) ##Target##]");
        addCommandTemplate("examine [-b] [##Target##]");
        addCommandTemplate("exa [-b] [##Target##]");
        addCommandTemplate("glance [(at|in) ##Target##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    // This should always be true, but if not, the command should fail
    if (canExecuteCommand(command))
    {
        if (initiator->hasTraitOfRoot("blind"))
        {
            notify_fail("You are blind.\n");
        }
        else
        {
            ret = 1;
            object target = getTarget(initiator, command);
            if (!target && (getTargetString(initiator, command) == ""))
            {
                target = environment(initiator);
            }

            int brief = sizeof(regexp(({ command }), "-b")) ||
                sizeof(regexp(({ command }), "glance"));

            if (target)
            {
                string longDesc = target->long(brief);
                if (longDesc)
                {
                    tell_object(initiator, longDesc);
                }
            }
            else
            {
                tell_object(initiator, sprintf("There is no '%s' here.\n",
                    getTargetString(initiator, command)));
            }
        }
    }
    return ret;
}
