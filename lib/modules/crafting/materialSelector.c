//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Dictionary;
private object SubselectorObj;
private string CraftingComponent;
private object CraftingItem;
private int Quantity;
private string Selection;

/////////////////////////////////////////////////////////////////////////////
public nomask void setItem(string item)
{
    CraftingComponent = item;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string materialClass()
{
    return CraftingComponent;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setQuantity(int quantity)
{
    Quantity = quantity;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setCraftingItem(object item)
{
    CraftingItem = item;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if(!arg)
    {
        AllowUndo = 0;
        AllowAbort = 1;
        NumColumns = 2;
        Dictionary = load_object("/lib/dictionaries/craftingDictionary.c");
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    if (!CraftingItem)
    {
        raise_error("ERROR: materialSelector.c - The type has not been "
            "set.\n");
    }

    Description = "choose a " + CraftingComponent + " with which to craft";
    Type = "Select " + capitalize(CraftingComponent);

    Data = Dictionary->getMaterialsOfType(CraftingComponent, User, Quantity,
        CraftingItem);

    Data[to_string(sizeof(Data) + 1)] = ([
        "name": sprintf("Exit Select %s Menu", capitalize(CraftingComponent)),
        "type": "exit",
        "canShow": 1,
        "description": "This option lets you exit this crafting menu.\n"
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit");
        if (!ret && Data[selection]["canShow"])
        {
            Selection = Data[selection]["type"];
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string *flags = ({});

    if (member(Data[choice], "prerequisites met") &&
        !Data[choice]["prerequisites met"])
    {
        flags += ({ "P" });
    }
    if (member(Data[choice], "has materials") &&
        !Data[choice]["has materials"])
    {
        flags += ({ "M" });
    }
    string ret = sizeof(flags) ? configuration->decorate(sprintf("(%s)", 
        implode(flags, ",")), "note", "selector", colorConfiguration) : "     ";
        
    if (sizeof(flags) == 1)
    {
        ret += "  ";
    }
    return member(Data[choice], "canShow") ? ret : "";
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string displayType = Data[choice]["canShow"] ? "choice enabled" : "choice disabled";

    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "    " : "",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-20s", displayType, "selector", colorConfiguration),
        displayDetails(choice));
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return configuration->decorate("P", "note", "selector", colorConfiguration) +
        configuration->decorate(" denotes unrealized prerequisites.\n",
            "details", "selector", colorConfiguration) +
        configuration->decorate("M", "note", "selector", colorConfiguration) +
        configuration->decorate(" denotes that proper quantities of the "
            "material requirements are missing.\n",
            "details", "selector", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
public string selection()
{
    return Selection;
}
