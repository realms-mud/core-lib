//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        CommandType = "Wizard";
        addCommandTemplate("head [-n ##Lines##] ##Target##");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("cat"))
    {
        string source = regreplace(command, "^head( -n *[0-9]+|) ([^ ]+)", "\\2");
        
        int lines = 5;
        if (sizeof(regexp(({ command }), "^head -n *[0-9]+")))
        {
            lines = to_int(regreplace(command, "^head -n *([0-9]+).*", "\\1"));
        }

        string sourcePath = initiator->hasReadAccess(source);

        if (sourcePath)
        {
            if (file_size(sourcePath) > -1)
            {
                ret = 1;
                string contents = read_file(sourcePath, 0, lines);
                tell_object(initiator, contents);
            }
            else
            {
                tell_object(initiator, format(sprintf("The file '%s' does not exist.",
                    sourcePath), 78));
            }
        }
        else
        {
            tell_object(initiator, format(sprintf(
                "You do not have read access to '%s'", source || "???"), 78));
        }
    }
    return ret;
}
