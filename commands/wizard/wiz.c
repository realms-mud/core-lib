//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Wizard";
        addCommandTemplate("wiz ##Target##");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("wiz"))
    {
        string message = 0;
        if (sizeof(regexp(({ command }), "^wiz (.+)")))
        {
            ret = 1;
            message = regreplace(command, "^wiz (.+)", "\\1");
        
            object channels = load_object("/lib/dictionaries/channelDictionary.c");
            if (channels && sizeof(message))
            {
                channels->broadcastMessage("wiz", message, initiator);
            }
        }
        else
        {
            notify_fail("What do you want to say on the wiz line?\n");
        }
    }
    return ret;
}
