//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Dictionary;
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
    object questObj = Dictionary->questObject(type);
    if (questObj)
    {
        SuppressColon = 1;
        Description = "Details:[0m\n" +
            format(sprintf("[0;33mName[0m:  [0;33;1m%s[0m\n[0;36m%s[0m\n",
                questObj->name(), User->questStory(type)), 78);
    }
    else
    {
        NumColumns = 2;
        menu = Dictionary->questsOfType(User, type);
    }
    return menu + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        Description = "Select a quest to view in more detail";
        AllowUndo = 0;
        Type = "Quest";
        Dictionary = load_object("/lib/dictionaries/questsDictionary.c");

        Data = ([]);
    }
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

    if (User->questIsActive(Data[choice]["type"]))
    {
        ret = "[0;35m (!)[0m";
    }
    else if (User->questIsCompleted(Data[choice]["type"]))
    {
        object questObj = Dictionary->questObject(Data[choice]["type"]);

        if (questObj && questObj->questSucceeded(User))
        {
            ret = "[0;34;1m (*)[0m";
        }
        else if (questObj &&
            questObj->questInCompletionState(User->questState(Data[choice]["type"])) &&
            !questObj->questSucceeded(User))
        {
            ret = "[0;31m (X)[0m";
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
