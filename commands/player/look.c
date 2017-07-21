//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void init()
{
    addCommandTemplate("look [-b] [(at|in) ##Target##]");
    addCommandTemplate("l [-b] [(at|in) ##Target##]");
    addCommandTemplate("examine [-b] [##Target##]");
    addCommandTemplate("exa [-b] [##Target##]");
    addCommandTemplate("glance [(at|in) ##Target##]");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    // This should always be true, but if not, the command should fail
    if (canExecuteCommand(command))
    {
        ret = 1;

        object target = getTarget(initiator, command);
        if(!target)
        {
            target = environment(initiator);
        }

        int brief = sizeof(regexp(({ command }), "-b")) || 
            sizeof(regexp(({ command }), "glance"));

        tell_object(initiator, target->long(brief));
    }
    return ret;
}
