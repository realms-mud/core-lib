//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Dictionary;
private string Source;
private object SubselectorObj;
private int TotalPoints;
private int ShowTreeElements;

/////////////////////////////////////////////////////////////////////////////
public nomask void setSource(string source)
{
    Source = source;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void showTreeElements()
{
    ShowTreeElements = 1;
}

/////////////////////////////////////////////////////////////////////////////
protected mapping researchMenuSetup(string type)
{
    mapping menu = ([]);
    object researchObj = Dictionary->researchObject(type);
    if (researchObj)
    {
        SuppressColon = 1;
        Description = "Details:\n" + 
            Dictionary->getResearchDetails(type) +
            Dictionary->displayTreePrerequisites(type, User);

        if (User->isResearching(type))
        {
            NumColumns = 1;
            Description += configuration->decorate(sprintf("You still have "
                "another %s before research is completed.\n",
                researchObj->timeString(researchObj->query("research cost") -
                    User->isResearching(type))),
                "time left", "research", colorConfiguration);
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
        Description = "Details:\n" +
            Dictionary->getResearchTreeDetails(type, User);
        menu = Dictionary->getResearchTreeChoices(type, User);
    }
    else if (!sizeof(menu))
    {
        NumColumns = 2;
        menu = Dictionary->getResearchOfType(type, User, ShowTreeElements);
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
        AllowAbort = 1;
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

    int useUnicode = User->charsetConfiguration() == "unicode";

    if (User->isResearched(Data[choice]["type"]))
    {
        ret = configuration->decorate(useUnicode ? " (\xe2\x98\x85)" : " (*)", 
            "known", "research", colorConfiguration);
    }
    else if (member(User->availableResearchTrees(), Data[choice]["type"]) > -1)
    {
        ret = configuration->decorate(useUnicode ? " (\xe2\x87\xa8)" : " (T)",
            "available tree", "research", colorConfiguration);
    }
    else if (User->isResearching(Data[choice]["type"]))
    {
        ret = configuration->decorate(useUnicode ? " (\xe2\x8c\x9b)" : " (!)", 
            "in progress", "research", colorConfiguration);
    }
    else if (!User->canResearch(Data[choice]["type"]) &&
        (member(({ "Return to previous menu", "Research this item" }),
            Data[choice]["name"]) < 0))
    {
        ret = configuration->decorate(useUnicode ? " (\xe2\x95\xb3)" : " (X)", 
            "missing prerequisites", "research", colorConfiguration);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    string ret = "";
    if (TotalPoints > 0)
    {
        ret += sprintf("You have %d research point%s left to assign.\n", 
            TotalPoints, TotalPoints == 1 ? "" : "s");
    }

    int useUnicode = User->charsetConfiguration() == "unicode";
    return ret + configuration->decorate(useUnicode ? "(\xe2\x98\x85)" : "(*)",
        "known", "research", colorConfiguration) +
        configuration->decorate(" denotes already-chosen research, ",
            "details", "selector", colorConfiguration) +
        configuration->decorate(useUnicode ? "(\xe2\x87\xa8)" : "(T)",
            "available tree", "research", colorConfiguration) +
        configuration->decorate(" denotes an available research tree,\n",
            "details", "selector", colorConfiguration) +
        configuration->decorate(useUnicode ? "(\xe2\x8c\x9b)" : "(!)",
            "in progress", "research", colorConfiguration) +
        configuration->decorate(" denotes research in progress, and ",
            "details", "selector", colorConfiguration) +
        configuration->decorate(useUnicode ? "(\xe2\x95\xb3)" : "(X)",
            "missing prerequisites", "research", colorConfiguration) +
        configuration->decorate(" indicates that learning this research\n"
            "requires prerequisites that are missing - view description "
            "for details.\n", "details", "selector", colorConfiguration);
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
