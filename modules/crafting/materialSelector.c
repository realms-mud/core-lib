//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        raise_error("ERROR: componentSelector.c - The type has not been "
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
    string ret = sizeof(flags) ? sprintf("[0;34;1m([0;35m%s[0;34;1m)[0m", implode(flags, ",")) : "     ";
    if (sizeof(flags) == 1)
    {
        ret += "  ";
    }
    return member(Data[choice], "canShow") ? ret : "";
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "    " : "", Red,
        padSelectionDisplay(choice),
        Data[choice]["canShow"] ? "[0;32m%-20s[0m" : "[0;31m%-20s[0m",
        displayDetails(choice));
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return "[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that proper quantities of the material requirements are missing.\n";
}

/////////////////////////////////////////////////////////////////////////////
public string selection()
{
    return Selection;
}