//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Dictionary;
private object SubselectorObj;
private object Store;

/////////////////////////////////////////////////////////////////////////////
public nomask void setStore(object store)
{
    Store = store;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowAbort = 1;
    AllowUndo = 0;
    Description = "From this menu, you can view and purchase items";
    Type = "Purchase Items";

    Dictionary = getDictionary("shop");
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    if (!Store)
    {
        raise_error("ERROR: buyItemSelector.c - The store has not been "
            "set.\n");
    }

    string *itemTypes = Dictionary->getBuyItemTypes(Store);
    int menuItem = 1;

    if (sizeof(itemTypes))
    {
        itemTypes = sort_array(itemTypes, (: $1 > $2 :));
        foreach(string itemType in itemTypes)
        {
            Data[to_string(menuItem)] = ([
                "name": capitalize(itemType),
                "type": regreplace(itemType, "(.+)s - .*", "\\1", 1),
                "subType": lower_case(regreplace(itemType, ".+ - (.+)", "\\1", 1)),
                "description": "This option will allow you to view "
                    + lower_case(regreplace(itemType, ".+ - (.+)", "\\1", 1)) +
                    " type " + regreplace(itemType, "(.+)s - .*", "\\1", 1) +
                    "s that are for sale.\n"
            ]);
            menuItem++;
        }
    }
    Data[to_string(menuItem)] = ([
        "name":"Exit Buy Item Menu",
        "type": "exit",
        "description": "This option lets you exit the purchase item menu.\n"
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected string additionalInstructions()
{
    return (sizeof(Data) > 1) ? "" : "This vendor has nothing they are willing to sell to you.\n";
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
            SubselectorObj = clone_object("/lib/environment/shopInventories/buyItemSubselector.c");
            move_object(SubselectorObj, User);
            SubselectorObj->setBuyType(lower_case(Data[selection]["type"]),
                lower_case(Data[selection]["subType"]));
            SubselectorObj->setStore(Store);
            SubselectorObj->registerEvent(this_object());
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
        if (User)
        {
            tell_object(User, displayMessage());
        }
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}
