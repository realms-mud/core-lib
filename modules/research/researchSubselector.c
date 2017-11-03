//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/creation/baseSelector.c";

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
protected mapping researchMenuSetup(string type)
{
    mapping menu = ([]);
    object researchObj = Dictionary->researchObject(type);
    if (researchObj)
    {
        SuppressColon = 1;
        Description = "Details:[0m\n" + 
            Dictionary->getResearchDetails(type) +
            Dictionary->displayTreePrerequisites(type, User);

        if (User->isResearching(type))
        {
            NumColumns = 1;
            Description += 
                sprintf("[0;31;1mYou still have another %s before "
                    "research is completed.[0m\n", researchObj->timeString(
                        researchObj->query("research cost") -
                        User->isResearching(type)));
        }

        if (!User->isResearched(type) && !User->isResearching(type) &&
            User->canResearch(type) && 
            ((researchObj->query("research type") == "timed") ||
            ((researchObj->query("research type") == "points") &&
            (User->researchPoints() >= researchObj->query("research cost")))))
        {
            menu = ([ 
                "1": ([
                    "name":"Research this item",
                    "type" : "learn",
                    "description" : "Research the listed item.\n"
                ]) 
            ]);
        }
    }

    researchObj = Dictionary->researchTree(type);
    if (!sizeof(menu) && researchObj)
    {
        SuppressColon = 1;
        NumColumns = 2;
        Description = "Details:[0m\n" +
            Dictionary->getResearchTreeDetails(type, User);
        menu = Dictionary->getResearchTreeChoices(type, User);
    }
    else if (!sizeof(menu))
    {
        NumColumns = 2;
        menu = Dictionary->getResearchOfType(type, User);
    }
    return menu + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        Description = "Select a research item to view in more detail";
        AllowUndo = 0;
        Type = "Research";
        Dictionary = load_object("/lib/dictionaries/researchDictionary.c");

        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    if (!Source)
    {
        raise_error("ERROR: researchSubselector.c - The source has not been "
            "set.\n");
    }

    Data = researchMenuSetup(Source);
    TotalPoints = User->researchPoints();

    Data[to_string(sizeof(Data) + 1)] = ([
        "name":"Return to previous menu",
        "type": "exit",
        "description" : "Return to the main research menu.\n"
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit");
        if (Data[selection]["type"] == "learn")
        {
            ret = 1;
            User->initiateResearch(Source);
        }
        if (!ret)
        {
            SubselectorObj = clone_object("/lib/modules/research/researchSubselector.c");
            move_object(SubselectorObj, User);
            SubselectorObj->setSource(Data[selection]["type"]);
            SubselectorObj->registerEvent(this_object());
            SubselectorObj->setPointsRemaining(TotalPoints);
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

    if (User->isResearched(Data[choice]["type"]) || (member(
        User->availableResearchTrees(), Data[choice]["type"]) > -1))
    {
        ret = "[0;34;1m (*)[0m";
    }
    else if (User->isResearching(Data[choice]["type"]))
    {
        ret = "[0;35m (!)[0m";
    }
    else if (!User->canResearch(Data[choice]["type"]) &&
        (member(({ "Return to previous menu", "Research this item" }),
            Data[choice]["name"]) < 0))
    {
        ret = "[0;31m (X)[0m";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    string ret = "";
    if (TotalPoints > 0)
    {
        ret += sprintf("You have %d research points left to assign.\n", TotalPoints);
    }
    return ret + "[0;34;1m(*)[0m[0;32;1m denotes already-chosen research while "
        "[0;35m(!)[0m[0;32;1m denotes research in progress.\nResearch denoted "
        "[0;31m(X)[0m[0;32;1m cannot yet be learned - view description for details.[0m\n";
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (caller->selection())
    {
        if (stringp(caller->selection()))
        {
            TotalPoints = User->researchPoints();
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
