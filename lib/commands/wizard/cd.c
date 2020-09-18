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
        addCommandTemplate("cd [##Target##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("cd"))
    {
        string newDirectory = getTargetString(initiator, command);

        string homeDir = sprintf("/players/%s", 
            lower_case(initiator->RealName()));

        if (!newDirectory || (newDirectory == "") || (newDirectory == "~"))
        {
            newDirectory = homeDir;
        }
        newDirectory = regreplace(newDirectory, "^~/", homeDir);
        newDirectory = regreplace(newDirectory, "^~", "/players/");

        if (newDirectory[0] != '/')
        {
            newDirectory = sprintf("%s/%s", initiator->pwd(), newDirectory);
        }

        newDirectory = initiator->hasReadAccess(newDirectory);

        if (newDirectory && (file_size(newDirectory) == -2))
        {
            ret = 1;
            initiator->pwd(newDirectory);
            tell_object(initiator, sprintf("%s\n", newDirectory));
        }
        else if(!newDirectory)
        {
            notify_fail("You do not have the read access for that.\n");
        }
        else if (file_size(newDirectory) == -1)
        {
            notify_fail("That directory does not exist.\n");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Change to a directory.";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The cd command will change the user's current working "
        "directory provided that the user has read access to it.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: pwd";
}
