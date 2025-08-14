//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private object Port;

/////////////////////////////////////////////////////////////////////////////
public nomask void setPort(object port)
{
    Port = port;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    Description = "Sell Goods";
    Type = "Sell Cargo";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Data = ([]);

    object environment = Port || environment(User);
    object *vehicles = User->getVehicles();

    int counter = 1;
    int foundCargo = 0;

    if (pointerp(vehicles) && sizeof(vehicles))
    {
        foreach (object vehicle in vehicles)
        {
            if (objectp(vehicle))
            {
                string vehicleName = vehicle->query("name") ? 
                    vehicle->query("name") : vehicle->query("vehicle type");

                mapping cargo = vehicle->getCargo();
                if (sizeof(cargo))
                {
                    string *items = m_indices(cargo);
                    foreach (string item in items)
                    {
                        object itemObj = load_object(item);
                        if (objectp(itemObj))
                        {
                            int price = environment && function_exists("getItemPrice", environment)
                                ? to_int(environment->getItemPrice(item))
                                : itemObj->query("value");
                            int quantity = cargo[item];
                            int totalValue = price * quantity;

                            Data[to_string(counter++)] = ([
                                "name": sprintf("%s x%d (%d gold each) [%s]",
                                    itemObj->query("name"), quantity, price, vehicleName),
                                "type": "item",
                                "item path": item,
                                "vehicle": vehicle,
                                "price": price,
                                "quantity": quantity,
                                "total value": totalValue,
                                "description": sprintf("Sell %s from %s. You have %d units worth %d gold each.",
                                    itemObj->query("name"), vehicleName, quantity, price),
                                "canShow": 1
                            ]);
                            foundCargo = 1;
                        }
                    }
                }
            }
        }
    }

    if (!foundCargo)
    {
        Data[to_string(counter++)] = ([
            "name": "No Cargo to Sell",
            "type": "empty",
            "description": "Your vehicles have no cargo to sell.",
            "canShow": 1
        ]);
    }

    Data[to_string(counter++)] = ([
        "name": "Return to Trading Menu",
        "type": "exit",
        "description": "Return to the main trading menu.",
        "canShow": 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;

    if (User && Data[selection]["canShow"])
    {
        string type = Data[selection]["type"];
        if (type == "exit")
        {
            ret = 1;
        }
        else if (type == "item")
        {
            object vehicle = Data[selection]["vehicle"];
            SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/quantitySelector.c");
            SubselectorObj->setItem(Data[selection]["item path"]);
            SubselectorObj->setMaxQuantity(Data[selection]["quantity"]);
            SubselectorObj->setPrice(Data[selection]["price"]);
            SubselectorObj->setAction("sell");
            if (objectp(vehicle) && function_exists("setVehicle", SubselectorObj))
            {
                SubselectorObj->setVehicle(vehicle);
            }
            move_object(SubselectorObj, User);
            SubselectorObj->registerEvent(this_object());
            SubselectorObj->initiateSelector(User);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
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
    string displayType = Data[choice]["canShow"] ? "choice enabled" : "choice disabled";
    string colorConfig = User->colorConfiguration();

    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "    " : "",
        configuration->decorate("%s", "number", "selector", colorConfig),
        padSelectionDisplay(choice),
        configuration->decorate("%-35s", displayType, "selector", colorConfig),
        displayDetails(choice));
}
