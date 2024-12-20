//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "Wizard";
    addCommandTemplate("more ##Target##");
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
            
            tell_object(initiator, configuration->decorate("\nMore? [q to quit]\n",
                "page", "help", initiator->colorConfiguration()));

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

/////////////////////////////////////////////////////////////////////////////
protected string wildcardMeaning(string colorConfiguration)
{
    return configuration->decorate("<File to view>",
        "wildcard", "help", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Display the contents of a file with pagination";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("The 'more' command displays the contents of the selected "
        "file provided that the viewing wizard has read permission. The number "
        "of lines displayed per page defaults to 20, but can be altered "
        "by setting the 'page size' setting:\n     > " +
        configuration->decorate("set -p page size -v <lines>\n",
            "parameter", "help", colorConfiguration), 78);
}

/////////////////////////////////////////////////////////////////////////////
protected string notes(string displayCommand, string colorConfiguration)
{
    return "See also: set, cat, head, and tail";
}
