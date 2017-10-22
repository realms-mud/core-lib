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
        addCommandTemplate("drop [-a] [-u] ##Target##");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    object *targets = ({});
    if (getTargetString(initiator, command) == "all")
    {
        targets += filter_array(all_inventory(initiator),
            (: function_exists("drop", $1) :));
    }
    else
    {
        targets += ({ getTarget(initiator, command) });
    }
    targets -= ({ 0 });

    if (sizeof(targets) && canExecuteCommand(command))
    {
        ret = 1;
        foreach(object target in targets)
        {
            target->drop();
        }
        tell_object(initiator, "Saving character...\n");
    }
    return ret;
}
