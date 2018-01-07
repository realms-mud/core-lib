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
        "name": sprintf("Exit %s Menu", capitalize(CraftingComponent)),
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
        else
        {
            CraftingItem->set("description", Data[selection]["description"]);
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = "";

    if (Data[choice]["selector"] == "material")
    {
        ret = sprintf("[0;35;1m(%s)[0m\n",
            Data[choice]["type"]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (caller->selection())
    {
        if (User)
        {
            Dictionary->setCraftingMaterial(CraftingItem, caller->materialClass(),
                caller->selection(), CraftingComponent);
            tell_object(User, displayMessage());
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
        (NumColumns < 3) ? "    " : "", Red,
        padSelectionDisplay(choice), "[0;32m%-20s[0m",
        displayDetails(choice),
        (member(Data[choice], "selector") && (to_int(choice) % 2) ? "\n" : ""));
}