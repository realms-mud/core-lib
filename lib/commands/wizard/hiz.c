//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Wizard";
    addCommandTemplate("hiz ##Target##");
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

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Speak a message on the high-level wizard channel";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The hiz command will display the typed message to all "
        "wizards with a currently-active 'hiz' channel. These wizards are "
        "Elder wizards and higher.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: wiz";
}
