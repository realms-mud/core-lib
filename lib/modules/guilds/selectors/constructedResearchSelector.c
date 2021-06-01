//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private string CompositeGrouping;

/////////////////////////////////////////////////////////////////////////////
public nomask void setType(string type)
{
    Type = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setCompositeGrouping(string grouping)
{
    CompositeGrouping = grouping;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    NumColumns = 2;
    Description = "Construct Spell Main Menu";
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Data = ([]);
    mapping currentItems = User->getOptionsForCompositeResearch(
        CompositeGrouping);

    int optionCount = 1;

    if (sizeof(currentItems))
    {
        string *keys = sort_array(m_indices(currentItems), (: $1 > $2 :));
        foreach(string item in keys)
        {
            Data[to_string(optionCount)] = ([
                "name": sprintf("Modify '%s'", convertToTextOfLength(item, 20)),
                "description": 
                    getDictionary("research")->getCompositeDescription(
                        Type, item, currentItems[item]),
                "type": "modify",
                "value": currentItems[item] + ([ "name": item ])
            ]);
            optionCount++;
        }
    }
    Data[to_string(optionCount)] = ([
        "name": sprintf("Create New %s", Type),
        "description": sprintf("This option allows you to create a custom %s",
            Type),
        "type": "create",
        "value": ([])
    ]);
    Data[to_string(optionCount + 1)] = ([
        "name": "Exit Construct Spell Menu",
        "description": sprintf("This option leaves the construct %s menu.", Type),
        "type": "exit",
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
            SubselectorObj =
                clone_object("/lib/modules/guilds/selectors/constructedItemSelector.c");
            SubselectorObj->setType(Data[selection]["type"]);
            SubselectorObj->setData(Data[selection]["value"]);
            move_object(SubselectorObj, User);
            SubselectorObj->registerEvent(this_object());
            SubselectorObj->initiateSelector(User);
        }
    }
    return ret;
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
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    return sprintf("[%s]%s - %s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-30s", "choice enabled", "selector", 
            colorConfiguration),
        " ");
}
