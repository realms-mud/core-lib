//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
private int singleSource = 0;

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
    currentTarget = 0;
    awaitingQuantity = 0;
    awaitingCustomQuantity = 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setSingleSource(int value)
{
    singleSource = value;
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
    Type = "Select Quantity";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object itemObj = load_object(itemPath);
    Data = ([]);
    int counter = 1;

    // If single source, skip target selection and go straight to quantity
    if (singleSource && sizeof(targetOrder) == 1 && !awaitingQuantity)
    {
        currentTarget = targetOrder[0];
        awaitingQuantity = 1;
        selectingTarget = 0;
    }

    if (awaitingQuantity && currentTarget)
    {
        int maxQty = to_int(targets[currentTarget]["maxQuantity"]);
        Description = sprintf("How many %s would you like to %s for %s? (1-%d)",
            itemObj ? itemObj->query("name") : itemPath, action, currentTarget, maxQty);

        int *quantities = ({ 1, 5, 10, 25, 50, 100, maxQty });
        // Remove duplicates and sort ascending
        quantities = sort_array(m_indices(mkmapping(quantities)), (: $1 > $2 :));
        foreach(int qty in quantities)
        {
            if (qty <= maxQty && qty >= 1)
            {
                int totalCost = qty * pricePerUnit;
                Data[to_string(counter++)] = ([
                    "name": (qty == maxQty) ? "All units" :
                        sprintf("%d unit%s (%d gold)", qty, (qty == 1) ? "" : "s", totalCost),
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
    else if (!singleSource && selectingTarget)
    {
        Description = sprintf("Select which vehicle/warehouse to %s units %s.",
            action, (action == "buy" ? "for" : "from"));
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
            "name": "Cancel",
            "type": "exit",
            "description": "Cancel this transaction.",
            "canShow": 1
        ]);
    }
    else
    {
        Description = "No available vehicles or warehouse space for this transaction.";
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
        // Handle custom quantity input first, regardless of menu options
        if (awaitingCustomQuantity)
        {
            awaitingCustomQuantity = 0;
            int qty = to_int(selection);
            int maxQty = 0;
            if (currentTarget && member(targets, currentTarget))
            {
                maxQty = targets[currentTarget]["maxQuantity"];
            }
            if (qty >= 1 && qty <= maxQty)
            {
                allocations[currentTarget] = qty;
                awaitingQuantity = 0;
                string prevTarget = currentTarget;
                currentTarget = 0;
                if (singleSource)
                {
                    mapping allocationMap = ([]);
                    allocationMap[prevTarget] = ([
                        "object": targets[prevTarget]["object"],
                        "quantity": qty
                    ]);
                    executeTransaction(allocationMap);
                    notifySynchronous("onSelectorCompleted");
                    ret = 1;
                }
                else
                {
                    selectingTarget = 1;
                    setUpUserForSelection();
                    tell_object(User, displayMessage());
                    ret = -1;
                }
            }
            else
            {
                tell_object(User, configuration->decorate(
                    sprintf("Invalid quantity. Must be between 1 and %d.", maxQty),
                    "failure", "selector", User->colorConfiguration()));
                tell_object(User, displayMessage());
            }
            return ret;
        }

        if (awaitingQuantity && currentTarget)
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
                    string prevTarget = currentTarget;
                    currentTarget = 0;

                    // Immediately execute transaction for single source
                    if (singleSource)
                    {
                        mapping allocationMap = ([]);
                        allocationMap[prevTarget] = ([
                            "object": targets[prevTarget]["object"],
                            "quantity": qty
                        ]);
                        executeTransaction(allocationMap);
                        notifySynchronous("onSelectorCompleted");
                        ret = 1;
                    }
                    else
                    {
                        selectingTarget = 1;
                        setUpUserForSelection();
                        tell_object(User, displayMessage());
                        ret = -1;
                    }
                }
                else if (Data[selection]["type"] == "custom")
                {
                    tell_object(User, configuration->decorate(
                        sprintf("Enter quantity for %s (1-%d): ", currentTarget, maxQty),
                        "instructions", "selector", User->colorConfiguration()));
                    awaitingCustomQuantity = 1;
                    ret = -1;
                }
            }
        }
        else if (!singleSource && selectingTarget)
        {
            if (member(Data, selection))
            {
                if (Data[selection]["type"] == "exit")
                {
                    ret = 1;
                }
                else if (Data[selection]["type"] == "target")
                {
                    currentTarget = Data[selection]["name"];
                    awaitingQuantity = 1;
                    selectingTarget = 0;
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
