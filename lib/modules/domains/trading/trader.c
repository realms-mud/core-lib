//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/thing.c";

// Trading company data
private mapping tradingCompany = ([]);
private mapping currentVehicle = ([]);
private string currentLocation = "eledhel";
private int tradingExperience = 0;
private int lastInterestCalculation = 0;

/////////////////////////////////////////////////////////////////////////////
private void initializeFactions()
{
    // Initialize trading-specific factions
    string *factions = ({ 
        "merchants guild", "port authorities", "caravan masters", 
        "local nobility", "brigands", "pirates" 
    });
    
    object factionService = getService("factions");
    if (factionService)
    {
        foreach(string faction in factions)
        {
            factionService->updateFactionDisposition(faction, 0); // Start neutral
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private void initializeWarehouse(string location)
{
    if (!member(tradingCompany["warehouses"], location))
    {
        tradingCompany["warehouses"][location] = ([
            "capacity": 10000,
            "inventory": ([]),
            "rent paid": time() + 2592000 // 30 days
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
private void calculateInterest()
{
    object envDict = getDictionary("environment");
    int currentDay = envDict->currentDay();
    
    // Calculate interest every 30 days (approximately monthly)
    int daysPassed = currentDay - lastInterestCalculation;
    if (daysPassed >= 30)
    {
        int monthsPassed = daysPassed / 30;
        
        // Apply compound interest for each month
        for (int i = 0; i < monthsPassed; i++)
        {
            tradingCompany["debt"] = to_int(tradingCompany["debt"] * 1.1); // 10% monthly
            tradingCompany["bank"] = to_int(tradingCompany["bank"] * 1.005); // 0.5% monthly
        }
        
        lastInterestCalculation = currentDay - (daysPassed % 30);
    }
}

/////////////////////////////////////////////////////////////////////////////
public void initializeTrader()
{
    if (!sizeof(tradingCompany))
    {
        tradingCompany = ([
            "firm name": "",
            "cash": 0,
            "bank": 0,
            "debt": 0,
            "reputation": 0,
            "license level": 1,
            "warehouses": ([]),
            "vehicles": ({}),
            "active contracts": ([])
        ]);
        
        // Initialize starting vehicle
        currentVehicle = ([
            "type": "wagon",
            "capacity": 60,
            "damage": 0,
            "protection": 0,
            "cargo": ([]),
            "location": currentLocation
        ]);
        
        initializeFactions();
        initializeWarehouse(currentLocation);
        
        // Initialize interest calculation tracking
        object envDict = getDictionary("environment");
        lastInterestCalculation = envDict->currentDay();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void setFirmName(string name)
{
    if (name && stringp(name) && sizeof(name) > 0)
    {
        tradingCompany["firm name"] = name[0..22]; // Limit like Taipan
    }
}

/////////////////////////////////////////////////////////////////////////////
public string getFirmName()
{
    return (tradingCompany["firm name"] != "") ?
        tradingCompany["firm name"] : "Unnamed Trading Company";
}

/////////////////////////////////////////////////////////////////////////////
public void setupStartingChoice(int choice)
{
    switch(choice)
    {
        case 1: // Cash and debt (like Taipan option 1)
        {
            tradingCompany["cash"] = 400;
            tradingCompany["debt"] = 5000;
            currentVehicle["capacity"] = 60;
            currentVehicle["protection"] = 0;
            break;
        }
        case 2: // Protection and no cash (like Taipan option 2)  
        {
            tradingCompany["cash"] = 0;
            tradingCompany["debt"] = 0;
            currentVehicle["capacity"] = 10;
            currentVehicle["protection"] = 5;
            break;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public int getCash()
{
    // Apply interest if enough time has passed
    calculateInterest();
    return tradingCompany["cash"];
}

/////////////////////////////////////////////////////////////////////////////
public int addCash(int amount)
{
    int ret = 0;
    
    if (intp(amount))
    {
        tradingCompany["cash"] += amount;
        if (tradingCompany["cash"] < 0)
        {
            tradingCompany["cash"] = 0;
        }
        ret = tradingCompany["cash"];
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int getBank()
{
    // Apply interest if enough time has passed
    calculateInterest();
    return tradingCompany["bank"];
}

/////////////////////////////////////////////////////////////////////////////
public int getDebt()
{
    // Apply interest if enough time has passed
    calculateInterest();
    return tradingCompany["debt"];
}

/////////////////////////////////////////////////////////////////////////////
public int depositMoney(int amount)
{
    int ret = 0;
    
    if (amount > 0 && amount <= tradingCompany["cash"])
    {
        tradingCompany["cash"] -= amount;
        tradingCompany["bank"] += amount;
        ret = 1;
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int withdrawMoney(int amount)
{
    int ret = 0;
    
    if (amount > 0 && amount <= tradingCompany["bank"])
    {
        tradingCompany["bank"] -= amount;
        tradingCompany["cash"] += amount;
        ret = 1;
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int borrowMoney(int amount)
{
    int ret = 0;
    // Can borrow up to 2x current cash
    int maxLoan = tradingCompany["cash"] * 2;
    
    if (amount > 0 && amount <= maxLoan)
    {
        tradingCompany["cash"] += amount;
        tradingCompany["debt"] += amount;
        ret = 1;
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int repayDebt(int amount)
{
    int ret = 0;
    
    if (amount > 0 && amount <= tradingCompany["cash"] && 
        amount <= tradingCompany["debt"])
    {
        tradingCompany["cash"] -= amount;
        tradingCompany["debt"] -= amount;
        ret = 1;
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int getVehicleCapacity()
{
    return currentVehicle["capacity"];
}

/////////////////////////////////////////////////////////////////////////////
public int getVehicleUsedSpace()
{
    int used = 0;
    mapping cargo = currentVehicle["cargo"];
    
    if (mappingp(cargo))
    {
        string *items = m_indices(cargo);
        foreach(string item in items)
        {
            used += cargo[item];
        }
    }
    
    return used;
}

/////////////////////////////////////////////////////////////////////////////
public int getVehicleFreeSpace()
{
    return getVehicleCapacity() - getVehicleUsedSpace();
}

/////////////////////////////////////////////////////////////////////////////
public int addCargoToVehicle(string item, int quantity)
{
    int ret = 0;
    
    if (item && stringp(item) && quantity > 0)
    {
        if (getVehicleFreeSpace() >= quantity)
        {
            if (!member(currentVehicle["cargo"], item))
            {
                currentVehicle["cargo"][item] = 0;
            }
            currentVehicle["cargo"][item] += quantity;
            ret = 1;
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int removeCargoFromVehicle(string item, int quantity)
{
    int ret = 0;
    
    if (item && stringp(item) && quantity > 0)
    {
        if (member(currentVehicle["cargo"], item) && 
            currentVehicle["cargo"][item] >= quantity)
        {
            currentVehicle["cargo"][item] -= quantity;
            if (currentVehicle["cargo"][item] <= 0)
            {
                m_delete(currentVehicle["cargo"], item);
            }
            ret = 1;
        }
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int getCargoQuantity(string item)
{
    int ret = 0;
    
    if (item && stringp(item) && member(currentVehicle["cargo"], item))
    {
        ret = currentVehicle["cargo"][item];
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public mapping getVehicle()
{
    return currentVehicle + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public mapping getWarehouse(string location)
{
    if (!location) 
    {
        location = currentLocation;
    }
    
    if (!member(tradingCompany["warehouses"], location))
    {
        initializeWarehouse(location);
    }
    
    return tradingCompany["warehouses"][location] + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public int storeInWarehouse(string item, int quantity, string location)
{
    int ret = 0;
    
    if (!location) 
    {
        location = currentLocation;
    }
    
    mapping warehouse = getWarehouse(location);
    
    int currentStored = 0;
    if (member(warehouse["inventory"], item))
    {
        currentStored = warehouse["inventory"][item];
    }
    
    if ((currentStored + quantity) <= warehouse["capacity"])
    {
        if (!member(warehouse["inventory"], item))
        {
            warehouse["inventory"][item] = 0;
        }
        warehouse["inventory"][item] += quantity;
        tradingCompany["warehouses"][location] = warehouse;
        ret = 1;
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int loadFromWarehouse(string item, int quantity, string location)
{
    int ret = 0;
    
    if (!location) 
    {
        location = currentLocation;
    }
    
    mapping warehouse = getWarehouse(location);
    
    if (member(warehouse["inventory"], item) && 
        warehouse["inventory"][item] >= quantity &&
        getVehicleFreeSpace() >= quantity)
    {
        // Remove from warehouse
        warehouse["inventory"][item] -= quantity;
        if (warehouse["inventory"][item] <= 0)
        {
            m_delete(warehouse["inventory"], item);
        }
        
        // Add to vehicle
        if (!member(currentVehicle["cargo"], item))
        {
            currentVehicle["cargo"][item] = 0;
        }
        currentVehicle["cargo"][item] += quantity;
        
        tradingCompany["warehouses"][location] = warehouse;
        ret = 1;
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int unloadToWarehouse(string item, int quantity, string location)
{
    int ret = 0;
    
    if (!location) 
    {
        location = currentLocation;
    }
    
    if (member(currentVehicle["cargo"], item) && 
        currentVehicle["cargo"][item] >= quantity &&
        storeInWarehouse(item, quantity, location))
    {
        currentVehicle["cargo"][item] -= quantity;
        if (currentVehicle["cargo"][item] <= 0)
        {
            m_delete(currentVehicle["cargo"], item);
        }
        ret = 1;
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string getCurrentLocation()
{
    return currentLocation;
}

/////////////////////////////////////////////////////////////////////////////
public void setCurrentLocation(string location)
{
    if (location && stringp(location) && sizeof(location) > 0)
    {
        currentLocation = location;
        currentVehicle["location"] = location;
    }
}

/////////////////////////////////////////////////////////////////////////////
public string getDateString()
{
    object envDict = getDictionary("environment");
    return sprintf("%s, %d", envDict->currentMonth(), envDict->currentYear());
}

/////////////////////////////////////////////////////////////////////////////
public mapping getTradingData()
{
    return ([
        "firm": getFirmName(),
        "cash": getCash(),
        "bank": getBank(),
        "debt": getDebt(),
        "location": getCurrentLocation(),
        "date": getDateString(),
        "vehicle": getVehicle(),
        "warehouse": getWarehouse(currentLocation)
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public void addTradingExperience(int amount)
{
    tradingExperience += amount;
    
    // Trading experience accumulates but doesn't automatically grant research points
    // Players would need to use their experience through other means
    if (tradingExperience >= 100)
    {
        tell_object(this_object(), "Your trading experience has increased significantly!");
        tradingExperience -= 100; // Reset the counter
    }
}

/////////////////////////////////////////////////////////////////////////////
public int getTradingExperience()
{
    return tradingExperience;
}

/////////////////////////////////////////////////////////////////////////////
public void modifyReputation(string faction, int amount, string reason)
{
    object factionService = getService("factions");
    if (factionService)
    {
        factionService->updateFactionDisposition(faction, amount);
        
        if (amount > 0)
        {
            tell_object(this_object(), sprintf("Your reputation with %s improves (%s).", 
                       faction, reason));
        }
        else if (amount < 0)
        {
            tell_object(this_object(), sprintf("Your reputation with %s declines (%s).", 
                       faction, reason));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public mapping getAllReputations()
{
    mapping reps = ([]);
    string *factions = ({ "merchants guild", "port authorities", "caravan masters", 
                         "local nobility", "brigands", "pirates" });
    
    object factionService = getService("factions");
    if (factionService)
    {
        foreach(string faction in factions)
        {
            reps[faction] = factionService->factionReputationToward(faction);
        }
    }
    
    return reps;
}

/////////////////////////////////////////////////////////////////////////////
public mapping getActiveContracts()
{
    return tradingCompany["active contracts"] + ([]);
}

/////////////////////////////////////////////////////////////////////////////
public int acceptContract(string contractId, mapping contractData)
{
    int ret = 0;
    
    if (contractId && mappingp(contractData))
    {
        tradingCompany["active contracts"][contractId] = contractData;
        ret = 1;
    }
    
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int completeContract(string contractId)
{
    int ret = 0;
    
    if (member(tradingCompany["active contracts"], contractId))
    {
        m_delete(tradingCompany["active contracts"], contractId);
        ret = 1;
    }
    
    return ret;
}
