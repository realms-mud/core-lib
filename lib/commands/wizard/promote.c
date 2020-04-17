//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Wizard";
        addCommandTemplate("promote ##Target## [to ##Value##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("promote"))
    {
        ret = 1;
        string targetName = 0;
        if (sizeof(regexp(({ command }), "promote [^ ]+( to .+$|$)")))
        {
            targetName =
                regreplace(command, "^promote ([^ ]+)( to .+$|$)", "\\1");
        }

        string level = "apprentice";
        if (sizeof(regexp(({ command }), "to (.+)")))
        {
            ret = 1;
            level = regreplace(command, "^promote .+ to (.+)", "\\1");
        }
        printf("Gonna promote %O to level %O\n", targetName, level);
    }
    return ret;
}
