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
        addCommandTemplate("more ##Target##");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void pageString(string message, object initiator)
{
    if (message)
    {
        string *messageLines = explode(message, "\n");
        int pageSize = initiator->pageSize();
        if (sizeof(messageLines) > pageSize)
        {
            pageString(implode(messageLines[0..(pageSize - 1)], "\n"), initiator);
            tell_object(initiator, "\n\x1b[0;35;1mMore? [q to quit]\x1b[0m\n");
            input_to("responseToPage", 1, implode(messageLines[pageSize..], "\n"), initiator);
        }
        else
        {
            tell_object(initiator, message);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask void responseToPage(string response, string message, object initiator)
{
    if (stringp(response) && (lower_case(response[0..0]) != "q"))
    {
        pageString(message, initiator);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command) && initiator->hasExecuteAccess("more"))
    {
        notify_fail("");
        string source = regreplace(command, "^more ([^ ]+)", "\\1");
        string sourcePath = initiator->hasReadAccess(source);

        if (sourcePath)
        {
            if (file_size(sourcePath) > -1)
            {
                ret = 1;
                string contents = read_file(sourcePath);
                pageString(contents, initiator);
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
