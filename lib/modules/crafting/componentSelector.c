//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Dictionary;
private object SubselectorObj;
private string CraftingComponent;
private object CraftingItem;
private mapping Materials;
private mapping AdditionalMaterials;
private string InitialMaterial;
private string ConfirmChoice;

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
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    NumColumns = 2;
    Dictionary = getDictionary("crafting");
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    if (!CraftingComponent)
    {
        raise_error("ERROR: componentSelector.c - The type has not been "
            "set.\n");
    }

    if (!InitialMaterial)
    {
        InitialMaterial = CraftingItem->query("material");
    }

    Description = sprintf("Select materials and the type of %s you will craft",
        CraftingComponent);
    Type = "Craft " + capitalize(CraftingComponent);

    Data = Dictionary->getMaterialsDataForItem(CraftingComponent,
        User, Materials);

    ConfirmChoice = to_string(sizeof(Data) + 1);
    Data[ConfirmChoice] = ([
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
        if ((Data[selection]["selector"] == "material") && 
            (!Data[selection]["is disabled"] || (AdditionalMaterials &&
            member(AdditionalMaterials, Data[selection]["type"]))))
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
                CraftingItem->set("material", InitialMaterial);
                CraftingItem->unset("primary crafting material");
            }
        }
        else if (Data[selection]["type"] == "confirm")
        {
            ret = !Data[selection]["is disabled"];
        }
        else if (!Data[selection]["is disabled"])
        {
            AdditionalMaterials = Data[selection]["materials"];
            Dictionary->selectComponent(CraftingItem, CraftingComponent,
                Data[selection]["type"]);
            Data[ConfirmChoice]["is disabled"] = 
                !Dictionary->hasMaterialsSelected(CraftingItem, CraftingComponent, Materials);
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
        ret = configuration->decorate(sprintf("%-9s",
            (!Data[choice]["is disabled"] || (AdditionalMaterials &&
                member(AdditionalMaterials, Data[choice]["type"]))) ?
            Dictionary->getCraftingMaterial(CraftingItem, Data[choice]["type"],
                CraftingComponent) : (Data[choice]["is disabled"] ? "N/A" : "none")),
            "selected", "selector", colorConfiguration);
    }
    else if (Data[choice]["type"] ==
        Dictionary->selectionForComponent(CraftingItem, CraftingComponent))
    {
        ret = configuration->decorate(sprintf("%-9s",
            (User->charsetConfiguration() == "unicode") ? "   (\u2020)" :
                "   (*)"),
            "selected", "selector", colorConfiguration); 
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
        Data[ConfirmChoice]["is disabled"] =
            !Dictionary->hasMaterialsSelected(CraftingItem, CraftingComponent, Materials);
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
    string displayType = (member(Data[choice], "is disabled") &&
        Data[choice]["is disabled"] && !(AdditionalMaterials &&
        member(AdditionalMaterials, Data[choice]["type"]))) ? 
        "choice disabled" : "choice enabled";

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
    return configuration->decorate("<material>", "selected", "selector",
        colorConfiguration) +
        configuration->decorate(" denotes a selected material.\n", "details",
            "selector", colorConfiguration) +
        configuration->decorate((User->charsetConfiguration() == "unicode") ?
            "(\u2020)" : "(*)", "selected", "selector", colorConfiguration) +
        configuration->decorate(" denotes that a specific component type has been chosen.\n", 
            "details", "selector", colorConfiguration);
}
