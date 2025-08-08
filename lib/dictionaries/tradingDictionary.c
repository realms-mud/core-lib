//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/thing.c";

// Common trading items available across all ports
private mapping tradingItems = ([
    "metal": ({
        "/lib/instances/items/materials/metal/",
        "/lib/instances/items/materials/metal-ores/",
    }),
    "wood" : ({
        "/lib/instances/items/materials/wood/",
    }),
    "clay": ({
        "/lib/instances/items/materials/clay/",
    }),
    "stone": ({
        "/lib/instances/items/materials/stone/",
    }),
    "leather": ({
        "/lib/instances/items/materials/leather/",
    }),
    "textile": ({
        "/lib/instances/items/materials/textile/",
    }),
    "trophy materials": ({
        "/lib/instances/items/materials/plumage/",
        "/lib/instances/items/materials/skeletal/",
    }),
    "food": ({
        "/lib/instances/items/food/bread/",
        "/lib/instances/items/food/plants/fruit/",
        "/lib/instances/items/food/plants/grains/",
        "/lib/instances/items/food/plants/greens/",
        "/lib/instances/items/food/plants/legumes/",
        "/lib/instances/items/food/plants/nuts/",
        "/lib/instances/items/food/plants/roots/",
        "/lib/instances/items/food/plants/stems/",
    }),
    "spices": ({
        "/lib/instances/items/food/plants/herbs/",
        "/lib/instances/items/food/plants/fruit/black-peppercorn.c",
        "/lib/instances/items/food/plants/fruit/long-pepper.c",
        "/lib/instances/items/food/plants/fruit/cayenne-pepper.c",
        "/lib/instances/items/food/plants/fruit/dragon-pepper.c",
        "/lib/instances/items/food/plants/fruit/serrano-pepper.c",
        "/lib/instances/items/food/plants/fruit/red-chili-pepper.c",
        "/lib/instances/items/food/plants/fruit/green-chili-pepper.c",
        "/lib/instances/items/food/plants/fruit/tabasco-pepper.c",
        "/lib/instances/items/food/plants/fruit/jalapeno-pepper.c",
        "/lib/instances/items/food/plants/fruit/habanero-pepper.c",
        "/lib/instances/items/food/plants/fruit/birds-eye-chili.c",
        "/lib/instances/items/food/salt.c",
        "/lib/instances/items/food/plants/roots/black-garlic.c",
        "/lib/instances/items/food/plants/roots/ginger.c",
        "/lib/instances/items/food/plants/roots/garlic.c",
        "/lib/instances/items/food/plants/roots/red-garlic.c",
        "/lib/instances/items/food/plants/roots/silverskin-garlic.c",
        "/lib/instances/items/food/plants/roots/wild-garlic.c",
    }),
    "weapons": ({
        "/lib/instances/items/weapons/swords/",
        "/lib/instances/items/weapons/axes/",
        "/lib/instances/items/weapons/bows/",
        "/lib/instances/items/weapons/staffs/",
        "/lib/instances/items/weapons/daggers/",
        "/lib/instances/items/weapons/maces/",
        "/lib/instances/items/weapons/pole-arms/",
        "/lib/instances/items/weapons/thrown/",
        "/lib/instances/items/weapons/slings/",
        "/lib/instances/items/weapons/hammers/",
        "/lib/instances/items/weapons/shields/",
        "/lib/instances/items/weapons/crossbows/",
        "/lib/instances/items/weapons/ammunition/",
        "/lib/instances/items/weapons/flails/",
    }),
    "armor": ({
        "/lib/instances/items/armor/light-armor/",
        "/lib/instances/items/armor/medium-armor/",
        "/lib/instances/items/armor/heavy-armor/",
        "/lib/instances/items/armor/accessories/coif.c",
        "/lib/instances/items/armor/accessories/helmet.c",
        "/lib/instances/items/armor/accessories/gauntlets.c",
        "/lib/instances/items/armor/accessories/sabaton.c",
        "/lib/instances/items/armor/accessories/helm.c",
    }),
    "crystals": ({
        "/lib/instances/items/materials/crystal/",
    }),
    "jewelry": ({
        "/lib/instances/items/armor/accessories/amulet.c",
        "/lib/instances/items/armor/accessories/ring.c",
        "/lib/instances/items/armor/accessories/bracers.c",
        "/lib/instances/items/armor/accessories/circlet.c",
        "/lib/instances/items/armor/accessories/necklace.c",
        "/lib/instances/items/armor/accessories/tiara.c",
        "/lib/instances/items/armor/accessories/crown.c",
        "/lib/instances/items/armor/accessories/diadem.c",
    }),
    "clothing": ({
        "/lib/instances/items/armor/clothing/",
        "/lib/instances/items/armor/accessories/belt.c",
        "/lib/instances/items/armor/accessories/boots.c",
        "/lib/instances/items/armor/accessories/gloves.c",
        "/lib/instances/items/armor/accessories/hat.c",
        "/lib/instances/items/armor/accessories/sandals.c",
        "/lib/instances/items/armor/accessories/sash.c",
        "/lib/instances/items/armor/accessories/shoes.c",
    }),
    "potions": ({
        "/lib/instances/items/potions/",
    }),
    "musical instruments": ({
        "/lib/instances/items/instruments/brass/",
        "/lib/instances/items/instruments/woodwind/",
        "/lib/instances/items/instruments/strings/",
        "/lib/instances/items/instruments/percussion/",
    }),
    "beer": ({
        "/lib/instances/items/drinks/beer/",
    }),
    "books": ({
        "/lib/instances/items/books/",
    }),
]);

