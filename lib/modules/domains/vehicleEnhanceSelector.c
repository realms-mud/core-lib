//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Location;
private object Vehicle;
private string SlotType;

/////////////////////////////////////////////////////////////////////////////
public nomask void setLocation(string location)
{
    Location = location;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setVehicle(object vehicle)
{
    Vehicle = vehicle;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setSlotType(string slotType)
{
    SlotType = slotType;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    Description = "Enhance Vehicle";
    Type = "Vehicle Enhancement";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object vehicleService = getService("vehicle");
    if (vehicleService && objectp(Vehicle))
    {
        Data = vehicleService->getEnhancementMenu(User, Vehicle, SlotType);
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

        if (!ret && member(Data[selection], "component"))
        {
            object vehicleService = getService("vehicle");
            if (vehicleService)
            {
                string component = Data[selection]["component"];
                string slot = Data[selection]["slot"];
                int cost = Data[selection]["cost"];
                
                if (User->getMoney() >= cost)
                {
                    User->addMoney(-cost);
                    Vehicle->setComponent(slot, component);
                    
                    tell_object(User, sprintf("You have installed %s in the %s slot for %d gold.",
                        component, slot, cost));
                    ret = 1;
                }
                else
                {
                    tell_object(User, sprintf("You need %d gold to install this component.",
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