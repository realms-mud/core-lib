//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string itemPath;
private int maxQuantity;
private int pricePerUnit;
private string action; // "buy" or "sell"

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
public void setPrice(int price)
{
    pricePerUnit = price;
}

/////////////////////////////////////////////////////////////////////////////
public void setAction(string act)
{
    action = act;
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
    object itemObj = load_object(itemPath + ".c");
    if (itemObj)
    {
        Description = sprintf("How many %s would you like to %s?", 
                             itemObj->query("name"), action);
        Type = sprintf("%s %s", capitalize(action), itemObj->query("name"));
        
        Data = ([]);
        int counter = 1;
        
        // Quick quantity options
        int *quantities = ({ 1, 5, 10, 25, 50, 100 });
        foreach(int qty in quantities)
        {
            if (qty <= maxQuantity)
            {
                int totalCost = qty * pricePerUnit;
                Data[to_string(counter++)] = ([
                    "name": sprintf("%d units (%d gold total)", qty, totalCost),
                    "type": "quantity",
                    "quantity": qty,
                    "total_cost": totalCost,
                    "description": sprintf("%s %d units for %d gold total.",
                                         capitalize(action), qty, totalCost),
                    "canShow": 1
                ]);
            }
        }
        
        // Custom quantity option
        Data[to_string(counter++)] = ([
            "name": "Custom Quantity",
            "type": "custom",
            "description": "Enter a specific quantity to " + action + ".",
            "canShow": 1
        ]);
        
        // All available
        if (maxQuantity > 1)
        {
            int totalCost = maxQuantity * pricePerUnit;
            Data[to_string(counter++)] = ([
                "name": sprintf("Maximum (%d units for %d gold)", maxQuantity, totalCost),
                "type": "quantity",
                "quantity": maxQuantity,
                "total_cost": totalCost,
                "description": sprintf("%s all available units (%d) for %d gold total.",
                                     capitalize(action), maxQuantity, totalCost),
                "canShow": 1
            ]);
        }
        
        Data[to_string(counter++)] = ([
            "name": "Cancel",
            "type": "exit",
            "description": "Cancel this transaction.",
            "canShow": 1
        ]);
    }
    else
    {
        tell_object(User, configuration->decorate("Invalid item selected.",
                   "failure", "selector", User->colorConfiguration()));
    }
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
                executeTransaction(Data[selection]["quantity"]);
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

/////////////////////////////////////////////////////////////////////////////
private int handleCustomQuantity()
{
    int ret = -1;
    
    tell_object(User, configuration->decorate(
        sprintf("Enter quantity (1-%d): ", maxQuantity),
        "instructions", "selector", User->colorConfiguration()));
    
    input_to("processCustomQuantity", 0);
    
    return ret; // Don't exit yet
}

/////////////////////////////////////////////////////////////////////////////
private void processCustomQuantity(string input)
{
    int quantity = to_int(input);
    
    if (quantity >= 1 && quantity <= maxQuantity)
    {
        executeTransaction(quantity);
        notifySynchronous("onSelectorCompleted");
    }
    else
    {
        tell_object(User, configuration->decorate(
            sprintf("Invalid quantity. Must be between 1 and %d.", maxQuantity),
            "failure", "selector", User->colorConfiguration()));
        tell_object(User, displayMessage());
    }
}

/////////////////////////////////////////////////////////////////////////////
private void executeTransaction(int quantity)
{
    object trader = User->getService("trader");
    object environment = environment(User);
    object itemObj = load_object(itemPath + ".c");
    
    string colorConfiguration = User->colorConfiguration();
    
    if (action == "buy")
    {
        int totalCost = quantity * pricePerUnit;
        if (trader->getCash() >= totalCost)
        {
            trader->addCash(-totalCost);
            
            // Add to vehicle cargo
            mapping vehicle = trader->getVehicle();
            if (!member(vehicle["cargo"], itemPath))
            {
                vehicle["cargo"][itemPath] = 0;
            }
            vehicle["cargo"][itemPath] += quantity;
            
            tell_object(User, configuration->decorate(
                sprintf("You purchased %d %s for %d gold total.",
                       quantity, itemObj->query("name"), totalCost),
                "success", "quests", colorConfiguration));
            
            trader->addTradingExperience(quantity);
        }
        else
        {
            tell_object(User, configuration->decorate(
                "You don't have enough gold for that purchase.",
                "failure", "selector", colorConfiguration));
        }
    }
    else if (action == "sell")
    {
        mapping vehicle = trader->getVehicle();
        if (member(vehicle["cargo"], itemPath) && 
            vehicle["cargo"][itemPath] >= quantity)
        {
            int totalValue = quantity * pricePerUnit;
            trader->addCash(totalValue);
            
            vehicle["cargo"][itemPath] -= quantity;
            if (vehicle["cargo"][itemPath] <= 0)
            {
                m_delete(vehicle["cargo"], itemPath);
            }
            
            tell_object(User, configuration->decorate(
                sprintf("You sold %d %s for %d gold total.",
                       quantity, itemObj->query("name"), totalValue),
                "success", "quests", colorConfiguration));
            
            trader->addTradingExperience(quantity);
        }
        else
        {
            tell_object(User, configuration->decorate(
                "You don't have enough of that item to sell.",
                "failure", "selector", colorConfiguration));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int handleSpecialSelection()
{
    return 0;
}
