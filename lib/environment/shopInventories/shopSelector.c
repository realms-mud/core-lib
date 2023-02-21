//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

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
    Description = "Welcome";
    Type = "Shop";

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

    Description = Store->welcomeMessage();
    Type = Store->name();

    Data = ([
        "1":([
            "name": "Purchase Items",
            "description": "This options lets you purchase items from the store.\n",
            "type": "buy",
            "selector": "buyItemSelector"
        ]),
        "2":([
            "name": "Sell Items",
            "description": "This options lets you sell items to the store.\n",
            "type": "sell",
            "selector": "sellItemSelector"
        ]),
        "3":([
            "name":"Exit Shop Menu",
            "type": "exit",
            "description": "This option lets you exit the shop menu.\n"
        ])
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
            SubselectorObj = clone_object(sprintf("/lib/environment/shopInventories/%s.c",
                Data[selection]["selector"]));
            move_object(SubselectorObj, User);
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
