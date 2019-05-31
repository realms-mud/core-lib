//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Dictionary;
private object SubselectorObj;
private string CraftingItem;
private string CraftingType;
private string CraftingSubType;
private object Item;
private int SettingName = 0;
private int SettingDescription = 0;
private string NewDescription = 0;
private string OriginalName = 0;

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
        getEquipmentStatistics(Item, User);

    ret = regreplace(ret, "[^\n]*(.*Mater.*)", "\\1", 1);

    mapping craftingMaterials = Item->query("crafting materials");

    if (!Item->query("primary crafting material"))
    {
        ret = regreplace(ret, "(.*Material: )([^\n])*(.*)",
            sprintf("\\1%s\\3", configuration->decorate("none selected",
                "failure", "selector", colorConfiguration)));
    }

    mapping enchantments = Item->query("crafting enchantments");
    if (mappingp(enchantments))
    {
        ret += configuration->decorate("This item will have the following "
            "enchantments:\n", "details", "selector", colorConfiguration);

        string *enchantmentList = m_indices(enchantments);
        foreach(string enchantment in enchantmentList)
        {
            ret += configuration->decorate(sprintf("\t%s (x%d)\n", 
                capitalize(enchantment), enchantments[enchantment]),
                "information", "selector", colorConfiguration); 
        }
    }
    return regreplace(format(sprintf("%s - From this menu, you will select the components that "
        "will be used to craft your %s. The relative statistics for the item "
        "you are creating are:", Type, CraftingItem), 78), (Type + " - "), "") + ret;
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

    Type = "Craft " + capitalize(CraftingItem);
    Description = getDescription();

    Data = Dictionary->getCraftingDataForItem(CraftingType, CraftingItem, User);

    Data[to_string(sizeof(Data) + 1)] = ([
        "name":sprintf("Enchant %s", capitalize(CraftingItem)),
        "type" : "enchantments",
        "is disabled" : !Dictionary->canEnchantItem(Item, User),
        "description" : "This option lets you enchant the item being crafted.\n"
    ]);

    Data[to_string(sizeof(Data) + 1)] = ([
        "name":sprintf("Give %s a name", CraftingItem),
        "type" : "name",
        "description" : "This option lets you name the item being crafted.\n"
    ]);

    Data[to_string(sizeof(Data) + 1)] = ([
        "name":sprintf("Give %s a special description", CraftingItem),
        "type" : "describe",
        "description" : "This option lets you name the item being crafted.\n"
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
protected int handleSpecialSelection()
{
    return SettingName || SettingDescription;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        if (SettingName)
        {
            SettingName = 0;
            Item->set("name", selection); 
            Item->set("short", selection);
            ret = 0;
        }
        else if (SettingDescription)
        {
            if (selection != "**")
            {
                NewDescription += selection + "\n";
            }
            else
            {
                SettingDescription = 0;
                Item->set("long", NewDescription);
            }
        }
        else
        {
            ret = (Data[selection]["type"] == "exit");
            if (ret == 1)
            {
                User->abortCrafting();
            }

            if (Data[selection]["type"] == "name")
            {
                SettingName = 1;
                OriginalName = Item->query("name");
                tell_object(User, configuration->decorate(
                    "Please enter the item's new name: ", "details",
                    "selector", colorConfiguration));
            }
            else if (Data[selection]["type"] == "describe")
            {
                SettingDescription = 1;
                NewDescription = "";
                tell_object(User, configuration->decorate("Please enter the "
                    "item's new description. Type '**' on a line by "
                    "itself\nwhen you are done.\n", "details",
                    "selector", colorConfiguration)); 
            }
            else if (Data[selection]["type"] == "craft")
            {
                if (!Data[selection]["is disabled"])
                {
                    if (Dictionary->craftItem(Item, User))
                    {
                        Dictionary->setCraftingSkill(CraftingType, CraftingItem,
                            Item, User);
                        User->completeCrafting();
                        tell_object(User, configuration->decorate(sprintf(
                            "You have successfully crafted %s.\n", 
                            CraftingItem), "details",  "selector", 
                            colorConfiguration));
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
        ret = configuration->decorate("   (*)", "selected", "selector", 
            colorConfiguration);
    }
    else if ((Data[choice]["type"] == "name") && OriginalName &&
        (Item->query("name") != OriginalName))
    {
        ret = configuration->decorate(sprintf("   (%s)", Item->query("name")), 
            "selected", "selector", colorConfiguration); 
    }
    else if ((Data[choice]["type"] == "describe") && NewDescription &&
        Item->query("long"))
    {
        ret = configuration->decorate("   (*)", "selected", "selector",
            colorConfiguration);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string displayType = (member(Data[choice], "is disabled") &&
        Data[choice]["is disabled"]) ? "choice disabled" : "choice enabled";

    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "\t" : "",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-20s", displayType, "selector", colorConfiguration),
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
    return configuration->decorate((User->charsetConfiguration() == "unicode") ?
            "   (\xe2\x80\xa0)" : "(*)", "selected", "selector", colorConfiguration) +
        configuration->decorate(" denotes that a specific component type has "
            "been chosen.\n", "details", "selector", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj) || handleSpecialSelection();
}

/////////////////////////////////////////////////////////////////////////////
public void onSelectorAborted(object caller)
{
    User->abortCrafting();
    "baseSelector"::onSelectorAborted(caller);
}
