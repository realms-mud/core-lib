//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Wizard";
    addCommandTemplate("wiz ##Target##");
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
        
            object channels = getService("channel");
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

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Speak a message on the wizard channel";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The wiz command will display the typed message to all "
        "wizards with a currently-active 'wiz' channel.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: hiz";
}
