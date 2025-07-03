// /lib/modules/domains/trading/travelSelector.c
//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private string selectedDestination;

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    Description = "Travel Planning";
    Type = "Travel";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object environment = environment(User);
    if (!environment || !environment->isPort()) 
    {
        tell_object(User, configuration->decorate("You must be at a trading port to plan travel.",
                   "failure", "selector", User->colorConfiguration()));
        return;
    }
    
    mapping routes = environment->getTradeRoutes();
    object trader = User->getService("trader");
    
    Data = ([]);
    int counter = 1;
    
    if (!sizeof(routes)) 
    {
        Data[to_string(counter++)] = ([
            "name": "No Routes Available",
            "type": "empty",
            "description": "There are no trade routes available from this port.",
            "canShow": 0
        ]);
    } 
    else 
    {
        string *destinations = m_indices(routes);
        foreach(string dest in destinations) 
        {
            mapping route = routes[dest];
            
            // Calculate travel cost based on distance and vehicle type
            int baseCost = route["days"] * 50; // 50 gold per day
            mapping vehicle = trader->getVehicle();
            
            // Modify cost based on vehicle type
            switch(vehicle["type"]) 
            {
                case "ship": baseCost = to_int(baseCost * 0.8); break;  // Ships are efficient
                case "wagon": baseCost = to_int(baseCost * 1.0); break; // Standard cost
                case "barge": baseCost = to_int(baseCost * 0.9); break; // Barges moderate
            }
            
            Data[to_string(counter++)] = ([
                "name": sprintf("%s (%s route)", capitalize(dest), route["type"]),
                "type": "destination",
                "destination": dest,
                "route_info": route,
                "travel_cost": baseCost,
                "description": sprintf("Travel to %s via %s route. Distance: %d days, "
                                     "Danger Level: %d%%, Cost: %d gold",
                                     capitalize(dest), route["type"], route["days"], 
                                     route["danger"], baseCost),
                "canShow": (trader->getCash() >= baseCost)
            ]);
        }
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
    if (User) 
    {
        ret = (Data[selection]["type"] == "exit");
        
        if (!ret && Data[selection]["canShow"] && 
            Data[selection]["type"] == "destination") 
        {
            selectedDestination = Data[selection]["destination"];
            
            // Show travel confirmation
            SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/travelConfirmSelector.c");
            SubselectorObj->setDestination(selectedDestination);
            SubselectorObj->setRouteInfo(Data[selection]["route_info"]);
            SubselectorObj->setTravelCost(Data[selection]["travel_cost"]);
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
    
    string costInfo = "";
    if (Data[choice]["type"] == "destination" && !Data[choice]["canShow"]) 
    {
        costInfo = configuration->decorate(sprintf(" (Need %d gold)", 
                   Data[choice]["travel_cost"]), "note", "selector", colorConfiguration);
    }
    
    return sprintf("%s[%s]%s - %s%s%s",
        (NumColumns < 3) ? "    " : "",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-35s", displayType, "selector", colorConfiguration),
        costInfo,
        displayDetails(choice));
}
