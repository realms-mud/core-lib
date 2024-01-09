//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Dictionary;
private object SubselectorObj;
private string *ProhibitedTypes = ({});
private object Store;

/////////////////////////////////////////////////////////////////////////////
public nomask void setStore(object store)
{
    Store = store;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setProhibitedTypes(string *types)
{
    ProhibitedTypes = types + ({ });
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowAbort = 1;
    AllowUndo = 0;
    Description = "From this menu, you can view and sell your character's "
        "items";
    Type = "Sell Items";

    Dictionary = getDictionary("shop");
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    if (!Store)
    {
        raise_error("ERROR: sellItemSelector.c - The store has not been "
            "set.\n");
    }

    string *itemTypes = Dictionary->getSellItemTypes(User);
    int menuItem = 1;

    itemTypes -= ProhibitedTypes;
    if (sizeof(itemTypes))
    {
        itemTypes = sort_array(itemTypes, (: $1 > $2 :));
        foreach(string itemType in itemTypes)
        {
            Data[to_string(menuItem)] = ([
                "name": capitalize(itemType) + "s",
                "type": itemType,
                "description": "This option will allow you to view your sellable\n"
                    + itemType + "s.\n"
            ]);
            menuItem++;
        }
    }
    Data[to_string(menuItem)] = ([
        "name":"Exit Sell Item Menu",
        "type": "exit",
        "description": "This option lets you exit the sell item menu.\n"

    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected string additionalInstructions()
{
    return (sizeof(Data) > 1) ? "" : "You have nothing you can sell to this vendor!\n";
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
            SubselectorObj = clone_object("/lib/environment/shopInventories/sellItemSubselector.c");
            move_object(SubselectorObj, User);
            SubselectorObj->setSellType(lower_case(Data[selection]["type"]));
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
