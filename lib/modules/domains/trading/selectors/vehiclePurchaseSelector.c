//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Location;
private string VehicleType;

/////////////////////////////////////////////////////////////////////////////
public nomask void setLocation(string location)
{
    Location = location;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setVehicleType(string type)
{
    VehicleType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    Description = "Purchase Vehicle";
    Type = "Vehicle Purchase";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object vehicleService = getService("vehicle");
    if (vehicleService)
    {
        Data = vehicleService->getPurchaseMenu(User, Location, VehicleType);
    }
    
    Data[to_string(sizeof(Data) + 1)] = ([
        "name": "Return to Vehicle Menu",
        "type": "exit",
        "description": "This option returns you to the main vehicle menu.\n",
        "canShow": 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit") || (selection == "abort");

        if (!ret && member(Data[selection], "vehicle type"))
        {
            object vehicleService = getService("vehicle");
            if (vehicleService)
            {
                string vehicleType = Data[selection]["vehicle type"];
                int cost = Data[selection]["cost"];
                
                if (User->getMoney() >= cost)
                {
                    User->addMoney(-cost);
                    object vehicle = vehicleService->createVehicle(vehicleType, Location);
                    User->addVehicle(vehicle);
                    
                    tell_object(User, sprintf("You have purchased a %s for %d gold.",
                        Data[selection]["name"], cost));
                    ret = 1;
                }
                else
                {
                    tell_object(User, sprintf("You need %d gold to purchase this vehicle.",
                        cost));
                    ret = 0;
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}