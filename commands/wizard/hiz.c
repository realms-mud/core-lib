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
        addCommandTemplate("hiz ##Target##");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("hiz"))
    {
        string message = 0;
        if (sizeof(regexp(({ command }), "^hiz (.+)")))
        {
            ret = 1;
            message = regreplace(command, "^hiz (.+)", "\\1");
        
            object channels = load_object("/lib/dictionaries/channelDictionary.c");
            if (channels && sizeof(message))
            {
                channels->broadcastMessage("hiz", message, initiator);
            }
        }
        else
        {
            notify_fail("What do you want to say on the hiz line?\n");
        }
    }
    return ret;
}
