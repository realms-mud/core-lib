//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Location;
private string WorkerType;
private int QuantityNeeded;
private mapping Selections = ([]);

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
public nomask void setQuantityNeeded(int quantity)
{
    QuantityNeeded = quantity;
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
    object dictionary = load_object("/lib/dictionaries/domainDictionary.c");

    if (dictionary && WorkerType)
    {
        Description = "Assign Workers:\n" +
            configuration->decorate(format(sprintf("From this menu, you can "
                "select the %s who will be executing your project "
                "in your holdings at %s.", 
                dictionary->pluralizeValue(WorkerType, 1),
                dictionary->getLocationDisplayName(Location)), 78),
                "description", "selector", colorConfiguration) +
            dictionary->getWorkersOfType(User, WorkerType, Location);

        Data = dictionary->getWorkersByTypeMenu(User, Location, WorkerType,
            (QuantityNeeded - sizeof(Selections)) != 0);
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
    if ((Data[choice]["type"] == "confirm") &&
        (User->colorConfiguration() == "none"))
    {
        ret = sprintf("%-7s", "  N/A");
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
    string choiceColor = member(Data[choice], "is disabled") &&
        Data[choice]["is disabled"] ? "choice disabled" : "choice enabled";

    return sprintf("[%s]%s - %s%s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-25s", choiceColor, "selector", colorConfiguration),
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

        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}
