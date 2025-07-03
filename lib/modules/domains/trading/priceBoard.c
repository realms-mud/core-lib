//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("price board");
    addAlias("board");
    addAlias("prices");
    addAlias("market");
    
    addItemTemplate("a large wooden board covered with chalked prices and "
                   "trading announcements. Current market rates and available "
                   "contracts are posted here for all merchants to see. The "
                   "board is updated regularly with the latest information.");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("readBoard", "read");
    add_action("readBoard", "look");
    add_action("readBoard", "examine");
    add_action("checkPrices", "prices");
    add_action("checkContracts", "contracts");
}

/////////////////////////////////////////////////////////////////////////////
public int readBoard(string str)
{
    int ret = 0;
    
    if (str && (str == "board" || str == "prices" || str == "market"))
    {
        object port = environment();
        if (port && port->isPort())
        {
            displayBoardContent(this_player(), port);
            ret = 1;
        }
        else
        {
            tell_object(this_player(), "This board is not functional here.");
            ret = 1;
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int checkPrices(string str)
{
    object port = environment();
    if (port && port->isPort())
    {
        object tradingDict = getDictionary("trading");
        tell_object(this_player(), tradingDict->getMarketPricesDisplay(this_player(), port));
    }
    else
    {
        tell_object(this_player(), "No market information available here.");
    }
    
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public int checkContracts(string str)
{
    object port = environment();
    if (port && port->isPort())
    {
        displayAvailableContracts(this_player(), port);
    }
    else
    {
        tell_object(this_player(), "No contract information available here.");
    }
    
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
private void displayBoardContent(object player, object port)
{
    string colorConfiguration = player->colorConfiguration();
    string charset = player->charsetConfiguration();
    
    object commandsDict = getDictionary("commands");
    object configDict = getDictionary("configuration");
    
    string boardDisplay = commandsDict->buildBanner(colorConfiguration, charset, "top", 
                         sprintf("%s Trading Board", port->getPortName()));
    
    boardDisplay += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("Welcome to the trading district! This board contains:", 
                           "description", "selector", colorConfiguration));
    
    boardDisplay += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("• Current market prices for all goods", 
                           "choice enabled", "selector", colorConfiguration));
    
    boardDisplay += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("• Available trading contracts", 
                           "choice enabled", "selector", colorConfiguration));
    
    boardDisplay += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("• Travel routes and schedules", 
                           "choice enabled", "selector", colorConfiguration));
    
    boardDisplay += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("Commands:", "field header", "research", colorConfiguration) +
        configDict->decorate(" 'prices' - View market prices", "description", "selector", colorConfiguration));
    
    boardDisplay += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("         'contracts' - View available contracts", 
                           "description", "selector", colorConfiguration));
    
    boardDisplay += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("         'trade' - Enter trading subsystem", 
                           "description", "selector", colorConfiguration));
    
    boardDisplay += commandsDict->buildBanner(colorConfiguration, charset, "bottom", "-");
    
    tell_object(player, boardDisplay);
}

/////////////////////////////////////////////////////////////////////////////
private void displayAvailableContracts(object player, object port)
{
    string colorConfiguration = player->colorConfiguration();
    string charset = player->charsetConfiguration();
    mapping contracts = port->getContracts();
    
    object commandsDict = getDictionary("commands");
    object configDict = getDictionary("configuration");
    
    string contractDisplay = commandsDict->buildBanner(colorConfiguration, charset, "top", 
                            sprintf("%s Trading Contracts", port->getPortName()));
    
    if (sizeof(contracts))
    {
        string *contractIds = m_indices(contracts);
        foreach(string id in contractIds)
        {
            mapping contract = contracts[id];
            
            // Check if contract is still valid
            int timeLeft = contract["deadline"] - time();
            int daysLeft = timeLeft / 86400;
            
            if (timeLeft > 0)
            {
                string urgency = "";
                if (daysLeft <= 3)
                {
                    urgency = configDict->decorate(" [URGENT]", "penalty modifier", "research", colorConfiguration);
                }
                else if (daysLeft <= 7)
                {
                    urgency = configDict->decorate(" [Soon]", "warning", "selector", colorConfiguration);
                }
                
                string contractLine = configDict->decorate(sprintf("%s: ", id),
                                     "field header", "research", colorConfiguration) +
                                     configDict->decorate(contract["description"],
                                     "field data", "research", colorConfiguration) + urgency;
                
                contractDisplay += commandsDict->banneredContent(colorConfiguration, charset, contractLine);
                
                string detailsLine = configDict->decorate("  Reward: ",
                                   "choice enabled", "selector", colorConfiguration) +
                                   configDict->decorate(sprintf("%d gold", contract["reward"]),
                                   "data", "selector", colorConfiguration) +
                                   configDict->decorate("  Time Left: ",
                                   "choice enabled", "selector", colorConfiguration) +
                                   configDict->decorate(sprintf("%d days", daysLeft),
                                   daysLeft <= 3 ? "penalty modifier" : "data", "selector", colorConfiguration);
                
                contractDisplay += commandsDict->banneredContent(colorConfiguration, charset, detailsLine);
            }
        }
    }
    else
    {
        contractDisplay += commandsDict->banneredContent(colorConfiguration, charset,
                          configDict->decorate("No contracts available at this time.",
                          "note", "selector", colorConfiguration));
    }
    
    contractDisplay += commandsDict->banneredContent(colorConfiguration, charset,
                      configDict->decorate("Use 'trade' to enter the trading subsystem for more options.",
                      "instructions", "selector", colorConfiguration));
    
    contractDisplay += commandsDict->buildBanner(colorConfiguration, charset, "bottom", "-");
    
    tell_object(player, contractDisplay);
}
