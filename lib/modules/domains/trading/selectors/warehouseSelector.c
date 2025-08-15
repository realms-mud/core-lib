//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private object Port;

/////////////////////////////////////////////////////////////////////////////
public void setPort(object port)
{
    Port = port;
}

/////////////////////////////////////////////////////////////////////////////
private void displayWarehouseStatus()
{
    mapping warehouse = User->getWarehouse(Port);
    string colorConfig = User->colorConfiguration();
    
    object commandsService = getService("commands");
    string charset = User->charsetConfiguration();
    
    string warehouseDisplay = commandsService->buildBanner(colorConfig, charset, "top", 
                             sprintf("%s Warehouse", Port));
    
    // Calculate warehouse used space
    int used = 0;
    if (sizeof(warehouse["inventory"]))
    {
        string *items = m_indices(warehouse["inventory"]);
        foreach(string item in items)
        {
            used += warehouse["inventory"][item];
        }
    }
    
    // Capacity information
    warehouseDisplay += commandsService->banneredContent(colorConfig, charset,
        configuration->decorate("Capacity: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d/%d units used", used, warehouse["capacity"]),
                               "field data", "research", colorConfig) +
        configuration->decorate("     Space Available: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d units", warehouse["capacity"] - used),
                               "field data", "research", colorConfig));
    
    // Rental information
    int daysLeft = (warehouse["rent paid"] - time()) / 86400;
    string rentColor = (daysLeft < 7) ? "penalty modifier" : "field data";
    warehouseDisplay += commandsService->banneredContent(colorConfig, charset,
        configuration->decorate("Rent Status: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d days remaining", daysLeft),
                               rentColor, "research", colorConfig));
    
    // Inventory listing
    if (sizeof(warehouse["inventory"]))
    {
        warehouseDisplay += commandsService->banneredContent(colorConfig, charset,
                           configuration->decorate("Stored Inventory:", "field header", "research", colorConfig));
        
        string *items = m_indices(warehouse["inventory"]);
        foreach(string item in items)
        {
            object itemObj = load_object(item);
            string itemName = itemObj ? itemObj->query("name") : item;
            
            string itemLine = configuration->decorate(sprintf("  %-30s: ", itemName),
                             "choice enabled", "selector", colorConfig) +
                             configuration->decorate(sprintf("%d units", warehouse["inventory"][item]),
                             "data", "selector", colorConfig);
            
            warehouseDisplay += commandsService->banneredContent(colorConfig, charset, itemLine);
        }
    }
    else
    {
        warehouseDisplay += commandsService->banneredContent(colorConfig, charset,
                           configuration->decorate("Warehouse is empty.", "note", "selector", colorConfig));
    }
    
    warehouseDisplay += commandsService->buildBanner(colorConfig, charset, "bottom", "-");
    
    tell_object(User, warehouseDisplay);
}

/////////////////////////////////////////////////////////////////////////////
private void handleRentPayment()
{
    int rentCost = 1000; // Base monthly rent
    string colorConfig = User->colorConfiguration();
    
    if (User->getCash() >= rentCost)
    {
        User->addCash(-rentCost);
        
        // Extend rent by 30 days
        mapping warehouse = User->getWarehouse(Port);
        warehouse["rent paid"] += (30 * 86400);
        
        tell_object(User, configuration->decorate(
            sprintf("You paid %d gold for 30 days of warehouse rental.", rentCost),
            "success", "quests", colorConfig));
    }
    else
    {
        tell_object(User, configuration->decorate(
            sprintf("You need %d gold to pay the warehouse rent.", rentCost),
            "failure", "selector", colorConfig));
    }
}

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
    object environment = environment(User);
    
    mapping warehouse = User->getWarehouse(Port);
    mapping vehicle = User->getVehiclesAtLocation(Port->getPortName());
 
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
            "canShow": (User->getVehicleFreeSpace() > 0)
        ]);
    }
        
    // Unload cargo from vehicle to warehouse
    if (mappingp(vehicle) && member(vehicle, "cargo") && sizeof(vehicle["cargo"]))
    {
        Data[to_string(counter++)] = ([
            "name": "Unload Cargo to Warehouse",
            "type": "unload", 
            "description": "Transfer goods from your vehicle to warehouse storage.",
            "canShow": 1
        ]);
    }
        
    // Warehouse rental management
    int daysLeft = (warehouse["rent paid"] - time()) / 86400;
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
        configuration->decorate("%-30s", displayType, "selector", colorConfig),
        displayDetails(choice));
}
