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
