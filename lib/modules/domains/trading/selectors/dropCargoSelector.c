//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string itemPath;
private int maxQuantity;

/////////////////////////////////////////////////////////////////////////////
public void setItem(string item) 
{
    itemPath = item;
}

/////////////////////////////////////////////////////////////////////////////
public void setMaxQuantity(int max) 
{
    maxQuantity = max;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    HasDescription = 0;
    SuppressColon = 1;
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object itemObj = load_object(itemPath);
    object configuration = getDictionary("configuration");
    
    if (!itemObj) 
    {
        tell_object(User, configuration->decorate("Invalid item selected.",
                   "failure", "selector", User->colorConfiguration()));
        return;
    }
    
    Description = sprintf("How many %s would you like to drop?", itemObj->query("name"));
    Type = sprintf("Drop %s", itemObj->query("name"));
    
    Data = ([]);
    int counter = 1;
    
    // Quick quantity options
    int *quantities = ({ 1, 5, 10, 25, 50 });
    foreach(int qty in quantities) 
    {
        if (qty <= maxQuantity) 
        {
            Data[to_string(counter++)] = ([
                "name": sprintf("%d units", qty),
                "type": "quantity",
                "quantity": qty,
                "description": sprintf("Drop %d units of %s. This will permanently destroy them.",
                                     qty, itemObj->query("name")),
                "canShow": 1
            ]);
        }
    }
    
    // Custom quantity option
    Data[to_string(counter++)] = ([
        "name": "Custom Quantity",
        "type": "custom",
        "description": "Enter a specific quantity to drop.",
        "canShow": 1
    ]);
    
    // Drop all of this item
    Data[to_string(counter++)] = ([
        "name": sprintf("Drop All (%d units)", maxQuantity),
        "type": "quantity",
        "quantity": maxQuantity,
        "description": sprintf("Drop all %d units of %s.", maxQuantity, itemObj->query("name")),
        "canShow": 1
    ]);
    
    Data[to_string(counter++)] = ([
        "name": "Cancel",
        "type": "exit",
        "description": "Don't drop any cargo.",
        "canShow": 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
private void dropCargo(int quantity) 
{
    object itemObj = load_object(itemPath);
    object configuration = getDictionary("configuration");
    string colorConfiguration = User->colorConfiguration();
    
    if (User->getCargoQuantity(itemPath) >= quantity)
    {
        // Calculate value lost
        int value = 0;
        object environment = environment(User);
        if (environment && environment->isPort()) 
        {
            value = environment->getItemPrice(itemPath) * quantity;
        }
        
        // Remove cargo using proper accessor
        User->removeCargoFromVehicle(itemPath, quantity);
        
        tell_object(User, configuration->decorate(
            sprintf("You dropped %d %s (estimated value: %d gold).",
                   quantity, itemObj->query("name"), value),
            "failure", "selector", colorConfiguration));
    } 
    else 
    {
        tell_object(User, configuration->decorate(
            "You don't have enough of that item to drop.",
            "failure", "selector", colorConfiguration));
    }
}

/////////////////////////////////////////////////////////////////////////////
private int handleCustomQuantity() 
{
    object configuration = getDictionary("configuration");
    tell_object(User, configuration->decorate(
        sprintf("Enter quantity to drop (1-%d): ", maxQuantity),
        "instructions", "selector", User->colorConfiguration()));
    
    input_to("processCustomQuantity", 0);
    return -1; // Don't exit yet
}

/////////////////////////////////////////////////////////////////////////////
private void processCustomQuantity(string input) 
{
    int quantity = to_int(input);
    object configuration = getDictionary("configuration");
    
    if (quantity < 1 || quantity > maxQuantity) 
    {
        tell_object(User, configuration->decorate(
            sprintf("Invalid quantity. Must be between 1 and %d.", maxQuantity),
            "failure", "selector", User->colorConfiguration()));
        tell_object(User, displayMessage());
        return;
    }
    
    dropCargo(quantity);
    notifySynchronous("onSelectorCompleted");
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
            if (Data[selection]["type"] == "quantity") 
            {
                dropCargo(Data[selection]["quantity"]);
                ret = 1;
            } 
            else if (Data[selection]["type"] == "custom") 
            {
                ret = handleCustomQuantity();
            }
        }
    }
    return ret;
}
