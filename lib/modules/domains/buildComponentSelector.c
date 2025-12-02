//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Location;
private mapping ConstructionData = 0;
private object Service = getService("domain");
private object SubselectorObj;

/////////////////////////////////////////////////////////////////////////////
public nomask void setLocation(string location)
{
    mapping info = Service->getPlayerHolding(User, location);
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
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    SuppressColon = 1;
    Description = "Buildings";
    Type = "Building Projects";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object Service = getService("domain");

    if (Service && ConstructionData)
    {
        Description = (member(ConstructionData, "name") ? 
            (Service->generateTitle(ConstructionData["name"]) + ":\n") : 
            "Buildings:\n") +
            configuration->decorate(format(sprintf("From this menu, you can "
                "initiate, modify, or abort projects in your holdings at %s.",
                Service->getLocationDisplayName(Location)), 78),
                "description", "selector", colorConfiguration);

        Data = Service->getBuildComponentMenu(User, Location, 
            ConstructionData);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        mapping data = caller->getSectionData();
        if (mappingp(data))
        {
            if (!member(ConstructionData, "selected sections"))
            {
                ConstructionData["selected sections"] = ([]);
            }
            ConstructionData["selected sections"][data["selected section"]] = ([
                "selection": data["chosen section"],
                "materials": data["selected materials"]
            ]);
        }
        else
        {
            data = caller->ConstructionData();
            if (mappingp(data))
            {
                ConstructionData["assigned workers"] = 
                    data["assigned workers"];
            }
        }
        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = "";

    if ((Data[choice]["type"] == "create") && Data[choice]["is disabled"])
    {
        ret = sprintf("%-3s", (User->colorConfiguration() == "none") ?
            "N/A" : "");
    }
    return ret;
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
            if ((Data[selection]["type"] == "create"))
            {
                ret = !Data[selection]["is disabled"];
                if (ret)
                {
                    User->buildDomainUpgrade(Location,
                        ConstructionData["type"],
                        ConstructionData["value"]);
                }
            }
            else if (Data[selection]["type"] == "workers")
            {
                SubselectorObj =
                    clone_object("/lib/modules/domains/workCrewSelector.c");
                SubselectorObj->setWorkerData(Data[selection]["data"]);
                SubselectorObj->setConstructionData(ConstructionData);
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
                    ConstructionData["name"], Data[selection]["type"],
                    Data[selection]["previous selections"]);
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
