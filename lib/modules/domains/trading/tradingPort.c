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
private int SetupCompleted = 0;

// Available trade routes
private mapping tradeRoutes = ([]);
private mapping contracts = ([]);
private string *availableGoods = ({});
private mapping acceptedContracts = ([]);

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
private mapping generateRandomContract()
{
    string *itemTypes = ({ "materials", "weapons", "food", "textiles", "spices" });
    string itemType = itemTypes[random(sizeof(itemTypes))];
    
    int quantity = 10 + random(50);
    int baseReward = quantity * 100;
    
    string *destinations = m_indices(tradeRoutes);
    string destination = sizeof(destinations) ? 
                        destinations[random(sizeof(destinations))] : "eledhel";
    
    return ([
        "item type": itemType,
        "quantity": quantity,
        "destination": destination,
        "reward": baseReward,
        "deadline": getDictionary("trading")->generateDeadline(
            (7 + random(14)) * 1440),
        "description": sprintf("Deliver %d units of %s to %s", 
                              quantity, itemType, capitalize(destination))
    ]);
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
public void addContract(string id, mapping contract)
{
    if (stringp(id) && mappingp(contract))
    {
        contracts[id] = contract;
    }
}

/////////////////////////////////////////////////////////////////////////////
public void clearContracts()
{
    contracts = ([]);
}

/////////////////////////////////////////////////////////////////////////////
public int acceptContract(string userId, string contractId)
{
    int ret = 0;
    if (!member(acceptedContracts, userId))
    {
        acceptedContracts[userId] = ({});
    }

    if (member(contracts, contractId) && 
        (member(acceptedContracts[userId], contractId) == -1))
    {
        acceptedContracts[userId] += ({ contractId });
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int revokeContract(string userId, string contractId)
{
    int ret = 0;
    if (member(acceptedContracts, userId))
    {
        if (member(acceptedContracts[userId], contractId) > -1)
        {
            acceptedContracts[userId] -= ({ contractId });
            ret = 1;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int hasAcceptedContract(string userId, string contractId)
{
    return member(acceptedContracts, userId) && (member(acceptedContracts[userId], contractId) > -1);
}

/////////////////////////////////////////////////////////////////////////////
public mapping queryAvailableContracts(object user)
{
    string userId = user ? user->RealName() : 0;
    mapping result = ([]);
    foreach (string id in m_indices(contracts))
    {
        if (!userId || !hasAcceptedContract(userId, id))
        {
            result[id] = contracts[id] + ([]);
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
private int canDeliverContract(object user, string contractId)
{
    return objectp(user) && 
        stringp(contractId) &&
        hasAcceptedContract(user->RealName(), contractId) &&
        member(contracts, contractId) &&
        mappingp(contracts[contractId]) && 
        user->has("trader");
}

/////////////////////////////////////////////////////////////////////////////
public int deliverContract(object user, string contractId)
{
    int delivered = 0;

    string userId = user->RealName();
    object vehicle = user->getVehicleForTradeRun(contractId);

    if (canDeliverContract(user, contractId) && stringp(userId) &&
        objectp(vehicle))
    {
        mapping contract = contracts[contractId];

        int requiredAmount = contract["quantity"];
        int alreadyDelivered = member(contract, "delivered") ? contract["delivered"] : 0;
        int remaining = requiredAmount - alreadyDelivered;

        if (remaining > 0)
        {
            object tradingDict = getDictionary("trading");
            string itemType = contract["item type"];
            string *validBlueprints = user->getItemListForType(itemType);

            int available = 0;
            mapping blueprintQuantities = ([]);

            foreach (string blueprint in validBlueprints)
            {
                int qty = vehicle->getCargoQuantity(blueprint);
                if (qty > 0)
                {
                    blueprintQuantities[blueprint] = qty;
                    available += qty;
                }
            }

            if (available > 0)
            {
                int toDeliver = (available < remaining) ? available : remaining;
                int leftToRemove = toDeliver;

                foreach (string blueprint in m_indices(blueprintQuantities))
                {
                    int qty = blueprintQuantities[blueprint];
                    int removeQty = (qty < leftToRemove) ? qty : leftToRemove;

                    if (removeQty > 0 && function_exists("removeCargo", vehicle))
                    {
                        vehicle->removeCargo(blueprint, removeQty);
                        leftToRemove -= removeQty;
                    }
                    if (leftToRemove <= 0)
                    {
                        break;
                    }
                }

                delivered = toDeliver;
                mapping userContracts = user->getActiveContracts();

                if (member(userContracts, contractId))
                {
                    if (!member(userContracts[contractId], "delivered"))
                    {
                        userContracts[contractId]["delivered"] = 0;
                    }
                    userContracts[contractId]["delivered"] += delivered;
                    user->setActiveContract(contractId, userContracts[contractId]);
                }

                if (!member(contract, "delivered"))
                {
                    contract["delivered"] = 0;
                }
                contract["delivered"] += delivered;
                contracts[contractId] = contract;
            }
        }
    }
    return delivered;
}

/////////////////////////////////////////////////////////////////////////////
private void clearMarketModifier(string category)
{
    if (member(marketModifiers, category))
    {
        m_delete(marketModifiers, category);
    }
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
public string *getSpecialties()
{
    return m_indices(specialties) + ({});
}

/////////////////////////////////////////////////////////////////////////////
public void addImportNeed(string itemType, float priceModifier)
{
    imports[itemType] = priceModifier;
}

/////////////////////////////////////////////////////////////////////////////
public string *getImportNeeds()
{
    return m_indices(imports) + ({});
}

/////////////////////////////////////////////////////////////////////////////
public void setAvailableGoods(string *goods)
{
    if (pointerp(goods)) {
        availableGoods = goods;
    }
}

/////////////////////////////////////////////////////////////////////////////
public string *getAvailableGoods()
{
    return availableGoods + ({});
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
public mapping getTradeRoutes()
{
    return tradeRoutes + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public float getItemPrice(string itemBlueprint)
{
    float ret = 0;
    
    if (!sizeof(availableGoods) || 
        (member(availableGoods, itemBlueprint) > -1))
    {
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
                float basePrice = item->query("value") * 100;
                float modifier = calculatePriceModifier(item);
            
                currentPrices[itemBlueprint] = to_int(basePrice * modifier);
                ret = currentPrices[itemBlueprint];
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int buyFromPlayer(object player, string itemBlueprint, int quantity)
{
    int ret = 0;
    float price = getItemPrice(itemBlueprint);
    int totalCost = to_int(price * quantity);
    
    object trader = player->getModule("trader");
    if (trader)
    {
        if (trader->getCash() >= totalCost)
        {
            trader->addCash(-totalCost);
            
            // Add to player's vehicle using proper accessor
            trader->addCargoToVehicle(itemBlueprint, quantity);
            
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
    object trader = player->getModule("trader");
    
    if (trader)
    {
        if (trader->getCargoQuantity(itemBlueprint) >= quantity)
        {
            float price = getItemPrice(itemBlueprint);
            int totalValue = to_int(price * quantity);
            
            // Remove from vehicle using proper accessor
            trader->removeCargoFromVehicle(itemBlueprint, quantity);
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
public nomask void reset()
{
    ::reset();
    generatePrices();
    generateContracts();
}

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    object tradingDictionary = getDictionary("trading");
    if (tradingDictionary && (portName != "Unknown Port"))
    {
        tradingDictionary->registerPort(this_object());
    }
}
