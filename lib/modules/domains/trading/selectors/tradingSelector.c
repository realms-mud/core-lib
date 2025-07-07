//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object SubselectorObj;
private object TradingDictionary;
private int justDisplayedStatus = 0;

/////////////////////////////////////////////////////////////////////////////
private void displayTradingStatus() 
{
    mapping data = User->getTradingData();
    string colorConfig = User->colorConfiguration();
    
    object commandsDictionary = getDictionary("commands");
    string charset = User->charsetConfiguration();
    
    string statusDisplay = 
        commandsDictionary->buildBanner(colorConfig, charset, "top", 
            sprintf("%s Trading Status", data["firm"]));
    
    // Company information
    statusDisplay += commandsDictionary->banneredContent(colorConfig, charset,
        configuration->decorate("Location: ", "field header", "research", colorConfig) +
        configuration->decorate(data["location"], "field data", "research", colorConfig) +
        configuration->decorate("        Date: ", "field header", "research", colorConfig) +
        configuration->decorate(data["date"], "field data", "research", colorConfig));
    
    // Financial status
    statusDisplay += commandsDictionary->banneredContent(colorConfig, charset,
        configuration->decorate("Cash: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d gold", data["cash"]), "field data", "research", colorConfig) +
        configuration->decorate("     Bank: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d gold", data["bank"]), "field data", "research", colorConfig) +
        configuration->decorate("     Debt: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d gold", data["debt"]), 
                               data["debt"] > 0 ? "penalty modifier" : "field data", "research", colorConfig));
    
    // Vehicle information
    mapping vehicle = data["vehicle"];
    statusDisplay += commandsDictionary->banneredContent(colorConfig, charset,
        configuration->decorate(sprintf("Vehicle: %s", vehicle["type"]), "field header", "research", colorConfig));
    
    statusDisplay += commandsDictionary->banneredContent(colorConfig, charset,
        configuration->decorate("Capacity: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d/%d units", User->getVehicleUsedSpace(), vehicle["capacity"]), 
                               "field data", "research", colorConfig) +
        configuration->decorate("     Protection: ", "field header", "research", colorConfig) +
        configuration->decorate(sprintf("%d", vehicle["protection"]), "field data", "research", colorConfig));
    
    statusDisplay += commandsDictionary->buildBanner(colorConfig, charset, "bottom", "-");
    
    tell_object(User, statusDisplay);
}

/////////////////////////////////////////////////////////////////////////////
private void displayMarketPrices() 
{
    object environment = environment(User);

    if (!environment || !environment->isPort()) 
    {
        tell_object(User, configuration->decorate("You must be at a trading port to view market prices.",
                   "failure", "selector", colorConfiguration));
        return;
    }
    
    string colorConfig = User->colorConfiguration();
    object commandsDictionary = getDictionary("commands");
    string charset = User->charsetConfiguration();
    
    string priceDisplay = commandsDictionary->buildBanner(colorConfig, charset, "top", 
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
        object itemObj = load_object(item);
        
        if (itemObj) 
        {
            string itemLine = configuration->decorate(sprintf("%-25s: ", itemObj->query("name")),
                             "field header", "research", colorConfig) +
                             configuration->decorate(sprintf("%d gold", price),
                             "field data", "research", colorConfig);
            
            priceDisplay += commandsDictionary->banneredContent(colorConfig, charset, itemLine);
        }
    }
    
    priceDisplay += commandsDictionary->buildBanner(colorConfig, charset, "bottom", "-");
    
    tell_object(User, priceDisplay);
}

public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    Description = "Main Trading Menu";
    Type = "Trading";
    Data = ([]);
    
    TradingDictionary = load_object("/lib/dictionaries/tradingDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
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
    
    // Only add warehouse option when at a port
    if (isAtPort) 
    {
        Data[to_string(counter++)] = ([
            "name": "Manage Warehouse",
            "type": "warehouse",
            "description": "Transfer cargo between your vehicle and warehouse, "
                          "view stored inventory.",
            "canShow": 1
        ]);
        
        Data[to_string(counter++)] = ([
            "name": "Buy Goods",
            "type": "buy",
            "description": "Purchase goods from the local market to trade.",
            "canShow": 1
        ]);
        
        // Only add sell option when player has cargo
        if (sizeof(User->getVehicle()["cargo"]) > 0)
        {
            Data[to_string(counter++)] = ([
                "name": "Sell Goods", 
                "type": "sell",
                "description": "Sell your cargo at the local market.",
                "canShow": 1
            ]);
        }
        
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
    if (User->getVehicleUsedSpace() > User->getVehicleCapacity()) 
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
                    justDisplayedStatus = 1; // Suppress menu redisplay once
                    ret = -1;
                    break;
                case "prices":
                    displayMarketPrices();
                    justDisplayedStatus = 1; // Suppress menu redisplay once
                    ret = -1;
                    break;
                case "warehouse":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/warehouseSelector.c");
                    ret = -1;
                    break;
                case "buy":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/buySelector.c");
                    ret = -1;
                    break;
                case "sell":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/sellSelector.c");
                    ret = -1;
                    break;
                case "contracts":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/contractsSelector.c");
                    ret = -1;
                    break;
                case "travel":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/travelSelector.c");
                    ret = -1;
                    break;
                case "bank":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/bankSelector.c");
                    ret = -1;
                    break;
                case "overload":
                    SubselectorObj = clone_object("/lib/modules/domains/trading/selectors/overloadSelector.c");
                    ret = -1;
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
    int ret = objectp(SubselectorObj) || justDisplayedStatus;
    if (justDisplayedStatus) 
    {
        justDisplayedStatus = 0; // Reset after suppressing once
    }
    return ret;
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
