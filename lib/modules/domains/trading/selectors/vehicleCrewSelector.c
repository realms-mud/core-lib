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
    Description = "Assign Crew";
    Type = "Vehicle Crew Assignment";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object vehicleService = getService("vehicle");
    if (vehicleService && objectp(Vehicle))
    {
        Data = vehicleService->getCrewAssignmentMenu(User, Vehicle, Location, SlotType);
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

        if (!ret && member(Data[selection], "henchman"))
        {
            object vehicleService = getService("vehicle");
            if (vehicleService)
            {
                string henchmanId = Data[selection]["henchman"];
                string slot = Data[selection]["slot"];
                
                if (Data[selection]["type"] == "assign")
                {
                    Vehicle->assignHenchman(slot, henchmanId);
                    tell_object(User, sprintf("You have assigned %s to the %s position.",
                        Data[selection]["name"], slot));
                }
                else if (Data[selection]["type"] == "unassign")
                {
                    Vehicle->unassignHenchman(slot);
                    tell_object(User, sprintf("You have removed %s from the %s position.",
                        Data[selection]["name"], slot));
                }
                ret = 0; // Stay in menu to allow more assignments
            }
        }
        else if (!ret && Data[selection]["type"] == "hire")
        {
            int cost = Data[selection]["cost"];
            if (User->getMoney() >= cost)
            {
                User->addMoney(-cost);
                string henchmanType = Data[selection]["henchman type"];
                object newHenchman = User->addHenchman(Location, ([
                    "type": henchmanType,
                    "activity": "idle"
                ]));
                
                tell_object(User, sprintf("You have hired a %s for %d gold.",
                    henchmanType, cost));
                ret = 0; // Refresh menu
            }
            else
            {
                tell_object(User, sprintf("You need %d gold to hire this crew member.",
                    cost));
                ret = 0;
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