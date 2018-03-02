//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/commands/baseCommand.c";

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
        addCommandTemplate("help");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int execute(string command, object initiator)
{
    int ret = 0;

    if (canExecuteCommand(command))
    {
        object commandRegistry = load_object("/lib/commands/commandRegistry.c");
        mapping commandList = commandRegistry->getListOfCommands();
       // string message = 
        //write(convertDataToString(commandList));
        ret = 1;
    }
    return ret;
}
