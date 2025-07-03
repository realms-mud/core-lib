//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 1;
    AllowAbort = 1;
    Description = "Warehouse Management";
    Type = "Warehouse";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object trader = User->getService("trader");
    object environment = environment(User);
    
    if (environment && environment->isPort())
    {
        mapping warehouse = trader->getWarehouse(trader->getCurrentLocation());
        mapping vehicle = trader->getVehicle();
        
        Data = ([]);
        int counter = 1;
        
        // Show warehouse status
        Data[to_string(counter++)] = ([
            "name": "View Warehouse Status",
            "type": "status",
            "description": "Display detailed warehouse inventory and capacity information.",
            "canShow": 1
        ]);
        
        // Load cargo from warehouse to vehicle
        if (sizeof(warehouse["inventory"]))
        {
            Data[to_string(counter++)] = ([
                "name": "Load Cargo from Warehouse",
                "type": "load",
                "description": "Transfer goods from warehouse to your vehicle.",
                "canShow": (trader->getVehicleFreeSpace() > 0)
            ]);
        }
        
        // Unload cargo from vehicle to warehouse
        if (sizeof(vehicle["cargo"]))
        {
            Data[to_string(counter++)] = ([
                "name": "Unload Cargo to Warehouse",
                "type": "unload", 
                "description": "Transfer goods from your vehicle to warehouse storage.",
                "canShow": 1
            ]);
        }
        
        // Warehouse rental management
        int daysLeft = (warehouse["rent_paid"] - time()) / 86400;
        if (daysLeft < 7)
        {
            Data[to_string(counter++)] = ([
                "name": sprintf("Pay Warehouse Rent (%d days left)", daysLeft),
                "type": "rent",
                "description": sprintf("Extend warehouse rental. Current rent expires in %d days.", daysLeft),
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
    else
    {
        tell_object(User, configuration->decorate("You must be at a trading port to access your warehouse.",
                   "failure", "selector", User->colorConfiguration()));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    
    if (User)
    {
        ret = (Data[selection]["type"] == "exit");
        
        if (!ret && Data[selection]["canShow"])
        {
            switch(Data[selection]["type"])
            {
                case "status":
                {
                    displayWarehouseStatus();
                    break;
                }
                case "load":
                {
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/warehouseLoadSelector.c");
                    break;
                }
                case "unload":
                {
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/warehouseUnloadSelector.c");
                    break;
                }
                case "rent":
                {
                    handleRentPayment();
                    break;
                }
            }
            
            if (SubselectorObj)
            {
                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
            }
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private void displayWarehouseStatus()
{
    object trader = User->getService("trader");
    mapping warehouse = trader->getWarehouse(trader->getCurrentLocation());
    string colorConfiguration = User->colorConfiguration();
    
    object commandsDictionary = getDictionary("commands");
    string charset = User->charsetConfiguration();
    object tradingDict = getDictionary("trading");
    
    string warehouseDisplay = commandsDictionary->buildBanner(colorConfiguration, charset, "top", 
                             sprintf("%s Warehouse", trader->getCurrentLocation()));
    
    // Capacity information
    int used = tradingDict->calculateWarehouseUsed(warehouse);
    warehouseDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
        configuration->decorate("Capacity: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d/%d units used", used, warehouse["capacity"]),
                               "field data", "research", colorConfiguration) +
        configuration->decorate("     Space Available: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d units", warehouse["capacity"] - used),
                               "field data", "research", colorConfiguration));
    
    // Rental information
    int daysLeft = (warehouse["rent_paid"] - time()) / 86400;
    string rentColor = (daysLeft < 7) ? "penalty modifier" : "field data";
    warehouseDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
        configuration->decorate("Rent Status: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d days remaining", daysLeft),
                               rentColor, "research", colorConfiguration));
    
    // Inventory listing
    if (sizeof(warehouse["inventory"]))
    {
        warehouseDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
                           configuration->decorate("Stored Inventory:", "field header", "research", colorConfiguration));
        
        string *items = m_indices(warehouse["inventory"]);
        foreach(string item in items)
        {
            object itemObj = load_object(item + ".c");
            string itemName = itemObj ? itemObj->query("name") : item;
            
            string itemLine = configuration->decorate(sprintf("  %-30s: ", itemName),
                             "choice enabled", "selector", colorConfiguration) +
                             configuration->decorate(sprintf("%d units", warehouse["inventory"][item]),
                             "data", "selector", colorConfiguration);
            
            warehouseDisplay += commandsDictionary->banneredContent(colorConfiguration, charset, itemLine);
        }
    }
    else
    {
        warehouseDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
                           configuration->decorate("Warehouse is empty.", "note", "selector", colorConfiguration));
    }
    
    warehouseDisplay += commandsDictionary->buildBanner(colorConfiguration, charset, "bottom", "-");
    
    tell_object(User, warehouseDisplay);
}

/////////////////////////////////////////////////////////////////////////////
private void handleRentPayment()
{
    object trader = User->getService("trader");
    int rentCost = 1000; // Base monthly rent
    
    string colorConfiguration = User->colorConfiguration();
    
    if (trader->getCash() >= rentCost)
    {
        trader->addCash(-rentCost);
        
        // Extend rent by 30 days
        mapping warehouse = trader->getWarehouse(trader->getCurrentLocation());
        warehouse["rent_paid"] += (30 * 86400);
        
        tell_object(User, configuration->decorate(
            sprintf("You paid %d gold for 30 days of warehouse rental.", rentCost),
            "success", "quests", colorConfiguration));
    }
    else
    {
        tell_object(User, configuration->decorate(
            sprintf("You need %d gold to pay the warehouse rent.", rentCost),
            "failure", "selector", colorConfiguration));
    }
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
    
    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "    " : "",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-30s", displayType, "selector", colorConfiguration),
        displayDetails(choice));
}
