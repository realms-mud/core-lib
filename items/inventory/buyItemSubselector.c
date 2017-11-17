//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/creation/baseSelector.c";

private object Dictionary;
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
public nomask void reset(int arg)
{
    if (!arg)
    {
        Description = "Select an item to buy:\n"
            "[0;31m-=-=-=-=-=-=-= Name =-=-=-=-=-=-=- Cost -=-=-= Item Details =-=-=-=-=-=-=-=-=-[0m";
        AllowUndo = 0;
        NumColumns = 1;
        SuppressColon = 1;
        Type = "Buy Items";
        Dictionary = load_object("/lib/dictionaries/shopDictionary.c");

        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
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
    Data = Dictionary->getBuyItemDetailsForType(Store, BuyType, BuySubType);

    Data[to_string(sizeof(Data) + 1)] = ([
        "name":"Return to previous menu",
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
            Dictionary->buyItems(User, Store, 
                Data[selection]["object list"]);
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
    return sprintf("[%s]%s - %s%s", Red,
        padSelectionDisplay(choice), "[0;32m%s[0m",
        displayDetails(choice));
}