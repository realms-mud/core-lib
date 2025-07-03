// /lib/modules/domains/trading/overloadSelector.c
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
    AllowAbort = 0; // Must resolve overload situation
    Description = "Vehicle Overload Resolution";
    Type = "Overload";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object trader = User->getService("trader");
    mapping vehicle = trader->getVehicle();
    mapping cargo = vehicle["cargo"];
    
    int capacity = trader->getVehicleCapacity();
    int used = trader->getVehicleUsedSpace();
    int excess = used - capacity;
    
    Data = ([]);
    int counter = 1;
    
    // Show overload status
    Data[to_string(counter++)] = ([
        "name": sprintf("View Overload Status (%d units over capacity)", excess),
        "type": "status",
        "excess": excess,
        "description": sprintf("Your vehicle is carrying %d units but can only hold %d units. "
                             "You must reduce cargo by %d units before you can travel.",
                             used, capacity, excess),
        "canShow": 1
    ]);
    
    // Options to reduce cargo
    if (sizeof(cargo)) 
    {
        string *items = m_indices(cargo);
        foreach(string item in items) 
        {
            object itemObj = load_object(item + ".c");
            string itemName = itemObj ? itemObj->query("name") : item;
            int quantity = cargo[item];
            
            Data[to_string(counter++)] = ([
                "name": sprintf("Drop %s (have %d)", itemName, quantity),
                "type": "drop",
                "item_path": item,
                "item_name": itemName,
                "quantity": quantity,
                "description": sprintf("Drop some or all of your %s cargo. "
                                     "This will permanently destroy the items.",
                                     itemName),
                "canShow": 1
            ]);
        }
        
        // Drop all cargo option
        Data[to_string(counter++)] = ([
            "name": "Drop All Cargo (Emergency)",
            "type": "drop_all",
            "description": "Drop all cargo immediately. This will permanently destroy "
                          "all items but will resolve the overload situation.",
            "canShow": 1
        ]);
    }
    
    // Warehouse option (if at port)
    object environment = environment(User);
    if (environment && environment->isPort()) 
    {
        Data[to_string(counter++)] = ([
            "name": "Transfer to Warehouse",
            "type": "warehouse",
            "description": "Transfer excess cargo to your warehouse at this port.",
            "canShow": 1
        ]);
    }
    
    // Upgrade vehicle option (if enough money)
    int upgradeCost = calculateUpgradeCost(capacity);
    Data[to_string(counter++)] = ([
        "name": sprintf("Upgrade Vehicle Capacity (%d gold)", upgradeCost),
        "type": "upgrade",
        "upgrade_cost": upgradeCost,
        "description": sprintf("Permanently increase your vehicle's capacity by 50 units "
                             "for %d gold. This will resolve the overload.",
                             upgradeCost),
        "canShow": (trader->getCash() >= upgradeCost)
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User) 
    {
        string selectionType = Data[selection]["type"];
        
        // Check if overload is resolved after each action
        object trader = User->getService("trader");
        ret = (trader->getVehicleUsedSpace() <= trader->getVehicleCapacity());
        
        if (!ret && Data[selection]["canShow"]) 
        {
            switch(selectionType) 
            {
                case "status":
                    displayOverloadStatus();
                    break;
                case "drop":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/dropCargoSelector.c");
                    SubselectorObj->setItem(Data[selection]["item_path"]);
                    SubselectorObj->setMaxQuantity(Data[selection]["quantity"]);
                    break;
                case "drop_all":
                    handleDropAllCargo();
                    break;
                case "warehouse":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/overloadWarehouseSelector.c");
                    break;
                case "upgrade":
                    handleVehicleUpgrade(Data[selection]["upgrade_cost"]);
                    break;
            }
            
            if (SubselectorObj) 
            {
                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
            }
        }
        
        // Recheck if overload is resolved
        ret = (trader->getVehicleUsedSpace() <= trader->getVehicleCapacity());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private void displayOverloadStatus() 
{
    object trader = User->getService("trader");
    mapping vehicle = trader->getVehicle();
    string colorConfiguration = User->colorConfiguration();
    
    object commandsDictionary = getDictionary("commands");
    string charset = User->charsetConfiguration();
    
    int capacity = trader->getVehicleCapacity();
    int used = trader->getVehicleUsedSpace();
    int excess = used - capacity;
    
    string statusDisplay = commandsDictionary->buildBanner(colorConfiguration, charset, "top", 
                          "Vehicle Overload Crisis");
    
    // Capacity information
    statusDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
        configuration->decorate("Vehicle Capacity: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d units", capacity), "field data", "research", colorConfiguration) +
        configuration->decorate("     Current Load: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d units", used), "penalty modifier", "research", colorConfiguration));
    
    statusDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
        configuration->decorate("Excess Cargo: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d units", excess), "penalty modifier", "research", colorConfiguration) +
        configuration->decorate(" - YOU CANNOT TRAVEL UNTIL THIS IS RESOLVED!", 
                               "failure", "selector", colorConfiguration));
    
    // Current cargo breakdown
    statusDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
                     configuration->decorate("Current Cargo:", "field header", "research", colorConfiguration));
    
    mapping cargo = vehicle["cargo"];
    if (sizeof(cargo)) 
    {
        string *items = m_indices(cargo);
        foreach(string item in items) 
        {
            object itemObj = load_object(item + ".c");
            string itemName = itemObj ? itemObj->query("name") : item;
            
            string cargoLine = configuration->decorate(sprintf("  %-25s: ", itemName),
                              "choice enabled", "selector", colorConfiguration) +
                              configuration->decorate(sprintf("%d units", cargo[item]),
                              "data", "selector", colorConfiguration);
            
            statusDisplay += commandsDictionary->banneredContent(colorConfiguration, charset, cargoLine);
        }
    }
    
    statusDisplay += commandsDictionary->buildBanner(colorConfiguration, charset, "bottom", "-");
    
    tell_object(User, statusDisplay);
}

