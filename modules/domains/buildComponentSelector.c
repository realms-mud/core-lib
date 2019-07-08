//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Location;
private mapping ConstructionData = 0;
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
public nomask void setConstructionData(mapping data)
{
    ConstructionData = data;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        AllowUndo = 0;
        AllowAbort = 1;
        SuppressColon = 1;
        Description = "Buildings";
        Type = "Building Projects";
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object dictionary = load_object("/lib/dictionaries/domainDictionary.c");

    if (dictionary && ConstructionData)
    {
        Description = (member(ConstructionData, "name") ? 
            (dictionary->generateTitle(ConstructionData["name"]) + ":\n") : 
            "Buildings:\n") +
            configuration->decorate(format(sprintf("From this menu, you can "
                "initiate, modify, or abort projects in your holdings at %s.",
                dictionary->getLocationDisplayName(Location)), 78),
                "description", "selector", colorConfiguration);

        Data = dictionary->getBuildComponentMenu(User, Location, 
            ConstructionData);
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
    string section = "";
    if(member(Data[choice], "first section"))
    {
        string padding = (sizeof(Data) < 10) ? "" : " ";
        foreach(string line in Data[choice]["first section"])
        {
            section += sprintf("%s%s\n", padding, line);
        }
    }

    string choiceColor = member(Data[choice], "is disabled") &&
        Data[choice]["is disabled"] ? "choice disabled" : "choice enabled";

    return section + sprintf("[%s]%s - %s%s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-20s", choiceColor, "selector", colorConfiguration),
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

        if (!ret)
        {
            if (Data[selection]["type"] == "create")
            {
                User->buildDomainUpgrade(Location,
                    ConstructionData["type"],
                    ConstructionData["value"]);
                ret = 1;
            }
            else if (Data[selection]["type"] == "workers")
            {
                SubselectorObj =
                    clone_object("/lib/modules/domains/workCrewSelector.c");
                SubselectorObj->setWorkerData(Data[selection]["data"],
                    ConstructionData["name"]);
                SubselectorObj->setLocation(Location);

                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
            }
            else
            {
                SubselectorObj =
                    clone_object("/lib/modules/domains/sectionSelector.c");
                SubselectorObj->setDetails(Data[selection]["details"],
                    ConstructionData["name"], Data[selection]["type"]);
                SubselectorObj->setLocation(Location);

                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
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
