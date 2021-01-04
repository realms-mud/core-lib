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
        CommandType = "General";
        addCommandTemplate("wimpy [-v ##Value##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        ret = 1;
        if (sizeof(regexp(({ command }), "-v")))
        {
            string value = regreplace(command, ".*-v ([-0-9]+)", "\\1");
            initiator->Wimpy(value);       
        }
        else
        {
            initiator->Wimpy();
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Sets the 'run away' threshhold for the user";
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
            ret = "This option will change the hit point percentage "
                "threshhold (expressed as a value from 0 to 70).";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Wimpy allows the user to set a value at which their "
        "character will automatically run away from active combat. This "
        "threshhold is the point where their current hit points fall below "
        "the percentage of their maximum hit points. When this happens, "
        "their valor will take backseat to their thoughts of "
        "self-preservation and they will run away to an adjacent "
        "environment", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: kill";
}
