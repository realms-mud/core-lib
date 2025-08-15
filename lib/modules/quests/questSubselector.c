//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Service;
private string Source;
private object SubselectorObj;
private int TotalPoints;

/////////////////////////////////////////////////////////////////////////////
public nomask void setSource(string source)
{
    Source = source;
}

/////////////////////////////////////////////////////////////////////////////
protected mapping questMenuSetup(string type)
{
    mapping menu = ([]);
    object questObj = Service->questObject(type);
    if (questObj)
    {
        SuppressColon = 1;
        Description = "Details:\n" +
            configuration->decorate("Name:  ",
                "heading", "quests", colorConfiguration) +
            configuration->decorate(capitalize(questObj->name()),
                "data", "quests", colorConfiguration) + "\n" +
            configuration->decorate(format(User->questStory(type), 78),
                "description", "quests", colorConfiguration) + "\n";
    }
    else
    {
        NumColumns = 2;
        menu = Service->questsOfType(User, type);
    }
    return menu + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    Description = "Select a quest to view in more detail";
    AllowUndo = 0;
    AllowAbort = 1;
    Type = "Quest";
    Service = getService("quests");

    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    if (!Source)
    {
        raise_error("ERROR: questSubselector.c - The source has not been "
            "set.\n");
    }

    Data = questMenuSetup(Source);

    Data[to_string(sizeof(Data) + 1)] = ([
        "name":"Return to previous menu",
        "type": "exit",
        "description" : "Return to the main quest menu.\n"
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit");

        if (!ret)
        {
            SubselectorObj = clone_object("/lib/modules/quests/questSubselector.c");
            move_object(SubselectorObj, User);
            SubselectorObj->setSource(Data[selection]["type"]);
            SubselectorObj->registerEvent(this_object());
            SubselectorObj->initiateSelector(User);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string selection()
{
    return Source;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = "";

    int useUnicode = User->charsetConfiguration() == "unicode";

    if (User->questIsActive(Data[choice]["type"]))
    {
        ret = configuration->decorate(
            useUnicode ? " (\u231b)" : " (!)",
            "active quest", "quests", colorConfiguration); 
    }
    else if (User->questIsCompleted(Data[choice]["type"]))
    {
        object questObj = Service->questObject(Data[choice]["type"]);

        if (questObj && questObj->questSucceeded(User))
        {
            ret = configuration->decorate(
                useUnicode ? " (\u2605)" : " (*)",
                "selected", "selector", colorConfiguration); 
        }
        else if (questObj &&
            questObj->questInCompletionState(User->questState(Data[choice]["type"])) &&
            !questObj->questSucceeded(User))
        {
            ret = configuration->decorate(
                useUnicode ? " (\u2573)" : " (X)",
                "failure", "selector", colorConfiguration);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (caller->selection())
    {
        if (stringp(caller->selection()))
        {
            if (User)
            {
                tell_object(User, displayMessage());
            }
        }
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}
