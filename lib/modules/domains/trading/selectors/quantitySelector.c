//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string itemPath;
private int maxQuantity;
private int pricePerUnit;
private string action; // "buy" or "sell"
private object vehicle;
private object Port;
private int awaitingCustomQuantity = 0;

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
public void setVehicle(object v)
{
    vehicle = v;
}

/////////////////////////////////////////////////////////////////////////////
public void setPort(object port)
{
    Port = port;
}

/////////////////////////////////////////////////////////////////////////////
private void executeTransaction(int quantity)
{
    object itemObj = load_object(itemPath);
    string colorConfig = User->colorConfiguration();

    if (action == "buy")
    {
        int totalCost = quantity * pricePerUnit;
        if (User->getCash() >= totalCost && objectp(vehicle) && vehicle->getFreeSpace() >= quantity)
        {
            User->addCash(-totalCost);
            vehicle->addCargo(itemPath, quantity);

            tell_object(User, configuration->decorate(
                sprintf("You purchased %d %s for %d gold total.",
                    quantity, itemObj->query("name"), totalCost),
                "success", "quests", colorConfig));

            User->addTradingExperience(quantity);
        }
        else
        {
            string failMsg = "You don't have enough gold for that purchase.";
            if (objectp(vehicle) && vehicle->getFreeSpace() < quantity)
            {
                failMsg = "Your vehicle does not have enough space for that purchase.";
            }
            tell_object(User, configuration->decorate(
                failMsg,
                "failure", "selector", colorConfig));
        }
    }
    else if (action == "sell")
    {
        if (objectp(vehicle) && vehicle->getCargoQuantity(itemPath) >= quantity)
        {
            int totalValue = quantity * pricePerUnit;
            User->addCash(totalValue);
            vehicle->removeCargo(itemPath, quantity);

            tell_object(User, configuration->decorate(
                sprintf("You sold %d %s for %d gold total.",
                    quantity, itemObj->query("name"), totalValue),
                "success", "quests", colorConfig));

            User->addTradingExperience(quantity);
        }
        else
        {
            tell_object(User, configuration->decorate(
                "You don't have enough of that item to sell.",
                "failure", "selector", colorConfig));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private int handleCustomQuantity()
{
    tell_object(User, configuration->decorate(
        sprintf("Enter quantity (1-%d): ", maxQuantity),
        "instructions", "selector", User->colorConfiguration()));
    awaitingCustomQuantity = 1;
    return -1;
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

    if (itemObj)
    {
        Description = sprintf("How many %s would you like to %s?",
            itemObj->query("name"), action);
        Type = sprintf("%s %s", capitalize(action), itemObj->query("name"));

        Data = ([]);
        int counter = 1;

        // Quick quantity options
        int *quantities = ({ 1, 5, 10, 25, 50, 100 });
        foreach (int qty in quantities)
        {
            if (qty <= maxQuantity)
            {
                int totalCost = qty * pricePerUnit;
                Data[to_string(counter++)] = ([
                    "name": sprintf("%d unit%s (%d gold total)", qty, 
                        (qty == 1) ? "" : "s", totalCost),
                    "type": "quantity",
                    "quantity": qty,
                    "total cost": totalCost,
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
                "total cost": totalCost,
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
        if (awaitingCustomQuantity)
        {
            awaitingCustomQuantity = 0;
            int quantity = to_int(selection);
            if (quantity >= 1 && quantity <= maxQuantity)
            {
                executeTransaction(quantity);
                notifySynchronous("onSelectorCompleted");
                ret = 1;
            }
            else
            {
                tell_object(User, configuration->decorate(
                    sprintf("Invalid quantity. Must be between 1 and %d.", maxQuantity),
                    "failure", "selector", User->colorConfiguration()));
                tell_object(User, displayMessage());
            }
        }
        else if (member(Data, selection))
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
        else
        {
            tell_object(User, displayMessage());
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return awaitingCustomQuantity;
}

/////////////////////////////////////////////////////////////////////////////
protected int handleSpecialSelection()
{
    return awaitingCustomQuantity;
}
