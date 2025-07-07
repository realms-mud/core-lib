//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/thing.c";

// Common trading items available across all ports
private string *commonTradingItems = ({
    "/lib/instances/items/materials/metal/iron",
    "/lib/instances/items/materials/wood/oak", 
    "/lib/instances/items/weapons/swords/long-sword",
    "/lib/instances/items/food/bread/wheat-bread",
    "/lib/instances/items/food/plants/fruit/black-peppercorn",
    "/lib/instances/items/materials/crystal/diamond",
    "/lib/instances/items/materials/textile/silk",
});

/////////////////////////////////////////////////////////////////////////////
public string *getCommonTradingItems()
{
    return commonTradingItems + ({});
}

/////////////////////////////////////////////////////////////////////////////
public string getTradingHelpDisplay(object player)
{
    string ret = "";
    string colorConfiguration = player->colorConfiguration();
    string charset = player->charsetConfiguration();
    
    object commandsDict = getDictionary("commands");
    object configDict = getDictionary("configuration");
    
    ret = commandsDict->buildBanner(colorConfiguration, charset, "top", "Trading Commands");
    
    ret += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("trade", "selector menu name", "selector", colorConfiguration) +
        configDict->decorate(" - Enter the trading subsystem", "selector description", "selector", colorConfiguration));
    
    ret += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("prices", "selector menu name", "selector", colorConfiguration) +
        configDict->decorate(" - View current market prices", "selector description", "selector", colorConfiguration));
    
    ret += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("contracts", "selector menu name", "selector", colorConfiguration) +
        configDict->decorate(" - View available trading contracts", "selector description", "selector", colorConfiguration));
    
    ret += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("travel", "selector menu name", "selector", colorConfiguration) +
        configDict->decorate(" - View/initiate travel to other ports", "selector description", "selector", colorConfiguration));
    
    ret += commandsDict->banneredContent(colorConfiguration, charset,
        configDict->decorate("warehouse", "selector menu name", "selector", colorConfiguration) +
        configDict->decorate(" - Manage your warehouse inventory", "selector description", "selector", colorConfiguration));
    
    ret += commandsDict->buildBanner(colorConfiguration, charset, "bottom", "-");
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string getMarketPricesDisplay(object player, object port)
{
    string ret = "";
    string colorConfiguration = player->colorConfiguration();
    string charset = player->charsetConfiguration();
    
    object commandsDict = getDictionary("commands");
    object configDict = getDictionary("configuration");
    
    ret = commandsDict->buildBanner(colorConfiguration, charset, "top", 
                         sprintf("%s Market Prices", port->getPortName()));
    
    foreach(string item in commonTradingItems)
    {
        int price = port->getItemPrice(item);
        object itemObj = load_object(item);
        
        if (itemObj)
        {
            string itemLine = configDict->decorate(sprintf("%-25s: ", itemObj->query("name")),
                             "selector field header", "selector", colorConfiguration) +
                             configDict->decorate(sprintf("%d gold", price),
                             "selector field data", "selector", colorConfiguration);
            
            ret += commandsDict->banneredContent(colorConfiguration, charset, itemLine);
        }
    }
    
    ret += commandsDict->banneredContent(colorConfiguration, charset,
                   configDict->decorate("Use 'trade' to enter the trading subsystem.",
                   "selector instructions", "selector", colorConfiguration));
    
    ret += commandsDict->buildBanner(colorConfiguration, charset, "bottom", "-");
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public mapping getAvailableGoods(object port, object trader)
{
    mapping goods = ([]);
    
    if (port && port->isPort())
    {
        int counter = 1;
        foreach(string item in commonTradingItems)
        {
            object itemObj;
            string err = catch (itemObj = load_object(item); nolog);

            if (!err && itemObj)
            {
                int price = port->getItemPrice(item);
                int canAfford = trader->getCash() / price;
                
                goods[to_string(counter++)] = ([
                    "name": sprintf("%s (%d gold)", itemObj->query("name"), price),
                    "item path": item,
                    "price": price,
                    "can afford": canAfford,
                    "canShow": (canAfford > 0)
                ]);
            }
        }
    }
    
    return goods;
}

/////////////////////////////////////////////////////////////////////////////
public mapping getCargoForSale(object trader, object port)
{
    mapping cargo = ([]);
    
    if (trader && port && port->isPort())
    {
        mapping vehicle = trader->getVehicle();
        mapping vehicleCargo = vehicle["cargo"];
        
        if (sizeof(vehicleCargo))
        {
            int counter = 1;
            string *items = m_indices(vehicleCargo);
            foreach(string item in items)
            {
                object itemObj = load_object(item);
                if (itemObj)
                {
                    int price = port->getItemPrice(item);
                    int quantity = vehicleCargo[item];
                    
                    cargo[to_string(counter++)] = ([
                        "name": sprintf("%s x%d (%d gold each)", 
                                       itemObj->query("name"), quantity, price),
                        "item path": item,
                        "price": price,
                        "quantity": quantity,
                        "total value": price * quantity,
                        "canShow": 1
                    ]);
                }
            }
        }
    }
    
    return cargo;
}

/////////////////////////////////////////////////////////////////////////////
public string getItemPathForType(string itemType)
{
    string ret = "/lib/instances/items/materials/metal/iron";
    
    // Map item types to actual item paths for contracts
    switch(itemType)
    {
        case "materials": 
        {
            ret = "/lib/instances/items/materials/metal/iron";
            break;
        }
        case "weapons": 
        {
            ret = "/lib/instances/items/weapons/swords/long-sword";
            break;
        }
        case "food": 
        {
            ret = "/lib/instances/items/food/bread";
            break;
        }
        case "textiles": 
        {
            ret = "/lib/instances/items/materials/textile/silk";
            break;
        }
        case "spices": 
        {
            ret = "/lib/instances/items/materials/spice/pepper";
            break;
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int calculateWarehouseUsed(mapping warehouse)
{
    int used = 0;
    
    if (mappingp(warehouse) && mappingp(warehouse["inventory"]))
    {
        string *items = m_indices(warehouse["inventory"]);
        foreach(string item in items)
        {
            used += warehouse["inventory"][item];
        }
    }
    
    return used;
}

/////////////////////////////////////////////////////////////////////////////
public mapping getItemCategories()
{
    return ([
        "materials": "Raw materials and components",
        "weapons": "Arms and armaments",
        "food": "Consumable foodstuffs",
        "textiles": "Cloth and fabric goods",
        "spices": "Exotic spices and seasonings",
        "tools": "Crafting and utility tools"
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public string formatTradingMessage(string message, string messageType, object player)
{
    string ret = message;
    object configDict = getDictionary("configuration");
    string colorConfiguration = player->colorConfiguration();
    
    switch(messageType)
    {
        case "success":
        {
            ret = configDict->decorate(message, "success", "quests", colorConfiguration);
            break;
        }
        case "failure":
        {
            ret = configDict->decorate(message, "failure", "selector", colorConfiguration);
            break;
        }
        case "warning":
        {
            ret = configDict->decorate(message, "warning", "selector", colorConfiguration);
            break;
        }
        case "info":
        {
            ret = configDict->decorate(message, "description", "selector", colorConfiguration);
            break;
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int isValidTradeItem(string itemPath)
{
    int ret = 0;
    
    if (itemPath && stringp(itemPath))
    {
        ret = (member(commonTradingItems, itemPath) > -1);
        
        if (!ret)
        {
            object itemObj = load_object(itemPath);
            ret = (itemObj && itemObj->query("value") > 0);
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public mapping getTradeRouteTypes()
{
    return ([
        "maritime": ([
            "description": "Travel by sea using ships",
            "base danger": 15,
            "weather factor": 1.2,
            "capacity bonus": 1.5
        ]),
        "overland": ([
            "description": "Travel by land using wagons", 
            "base danger": 25,
            "weather factor": 1.0,
            "capacity bonus": 1.0
        ]),
        "river": ([
            "description": "Travel by river using barges",
            "base danger": 10,
            "weather factor": 0.8,
            "capacity bonus": 1.3
        ])
    ]);
}
