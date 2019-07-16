//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Location;
private string WorkerType;
private int QuantityNeeded;
private int Duration;
private int CurrentCost = 0;
private mapping Selections = ([]);

private object dictionary = load_object("/lib/dictionaries/domainDictionary.c");

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
public nomask void setQuantityNeeded(int quantity)
{
    QuantityNeeded = quantity;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setDuration(int duration)
{
    Duration = duration;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setWorkerType(string type)
{
    WorkerType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        AllowUndo = 0;
        AllowAbort = 1;
        SuppressColon = 1;
        NumColumns = 2;
        Description = "Assign Workers";
        Type = "Building Projects";
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    if (dictionary && WorkerType)
    {
        Description = "Assign Workers:\n" +
            configuration->decorate(format(sprintf("From this menu, you can "
                "select the %s who will be executing your project "
                "in your holdings at %s.", 
                dictionary->pluralizeValue(WorkerType, 1),
                dictionary->getLocationDisplayName(Location)), 78),
                "description", "selector", colorConfiguration) +
            dictionary->getWorkersOfType(User, WorkerType, Location,
                QuantityNeeded, Selections);

        Data = dictionary->getWorkersByTypeMenu(User, Location, WorkerType,
            (QuantityNeeded - sizeof(Selections)) != 0, Duration, CurrentCost);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    int needed = QuantityNeeded - sizeof(Selections);
    return sprintf("You have %d worker%s left to assign.\n", needed,
        needed == 1 ? "" : "s");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = sprintf("%7s", "");
    if ((member(({ "hire apprentice", "hire journeyman" }),
        Data[choice]["type"]) > -1) && Data[choice]["is disabled"])
    {
        ret = sprintf("%-7s", (User->colorConfiguration() == "none") ?
            "low $" : "");
    }
    else if ((Data[choice]["type"] == "confirm") && Data[choice]["is disabled"])
    {
        ret = sprintf("%-7s", (User->colorConfiguration() == "none") ?
            "N/A" : "");
    }
    else if (Data[choice]["is disabled"])
    {
        ret = configuration->decorate(sprintf("%-7s", "busy"),
            "busy", "player domains", colorConfiguration);
    }
    else if (member(m_indices(Selections), Data[choice]["type"]) > -1)
    {
        ret = configuration->decorate(sprintf("%-7s",
            (User->charsetConfiguration() == "unicode") ? "   (\xe2\x80\xa0)" :
            "   (*)"),
            "selected", "selector", colorConfiguration);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string choiceColor = ((member(Data[choice], "is disabled") &&
        Data[choice]["is disabled"]) || ((QuantityNeeded == sizeof(Selections)) &&
            member(Data[choice], "data") &&
            !member(Selections, Data[choice]["type"]))) ? 
            "choice disabled" : "choice enabled";

    return sprintf("[%s]%s - %s%s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-25s", choiceColor, "selector", colorConfiguration),
        displayDetails(choice),
        Data[choice]["layout panel"] || "");
}

/////////////////////////////////////////////////////////////////////////////
private nomask void setupHireling(string type, string selection)
{
    mapping workerData = dictionary->getRandomHenchman(
        WorkerType, type, Data[selection]["cost"],
        Data[selection]["duration"]);
    CurrentCost += Data[selection]["cost"];

    object worker = User->addHenchman(Location, workerData);

    Selections[worker->Name() + " " + worker->Title()] = ([
        "object": worker,
        "benefits" : dictionary->getBenefits(User, worker,
            WorkerType),
        "level" : dictionary->getBenefitLevel(worker, WorkerType)
    ]);
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
            else if (!Data[selection]["is disabled"])
            {
                if ((Data[selection]["type"] == "hire apprentice") &&
                    (QuantityNeeded > sizeof(Selections)))
                {
                    setupHireling("apprentice", selection);
                }
                else if ((Data[selection]["type"] == "hire journeyman") &&
                    (QuantityNeeded > sizeof(Selections)))
                {
                    setupHireling("journeyman", selection);
                }
                else if (!member(Selections, Data[selection]["type"]) &&
                    (QuantityNeeded > sizeof(Selections)))
                {
                    object worker = Data[selection]["data"];
                    Selections[Data[selection]["type"]] = ([
                        "object": worker,
                        "benefits": dictionary->getBenefits(User, worker, 
                            WorkerType),
                        "level": dictionary->getBenefitLevel(worker, WorkerType)
                    ]);
                }
                else
                {
                    if (Data[selection]["cost"])
                    {
                        CurrentCost -= Data[selection]["cost"];
                        User->removeHenchman(Location, Data[selection]["name"]);
                    }
                    m_delete(Selections, Data[selection]["type"]);
                }
                setUpUserForSelection();
            }
        }
    }
    return ret;
}
