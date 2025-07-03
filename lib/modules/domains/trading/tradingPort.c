//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

private string portName = "Unknown Port";
private string portType = "coastal";
private mapping specialties = ([]);
private mapping imports = ([]);
private mapping currentPrices = ([]);
private mapping marketModifiers = ([]);
private int lastPriceUpdate = 0;

// Available trade routes
private mapping tradeRoutes = ([]);
private mapping contracts = ([]);

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    SetClimate("temperate");
    SetAmbientLight(30);
    setPortDefaults();
    generatePrices();
    generateContracts();
}

/////////////////////////////////////////////////////////////////////////////
private void setPortDefaults()
{
    // Override in specific port implementations
    portName = "Generic Port";
    portType = "coastal";
    
    // Default route (should be overridden)
    tradeRoutes = ([
        "eledhel": ([ "type": "overland", "days": 5, "danger": 10 ])
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public void setPortName(string name)
{
    if (name && stringp(name))
    {
        portName = name;
    }
}

/////////////////////////////////////////////////////////////////////////////
public string getPortName()
{
    return portName;
}

/////////////////////////////////////////////////////////////////////////////
public void setPortType(string type)
{
    if (member(({ "coastal", "river", "inland", "capital" }), type) > -1)
    {
        portType = type;
    }
}

/////////////////////////////////////////////////////////////////////////////
public string getPortType()
{
    return portType;
}

/////////////////////////////////////////////////////////////////////////////
public void addSpecialty(string itemType, float priceModifier)
{
    specialties[itemType] = priceModifier;
}

/////////////////////////////////////////////////////////////////////////////
public void addImportNeed(string itemType, float priceModifier)
{
    imports[itemType] = priceModifier;
}

/////////////////////////////////////////////////////////////////////////////
public void addTradeRoute(string routeType, string destination, int days)
{
    tradeRoutes[destination] = ([
        "type": routeType,
        "days": days,
        "danger": calculateRouteDanger(routeType, days)
    ]);
}

/////////////////////////////////////////////////////////////////////////////
private int calculateRouteDanger(string routeType, int days)
{
    int baseDanger = 5;
    
    switch(routeType)
    {
        case "maritime": 
        {
            baseDanger = 15; 
            break;
        }
        case "overland": 
        {
            baseDanger = 25; 
            break;
        }
        case "river": 
        {
            baseDanger = 10; 
            break;
        }
    }
    
    return baseDanger + (days * 2);
}

/////////////////////////////////////////////////////////////////////////////
public mapping getTradeRoutes()
{
    return tradeRoutes + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public int getItemPrice(string itemBlueprint)
{
    int ret = 0;
    
    // Check if we need to update prices
    if ((time() - lastPriceUpdate) > 3600)
    {
        generatePrices();
    }
    
    if (member(currentPrices, itemBlueprint))
    {
        ret = currentPrices[itemBlueprint];
    }
    else
    {
        // Calculate price for new item
        object item = load_object(itemBlueprint);
        if (item)
        {
            int basePrice = item->query("value");
            float modifier = calculatePriceModifier(item);
            
            currentPrices[itemBlueprint] = to_int(basePrice * modifier);
            ret = currentPrices[itemBlueprint];
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private float calculatePriceModifier(object item)
{
    float modifier = 1.0;
    string itemType = getItemCategory(item);
    
    // Port specialization
    if (member(specialties, itemType))
    {
        modifier *= specialties[itemType];
    }
    
    // Import needs
    if (member(imports, itemType))
    {
        modifier *= imports[itemType];
    }
    
    // Market fluctuations
    if (member(marketModifiers, itemType))
    {
        modifier *= marketModifiers[itemType];
    }
    else
    {
        // Random daily fluctuation
        marketModifiers[itemType] = 0.85 + (random(30) / 100.0);
        modifier *= marketModifiers[itemType];
    }
    
    return modifier;
}

/////////////////////////////////////////////////////////////////////////////
private string getItemCategory(object item)
{
    string ret = "general";
    string type = item->query("type");
    
    // Map item types to trade categories
    switch(type)
    {
        case "weapon": 
        {
            ret = "weapons";
            break;
        }
        case "armor": 
        {
            ret = "armor";
            break;
        }
        case "clothing": 
        {
            ret = "textiles";
            break;
        }
        case "food": 
        {
            ret = "food";
            break;
        }
        case "material": 
        {
            ret = "materials";
            break;
        }
        case "tool": 
        {
            ret = "tools";
            break;
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private void generatePrices()
{
    lastPriceUpdate = time();
    
    // Clear old modifiers
    marketModifiers = ([]);
    
    // Generate random market events
    if (random(20) == 0)
    {
        generateMarketEvent();
    }
}

/////////////////////////////////////////////////////////////////////////////
private void generateMarketEvent()
{
    string *categories = ({ "weapons", "armor", "materials", "food", "textiles", "tools" });
    string affectedCategory = categories[random(sizeof(categories))];
    
    float modifier;
    string eventDesc;
    
    if (random(2))
    {
        // Price increase
        modifier = 1.5 + (random(50) / 100.0); // 150-200% of normal
        eventDesc = sprintf("High demand for %s drives prices up!", affectedCategory);
    }
    else
    {
        // Price decrease  
        modifier = 0.4 + (random(30) / 100.0); // 40-70% of normal
        eventDesc = sprintf("Market surplus of %s causes prices to drop!", affectedCategory);
    }
    
    marketModifiers[affectedCategory] = modifier;
    
    // Notify players in the area using configuration dictionary
    object configDict = getDictionary("configuration");
    string marketNews = configDict->decorate("Market News: ", "success", "quests", "3-bit") +
                       configDict->decorate(eventDesc, "description", "selector", "3-bit");
    
    tell_room(this_object(), sprintf("\n%s\n", marketNews));
}

/////////////////////////////////////////////////////////////////////////////
public int buyFromPlayer(object player, string itemBlueprint, int quantity)
{
    int ret = 0;
    int price = getItemPrice(itemBlueprint);
    int totalCost = price * quantity;
    
    object trader = player->getService("trader");
    if (trader)
    {
        if (trader->getCash() >= totalCost)
        {
            trader->addCash(-totalCost);
            
            // Add to player's vehicle
            mapping vehicle = trader->getVehicle();
            if (!member(vehicle["cargo"], itemBlueprint))
            {
                vehicle["cargo"][itemBlueprint] = 0;
            }
            vehicle["cargo"][itemBlueprint] += quantity;
            
            object configDict = getDictionary("configuration");
            string colorConfig = player->colorConfiguration();
            
            tell_object(player, configDict->decorate(
                sprintf("You purchase %d %s for %d gold.", 
                       quantity, itemBlueprint, totalCost),
                "success", "quests", colorConfig));
            
            // Add trading experience
            trader->addTradingExperience(quantity);
            
            ret = 1;
        }
        else
        {
            object configDict = getDictionary("configuration");
            string colorConfig = player->colorConfiguration();
            
            tell_object(player, configDict->decorate(
                "You don't have enough gold for that purchase.",
                "failure", "selector", colorConfig));
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int sellToPlayer(object player, string itemBlueprint, int quantity)
{
    int ret = 0;
    object trader = player->getService("trader");
    
    if (trader)
    {
        mapping vehicle = trader->getVehicle();
        
        if (member(vehicle["cargo"], itemBlueprint) && 
            vehicle["cargo"][itemBlueprint] >= quantity)
        {
            int price = getItemPrice(itemBlueprint);
            int totalValue = price * quantity;
            
            // Remove from vehicle
            vehicle["cargo"][itemBlueprint] -= quantity;
            if (vehicle["cargo"][itemBlueprint] <= 0)
            {
                m_delete(vehicle["cargo"], itemBlueprint);
            }
            
            trader->addCash(totalValue);
            
            object configDict = getDictionary("configuration");
            string colorConfig = player->colorConfiguration();
            
            tell_object(player, configDict->decorate(
                sprintf("You sell %d %s for %d gold.", 
                       quantity, itemBlueprint, totalValue),
                "success", "quests", colorConfig));
            
            // Add trading experience
            trader->addTradingExperience(quantity);
            
            ret = 1;
        }
        else
        {
            object configDict = getDictionary("configuration");
            string colorConfig = player->colorConfiguration();
            
            tell_object(player, configDict->decorate(
                "You don't have that item to sell.",
                "failure", "selector", colorConfig));
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private void generateContracts()
{
    contracts = ([]);
    
    // Generate random trading contracts
    for (int i = 0; i < 3; i++)
    {
        string contractId = sprintf("contract_%d", i);
        contracts[contractId] = generateRandomContract();
    }
}

/////////////////////////////////////////////////////////////////////////////
private mapping generateRandomContract()
{
    string *itemTypes = ({ "materials", "weapons", "food", "textiles", "spices" });
    string itemType = itemTypes[random(sizeof(itemTypes))];
    
    int quantity = 10 + random(50);
    int baseReward = quantity * 100;
    int deadline = time() + (86400 * (7 + random(14))); // 1-3 weeks
    
    string *destinations = m_indices(tradeRoutes);
    string destination = sizeof(destinations) ? 
                        destinations[random(sizeof(destinations))] : "eledhel";
    
    return ([
        "item_type": itemType,
        "quantity": quantity,
        "destination": destination,
        "reward": baseReward,
        "deadline": deadline,
        "description": sprintf("Deliver %d units of %s to %s", 
                              quantity, itemType, destination)
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public mapping getContracts()
{
    // Refresh contracts weekly
    if (random(7) == 0)
    {
        generateContracts();
    }
    return contracts + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public int isPort()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public void adjustMarketPrices(string category, float modifier, int duration)
{
    marketModifiers[category] = modifier;
    call_out("clearMarketModifier", duration, category);
}

/////////////////////////////////////////////////////////////////////////////
private void clearMarketModifier(string category)
{
    if (member(marketModifiers, category))
    {
        m_delete(marketModifiers, category);
    }
}
