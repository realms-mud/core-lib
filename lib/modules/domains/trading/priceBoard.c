//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
private void displayBoardContent(object player, object port)
{
    string colorConfiguration = player->colorConfiguration();
    string charset = player->charsetConfiguration();
    
    object commandsDict = getService("commands");
    object configDict = getService("configuration");
    
    string boardDisplay = commandsDict->buildBanner(colorConfiguration, charset, "top", 
                         sprintf("%s Trading Board", port->getPortName()));
    
    boardDisplay += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("Welcome to the trading district! This board contains:", 
                           "description", "selector", colorConfiguration));
    
    boardDisplay += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("- Current market prices for all goods", 
                           "choice enabled", "selector", colorConfiguration));
    
    boardDisplay += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("- Available trading contracts", 
                           "choice enabled", "selector", colorConfiguration));
    
    boardDisplay += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("- Travel routes and schedules", 
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
    
    object commandsDict = getService("commands");
    object configDict = getService("configuration");
    
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

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("price board");
    addAlias("board");
    addAlias("prices");
    addAlias("market");
    addAlias("trading board");
    addAlias("notice board");
    
    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". In the early morning light, merchants can be seen updating the board with fresh prices from overnight arrivals",
        ". As dawn breaks, a port official chalks new contract listings onto the weathered surface"
    }));
    
    addTimeOfDayDescription("morning", ({
        ". The morning finds traders clustered around the board, studying the latest market rates and contract opportunities",
        ". Fresh chalk marks gleam white against the darkened wood as morning business gets underway"
    }));
    
    addTimeOfDayDescription("noon", ({
        ". At midday, the board is frequently consulted by merchants taking a break from the busy trading activities",
        ". The noon sun illuminates the chalked prices and announcements, making them easy to read"
    }));
    
    addTimeOfDayDescription("afternoon", ({
        ". Afternoon shadows play across the board's surface as traders check for any price changes or new contracts",
        ". The board shows signs of heavy use throughout the afternoon, with some prices being erased and rewritten"
    }));
    
    addTimeOfDayDescription("evening", ({
        ". As evening approaches, lanterns are lit nearby to keep the board readable for late trading activities",
        ". The day's final price updates are chalked onto the board as merchants prepare to close their stalls"
    }));
    
    addTimeOfDayDescription("dusk", ({
        ". At dusk, oil lamps cast flickering light across the chalked announcements and price listings",
        ". The board's contents are reviewed one last time before the day's trading comes to an end"
    }));
    
    addTimeOfDayDescription("night", ({
        ". By night, the board is illuminated by nearby torches, still accessible to those engaged in late-night trading",
        ". Moonlight and torchlight combine to keep the trading information visible even after dark"
    }));
    
    // Seasonal variations
    addSeasonDescription("spring", ({
        " with fresh notices about spring crops and new trade routes opening as winter weather clears",
        " where announcements about seasonal goods and agricultural contracts dominate the available space"
    }));
    
    addSeasonDescription("summer", ({
        " with contracts for summer harvests and notices about increased shipping activity in the fair weather",
        " where the wood has faded slightly from the intense summer sun, but the chalk marks remain clearly visible"
    }));
    
    addSeasonDescription("autumn", ({
        " with urgent notices about winter preparations and contracts for preserved goods before the cold season",
        " where harvest-related announcements and preparations for winter trading dominate the posted notices"
    }));
    
    addSeasonDescription("winter", ({
        " with notices about limited winter routes and premium prices for goods that brave the harsh weather",
        " where ice sometimes forms in the corners, and the chalk occasionally freezes, making updates difficult"
    }));
    
    // Lighting condition descriptions (using correct method names)
    addNearDarkDescriptionTemplate("a large dark board with barely visible chalk markings");
    addLowLightDescriptionTemplate("a wooden notice board with faint chalk writing visible in the dim light");
    addDimLightDescriptionTemplate("a substantial wooden board covered with chalked trading information");
    addSomeLightDescriptionTemplate("a well-maintained trading board with clearly visible price listings and contract announcements chalked across its surface");
    
    // Bright light description (uses the base addDescriptionTemplate)
    addDescriptionTemplate("a large wooden board covered with chalked prices and trading announcements");
    
    // Comprehensive item template for detailed examination
    addItemTemplate("This substantial wooden board stands as the central hub of trading information for the district. "
                   "Made from thick oak planks weathered by constant use, its dark surface is covered with chalked "
                   "announcements in various hands. Current market prices for common goods are listed in neat columns "
                   "on the left side, while contract opportunities and trading notices fill the right. The bottom "
                   "section contains travel schedules and route information. Small pieces of chalk and erasers hang "
                   "from strings attached to the frame's sides, allowing merchants to update information as needed. "
                   "The board's frame shows the wear of countless hands and the wood bears the faint impressions of "
                   "countless previous announcements that have been erased and written over.");
    
    // Provide some ambient light since people need to read it
    addSourceOfLight(2);
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
    
    if (str && (str == "board" || str == "prices" || str == "market" || str == "trading board" || str == "notice board"))
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
        object tradingDict = getService("trading");
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
