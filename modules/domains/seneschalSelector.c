//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        AllowUndo = 0;
        AllowAbort = 1;
        Description = "Main Menu";
        Type = "Domain Management";
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object dictionary = load_object("/lib/dictionaries/domainDictionary.c");
    if (dictionary)
    {
        Data = dictionary->getTopLevelDomainMenu(User);
    }
    Data[to_string(sizeof(Data) + 1)] = ([
        "name":"Exit Domain Management Menu",
            "type" : "exit",
            "description" : "This option lets you exit the domain menu.\n",
            "canShow" : 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit") || (selection == "abort");
        if (!ret && Data[selection]["canShow"])
        {
            SubselectorObj =
                clone_object(Data[selection]["selector file"]);
            SubselectorObj->setType(Data[selection]["selector"]);
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
    return sprintf("[%s]%s - %s%s", Red,
        padSelectionDisplay(choice),
        Data[choice]["canShow"] ? "[0;32m%s[0m" : "[0;31m%-40s [0;35m(Missing Prerequisites)[0m",
        displayDetails(choice));
}
