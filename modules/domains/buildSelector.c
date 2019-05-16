//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Location;
private string HoldingType = "none";

/////////////////////////////////////////////////////////////////////////////
public nomask void setLocation(string location)
{
    Location = location;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setHoldingType(string type)
{
    HoldingType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        AllowUndo = 0;
        AllowAbort = 1;
        Description = "Main Menu";
        Type = "Building Projects";
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object dictionary = load_object("/lib/dictionaries/domainDictionary.c");
    if (dictionary)
    {
        Data = dictionary->getBuildingMenu(User, Location, HoldingType,
            "northwest tower");
    }
    Data[to_string(sizeof(Data) + 1)] = ([
        "name":"Exit Building Projects Menu",
        "type" : "exit",
        "description" : "This option lets you exit the building "
        "projects menu.\n",
        "canShow" : 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string section = "";
    if(member(Data[choice], "first section"))
    {
        string padding = (sizeof(Data) < 10) ? "" : " ";
        foreach(string line in Data[choice]["first section"])
        {
            section += sprintf("%26s%s%s\n", "", padding, line);
        }
    }
    return section + sprintf("[%s]%s - %s%s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-20s", "choice enabled", "selector", colorConfiguration),
        displayDetails(choice),
        Data[choice]["layout panel"] || "");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit") || (selection == "abort");
        if (!ret && member(Data[selection], "is category") &&
            Data[selection]["is category"])
        {
            HoldingType = Data[selection]["type"];
            Description = capitalize(HoldingType) + ":\n" +
                configuration->decorate(format(Data[selection]["description"], 78), 
                    "description", "selector", colorConfiguration);
            SuppressColon = 1;
            initiateSelector(User);
        }
    }
    return ret;
}
