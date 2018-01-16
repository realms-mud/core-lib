//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Dictionary;
private object SubselectorObj;
private string CraftingComponent;
private object CraftingItem;
private mapping Materials;

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
public nomask void setDetails(mapping data)
{
    Materials = data;
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
    if (!CraftingComponent)
    {
        raise_error("ERROR: componentSelector.c - The type has not been "
            "set.\n");
    }

    Description = sprintf("Select materials and the type of %s you will craft",
        CraftingComponent);
    Type = "Craft " + capitalize(CraftingComponent);

    Data = Dictionary->getMaterialsDataForItem(CraftingComponent,
        User, Materials);

    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Confirm Selection",
        "type": "confirm",
        "is disabled": !Dictionary->hasMaterialsSelected(CraftingItem, CraftingComponent, Materials),
        "description": "This option confirms the item to craft and returns to the previous menu.\n"
    ]);
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Cancel Selection",
        "type": "exit",
        "description": "This option cancels and exits this crafting menu.\n"
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = 0;
        if (Data[selection]["selector"] == "material")
        {
            SubselectorObj = clone_object(sprintf("/lib/modules/crafting/%sSelector.c",
                Data[selection]["selector"]));
            SubselectorObj->setItem(Data[selection]["type"]);
            SubselectorObj->setCraftingItem(CraftingItem);
            SubselectorObj->setQuantity(Materials[Data[selection]["type"]]);
            move_object(SubselectorObj, User);
            SubselectorObj->registerEvent(this_object());
            SubselectorObj->initiateSelector(User);
        }
        else if (Data[selection]["type"] == "exit")
        {
            ret = 1;
            mapping materialData = CraftingItem->query("crafting materials");
            if (materialData && member(materialData, CraftingComponent))
            {
                CraftingItem->set("crafting materials",
                    m_delete(materialData, CraftingComponent));
            }
        }
        else if (Data[selection]["type"] == "confirm")
        {
            ret = !Data[selection]["is disabled"];
        }
        else if (!Data[selection]["is disabled"])
        {
            Dictionary->selectComponent(CraftingItem, CraftingComponent,
                Data[selection]["type"]);
            setUpUserForSelection();
            ret = 0;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = sprintf("%9s", "");

    if (Data[choice]["selector"] == "material")
    {
        ret = sprintf("%-22s", sprintf("[0;35;1m%s[0m",
            Dictionary->getCraftingMaterial(CraftingItem, Data[choice]["type"],
               CraftingComponent)));
    }
    else if (Data[choice]["type"] ==
        Dictionary->selectionForComponent(CraftingItem, CraftingComponent))
    {
        ret = sprintf("%-22s", "[0;35;1m   (*)[0m");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (caller->selection())
    {
        Dictionary->setCraftingMaterial(CraftingItem, caller->materialClass(),
            caller->selection(), CraftingComponent);
    }
    if (User)
    {
        setUpUserForSelection();
        tell_object(User, displayMessage());
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
    string displayFormat = "[0;32m%-20s[0m";
    if (member(Data[choice], "is disabled") &&
        Data[choice]["is disabled"])
    {
        displayFormat = "[0;31m%-20s[0m";
    }
    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "    " : "", Red,
        padSelectionDisplay(choice), displayFormat,
        displayDetails(choice));
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return "[0;35;1m<material>[0m[0;32m denotes a selected material.\n"
        "[0;35;1m(*)[0m[0;32m denotes that a specific component type that has been chosen.\n";
}
