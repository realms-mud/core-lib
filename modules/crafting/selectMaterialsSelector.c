//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Dictionary;
private object SubselectorObj;
private string CraftingItem;
private string CraftingType;
private string CraftingSubType;
private object Item;

/////////////////////////////////////////////////////////////////////////////
public nomask void setItem(string item)
{
    CraftingItem = item;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setType(string type)
{
    CraftingType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setSubType(string type)
{
    CraftingSubType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if(!arg)
    {
        AllowUndo = 0;
        AllowAbort = 1;
        SuppressColon = 1;
        Dictionary = load_object("/lib/dictionaries/craftingDictionary.c");
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void getItemToCraft()
{
    if (!Item)
    {
        string file = sprintf("/lib/instances/items/%s/%s/%s.c",
            CraftingType, CraftingSubType, regreplace(CraftingItem, " ", "-"));
        Item = clone_object(file);
        Item->set("identified");
        User->itemBeingCrafted(Item);
        Dictionary->applyCraftingBonuses(Item, User);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getDescription()
{
    string ret = load_object("/lib/dictionaries/materialsDictionary.c")->
        getEquipmentStatistics(Item, 0);

    ret = regreplace(ret, "[^\t]*(\t.*Mater.*)", "\n\\1", 1);

    mapping craftingMaterials = Item->query("crafting materials");

    if (!Item->query("primary crafting material"))
    {
        ret = regreplace(ret, "(.*Material: )([^\n])*(.*)", "\\1[0;31mnone selected[0m\\3", 1);
    }
    return sprintf("From this menu, you will select the\ncomponents that "
        "will be used to craft your %s. The relative statistics\nfor the item "
        "you are creating are:", CraftingItem) + ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    if (!CraftingItem || !CraftingType)
    {
        raise_error("ERROR: selectMaterialsSelector.c - The type has not been "
            "set.\n");
    }
    getItemToCraft();

    Description = getDescription();
    Type = "Craft " + capitalize(CraftingItem);

    Data = Dictionary->getCraftingDataForItem(CraftingType, CraftingItem, User);

    Data[to_string(sizeof(Data) + 1)] = ([
        "name":sprintf("Enchant %s", capitalize(CraftingItem)),
            "type" : "enchantments",
            "is disabled" : !Dictionary->canEnchantItem(Item, User),
            "description" : "This option lets you enchant the item being crafted.\n"
    ]);

    Data[to_string(sizeof(Data) + 1)] = ([
        "name": sprintf("Craft Selected %s", capitalize(CraftingItem)),
        "type": "craft",
        "is disabled": !Dictionary->allComponentsHaveBeenChosen(Item),
        "description": "This option lets you craft the chosen item.\n"
    ]);

    Data[to_string(sizeof(Data) + 1)] = ([
        "name": sprintf("Exit Craft %s Menu", capitalize(CraftingItem)),
        "type": "exit",
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
        if (ret == 1)
        {
            User->abortCrafting();
        }

        if (Data[selection]["type"] == "craft")
        {
            if (!Data[selection]["is disabled"])
            {
                if (Dictionary->craftItem(Item, User))
                {
                    Dictionary->setCraftingSkill(CraftingType, CraftingItem,
                        Item, User);
                    User->completeCrafting();
                    tell_object(User, sprintf("[0;32;1mYou have successfully "
                        "crafted %s.[0m\n", CraftingItem));
                    ret = 1;
                }
            }
        }
        else if (Data[selection]["type"] == "enchantments")
        {
            if (!Data[selection]["is disabled"])
            {
                SubselectorObj = clone_object("/lib/modules/crafting/enchantmentSelector.c");
                SubselectorObj->setCraftingItem(Item);

                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
            }
        }
        else if (!ret)
        {
            SubselectorObj = clone_object(sprintf("/lib/modules/crafting/%sSelector.c",
                Data[selection]["selector"]));
            SubselectorObj->setItem(Data[selection]["type"]);
            SubselectorObj->setCraftingItem(Item);
            if (member(Data[selection], "details"))
            {
                SubselectorObj->setDetails(Data[selection]["details"]);
            }
            if (member(Data[selection], "quantity"))
            {
                SubselectorObj->setQuantity(Data[selection]["quantity"]);
            }

            move_object(SubselectorObj, User);
            SubselectorObj->registerEvent(this_object());
            SubselectorObj->initiateSelector(User);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = "";

    mapping itemComponents = Item->query("crafting materials");
    string *componentList = ({});
    if (sizeof(itemComponents))
    {
        componentList = m_indices(itemComponents);
    }
    if (member(componentList, Data[choice]["type"]) > -1)
    {
        ret = "[0;35;1m   (*)[0m";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string displayFormat = "[0;32m%-20s[0m";
    if (member(Data[choice], "is disabled") &&
        Data[choice]["is disabled"])
    {
        displayFormat = "[0;31m%-20s[0m";
    }
    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "\t" : "", Red,
        padSelectionDisplay(choice), displayFormat,
        displayDetails(choice));
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        if (caller->materialClass() && caller->selection())
        {
            Dictionary->setCraftingMaterial(Item, caller->materialClass(),
                caller->selection());
        }
        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return "[0;35;1m(*)[0m[0;32m denotes that a specific component type has been chosen.\n";
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}

/////////////////////////////////////////////////////////////////////////////
public void onSelectorAborted(object caller)
{
    User->abortCrafting();
    "baseSelector"::onSelectorAborted(caller);
}

public object blah()
{
    return Item;
}
