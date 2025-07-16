//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing.c";

private mapping tradingCompany = ([]);
private string currentLocation = "";
private int tradingExperience = 0;
private int lastInterestCalculation = 0;

private object *vehicles = ({});
private mapping tradeRunVehicles = ([]);

/////////////////////////////////////////////////////////////////////////////
private void initializeFactions()
{
    object factionDict = getDictionary("factions");
    if (factionDict)
    {
        string *factionPaths = factionDict->getTradingFactions();
        object factionService = getService("factions");
        if (factionService && sizeof(factionPaths))
        {
            foreach (string factionPath in factionPaths)
            {
                if (file_size(factionPath) > 0)
                {
                    factionService->updateFactionDisposition(factionPath, 0);
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private void initializeWarehouse(string location)
{
    if (location && !member(tradingCompany["warehouses"], location))
    {
        tradingCompany["warehouses"][location] = ([
            "capacity": 10000,
            "inventory": ([]),
            "rent paid": time() + 2592000
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
private void calculateInterest()
{
    object envDict = getDictionary("environment");
    int currentDay = envDict->currentDay();
    int daysPassed = currentDay - lastInterestCalculation;
    if (daysPassed >= 30)
    {
        int monthsPassed = daysPassed / 30;
        for (int i = 0; i < monthsPassed; i++)
        {
            tradingCompany["debt"] = to_int(tradingCompany["debt"] * 1.1);
            tradingCompany["bank"] = to_int(tradingCompany["bank"] * 1.005);
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
            "active contracts": ([])
        ]);
        vehicles = ({});
        tradeRunVehicles = ([]);
        currentLocation = "";
        object envDict = getDictionary("environment");
        lastInterestCalculation = envDict->currentDay();
        initializeFactions();
    }
}

/////////////////////////////////////////////////////////////////////////////
public object addVehicle(string type, string location)
{
    object vehicle = 0;
    if (type && stringp(type) && location && stringp(location))
    {
        vehicle = clone_object("/lib/items/vehicle.c");
        vehicle->set("vehicle type", type);
        vehicle->setLocation(location);
        vehicles += ({ vehicle });
    }
    return vehicle;
}

/////////////////////////////////////////////////////////////////////////////
public object *getVehicles()
{
    object *result = vehicles + ({});
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public int assignVehicleToTradeRun(mixed tradeRunId, object vehicle)
{
    int ret = 0;
    if (objectp(vehicle))
    {
        int alreadyAssigned = 0;
        foreach (mixed key in m_indices(tradeRunVehicles))
        {
            if (tradeRunVehicles[key] == vehicle)
            {
                alreadyAssigned = 1;
                break;
            }
        }
        if (!alreadyAssigned)
        {
            tradeRunVehicles[tradeRunId] = vehicle;
            ret = 1;
        }
    }
    return ret;
}


/////////////////////////////////////////////////////////////////////////////
public void unassignVehicleFromTradeRun(mixed tradeRunId)
{
    if (member(tradeRunVehicles, tradeRunId))
    {
        m_delete(tradeRunVehicles, tradeRunId);
    }
}

/////////////////////////////////////////////////////////////////////////////
public object getVehicleForTradeRun(mixed tradeRunId)
{
    object result = 0;
    if (member(tradeRunVehicles, tradeRunId))
    {
        result = tradeRunVehicles[tradeRunId];
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public void setFirmName(string name)
{
    if (name && stringp(name) && sizeof(name) > 0)
    {
        tradingCompany["firm name"] = name[0..22];
    }
}

/////////////////////////////////////////////////////////////////////////////
public string getFirmName()
{
    string result = "Unnamed Trading Company";
    if (tradingCompany["firm name"] != "")
    {
        result = tradingCompany["firm name"];
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public void setupStartingChoice(int choice)
{
    if (sizeof(vehicles))
    {
        object vehicle = vehicles[0];
        switch (choice)
        {
            case 1:
            {
                tradingCompany["cash"] = 400;
                tradingCompany["debt"] = 5000;
                vehicle->set("components", ([]));
                break;
            }
            case 2:
            {
                tradingCompany["cash"] = 0;
                tradingCompany["debt"] = 0;
                vehicle->set("components", ([]));
                break;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public int getCash()
{
    calculateInterest();
    int result = tradingCompany["cash"];
    return result;
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
    calculateInterest();
    int result = tradingCompany["bank"];
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public int getDebt()
{
    calculateInterest();
    int result = tradingCompany["debt"];
    return result;
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
public int getVehicleCapacityForTradeRun(mixed tradeRunId)
{
    int result = 0;
    object vehicle = getVehicleForTradeRun(tradeRunId);
    if (objectp(vehicle))
    {
        result = vehicle->getCapacity();
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public int getVehicleUsedSpaceForTradeRun(mixed tradeRunId)
{
    int result = 0;
    object vehicle = getVehicleForTradeRun(tradeRunId);
    if (objectp(vehicle))
    {
        result = vehicle->getUsedSpace();
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public int getVehicleFreeSpaceForTradeRun(mixed tradeRunId)
{
    int result = 0;
    object vehicle = getVehicleForTradeRun(tradeRunId);
    if (objectp(vehicle))
    {
        result = vehicle->getFreeSpace();
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public int addCargoToVehicleForTradeRun(mixed tradeRunId, string item, int quantity)
{
    int ret = 0;
    object vehicle = getVehicleForTradeRun(tradeRunId);
    if (objectp(vehicle))
    {
        ret = vehicle->addCargo(item, quantity);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int removeCargoFromVehicleForTradeRun(mixed tradeRunId, string item, int quantity)
{
    int ret = 0;
    object vehicle = getVehicleForTradeRun(tradeRunId);
    if (objectp(vehicle))
    {
        ret = vehicle->removeCargo(item, quantity);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int getCargoQuantityForTradeRun(mixed tradeRunId, string item)
{
    int result = 0;
    object vehicle = getVehicleForTradeRun(tradeRunId);
    if (objectp(vehicle))
    {
        result = vehicle->getCargoQuantity(item);
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public mapping getVehicleBlueprintForTradeRun(mixed tradeRunId)
{
    mapping result = ([]);
    object vehicle = getVehicleForTradeRun(tradeRunId);
    if (objectp(vehicle))
    {
        result = vehicle->getBlueprint();
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public mapping getWarehouse(string location)
{
    mapping result = ([]);
    string useLocation = location;
    if (!useLocation)
    {
        useLocation = currentLocation;
    }
    if (!member(tradingCompany["warehouses"], useLocation))
    {
        initializeWarehouse(useLocation);
    }
    result = tradingCompany["warehouses"][useLocation] + ([]);
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public int storeInWarehouse(string item, int quantity, string location)
{
    int ret = 0;
    string useLocation = location;
    if (!useLocation)
    {
        useLocation = currentLocation;
    }
    mapping warehouse = getWarehouse(useLocation);
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
        tradingCompany["warehouses"][useLocation] = warehouse;
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int loadFromWarehouseToVehicleForTradeRun(mixed tradeRunId, string item, int quantity, string location)
{
    int ret = 0;
    string useLocation = location;
    if (!useLocation)
    {
        useLocation = currentLocation;
    }
    mapping warehouse = getWarehouse(useLocation);
    object vehicle = getVehicleForTradeRun(tradeRunId);
    if (member(warehouse["inventory"], item) &&
        warehouse["inventory"][item] >= quantity &&
        objectp(vehicle) &&
        vehicle->getFreeSpace() >= quantity)
    {
        warehouse["inventory"][item] -= quantity;
        if (warehouse["inventory"][item] <= 0)
        {
            m_delete(warehouse["inventory"], item);
        }
        vehicle->addCargo(item, quantity);
        tradingCompany["warehouses"][useLocation] = warehouse;
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int unloadFromVehicleToWarehouseForTradeRun(mixed tradeRunId, string item, int quantity, string location)
{
    int ret = 0;
    string useLocation = location;
    if (!useLocation)
    {
        useLocation = currentLocation;
    }
    object vehicle = getVehicleForTradeRun(tradeRunId);
    if (objectp(vehicle) &&
        vehicle->getCargoQuantity(item) >= quantity &&
        storeInWarehouse(item, quantity, useLocation))
    {
        vehicle->removeCargo(item, quantity);
        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string getCurrentLocation()
{
    string result = currentLocation;
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public void setCurrentLocation(string location)
{
    if (location && stringp(location) && sizeof(location) > 0)
    {
        currentLocation = location;
    }
}

/////////////////////////////////////////////////////////////////////////////
public string getDateString()
{
    object envDict = getDictionary("environment");
    string result = sprintf("%s, %d", envDict->currentMonth(), envDict->currentYear());
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public mapping getTradingData()
{
    mapping result = ([
        "firm": getFirmName(),
        "cash": getCash(),
        "bank": getBank(),
        "debt": getDebt(),
        "location": getCurrentLocation(),
        "date": getDateString(),
        "vehicles": map(vehicles, (: $1->getBlueprint() :)),
        "warehouse": getWarehouse(currentLocation)
    ]);
    return result;
}

/////////////////////////////////////////////////////////////////////////////
public void addTradingExperience(int amount)
{
    tradingExperience += amount;
    if (tradingExperience >= 100)
    {
        tell_object(this_object(), "Your trading experience has increased significantly!");
        tradingExperience -= 100;
    }
}

/////////////////////////////////////////////////////////////////////////////
public int getTradingExperience()
{
    int result = tradingExperience;
    return result;
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
    object factionDict = getDictionary("factions");
    if (factionDict)
    {
        string *factionPaths = factionDict->getTradingFactions();
        object factionService = getService("factions");
        if (factionService && sizeof(factionPaths))
        {
            foreach (string factionPath in factionPaths)
            {
                if (file_size(factionPath) > 0)
                {
                    reps[factionPath] = factionService->factionReputationToward(factionPath);
                }
            }
        }
    }
    return reps;
}

/////////////////////////////////////////////////////////////////////////////
public mapping getActiveContracts()
{
    mapping result = tradingCompany["active contracts"] + ([]);
    return result;
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
