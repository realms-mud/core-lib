//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string itemPath;
private int pricePerUnit;
private string action; // "buy" or "sell"
private object Port;
private mapping targets = ([]); // name -> ([ "object": obj, "maxQuantity": int ])
private mapping allocations = ([]); // name -> quantity
private string *targetOrder = ({});
private int selectingTarget = 1;
private string currentTarget = 0;
private int awaitingQuantity = 0;
private int awaitingCustomQuantity = 0;
private int awaitingConfirmation = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask void setItem(string item)
{
    itemPath = item;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setPrice(int price)
{
    pricePerUnit = price;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setAction(string act)
{
    action = act;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setPort(object port)
{
    Port = port;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setTargets(mapping t)
{
    targets = t;
    targetOrder = m_indices(targets);
    allocations = ([]);
    selectingTarget = 1;
    Type = "Select Quantity";
    currentTarget = 0;
    awaitingQuantity = 0;
    awaitingCustomQuantity = 0;
    awaitingConfirmation = 0;
}

/////////////////////////////////////////////////////////////////////////////
private void executeTransaction(mapping allocationMap)
{
    object tradingService = getService("trading");
    if (action == "buy")
    {
        tradingService->processBuy(User, Port, itemPath, allocationMap, pricePerUnit);
    }
    else if (action == "sell")
    {
        tradingService->processSell(User, Port, itemPath, allocationMap, pricePerUnit);
    }
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
    Data = ([]);
    int counter = 1;

    if (awaitingConfirmation)
    {
        int totalUnits = 0;
        int totalCost = 0;
        string summary = "You have selected:\n";
        foreach(string name in m_indices(allocations))
        {
            int qty = allocations[name];
            if (qty > 0)
            {
                summary += sprintf("  %s: %d units\n", name, qty);
                totalUnits += qty;
                totalCost += qty * pricePerUnit;
            }
        }
        summary += sprintf("\nTotal: %d units for %d gold.\n", totalUnits, totalCost);
        Description = summary;

        Data[to_string(counter++)] = ([
            "name": "Confirm Transaction",
            "type": "confirm",
            "description": "Confirm and execute this transaction.",
            "canShow": 1
        ]);
        Data[to_string(counter++)] = ([
            "name": "Cancel",
            "type": "exit",
            "description": "Cancel this transaction.",
            "canShow": 1
        ]);
    }
    else if (awaitingQuantity && currentTarget)
    {
        int maxQty = targets[currentTarget]["maxQuantity"];
        Description = sprintf("How many %s would you like to %s for %s? (0-%d)",
            itemObj ? itemObj->query("name") : itemPath, action, currentTarget, maxQty);

        int *quantities = ({ 0, 1, 5, 10, 25, 50, 100, maxQty });
        foreach(int qty in quantities)
        {
            if (qty <= maxQty && qty >= 0)
            {
                int totalCost = qty * pricePerUnit;
                Data[to_string(counter++)] = ([
                    "name": sprintf("%d unit%s (%d gold)", qty, (qty == 1) ? "" : "s", totalCost),
                    "type": "quantity",
                    "quantity": qty,
                    "description": sprintf("Select %d units for %s.", qty, currentTarget),
                    "canShow": 1
                ]);
            }
        }
        Data[to_string(counter++)] = ([
            "name": "Custom Quantity",
            "type": "custom",
            "description": "Enter a specific quantity.",
            "canShow": 1
        ]);
        Data[to_string(counter++)] = ([
            "name": "Cancel",
            "type": "exit",
            "description": "Cancel this transaction.",
            "canShow": 1
        ]);
    }
    else if (selectingTarget)
    {
        Description = "Select which vehicle/warehouse to allocate units to. You may select multiple, then choose 'Done'.";
        foreach(string name in targetOrder)
        {
            Data[to_string(counter++)] = ([
                "name": name,
                "type": "target",
                "description": sprintf("Allocate units for %O (max %O).", name, targets[name]["maxQuantity"]),
                "canShow": 1
            ]);
        }
        Data[to_string(counter++)] = ([
            "name": "Done",
            "type": "done",
            "description": "Finish selecting targets and review allocations.",
            "canShow": 1
        ]);
        Data[to_string(counter++)] = ([
            "name": "Cancel",
            "type": "exit",
            "description": "Cancel this transaction.",
            "canShow": 1
        ]);
    }
    else
    {
        Description = "No available vehicles or warehouse space for this purchase. The AI was too stupid to make this correctly.";
        Data["1"] = ([
            "name":"Cancel",
            "type" : "exit",
            "description" : "Cancel this transaction.",
            "canShow" : 1
        ]);
    }

    getService("log")->log("quantitySelectorLog", sprintf("QuantitySelector Data: %O", Data));
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;

    if (User)
    {
        if (awaitingConfirmation)
        {
            if (member(Data, selection) && Data[selection]["type"] == "confirm")
            {
                mapping allocationMap = ([]);
                foreach(string name in m_indices(targets))
                {
                    allocationMap[name] = ([
                        "object": targets[name]["object"],
                        "quantity": allocations[name] || 0
                    ]);
                }
                int totalCost = 0;
                foreach(string name in m_indices(allocationMap))
                {
                    totalCost += allocationMap[name]["quantity"] * pricePerUnit;
                }
                if (action == "buy" && User->getCash() < totalCost)
                {
                    tell_object(User, configuration->decorate(
                        "You do not have enough gold for that purchase.",
                        "failure", "selector", User->colorConfiguration()));
                    tell_object(User, displayMessage());
                }
                else
                {
                    executeTransaction(allocationMap);
                    notifySynchronous("onSelectorCompleted");
                    ret = 1;
                }
            }
            else
            {
                ret = 1; // Cancel
            }
        }
        else if (awaitingQuantity && currentTarget)
        {
            int maxQty = targets[currentTarget]["maxQuantity"];
            if (member(Data, selection))
            {
                if (Data[selection]["type"] == "exit")
                {
                    ret = 1;
                }
                else if (Data[selection]["type"] == "quantity")
                {
                    int qty = Data[selection]["quantity"];
                    allocations[currentTarget] = qty;
                    awaitingQuantity = 0;
                    currentTarget = 0;
                    setUpUserForSelection();
                    tell_object(User, displayMessage());
                    ret = -1;
                }
                else if (Data[selection]["type"] == "custom")
                {
                    tell_object(User, configuration->decorate(
                        sprintf("Enter quantity for %s (0-%d): ", currentTarget, maxQty),
                        "instructions", "selector", User->colorConfiguration()));
                    awaitingCustomQuantity = 1;
                    ret = -1;
                }
            }
            else if (awaitingCustomQuantity)
            {
                awaitingCustomQuantity = 0;
                int qty = to_int(selection);
                if (qty >= 0 && qty <= maxQty)
                {
                    allocations[currentTarget] = qty;
                    awaitingQuantity = 0;
                    currentTarget = 0;
                    setUpUserForSelection();
                    tell_object(User, displayMessage());
                    ret = -1;
                }
                else
                {
                    tell_object(User, configuration->decorate(
                        sprintf("Invalid quantity. Must be between 0 and %d.", maxQty),
                        "failure", "selector", User->colorConfiguration()));
                    tell_object(User, displayMessage());
                }
            }
        }
        else if (selectingTarget)
        {
            if (member(Data, selection))
            {
                if (Data[selection]["type"] == "exit")
                {
                    ret = 1;
                }
                else if (Data[selection]["type"] == "done")
                {
                    selectingTarget = 0;
                    awaitingConfirmation = 1;
                    setUpUserForSelection();
                    tell_object(User, displayMessage());
                    ret = -1;
                }
                else if (Data[selection]["type"] == "target")
                {
                    currentTarget = Data[selection]["name"];
                    awaitingQuantity = 1;
                    setUpUserForSelection();
                    tell_object(User, displayMessage());
                    ret = -1;
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
