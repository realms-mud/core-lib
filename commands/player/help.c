//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";
private object Dictionary;

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        Dictionary = load_object("/lib/dictionaries/commandsDictionary.c");
        addCommandTemplate("help [##Item##]");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs mapping flattenCommandList(mapping commandList, string category)
{
    mapping ret = ([]);

    string *keys = m_indices(commandList);
    foreach(string key in keys)
    {
        if (mappingp(commandList[key]))
        {
            ret += flattenCommandList(commandList[key]);
        }
        else
        {
            ret[key] = commandList[key];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string topLevelHelpMessage(mapping commandList,
    string colorConfiguration, int useUnicode)
{
    string message = "";
    if (sizeof(commandList))
    {
        string *commandCategories = sort_array(m_indices(commandList), (: $1 > $2 :));
        foreach(string commandCategory in commandCategories)
        {
            message += Dictionary->buildBanner(colorConfiguration, useUnicode, 
                "top", capitalize(commandCategory), "Help");

            string *commandEntries = sort_array(m_indices(
                commandList[commandCategory]), (: $1 > $2 :));
            int count = 0;
            foreach(string commandEntry in commandEntries)
            {
                if (!(count % 5))
                {
                    if (count)
                    {
                        message += " \x1b[0;31m|\x1b[0m\n";
                    }
                    message += "\x1b[0;31m| \x1b[0;37m";
                }
                message += sprintf("%-15s", commandEntry);
                count++;
            }
            int spacesLeft = count % 5;
            if (spacesLeft)
            {
                for (int i = spacesLeft; i < 5; i++)
                {
                    message += sprintf("%-15s", "");
                }
            }
            message += " \x1b[0;31m|\x1b[0m\n";
        }
        message += Dictionary->buildBanner(colorConfiguration, useUnicode, "center", "", "");
    }
    return message;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void pageString(string message, object initiator,
    string colorConfiguration, int useUnicode)
{
    string *messageLines = explode(message, "\n");
    int pageSize = initiator->pageSize();
    if (sizeof(messageLines) > pageSize)
    {
        pageString(implode(messageLines[0..(pageSize - 1)], "\n"), initiator, 
            colorConfiguration, useUnicode);
        tell_object(initiator, "\n\x1b[0;35;1mMore? [q to quit]\x1b[0m\n");
        input_to("responseToPage", 1, "\x1b[0;36m" + implode(messageLines[pageSize..], "\n"), 
            initiator, colorConfiguration, useUnicode);
    }
    else
    {
        tell_object(initiator, message);
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask void responseToPage(string response, string message, 
    object initiator, string colorConfiguration, int useUnicode)
{
    if (stringp(response) && (lower_case(response[0..0]) != "q"))
    {
        pageString(message, initiator, colorConfiguration, useUnicode);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayHelpDetails(string commandFile, string command,
    string colorConfiguration, int useUnicode)
{
    string ret = "";
    object commandObj = load_object(commandFile);

    if (commandObj)
    {
        ret += Dictionary->buildBanner(colorConfiguration, useUnicode, "top", "Help for", command) +
            commandObj->displaySynopsis(command, colorConfiguration, useUnicode);

        ret += commandObj->displayUsageDetails(command, colorConfiguration, useUnicode) +
            commandObj->displayDescription(command, colorConfiguration, useUnicode) +
            commandObj->displayOptions(command, colorConfiguration, useUnicode) +
            commandObj->displayNotes(command, colorConfiguration, useUnicode);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object commandRegistry = load_object("/lib/commands/commandRegistry.c");
        mapping commandList = commandRegistry->getListOfCommands(initiator);
        mapping flattenedCommandList = flattenCommandList(commandList);
        string message = "";

        string colorConfiguration = initiator->colorConfiguration();
        int useUnicode = initiator->charsetConfiguration() == "unicode";

        command = regreplace(command, "^(help *)(.*)", "\\2");
        if (!sizeof(command))
        {
            message = topLevelHelpMessage(commandList, colorConfiguration, useUnicode);
        }
        else if(member(flattenedCommandList, command))
        {
            message = displayHelpDetails(flattenedCommandList[command], command,
                colorConfiguration, useUnicode);
        }
        else
        {
            message = sprintf("No help could be found for '%s'.\n", command);
        }
        pageString(message, initiator, colorConfiguration, useUnicode);
        ret = 1;
    }
    return ret;
}
