//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object ShopService;
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
public nomask void InitializeSelector()
{
    Description = "Select an item to sell";
    AllowAbort = 1;
    AllowUndo = 0;
    NumColumns = 2;
    Type = "Sell Items";
    ShopService = getService("shop");

    Data = ([]);
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
    Data = ShopService->getSellItemDetailsForType(User, SellType, Store);

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
            ShopService->sellItems(User, Store,
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

    int showUnicode = User->charsetConfiguration() == "unicode";

    if (Data[choice]["do not sell"] || 
        (member(Data[choice], "value") && (!Data[choice]["value"])))
    {
        ret = configuration->decorate(showUnicode ?  " (X)": " (X)", 
            "failure", "selector", colorConfiguration);
    }
    else if (Data[choice]["is equipped"])
    {
        ret = configuration->decorate(showUnicode ? " (\u2020)" : " (*)", 
            "selected", "selector", colorConfiguration);
    }
    else if (member(Data[choice], "identified") &&
        !Data[choice]["identified"])
    {
        ret = configuration->decorate(showUnicode ? " (\u2047)" : " (?)", 
            "note", "selector", colorConfiguration);
    }
    else if (member(Data[choice], "known cursed item") &&
        Data[choice]["known cursed item"])
    {
        ret = configuration->decorate(showUnicode ? " (\u2620)" : " (C)", 
            "warning", "selector", colorConfiguration);
    }
    else
    {
        ret = "    ";
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
        (NumColumns < 3) ? "    " : "",
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
