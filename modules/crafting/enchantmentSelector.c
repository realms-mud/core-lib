//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Dictionary;
private object SubselectorObj;
private string CraftingComponent;
private object CraftingItem;
private string Selection;

/////////////////////////////////////////////////////////////////////////////
public nomask void setItem(string item)
{
    CraftingComponent = item;
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
        raise_error("ERROR: componentSelector.c - The type has not been "
            "set.\n");
    }

    if (!CraftingItem->query("possible enchantments"))
    {
        CraftingItem->set("possible enchantments",
            User->researchBonusTo("crafting enchantments"));
    }

    string enchantmentType = "enchantment type";
    if (CraftingComponent)
    {
        enchantmentType = sprintf("enchant %s", CraftingComponent);
        NumColumns = 2;
        AllowUndo = 1;
        Data = Dictionary->getEnchantmentsOfType(CraftingComponent, User,
            CraftingItem);
    }
    else
    {
        AllowUndo = 0;
        NumColumns = 1;
        Data = Dictionary->getEnchantmentTypes();
    }
    Description = "choose the " + enchantmentType + " with which to craft";
    Type = "Select " + capitalize(enchantmentType);

    Data[to_string(sizeof(Data) + 1)] = ([
        "name": sprintf("Exit Select %s Menu", capitalize(enchantmentType)),
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
        if (!ret && !CraftingComponent)
        {
            SubselectorObj = clone_object("/lib/modules/crafting/enchantmentSelector.c");
            SubselectorObj->setItem(Data[selection]["type"]);
            SubselectorObj->setCraftingItem(CraftingItem);

            move_object(SubselectorObj, User);
            SubselectorObj->registerEvent(this_object());
            SubselectorObj->initiateSelector(User);
        }
        else if (!ret && CraftingComponent && 
            (CraftingItem->query("total enchantments") < 
                CraftingItem->query("possible enchantments")))
        {
            if (Dictionary->addEnchantment(CraftingItem,
                Data[selection]["type"]))
            {
                CraftingItem->set("total enchantments",
                    CraftingItem->query("total enchantments") + 1);
            }
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
    string ret = "";
    string *flags = ({});

    mapping itemEnchantments = CraftingItem->query("crafting enchantments");
    string *enchantmentList = ({});

    if (mappingp(itemEnchantments) && sizeof(itemEnchantments))
    {
        enchantmentList = m_indices(itemEnchantments);
    }
    if ((member(enchantmentList, Data[choice]["type"]) > -1) &&
        (itemEnchantments[Data[choice]["type"]] > 0))
    {
        ret = "[0;35;1m(";
        for (int i = 0; i < itemEnchantments[Data[choice]["type"]]; i++)
        {
            ret += "*";
        }
        ret += ")[0m";
        for (int i = 0; i < (3 - itemEnchantments[Data[choice]["type"]]); i++)
        {
            ret += " ";
        }
    }
    else
    {
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
        ret = sizeof(flags) ? sprintf("[0;34;1m([0;35m%s[0;34;1m)[0m", implode(flags, ",")) : "     ";
        if (sizeof(flags) == 1)
        {
            ret += "  ";
        }
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
    string ret = sprintf("You can imbue this item with %d more (out of %d) enchantments.\n",
        CraftingItem->query("possible enchantments") - CraftingItem->query("total enchantments"),
        CraftingItem->query("possible enchantments"));

    string otherInfo = "[0;32mEach [0;35;1m*[0;32m denotes that an enchantment has been chosen once (max 3 per option).\n"
        "[0;35mP[0m[0;32m denotes unrealized prerequisites.\n"
        "[0;35mM[0m[0;32m denotes that material requirements are missing.\n";
    return CraftingComponent ? ret + otherInfo : ret;
}

/////////////////////////////////////////////////////////////////////////////
public string selection()
{
    return Selection;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void undoSelection(string selection)
{
    if (User)
    {
        Dictionary->addEnchantment(CraftingItem, Data[selection]["type"], 1);
        CraftingItem->set("total enchantments",
            CraftingItem->query("total enchantments") - 1);
    }
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