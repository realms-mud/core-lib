//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private int TotalPoints;
private object SubselectorObj;
private object Dictionary;

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if(!arg)
    {
        AllowUndo = 0;
        Description = "From this menu, you can view your character's known research\n"
            "as well as initiate new research";
        Type = "Research";

        Dictionary = load_object("/lib/dictionaries/researchDictionary.c");
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    string *sources = Dictionary->getResearchSourcesForUser(User);
    int menuItem = 1;

    if (sizeof(sources))
    {
        sources = sort_array(sources, (: $1 > $2 :));
        foreach(string source in sources)
        {
            Data[to_string(menuItem)] = ([
                "name":capitalize(source),
                "type": source,
                "description": "This option will allow you to view the details of\n"
                    "research gained from " + source + ".\n"
            ]);
            menuItem++;
        }
    }
    Data[to_string(menuItem)] = ([
        "name":"Exit Research Menu",
        "type": "exit",
        "description": "This option lets you exit the research menu.\n"

    ]);
    TotalPoints = User->researchPoints();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    string ret = "";
    if (TotalPoints > 0)
    {
        ret += sprintf("You have %d research points left to assign.\n", TotalPoints);
    }
    return ret;
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
            SubselectorObj = clone_object("/lib/modules/research/researchSubselector.c");
            move_object(SubselectorObj, User);
            SubselectorObj->setSource(lower_case(Data[selection]["type"]));
            SubselectorObj->registerEvent(this_object());
            SubselectorObj->setPointsRemaining(TotalPoints);
            SubselectorObj->initiateSelector(User);
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
