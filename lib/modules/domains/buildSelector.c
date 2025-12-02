//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Location;
private string HoldingType = 0;
private string Component = 0;
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
public nomask void setHoldingType(string type)
{
    HoldingType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setComponent(string component)
{
    Component = component;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    SuppressColon = 1;
    Description = "Main Menu";
    Type = "Building Projects";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object Service = getService("domain");

    Description = (HoldingType ? (capitalize(HoldingType) + ":\n") :
        "Main Menu:\n") +
        configuration->decorate(format(sprintf("From this menu, you can "
            "initiate, modify, or abort %sprojects in your holdings at %s.",
            (HoldingType ? (HoldingType + " ") : ""), 
            Service->getLocationDisplayName(Location)), 78),
            "description", "selector", colorConfiguration);

    if (Service)
    {
        Data = Service->getBuildingMenu(User, Location, HoldingType,
            Component);
    }

    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Exit Building Projects Menu",
        "type": "exit",
        "description": "This option lets you exit the building "
            "projects menu.\n",
        "canShow": 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        HoldingType = 0;
        Component = 0;
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

        if (!ret)
        {
            ret = 0;
            if (member(Data[selection], "is category") &&
                Data[selection]["is category"])
            {
                SubselectorObj =
                    clone_object("/lib/modules/domains/buildSelector.c");
                SubselectorObj->setHoldingType(Data[selection]["type"]);
                SubselectorObj->setLocation(Location);

                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
            }
            else if (member(Data[selection], "value") &&
                stringp(Data[selection]["value"]))
            {
                SubselectorObj =
                    clone_object("/lib/modules/domains/buildComponentSelector.c");
                SubselectorObj->setLocation(Location);
                SubselectorObj->setConstructionData(([
                    "type": Component,
                    "name": Data[selection]["value"]
                ]));

                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
            }
            else
            {
                SubselectorObj =
                    clone_object("/lib/modules/domains/buildSelector.c");
                SubselectorObj->setHoldingType(HoldingType);
                SubselectorObj->setComponent(Data[selection]["type"]);
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
