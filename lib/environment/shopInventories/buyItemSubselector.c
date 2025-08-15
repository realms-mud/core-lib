//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object ShopService;
private string BuyType;
private string BuySubType;
private object SubselectorObj;
private object Store;

/////////////////////////////////////////////////////////////////////////////
public nomask void setBuyType(string type, string subtype)
{
    BuyType = type;
    BuySubType = subtype;
}

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
    NumColumns = 1;
    SuppressColon = 1;
    Type = "Buy Items";
    ShopService = getService("shop");

    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Description = "Select an item to buy:\n" + configuration->decorate(
        "-=-=-=-=-=-=-= Name =-=-=-=-=-=-=- Cost -=-=-= Item Details =-=-=-=-=-=-=-=-=-",
        "decorator", "selector", colorConfiguration);

    if (!BuyType)
    {
        raise_error("ERROR: buyItemSubselector.c - The type has not been "
            "set.\n");
    }
    if (!Store)
    {
        raise_error("ERROR: buyItemSubselector.c - The store has not been "
            "set.\n");
    }
    Data = ShopService->getBuyItemDetailsForType(User, Store, BuyType, BuySubType);

    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Return to previous menu",
        "type": "exit",
        "description" : "Return to the main sell item menu.\n"
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
            ShopService->buyItem(User, Store, Data[selection]);
            setUpUserForSelection();
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string selection()
{
    return BuyType;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = "";
    if (Data[choice]["summary"])
    {
        ret = Data[choice]["summary"];
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

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    return sprintf("[%s]%s - %s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%s", "choice enabled", "selector", colorConfiguration),
        displayDetails(choice));
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return (User->colorConfiguration() == "none") ? 
        "Items with a (C) to the right of their name are particularly well-crafted.\n"
        "Items with a (M) to the right of their name are masterwork items.\n"
        "Items with a (E) to the right of their name are enchanted.\n"
        "Items with a (P) to the right of their name are enchanted with powerful magic.\n" : "";
}
