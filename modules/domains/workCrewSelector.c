//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Location;

private mapping WorkerData = 0;
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
public nomask void setWorkerData(mapping data)
{
    WorkerData = data + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setConstructionData(mapping data)
{
    ConstructionData = data + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping ConstructionData()
{
    return ConstructionData;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        AllowUndo = 0;
        AllowAbort = 1;
        SuppressColon = 1;
        Description = "Assign Workers";
        Type = "Building Projects";
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object dictionary = load_object("/lib/dictionaries/domainDictionary.c");

    if (dictionary && WorkerData)
    {
        Description = "Assign Workers:\n" +
            configuration->decorate(format(sprintf("From this menu, you can "
                "select the workers who will be executing your %s project "
                "in your holdings at %s.", WorkerData["display name"],
                dictionary->getLocationDisplayName(Location)), 78),
                "description", "selector", colorConfiguration) + "\n" +
            dictionary->getComponentWorkerInfo(User, ConstructionData);

        Data = dictionary->getWorkersMenu(User, Location,
            WorkerData);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        if (!member(ConstructionData, "assigned workers"))
        {
            ConstructionData["assigned workers"] = ([]);
        }
        ConstructionData["assigned workers"][caller->WorkerType()] =
            caller->Selections();

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
            if (!Data[selection]["is disabled"] && 
                Data[selection]["type"] == "confirm")
            {
                ret = 1;
            }
            else if (Data[selection]["type"] == "auto-select")
            {
                dictionary->autoSelectWorkers(Location, User, WorkerData,
                    ConstructionData);
            }
            else
            {
                SubselectorObj =
                    clone_object("/lib/modules/domains/workerSelector.c");
                SubselectorObj->setWorkerType(Data[selection]["type"]);
                SubselectorObj->setQuantityNeeded(Data[selection]["quantity"]);
                SubselectorObj->setDuration(Data[selection]["duration"]);
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
