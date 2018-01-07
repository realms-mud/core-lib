//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Dictionary;
private string SellType;
private object SubselectorObj;
private object Store;

/////////////////////////////////////////////////////////////////////////////
public nomask void setSellType(string type)
{
    SellType = type;
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
        Description = "Select an item to sell";
        AllowUndo = 0;
        NumColumns = 2;
        Type = "Sell Items";
        Dictionary = load_object("/lib/dictionaries/shopDictionary.c");

        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    if (!SellType)
    {
        raise_error("ERROR: sellItemSubselector.c - The type has not been "
            "set.\n");
    }
    if (!Store)
    {
        raise_error("ERROR: sellItemSubselector.c - The store has not been "
            "set.\n");
    }
    Data = Dictionary->getSellItemDetailsForType(User, SellType, Store);

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

        if (!ret && Data[selection]["do not sell"])
        {
            tell_object(User, "You cannot sell that item here.\n");
        }
        else if (!ret)
        {
            Dictionary->sellItems(User, Store, 
                Data[selection]["object list"]);
            setUpUserForSelection();
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string selection()
{
    return SellType;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = "";

    if (Data[choice]["do not sell"] || 
        (member(Data[choice], "value") && (!Data[choice]["value"])))
    {
        ret = "[0;31m (X)[0m";
    }
    else if (Data[choice]["is equipped"])
    {
        ret = "[0;34;1m (*)[0m";
    }
    else if (member(Data[choice], "identified") &&
        !Data[choice]["identified"])
    {
        ret = "[0;35m (?)[0m";
    }
    else if (member(Data[choice], "known cursed item") &&
        Data[choice]["known cursed item"])
    {
        ret = "[0;30;1m (C)[0m";
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
    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "\t" : "", Red,
        padSelectionDisplay(choice), "[0;32m%-30s[0m",
        displayDetails(choice));
}
