//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string itemPath;
private int maxQuantity;
private object vehicle;
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
public void setVehicle(object v)
{
    vehicle = v;
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
    Description = sprintf("Drop %s", itemObj ? itemObj->query("name") : "Item");
    Type = sprintf("Drop %s", itemObj ? itemObj->query("name") : "Item");

    Data = ([]);
    int counter = 1;

    // List all vehicles with this cargo
    object *vehicles = User->getVehicles();
    int found = 0;
    if (pointerp(vehicles) && sizeof(vehicles))
    {
        foreach (object v in vehicles)
        {
            if (objectp(v))
            {
                int qty = v->getCargoQuantity(itemPath);
                if (qty > 0)
                {
                    string vName = v->query("name") ? v->query("name") : v->query("vehicle type");
                    Data[to_string(counter++)] = ([
                        "name": sprintf("%s x%d [%s]", itemObj->query("name"), qty, vName),
                        "type": "vehicle",
                        "vehicle": v,
                        "quantity": qty,
                        "description": sprintf("Drop up to %d units from %s.", qty, vName),
                        "canShow": 1
                    ]);
                    found = 1;
                }
            }
        }
    }

    if (!found)
    {
        Data[to_string(counter++)] = ([
            "name": sprintf("Drop All .0 units."),
            "type": "empty",
            "description": "No cargo to drop.",
            "canShow": 1
        ]);
    }
    else
    {
        Data[to_string(counter++)] = ([
            "name": "Custom Quantity",
            "type": "custom",
            "description": "Enter a specific quantity to drop.",
            "canShow": 1
        ]);
    }

    Data[to_string(counter++)] = ([
        "name": "Cancel",
        "type": "exit",
        "description": "Cancel dropping cargo.",
        "canShow": 1
    ]);
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
            if (objectp(vehicle) && quantity >= 1 && quantity <= maxQuantity)
            {
                vehicle->removeCargo(itemPath, quantity);
                tell_object(User, sprintf("You dropped %d %s from %s.\n",
                    quantity, load_object(itemPath)->query("name"),
                    vehicle->query("name") ? vehicle->query("name") : vehicle->query("vehicle type")));
                notifySynchronous("onSelectorCompleted");
                ret = 1;
            }
            else
            {
                tell_object(User, "Invalid quantity.\n");
                tell_object(User, displayMessage());
            }
        }
        else if (member(Data, selection))
        {
            string type = Data[selection]["type"];
            if (type == "exit")
            {
                tell_object(User, "Drop Cargo has been exited.\n");
                ret = 1;
            }
            else if (type == "vehicle")
            {
                vehicle = Data[selection]["vehicle"];
                maxQuantity = Data[selection]["quantity"];
                tell_object(User, sprintf("How much %s would you like to drop from %s? (1-%d):\n",
                    load_object(itemPath)->query("name"),
                    vehicle->query("name") ? vehicle->query("name") : vehicle->query("vehicle type"),
                    maxQuantity));
                awaitingCustomQuantity = 1;
                ret = -1;
            }
            else if (type == "custom")
            {
                tell_object(User, "Select a vehicle first.\n");
                tell_object(User, displayMessage());
            }
            else if (type == "empty")
            {
                tell_object(User, "No cargo to drop.\n");
                ret = 1;
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
