//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Wizard";
    addCommandTemplate("cat [-n ##Lines##] ##Target##");
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("cat"))
    {
        notify_fail("");

        string source = regreplace(command, "^cat( -n *[0-9]+|) ([^ ]+)", "\\2");
        int lines = 0;
        if (sizeof(regexp(({ command }), "^cat -n *[0-9]+")))
        {
            lines = to_int(regreplace(command, "^cat -n *([0-9]+).*", "\\1"));
        }
        string sourcePath = initiator->hasReadAccess(source);

        if (sourcePath)
        {
            if (file_size(sourcePath) > -1)
            {
                ret = 1;
                string contents = read_file(sourcePath, 0, lines);
                if (contents)
                {
                    tell_object(initiator, contents);
                }
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

/////////////////////////////////////////////////////////////////////////////
protected string wildcardMeaning(string colorConfiguration)
{
    return configuration->decorate("<File to view>",
        "wildcard", "help", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Display the contents of a file";
}

/////////////////////////////////////////////////////////////////////////////
protected string flagInformation(string flag, string colorConfiguration)
{
    string ret = "";
    string parsedFlag = regreplace(flag, "[^-]*(-[a-zA-Z]+).*", "\\1");
    switch (parsedFlag)
    {
        case "-n":
        {
            ret = "This option will display only the first N lines of the "
                "file";
            break;
        }
    }
    return format(ret, 72);
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The 'cat' command displays the contents of the selected "
        "file provided that the viewing wizard has read permission. When "
        "the optional -n flag is selected, only the first N lines of the "
        "file are displayed.", 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: more, head, and tail";
}
