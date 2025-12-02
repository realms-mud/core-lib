//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";
private object commandsService;

/////////////////////////////////////////////////////////////////////////////
public nomask void SetupCommand()
{
    CommandType = "General";
    addCommandTemplate("help [##Item##]");

    commandsService = getService("commands");
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
private nomask string categoriesHelpList(string *commandCategories,
    mapping commandList, string colorConfiguration, string charset)
{
    string message = "";
    foreach(string commandCategory in commandCategories)
    {
        int columnSize = (member(({ "Wizard", "Social", "Player R&D",
            "Player Information", "Interactions", "General", "Emote / Soul" }),
            commandCategory) > -1) ? 15 : 25;

        message += commandsService->buildBanner(colorConfiguration, charset,
            "top", capitalize(commandCategory), "Help");

        string *commandEntries = sort_array(m_indices(
            commandList[commandCategory]), (: $1 > $2 :));
        int count = 0;

        string helpRow = "";
        foreach(string commandEntry in commandEntries)
        {
            if (!(count % (80 / columnSize)))
            {
                if (count)
                {
                    message += commandsService->banneredContent(
                        colorConfiguration, charset, helpRow);
                    helpRow = "";
                }
            }
            helpRow += sprintf("%-" + to_string(columnSize) + "s", commandEntry);
            count++;
        }

        count = count % (80 / columnSize);
        while(count && (count < (80 / columnSize)))
        {
            helpRow += sprintf("%-" + to_string(columnSize) + "s", "");
            count++;
        }

        message += commandsService->banneredContent(colorConfiguration, charset, helpRow);
    }
    message += commandsService->buildBanner(colorConfiguration, charset, "center", "", "");

    return message;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string topLevelHelpMessage(mapping commandList,
    string colorConfiguration, string charset)
{
    string message = "";
    if (sizeof(commandList))
    {
        string *commandCategories = sort_array(m_indices(commandList), 
            (: $1 > $2 :));

        message += categoriesHelpList(commandCategories, commandList,
            colorConfiguration, charset);
    }
    return message;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void pageString(string message, object initiator,
    string colorConfiguration, string charset)
{
    string *messageLines = explode(message, "\n");
    int pageSize = initiator->pageSize();
    if (sizeof(messageLines) > pageSize)
    {
        pageString(implode(messageLines[0..(pageSize - 1)], "\n"), initiator, 
            colorConfiguration, charset);
        tell_object(initiator, configuration->decorate("\nMore? [q to quit]\n",
            "page", "help", colorConfiguration));

        input_to("responseToPage", 1, configuration->decorate(
            implode(messageLines[pageSize..], "\n"),
            "text", "help", colorConfiguration),
            initiator, colorConfiguration, charset);
    }
    else
    {
        tell_object(initiator, message);
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask void responseToPage(string response, string message, 
    object initiator, string colorConfiguration, string charset)
{
    if (stringp(response) && (lower_case(response[0..0]) != "q"))
    {
        pageString(message, initiator, colorConfiguration, charset);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayHelpDetails(string commandFile, string command,
    string colorConfiguration, string charset, object initiator)
{
    string ret = "";
    object commandObj = load_object(commandFile);

    if (commandObj &&
        (member(inherit_list(commandObj),
            "/lib/modules/research/researchItem.c") > -1))
    {
        ret += commandObj->researchDetails();
    }
    else if (commandObj &&
        (member(inherit_list(commandObj),
            "/lib/modules/research/researchTree.c") > -1))
    {
        ret += commandObj->researchTreeDetails(initiator) +
            configuration->decorate("Items in this color are known.\n",
                "known", "research", colorConfiguration) +
            configuration->decorate("Items in this color are currently being researched.\n",
                "in progress", "research", colorConfiguration) +
            configuration->decorate("Items in this color are available to research.\n",
                "field data", "research", colorConfiguration) +
            configuration->decorate("Items in this color have unmet prerequisites "
                "and can't be researched yet.\n",
                "missing prerequisites", "research", colorConfiguration);
    }
    else if (commandObj)
    {
        ret += commandsService->buildBanner(colorConfiguration, charset, "top", "Help for", command) +
            commandObj->displaySynopsis(command, colorConfiguration, charset);

        ret += commandObj->displayUsageDetails(command, colorConfiguration, charset) +
            commandObj->displayDescription(command, colorConfiguration, charset) +
            commandObj->displayOptions(command, colorConfiguration, charset) +
            commandObj->displayNotes(command, colorConfiguration, charset);
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
        mapping commandList = commandRegistry->getListOfCommands(initiator) +
            initiator->categorizedResearch();

        mapping flattenedCommandList = flattenCommandList(commandList);
        string message = "";

        string colorConfiguration = initiator->colorConfiguration();
        string charset = initiator->charsetConfiguration();

        command = regreplace(command, "^(help *)(.*)", "\\2");
        if (!sizeof(command))
        {
            message = topLevelHelpMessage(commandList, colorConfiguration, charset);
        }
        else if (command == "soul")
        {
            message = configuration->decorate(format(
                "The following is a list of the available soul "
                "commands. Type 'help <command>' for further details "
                "about a specific soul command.\n", 78), 
                "text", "help", colorConfiguration) + 
                categoriesHelpList(({ "Emote / Soul" }), commandList,
                colorConfiguration, charset);
        }
        else if(member(flattenedCommandList, command))
        {
            message = displayHelpDetails(flattenedCommandList[command], command,
                colorConfiguration, charset, initiator);
        }
        else
        {
            message = sprintf("No help could be found for '%s'.\n", command);
        }
        pageString(message, initiator, colorConfiguration, charset);
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string synopsis(string displayCommand, string colorConfiguration)
{
    return "Displays usage information about a given command.";
}

/////////////////////////////////////////////////////////////////////////////
protected string description(string displayCommand, string colorConfiguration)
{
    return format("Help will display detailed usage information about the "
        "specified command. If no command is given, help will display "
        "the list of commands available to the player.", 78);
}