private mapping ports = ([ ]);

/////////////////////////////////////////////////////////////////////////////
public nomask void registerPort(object port)
{
    if (port && objectp(port) && port->isPort())
    {
        if (!member(ports, port->getPortName()) && (port->getPortName() != "Unknown Port"))
        {
            ports[port->getPortName()] = port;
        }
    }
    else
    {
        raise_error(sprintf("tradingDictionary.c: Invalid port object (%O).\n", 
            port));
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getPort(string portName)
{
    object ret = 0;
    if (member(ports, portName) && objectp(ports[portName]))
    {
        ret = ports[portName];
    }
    else
    {
        m_delete(ports, portName);
        raise_error(sprintf("tradingDictionary.c: Port '%s' is not registered.\n", portName));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public object *getAvailablePorts()
{
    object *result = ({});
    string *portNames = m_indices(ports);

    foreach (string portName in portNames)
    {
        object port = ports[portName];
        if (objectp(port))
        {
            result += ({ port });
        }
        else
        {
            m_delete(ports, portName);
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void create()
{
    if (!sizeof(ports))
    {
        string *portFiles = 
            get_dir("/lib/modules/domains/trading/ports/*.c", 0x10) -
                ({ "/lib/modules/domains/trading/ports/.", 
                    "/lib/modules/domains/trading/ports/.." });

        if (sizeof(portFiles))
        {
            foreach(string portFile in portFiles)
            {
                object port = load_object(portFile);
                if (port && objectp(port) && port->isPort())
                {
                    registerPort(port);
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public string *getTradingTypes()
{
    return m_indices(tradingItems);
}

/////////////////////////////////////////////////////////////////////////////
public string *getItemListForType(string itemType)
{
    string *items = ({});
    
    if (member(tradingItems, itemType))
    {
        foreach(string itemPath in tradingItems[itemType])
        {
            if (sizeof(regexp(({ itemPath }), "^.*[.]c$")) &&
                (file_size(itemPath) > 0))
            {
                items += ({ itemPath });
            }
            else
            {
                items += get_dir(itemPath + "*.c", 0x10);
            }
        }
    }
    else
    {
        raise_error(sprintf("tradingDictionary.c: Invalid trading type '%s'.\n", itemType));
    }
    return items;
}

/////////////////////////////////////////////////////////////////////////////
public string *getAllTradingItems()
{
    string *allItems = ({});
    string *types = getTradingTypes();
    foreach(string type in types)
    {
        allItems += getItemListForType(type);
    }
    return allItems;
}

/////////////////////////////////////////////////////////////////////////////
public int isValidTradingItem(mixed items)
{
    string *allItems = getAllTradingItems();
    int ret = 0;

    if (stringp(items))
    {
        ret = (member(allItems, items) != -1);
    }
    else if (pointerp(items) && sizeof(items) && stringp(items[0]))
    {
        ret = !sizeof(filter(items, (: member(allItems, $1) == -1 :)));
    }
    else if (pointerp(items) && sizeof(items) && objectp(items[0]))
    {
        items = map(items, (: object_name($1) :));
        ret = !sizeof(filter(items, (: member(allItems, sprintf("%s.c", $1)) == -1 :)));
    }

    return ret;
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
    
    string *commonTradingItems = getAllTradingItems();
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
        string *commonTradingItems = getAllTradingItems();
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
        int counter = 1;
        object *vehicles = ({});
        if (function_exists("getVehicles", trader))
        {
            vehicles = trader->getVehicles();
        }
        foreach (object vehicle in vehicles)
        {
            if (objectp(vehicle) && function_exists("getCargo", vehicle))
            {
                mapping vehicleCargo = vehicle->getCargo();
                if (mappingp(vehicleCargo) && sizeof(vehicleCargo))
                {
                    string *items = m_indices(vehicleCargo);
                    foreach (string item in items)
                    {
                        object itemObj = load_object(item);
                        if (itemObj)
                        {
                            int price = port->getItemPrice(item);
                            int quantity = vehicleCargo[item];

                            // Aggregate quantities if item is in multiple vehicles
                            if (member(cargo, item))
                            {
                                cargo[item]["quantity"] += quantity;
                                cargo[item]["total value"] += price * quantity;
                            }
                            else
                            {
                                cargo[item] = ([
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
            }
        }
    }

    mapping indexedCargo = ([]);
    int idx = 1;
    foreach (string item in m_indices(cargo))
    {
        indexedCargo[to_string(idx++)] = cargo[item];
    }

    return indexedCargo;
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
        string *commonTradingItems = getAllTradingItems();
        ret = (member(commonTradingItems, itemPath) > -1);
        
        if (!ret)
        {
            if (file_size(itemPath) > 0)
            {
                object itemObj = load_object(itemPath);
                ret = (itemObj && itemObj->query("value") > 0);
            }
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

/////////////////////////////////////////////////////////////////////////////
public nomask int getMaximumLoan(object user)
{
    int maxLoan = 0;

    if (objectp(user))
    {
        int currentDebt = user->getDebt();
        int cashOnHand = user->getCash();
        int bankBalance = user->getBank();

        maxLoan = (cashOnHand + bankBalance) * 2;

        if (maxLoan < 1000)
        {
            maxLoan = 1000; // Minimum loan amount
        }
        else if (maxLoan > 1000000)
        {
            maxLoan = 1000000; // Cap loan amount to prevent excessive borrowing
        }
        maxLoan -= currentDebt;
        if (maxLoan < 0)
        {
            maxLoan = 0;
        }
    }
    return maxLoan;
}

/////////////////////////////////////////////////////////////////////////////
public mapping queryAvailableContracts(object user)
{
    mapping contracts = ([]);
    object *allPorts = getAvailablePorts();

    foreach (object port in allPorts)
    {
        if (objectp(port) && function_exists("queryAvailableContracts", port))
        {
            mapping portContracts = port->queryAvailableContracts(user);
            if (mappingp(portContracts) && sizeof(portContracts))
            {
                foreach (string id in m_indices(portContracts))
                {
                    contracts[id] = portContracts[id];
                }
            }
        }
    }
    return contracts;
}

///////////////////////////////////////////////////////////////////////////////
public int acceptContract(object user, string portName, string contractId)
{
    int result = 0;
    object port = getPort(portName);

    if (objectp(user) && objectp(port) && function_exists("acceptContract", port))
    {
        mapping available = port->queryAvailableContracts(user);
        if (member(available, contractId))
        {
            // Mark as accepted in the port
            int portAccepted = port->acceptContract(user->RealName(), contractId);

            // Add to user's active contracts
            int userAccepted = user->acceptContract(contractId, available[contractId]);

            // Only succeed if both succeed
            if (portAccepted && userAccepted)
            {
                result = 1;
            }
            else
            {
                user->removeActiveContract(contractId);
                port->revokeContract(user->RealName(), contractId);
            }
        }
    }
    return result;
}

///////////////////////////////////////////////////////////////////////////////
public nomask int calculateContractProgress(object player, mapping contract)
{
    int total = 0;
    if (objectp(player) && mappingp(contract))
    {
        string itemType = contract["item type"];
        string *itemPaths = getItemListForType(itemType);
        if (sizeof(itemPaths))
        {
            object *vehicles = player->getVehicles();
            foreach (object vehicle in vehicles)
            {
                if (objectp(vehicle) && function_exists("getCargo", vehicle))
                {
                    mapping cargo = vehicle->getCargo();
                    if (mappingp(cargo))
                    {
                        foreach (string itemPath in itemPaths)
                        {
                            if (member(cargo, itemPath))
                            {
                                total += cargo[itemPath];
                            }
                        }
                    }
                }
            }
        }
        int needed = contract["quantity"];
        return (needed > 0) ? (total * 100) / needed : 0;
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping generateDeadline(int minutesFromNow)
{
    object environmentDictionary = getDictionary("environment");
    int nowYear = environmentDictionary->currentYear();
    int nowDay = environmentDictionary->currentDay();
    int nowMinute = environmentDictionary->currentTime();

    int totalMinutes = (nowYear * 365 + nowDay) * 1440 + nowMinute + minutesFromNow;

    int year = totalMinutes / (365 * 1440);
    int day = (totalMinutes % (365 * 1440)) / 1440;
    int minute = totalMinutes % 1440;

    return ([ "year": year, "day": day, "minute": minute ]);
}

///////////////////////////////////////////////////////////////////////////////
public nomask int getMinutesUntilDeadline(mapping deadline)
{
    int ret = 0;
    object environmentDictionary = getDictionary("environment");

    int nowYear = environmentDictionary->currentYear();
    int nowDay = environmentDictionary->currentDay();
    int nowMinute = environmentDictionary->currentTime();

    if (mappingp(deadline) &&
        member(deadline, "year") && member(deadline, "day") && member(deadline, "minute"))
    {
        int nowTotal = (nowYear * 365 + nowDay) * 1440 + nowMinute;
        int deadlineTotal = (deadline["year"] * 365 + deadline["day"]) * 1440 + deadline["minute"];
        ret = deadlineTotal - nowTotal;
    }
    else
    {
        raise_error("tradingDictionary.c: Invalid deadline format.\n");
    }
    return ret;
}

///////////////////////////////////////////////////////////////////////////////
public nomask string formatTimeLeft(int minutes)
{
    if (minutes <= 0)
        return "expired";

    int days = minutes / 1440;
    int hours = (minutes % 1440) / 60;
    int mins = minutes % 60;
    string result = "";

    if (days > 0)
        result += sprintf("%d day%s", days, (days == 1) ? "" : "s");
    if (hours > 0)
        result += (result != "" ? ", " : "") + sprintf("%d hour%s", hours, (hours == 1) ? "" : "s");
    if (mins > 0 && days == 0)
        result += (result != "" ? ", " : "") + sprintf("%d minute%s", mins, (mins == 1) ? "" : "s");
    if (result == "")
        result = "less than a minute";
    return result;
}
