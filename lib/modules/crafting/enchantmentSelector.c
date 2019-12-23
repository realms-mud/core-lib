//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        else if (!ret && CraftingComponent && Data[selection]["canShow"] &&
            ((CraftingComponent != "attack mutations") ||
            ((CraftingComponent == "attack mutations") &&
                !CraftingItem->query("crafting attack mutation"))) &&
            (CraftingItem->query("total enchantments") < 
                CraftingItem->query("possible enchantments")))
        {
            if (Dictionary->addEnchantment(CraftingItem,
                Data[selection]["type"]))
            {
                CraftingItem->set("total enchantments",
                    CraftingItem->query("total enchantments") + 1);
                if (CraftingComponent == "attack mutations")
                {
                    CraftingItem->set("crafting attack mutation", 1);
                }
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
        ret = "(";
        for (int i = 0; i < itemEnchantments[Data[choice]["type"]]; i++)
        {
            ret += "*";
        }
        ret += ")";
        ret = configuration->decorate(ret, "selected", "selector", colorConfiguration);

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
        ret = sizeof(flags) ? configuration->decorate(sprintf("(%s)",
            implode(flags, ",")), "note", "selector", colorConfiguration) : "     ";

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
    string displayType = (Data[choice]["canShow"] && 
        ((Data[choice]["type"] == "exit") || 
        (CraftingComponent != "attack mutations") ||
            ((CraftingComponent == "attack mutations") &&
            !CraftingItem->query("crafting attack mutation")))) ?
        "choice enabled" : "choice disabled";

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
    string ret = sprintf("You can imbue this item with %d more (out of %d) enchantments.\n",
        CraftingItem->query("possible enchantments") - 
        CraftingItem->query("total enchantments"),
        CraftingItem->query("possible enchantments"));

    string otherInfo = "";
    if ((CraftingComponent == "attack mutations") &&
        CraftingItem->query("crafting attack mutation"))
    {
        otherInfo = "Only one attack mutation can be set.\n";
    }
    else
    {
        otherInfo = configuration->decorate("Each ", "details", "selector",
            colorConfiguration) +
            configuration->decorate("*", "selected", "selector", colorConfiguration) +
            configuration->decorate(" denotes that an enchantment has been "
                "chosen once (max 3 per option).\n", "details", "selector",
                colorConfiguration) +
            configuration->decorate("P", "note", "selector", colorConfiguration) +
            configuration->decorate(" denotes unrealized prerequisites.\n",
                "details", "selector", colorConfiguration) +
            configuration->decorate("M", "note", "selector", colorConfiguration) +
            configuration->decorate(" denotes that proper quantities of the "
                "material requirements are missing.\n",
                "details", "selector", colorConfiguration);
    }
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
        if (CraftingItem->query("total enchantments") == 1)
        {
            CraftingItem->unset("total enchantments");
        }
        else
        {
            CraftingItem->set("total enchantments",
                CraftingItem->query("total enchantments") - 1);
        }

        if (CraftingComponent == "attack mutations")
        {
            CraftingItem->unset("crafting attack mutation");
        }
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
