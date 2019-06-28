//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Location;
private mapping MaterialData = 0;
private object dictionary = load_object("/lib/dictionaries/domainDictionary.c");
private object SubselectorObj;

/////////////////////////////////////////////////////////////////////////////
public nomask void setLocation(string location)
{
    mapping info = dictionary->getPlayerHolding(User, location);
    if (mappingp(info))
    {
        Location = location;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setMaterialData(mapping data)
{
    MaterialData = data;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        AllowUndo = 0;
        AllowAbort = 1;
        SuppressColon = 1;
        Description = "Materials";
        Type = "Building Projects";
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object dictionary = load_object("/lib/dictionaries/domainDictionary.c");

    if (dictionary && MaterialData)
    {
        Description = (member(MaterialData, "name") ? 
            (dictionary->generateTitle(MaterialData["name"]) + ":\n") : 
            "Materials:\n") +
            configuration->decorate(format(sprintf("From this menu, you can "
                "initiate, modify, or abort projects in your holdings at %s.",
                dictionary->getLocationDisplayName(Location)), 78),
                "description", "selector", colorConfiguration);

        Data = dictionary->getBuildComponentMenu(User, Location, 
            MaterialData);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string displayType = Data[choice]["canShow"] ? "choice enabled" : "choice disabled";

    return sprintf("[%s]%s - %s%s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-20s", displayType, "selector", colorConfiguration),
        displayDetails(choice),
        Data[choice]["layout panel"] || "");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return configuration->decorate("P", "note", "selector", colorConfiguration) +
        configuration->decorate(" denotes unrealized prerequisites.\n",
            "details", "selector", colorConfiguration) +
        configuration->decorate("M", "note", "selector", colorConfiguration) +
        configuration->decorate(" denotes that proper quantities of the "
            "material requirements are missing.\n",
            "details", "selector", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string *flags = ({});

    if (member(Data[choice], "prerequisites met") &&
        !Data[choice]["prerequisites met"])
    {
        flags += ({ "P" });
    }
    if (member(Data[choice], "has materials") &&
        !Data[choice]["has materials"])
    {
        flags += ({ "M" });
    }
    string ret = sizeof(flags) ? configuration->decorate(sprintf("(%s)",
        implode(flags, ",")), "note", "selector", colorConfiguration) : "     ";

    if (sizeof(flags) == 1)
    {
        ret += "  ";
    }
    return member(Data[choice], "canShow") ? ret : "";
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit") || (selection == "abort");

        if (!ret)
        {
            ret = 0;
            if (Data[selection]["type"] == "create")
            {
                User->buildDomainUpgrade(Location,
                    MaterialData["type"],
                    MaterialData["value"]);
                ret = 1;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}
