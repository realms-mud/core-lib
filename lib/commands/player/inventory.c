//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Player Information";
        addCommandTemplate("inventory [-v]");
        addCommandTemplate("i [-v]");
        addCommandTemplate("inven [-v]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if(canExecuteCommand(command) && initiator->has("inventory"))
    {
        ret = 1;

        int verbose = sizeof(regexp(({ command }), "-v"));
        tell_object(initiator, initiator->inventoryText(verbose, 1));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Displays the player's inventory";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-[a-zA-Z]+).*", "\\1");
    
    switch (parsedFlag)
    {
        case "-v":
        {
            ret = "This option will display verbose information about "
                "items in the player's inventory.";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Inventory will display all items that a player is "
        "currently carrying. Those items that are equipped/worn are "
        "shown with information about the particular slot that they "
        "are being used in.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: score";
}
