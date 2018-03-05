//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";
private object Dictionary;

/////////////////////////////////////////////////////////////////////////////
public int sortArray(mixed a, mixed b)
{
    string compA;
    string compB;

    if (mappingp(a) && mappingp(b))
    {
        compA = this_object()->convertDataToString(a);
        compB = this_object()->convertDataToString(b);
    }
    else
    {
        compA = to_string(a);
        compB = to_string(b);
    }

    return compA > compB;
}

/////////////////////////////////////////////////////////////////////////////
public string convertDataToString(mixed data)
{
    string ret = "";

    if (objectp(data))
    {
        ret += program_name(data);
    }
    else if (pointerp(data) && sizeof(data))
    {
        ret += "({ ";
        data = sort_array(data, "sortArray");
        foreach(mixed element in data)
        {
            ret += convertDataToString(element) + ", ";
        }
        ret += "})";
    }
    else if (mappingp(data))
    {
        ret += "([ ";
        mixed *indices = sort_array(m_indices(data), "sortArray");
        foreach(mixed index in indices)
        {
            ret += convertDataToString(index) + ": " + convertDataToString(data[index]) + ", ";
        }
        ret += "])";
    }
    else
    {
        ret += to_string(data);
    }
    return ret;
}

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
private nomask string topLevelHelpMessage(mapping commandList)
{
    string message = "";
    if (sizeof(commandList))
    {
        string *commandCategories = sort_array(m_indices(commandList), (: $1 > $2 :));
        foreach(string commandCategory in commandCategories)
        {
            message += Dictionary->buildBanner(capitalize(commandCategory), "Help");
            string *commandEntries = sort_array(m_indices(
                commandList[commandCategory]), (: $1 > $2 :));
            int count = 0;
            foreach(string commandEntry in commandEntries)
            {
                if (!(count % 5))
                {
                    if (count)
                    {
                        message += " [0;31m|[0m\n";
                    }
                    message += "[0;31m| [0;37m";
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
            message += " [0;31m|[0m\n";
        }
        message += Dictionary->buildBanner("", "");
    }
    return message;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string displayHelpDetails(string commandFile, string command)
{
    string ret = "Help for " + commandFile;
    object commandObj = load_object(commandFile);

    if (commandObj)
    {
        ret = commandObj->displayUsageDetails(command);
    }
    write(ret);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object commandRegistry = load_object("/lib/commands/commandRegistry.c");
        mapping commandList = commandRegistry->getListOfCommands();
        mapping flattenedCommandList = flattenCommandList(commandList);
        string message = "";

        command = regreplace(command, "^(help *)(.*)", "\\2");
        if (!sizeof(command))
        {
            message = topLevelHelpMessage(commandList);
        }
        else if(member(flattenedCommandList, command))
        {
            message = displayHelpDetails(flattenedCommandList[command], command);
            write("Boogers!\n");
        }
        tell_object(initiator, message);
        ret = 1;
    }
    return ret;
}
