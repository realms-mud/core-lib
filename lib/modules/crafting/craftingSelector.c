//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    Description = "Main Menu";
    Type = "Crafting";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object dictionary = load_object("/lib/dictionaries/craftingDictionary.c");
    if (dictionary)
    {
        Data = dictionary->getTopLevelCraftingMenu(User);
    }
    Data[to_string(sizeof(Data) + 1)] = ([
        "name":"Exit Crafting Menu",
        "type": "exit",
        "description": "This option lets you exit the crafting menu.\n",
        "canShow": 1
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
                clone_object("/lib/modules/crafting/craftItemSelector.c");
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
    string displayText = configuration->decorate("%s", "choice enabled",
        "selector", colorConfiguration);
    if (!Data[choice]["canShow"])
    {
        displayText = configuration->decorate("%-40s ", "choice disabled",
            "selector", colorConfiguration) +
            configuration->decorate("(Missing Prerequisites)", "note", "selector",
                colorConfiguration);
    }

    return sprintf("[%s]%s - %s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice), displayText, displayDetails(choice));
}
