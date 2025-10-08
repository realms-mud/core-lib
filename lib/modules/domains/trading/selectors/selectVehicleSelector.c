//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Port;
private object *Vehicles = ({});

/////////////////////////////////////////////////////////////////////////////
public void setPort(object port)
{
    Port = port;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    Description = "Select Vehicle";
    Type = "Vehicle";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    Data = ([]);
    Vehicles = User->getVehicles();
    string portRouteType = (Port && function_exists("getRouteType", Port)) ? Port->getRouteType() : 0;
    int counter = 1;

    foreach(object vehicle in Vehicles)
    {
        mapping blueprint = vehicle->getBlueprint();
        string name = blueprint["display name"];
        string routeType = blueprint["route type"];
        int onRoute = function_exists("isOnTradeRoute", vehicle) ? vehicle->isOnTradeRoute() : 0;
        string currentRoute = function_exists("getCurrentRouteType", vehicle) ? vehicle->getCurrentRouteType() : 0;

        int canShow = 0;
        string reason = "";

        // Only show vehicles compatible with the port's route type
        if (routeType == portRouteType)
        {
            // Enable if not on a trade route, or on a compatible trade route
            if (!onRoute)
            {
                canShow = 1;
            }
            else if (currentRoute == portRouteType)
            {
                canShow = 1;
            }
            else
            {
                reason = " (Unavailable: On incompatible trade route)";
            }
        }
        else
        {
            reason = " (Unavailable: Incompatible vehicle type)";
        }

        Data[to_string(counter++)] = ([
            "name": sprintf("%s [%s]", name, routeType),
            "type": "vehicle",
            "description": sprintf("Capacity: %d, Protection: %d%s",
                blueprint["capacity"], blueprint["protection"], reason),
            "canShow": canShow,
            "vehicle": vehicle
        ]);
    }

    Data[to_string(counter++)] = ([
        "name": "Cancel",
        "type": "exit",
        "description": "Return to previous menu.",
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
        ret = type == "exit";

        if (type == "vehicle")
        {
            object vehicle = Data[selection]["vehicle"];
        }
    }
    return -1;
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string displayType = Data[choice]["canShow"] ? "choice enabled" : "choice disabled";
    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "    " : "",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-30s", displayType, "selector", colorConfiguration),
        displayDetails(choice));
}
