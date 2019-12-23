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
        addCommandTemplate("mkdir [##Target##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("mkdir"))
    {
        string newDirectory = getTargetString(initiator, command);

        string homeDir = sprintf("/players/%s/",
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

        newDirectory = initiator->hasWriteAccess(newDirectory);

        string parentDirectory = 0;
        if (newDirectory)
        {
            string *path = explode(newDirectory, "/");
            parentDirectory = implode(path[0..(sizeof(path) - 2)], "/");
        }

        if (parentDirectory)
        {
            if (file_size(parentDirectory) != -2)
            {
                notify_fail(sprintf("Failed to make directory: %s does not "
                    "exist.\n", parentDirectory));
            }
            else if (file_size(newDirectory) != -1)
            {
                notify_fail(sprintf("Failed to make directory: %s already "
                    "exists.\n", newDirectory));
            }
            else
            {
                ret = 1;
                mkdir(newDirectory);
                tell_object(initiator, sprintf("Created %s\n", newDirectory));
            }
        }
        else if (!newDirectory)
        {
            notify_fail("You do not have the write access for that.\n");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Create a directory.";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The mkdir command will create the specified directory "
        "provided the user has write access.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: rm, cp, and mv";
}
