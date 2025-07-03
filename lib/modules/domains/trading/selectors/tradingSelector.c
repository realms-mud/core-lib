//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private object TradingDictionary;

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    Description = "Main Trading Menu";
    Type = "Trading";
    Data = ([]);
    
    TradingDictionary = load_object("/lib/modules/domains/trading/tradingDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object trader = User->getService("trader");
    object environment = environment(User);
    int isAtPort = (environment && environment->isPort());
    
    Data = ([]);
    int counter = 1;
    
    // Always available options
    Data[to_string(counter++)] = ([
        "name": "View Company Status",
        "type": "status",
        "description": "Display your trading company's financial status, "
                      "vehicle information, and current location.",
        "canShow": 1
    ]);
    
    Data[to_string(counter++)] = ([
        "name": "Manage Warehouse",
        "type": "warehouse",
        "description": "Transfer cargo between your vehicle and warehouse, "
                      "view stored inventory.",
        "canShow": isAtPort
    ]);
    
    // Port-specific options
    if (isAtPort) 
    {
        Data[to_string(counter++)] = ([
            "name": "Buy Goods",
            "type": "buy",
            "description": "Purchase goods from the local market to trade.",
            "canShow": 1
        ]);
        
        Data[to_string(counter++)] = ([
            "name": "Sell Goods", 
            "type": "sell",
            "description": "Sell your cargo at the local market.",
            "canShow": (sizeof(trader->getVehicle()["cargo"]) > 0)
        ]);
        
        Data[to_string(counter++)] = ([
            "name": "View Market Prices",
            "type": "prices",
            "description": "View current market prices for all goods.",
            "canShow": 1
        ]);
        
        Data[to_string(counter++)] = ([
            "name": "Browse Contracts",
            "type": "contracts",
            "description": "View and accept trading contracts.",
            "canShow": 1
        ]);
        
        Data[to_string(counter++)] = ([
            "name": "Travel to Another Port",
            "type": "travel",
            "description": "Begin a journey to another trading destination.",
            "canShow": 1
        ]);
        
        Data[to_string(counter++)] = ([
            "name": "Visit Bank",
            "type": "bank",
            "description": "Deposit, withdraw money, or manage loans.",
            "canShow": 1
        ]);
    }
    
    // Vehicle options
    if (trader->getVehicleUsedSpace() > trader->getVehicleCapacity()) 
    {
        Data[to_string(counter++)] = ([
            "name": "Resolve Overloading",
            "type": "overload",
            "description": "Your vehicle is overloaded and must be resolved.",
            "canShow": 1
        ]);
    }
    
    Data[to_string(counter++)] = ([
        "name": "Exit Trading Menu",
        "type": "exit",
        "description": "Close the trading interface.",
        "canShow": 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User) 
    {
        string selectionType = Data[selection]["type"];
        ret = (selectionType == "exit");
        
        if (!ret && Data[selection]["canShow"]) 
        {
            switch(selectionType) 
            {
                case "status":
                    displayTradingStatus();
                    break;
                case "warehouse":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/warehouseSelector.c");
                    break;
                case "buy":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/buySelector.c");
                    break;
                case "sell":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/sellSelector.c");
                    break;
                case "prices":
                    displayMarketPrices();
                    break;
                case "contracts":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/contractsSelector.c");
                    break;
                case "travel":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/travelSelector.c");
                    break;
                case "bank":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/bankSelector.c");
                    break;
                case "overload":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/overloadSelector.c");
                    break;
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
private void displayTradingStatus() 
{
    object trader = User->getService("trader");
    mapping data = trader->getTradingData();
    string colorConfiguration = User->colorConfiguration();
    
    object commandsDictionary = getDictionary("commands");
    string charset = User->charsetConfiguration();
    
    string statusDisplay = 
        commandsDictionary->buildBanner(colorConfiguration, charset, "top", 
            sprintf("%s Trading Status", data["firm"]));
    
    // Company information
    statusDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
        configuration->decorate("Location: ", "field header", "research", colorConfiguration) +
        configuration->decorate(data["location"], "field data", "research", colorConfiguration) +
        configuration->decorate("        Date: ", "field header", "research", colorConfiguration) +
        configuration->decorate(data["date"], "field data", "research", colorConfiguration));
    
    // Financial status
    statusDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
        configuration->decorate("Cash: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d gold", data["cash"]), "field data", "research", colorConfiguration) +
        configuration->decorate("     Bank: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d gold", data["bank"]), "field data", "research", colorConfiguration) +
        configuration->decorate("     Debt: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d gold", data["debt"]), 
                               data["debt"] > 0 ? "penalty modifier" : "field data", "research", colorConfiguration));
    
    // Vehicle information
    mapping vehicle = data["vehicle"];
    statusDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
        configuration->decorate(sprintf("Vehicle: %s", vehicle["type"]), "field header", "research", colorConfiguration));
    
    statusDisplay += commandsDictionary->banneredContent(colorConfiguration, charset,
        configuration->decorate("Capacity: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d/%d units", trader->getVehicleUsedSpace(), vehicle["capacity"]), 
                               "field data", "research", colorConfiguration) +
        configuration->decorate("     Protection: ", "field header", "research", colorConfiguration) +
        configuration->decorate(sprintf("%d", vehicle["protection"]), "field data", "research", colorConfiguration));
    
    statusDisplay += commandsDictionary->buildBanner(colorConfiguration, charset, "bottom", "-");
    
    tell_object(User, statusDisplay);
}

/////////////////////////////////////////////////////////////////////////////
private void displayMarketPrices() 
{
    object environment = environment(User);

    if (!environment || !environment->isPort()) 
    {
        tell_object(User, configuration->decorate("You must be at a trading port to view market prices.",
                   "failure", "selector", User->colorConfiguration()));
        return;
    }
    
    string colorConfiguration = User->colorConfiguration();
    object commandsDictionary = getDictionary("commands");
    string charset = User->charsetConfiguration();
    
    string priceDisplay = commandsDictionary->buildBanner(colorConfiguration, charset, "top", 
                         sprintf("%s Market Prices", environment->getPortName()));
    
    string *commonItems = ({
        "/lib/instances/items/materials/metal/iron",
        "/lib/instances/items/materials/wood/oak", 
        "/lib/instances/items/weapons/swords/long-sword",
        "/lib/instances/items/food/bread",
        "/lib/instances/items/materials/crystal/diamond"
    });
    
    foreach(string item in commonItems) 
    {
        int price = environment->getItemPrice(item);
        object itemObj = load_object(item + ".c");
        
        if (itemObj) 
        {
            string itemLine = configuration->decorate(sprintf("%-25s: ", itemObj->query("name")),
                             "field header", "research", colorConfiguration) +
                             configuration->decorate(sprintf("%d gold", price),
                             "field data", "research", colorConfiguration);
            
            priceDisplay += commandsDictionary->banneredContent(colorConfiguration, charset, itemLine);
        }
    }
    
    priceDisplay += commandsDictionary->buildBanner(colorConfiguration, charset, "bottom", "-");
    
    tell_object(User, priceDisplay);
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
