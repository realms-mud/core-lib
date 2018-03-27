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
        addCommandTemplate("mv [##Target##] [##Destination##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("mv"))
    {
        string source = regreplace(command, "^mv ([^ ]+) .*", "\\1");
        string destination = regreplace(command, "^mv [^ ]+ (.*)", "\\1");

        if (initiator->hasWriteAccess(source) &&
            initiator->hasWriteAccess(destination))
        {
            if (file_size(source) != -1)
            {
                ret = (rename(source, destination) == 0);
            }
            else
            {
                tell_object(initiator, format(sprintf("The file '%s' does not exist.",
                    source), 78));
            }
        }
        else
        {
            tell_object(initiator, format(sprintf(
                "You do not have write access to "
                "both '%s' and '%s'", source, destination), 78));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand)
{
    return "Move/rename a file.";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand)
{
    return format("The mv command will move the source file to the destination "
        "file provided that the user has write access to both locations.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand)
{
    return "See also: cp and rm";
}
