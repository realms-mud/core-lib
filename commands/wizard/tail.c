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
        addCommandTemplate("tail [-n ##Lines##] ##Target##");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("cat"))
    {
        notify_fail("");

        string source = regreplace(command, "^tail( -n *[0-9]+|) ([^ ]+)", "\\2");

        int lines = 8;
        if (sizeof(regexp(({ command }), "^tail -n *[0-9]+")))
        {
            lines = to_int(regreplace(command, "^tail -n *([0-9]+).*", "\\1"));
        }

        string sourcePath = initiator->hasReadAccess(source);

        if (sourcePath)
        {
            if (file_size(sourcePath) > -1)
            {
                ret = 1;
                string *contents = explode(read_file(sourcePath) || "", "\n");

                if (sizeof(contents) > lines)
                {
                    contents = contents[(sizeof(contents) - lines)..];
                }

                tell_object(initiator, implode(contents, "\n"));
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