/////////////////////////////////////////////////////////////////////////////
private void handleDropAllCargo() 
{
    object trader = User->getService("trader");
    mapping vehicle = trader->getVehicle();
    string colorConfiguration = User->colorConfiguration();
    
    // Calculate total value lost
    int totalValue = 0;
    mapping cargo = vehicle["cargo"];
    string *items = m_indices(cargo);
    
    object environment = environment(User);
    foreach(string item in items) 
    {
        if (environment && environment->isPort()) 
        {
            int price = environment->getItemPrice(item);
            totalValue += price * cargo[item];
        }
    }
    
    // Clear all cargo
    vehicle["cargo"] = ([]);
    
    tell_object(User, configuration->decorate(
        sprintf("You dropped all cargo! Estimated value lost: %d gold. "
               "Your vehicle is no longer overloaded.", totalValue),
        "failure", "selector", colorConfiguration));
}

/////////////////////////////////////////////////////////////////////////////
private void handleVehicleUpgrade(int cost)
{
    object trader = User->getService("trader");
    string colorConfiguration = User->colorConfiguration();
    
    if (trader->getCash() >= cost) 
    {
        trader->addCash(-cost);
        
        // Increase vehicle capacity
        mapping vehicle = trader->getVehicle();
        vehicle["capacity"] += 50;
        
        tell_object(User, configuration->decorate(
            sprintf("You upgraded your vehicle capacity by 50 units for %d gold. "
                   "Your vehicle is no longer overloaded.", cost),
            "success", "quests", colorConfiguration));
    } 
    else 
    {
        tell_object(User, configuration->decorate(
            sprintf("You need %d gold to upgrade your vehicle.", cost),
            "failure", "selector", colorConfiguration));
    }
}

/////////////////////////////////////////////////////////////////////////////
private int calculateUpgradeCost(int currentCapacity) 
{
    // Cost increases based on current capacity
    return (currentCapacity / 10) * 1000 + 5000; // Base 5000 + scaling cost
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller) 
{
    if (User) 
    {
        object trader = User->getService("trader");
        
        // Check if overload is resolved
        if (trader->getVehicleUsedSpace() <= trader->getVehicleCapacity()) 
        {
            tell_object(User, configuration->decorate(
                "Overload situation resolved! You can now travel.",
                "success", "quests", User->colorConfiguration()));
            
            // Exit back to trading menu
            notifySynchronous("onSelectorCompleted");
            return;
        }
        
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
    
    // Special formatting for critical choices
    string criticalIndicator = "";
    if (Data[choice]["type"] == "drop_all") 
    {
        criticalIndicator = configuration->decorate(" [DANGER]", "penalty modifier", 
                           "research", colorConfiguration);
    }
    
    return sprintf("%s[%s]%s - %s%s%s",
        (NumColumns < 3) ? "    " : "",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-35s", displayType, "selector", colorConfiguration),
        criticalIndicator,
        displayDetails(choice));
}
