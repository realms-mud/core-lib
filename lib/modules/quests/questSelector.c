//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        Description = "From this menu, you can view your character's available quests";
        Type = "Quest";

        Dictionary = load_object("/lib/dictionaries/questsDictionary.c");
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    string *sources = Dictionary->questTypes();
    int menuItem = 1;

    if (sizeof(sources))
    {
        sources = sort_array(sources, (: $1 > $2 :));
        foreach(string source in sources)
        {
            Data[to_string(menuItem)] = ([
                "name":capitalize(source),
                "type": source,
                "can display": sizeof(Dictionary->questsOfType(User, source)),
                "description": "This option will allow you to view the details of\n" +
                    source + ".\n"
            ]);
            menuItem++;
        }
    }
    Data[to_string(menuItem)] = ([
        "name":"Completed",
        "type": "completed",
        "can display": sizeof(Dictionary->questsOfType(User, "completed")),
        "description": "This option lets you view completed quests.\n"
    ]);
    Data[to_string(menuItem + 1)] = ([
        "name":"Exit Quest Menu",
        "type": "exit",
        "description": "This option lets you exit the quest menu.\n"
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = "";

    if (member(Data[choice], "can display") &&
        !Data[choice]["can display"])
    {
        ret = configuration->decorate("(No quests)", 
            "failure", "selector", colorConfiguration);
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
            if (Data[selection]["can display"])
            {
                SubselectorObj = clone_object("/lib/modules/quests/questSubselector.c");
                move_object(SubselectorObj, User);
                SubselectorObj->setSource(lower_case(Data[selection]["type"]));
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
            }
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
