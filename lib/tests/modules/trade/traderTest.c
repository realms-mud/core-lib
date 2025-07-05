//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Trader;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Trader = clone_object("/lib/modules/trader.c");
    Trader->initializeTrader();
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Trader);
}

/////////////////////////////////////////////////////////////////////////////
void InitializeTraderSetsUpDefaultValues()
{
    ExpectEq("Unnamed Trading Company", Trader->getFirmName());
    ExpectEq(0, Trader->getCash());
    ExpectEq(0, Trader->getBank());
    ExpectEq(0, Trader->getDebt());
    ExpectEq("eledhel", Trader->getCurrentLocation());
    
    mapping vehicle = Trader->getVehicle();
    ExpectEq("wagon", vehicle["type"]);
    ExpectEq(60, vehicle["capacity"]);
    ExpectEq(0, vehicle["damage"]);
    ExpectEq(0, vehicle["protection"]);
}

/////////////////////////////////////////////////////////////////////////////
void SetFirmNameSetsCorrectly()
{
    Trader->setFirmName("Test Trading Co");
    ExpectEq("Test Trading Co", Trader->getFirmName());
}

/////////////////////////////////////////////////////////////////////////////
void SetFirmNameTruncatesLongNames()
{
    string longName = "This is a very long trading company name that should be truncated";
    Trader->setFirmName(longName);
    ExpectEq(23, sizeof(Trader->getFirmName()));
    ExpectEq("This is a very long tra", Trader->getFirmName());
}

/////////////////////////////////////////////////////////////////////////////
void SetFirmNameIgnoresInvalidInput()
{
    Trader->setFirmName("Valid Name");
    Trader->setFirmName(0);
    ExpectEq("Valid Name", Trader->getFirmName());
    
    Trader->setFirmName("");
    ExpectEq("Valid Name", Trader->getFirmName());
}

/////////////////////////////////////////////////////////////////////////////
void SetupStartingChoiceOneSetsCorrectValues()
{
    Trader->setupStartingChoice(1);
    ExpectEq(400, Trader->getCash());
    ExpectEq(5000, Trader->getDebt());
    ExpectEq(60, Trader->getVehicleCapacity());
    
    mapping vehicle = Trader->getVehicle();
    ExpectEq(0, vehicle["protection"]);
}

/////////////////////////////////////////////////////////////////////////////
void SetupStartingChoiceTwoSetsCorrectValues()
{
    Trader->setupStartingChoice(2);
    ExpectEq(0, Trader->getCash());
    ExpectEq(0, Trader->getDebt());
    ExpectEq(10, Trader->getVehicleCapacity());
    
    mapping vehicle = Trader->getVehicle();
    ExpectEq(5, vehicle["protection"]);
}

/////////////////////////////////////////////////////////////////////////////
void AddCashIncreasesCorrectly()
{
    int initialCash = Trader->getCash();
    Trader->addCash(100);
    ExpectEq(initialCash + 100, Trader->getCash());
}

/////////////////////////////////////////////////////////////////////////////
void AddCashHandlesNegativeAmounts()
{
    Trader->setupStartingChoice(1);
    Trader->addCash(-500);
    ExpectEq(0, Trader->getCash());
}

/////////////////////////////////////////////////////////////////////////////
void AddCashReturnsNewTotal()
{
    Trader->setupStartingChoice(1);
    int result = Trader->addCash(100);
    ExpectEq(500, result);
}

/////////////////////////////////////////////////////////////////////////////
void AddCashIgnoresInvalidInput()
{
    Trader->setupStartingChoice(1);
    int initialCash = Trader->getCash();
    int result = Trader->addCash("invalid");
    ExpectEq(0, result);
    ExpectEq(initialCash, Trader->getCash());
}

/////////////////////////////////////////////////////////////////////////////
void DepositMoneyWorksCorrectly()
{
    Trader->setupStartingChoice(1);
    int result = Trader->depositMoney(200);
    
    ExpectEq(1, result);
    ExpectEq(200, Trader->getCash());
    ExpectEq(200, Trader->getBank());
}

/////////////////////////////////////////////////////////////////////////////
void DepositMoneyFailsWithInsufficientFunds()
{
    Trader->setupStartingChoice(1);
    int result = Trader->depositMoney(500);
    
    ExpectEq(0, result);
    ExpectEq(400, Trader->getCash());
    ExpectEq(0, Trader->getBank());
}

/////////////////////////////////////////////////////////////////////////////
void DepositMoneyFailsWithInvalidAmount()
{
    Trader->setupStartingChoice(1);
    int result = Trader->depositMoney(-100);
    
    ExpectEq(0, result);
    ExpectEq(400, Trader->getCash());
    ExpectEq(0, Trader->getBank());
}

/////////////////////////////////////////////////////////////////////////////
void WithdrawMoneyWorksCorrectly()
{
    Trader->setupStartingChoice(1);
    Trader->depositMoney(200);
    
    int result = Trader->withdrawMoney(100);
    
    ExpectEq(1, result);
    ExpectEq(300, Trader->getCash());
    ExpectEq(100, Trader->getBank());
}

/////////////////////////////////////////////////////////////////////////////
void WithdrawMoneyFailsWithInsufficientFunds()
{
    Trader->setupStartingChoice(1);
    Trader->depositMoney(200);
    
    int result = Trader->withdrawMoney(300);
    
    ExpectEq(0, result);
    ExpectEq(200, Trader->getCash());
    ExpectEq(200, Trader->getBank());
}

/////////////////////////////////////////////////////////////////////////////
void BorrowMoneyWorksCorrectly()
{
    Trader->setupStartingChoice(1);
    int result = Trader->borrowMoney(500);
    
    ExpectEq(1, result);
    ExpectEq(900, Trader->getCash());
    ExpectEq(5500, Trader->getDebt());
}

/////////////////////////////////////////////////////////////////////////////
void BorrowMoneyFailsExceedingLimit()
{
    Trader->setupStartingChoice(1);
    int result = Trader->borrowMoney(1000);
    
    ExpectEq(0, result);
    ExpectEq(400, Trader->getCash());
    ExpectEq(5000, Trader->getDebt());
}

/////////////////////////////////////////////////////////////////////////////
void RepayDebtWorksCorrectly()
{
    Trader->setupStartingChoice(1);
    int result = Trader->repayDebt(200);
    
    ExpectEq(1, result);
    ExpectEq(200, Trader->getCash());
    ExpectEq(4800, Trader->getDebt());
}

/////////////////////////////////////////////////////////////////////////////
void RepayDebtFailsWithInsufficientCash()
{
    Trader->setupStartingChoice(1);
    int result = Trader->repayDebt(500);
    
    ExpectEq(0, result);
    ExpectEq(400, Trader->getCash());
    ExpectEq(5000, Trader->getDebt());
}

/////////////////////////////////////////////////////////////////////////////
void RepayDebtFailsExceedingDebt()
{
    Trader->setupStartingChoice(2);
    Trader->addCash(1000);
    int result = Trader->repayDebt(100);
    
    ExpectEq(0, result);
    ExpectEq(1000, Trader->getCash());
    ExpectEq(0, Trader->getDebt());
}

/////////////////////////////////////////////////////////////////////////////
void GetVehicleCapacityReturnsCorrectValue()
{
    ExpectEq(60, Trader->getVehicleCapacity());
    
    Trader->setupStartingChoice(2);
    ExpectEq(10, Trader->getVehicleCapacity());
}

/////////////////////////////////////////////////////////////////////////////
void AddCargoToVehicleWorksCorrectly()
{
    int result = Trader->addCargoToVehicle("/test/item", 20);
    
    ExpectEq(1, result);
    ExpectEq(20, Trader->getCargoQuantity("/test/item"));
    ExpectEq(20, Trader->getVehicleUsedSpace());
    ExpectEq(40, Trader->getVehicleFreeSpace());
}

/////////////////////////////////////////////////////////////////////////////
void AddCargoToVehicleFailsWhenExceedingCapacity()
{
    int result = Trader->addCargoToVehicle("/test/item", 70);
    
    ExpectEq(0, result);
    ExpectEq(0, Trader->getCargoQuantity("/test/item"));
    ExpectEq(0, Trader->getVehicleUsedSpace());
}

/////////////////////////////////////////////////////////////////////////////
void AddCargoToVehicleAccumulatesQuantities()
{
    Trader->addCargoToVehicle("/test/item", 20);
    Trader->addCargoToVehicle("/test/item", 15);
    
    ExpectEq(35, Trader->getCargoQuantity("/test/item"));
    ExpectEq(35, Trader->getVehicleUsedSpace());
}

/////////////////////////////////////////////////////////////////////////////
void RemoveCargoFromVehicleWorksCorrectly()
{
    Trader->addCargoToVehicle("/test/item", 30);
    int result = Trader->removeCargoFromVehicle("/test/item", 10);
    
    ExpectEq(1, result);
    ExpectEq(20, Trader->getCargoQuantity("/test/item"));
    ExpectEq(20, Trader->getVehicleUsedSpace());
}

/////////////////////////////////////////////////////////////////////////////
void RemoveCargoFromVehicleFailsWithInsufficientCargo()
{
    Trader->addCargoToVehicle("/test/item", 10);
    int result = Trader->removeCargoFromVehicle("/test/item", 20);
    
    ExpectEq(0, result);
    ExpectEq(10, Trader->getCargoQuantity("/test/item"));
}

/////////////////////////////////////////////////////////////////////////////
void RemoveCargoFromVehicleRemovesItemWhenEmpty()
{
    Trader->addCargoToVehicle("/test/item", 20);
    Trader->removeCargoFromVehicle("/test/item", 20);
    
    ExpectEq(0, Trader->getCargoQuantity("/test/item"));
    ExpectEq(0, Trader->getVehicleUsedSpace());
}

/////////////////////////////////////////////////////////////////////////////
void GetVehicleUsedSpaceCalculatesCorrectly()
{
    ExpectEq(0, Trader->getVehicleUsedSpace());
    ExpectEq(60, Trader->getVehicleFreeSpace());
    
    // Use proper accessor methods instead of direct mapping manipulation
    Trader->addCargoToVehicle("/test/item1", 20);
    Trader->addCargoToVehicle("/test/item2", 15);
    
    ExpectEq(35, Trader->getVehicleUsedSpace());
    ExpectEq(25, Trader->getVehicleFreeSpace());
}

/////////////////////////////////////////////////////////////////////////////
void SetCurrentLocationUpdatesCorrectly()
{
    Trader->setCurrentLocation("hillgarath");
    ExpectEq("hillgarath", Trader->getCurrentLocation());
    
    mapping vehicle = Trader->getVehicle();
    ExpectEq("hillgarath", vehicle["location"]);
}

/////////////////////////////////////////////////////////////////////////////
void SetCurrentLocationIgnoresInvalidInput()
{
    string originalLocation = Trader->getCurrentLocation();
    Trader->setCurrentLocation(0);
    ExpectEq(originalLocation, Trader->getCurrentLocation());
    
    Trader->setCurrentLocation("");
    ExpectEq(originalLocation, Trader->getCurrentLocation());
}

/////////////////////////////////////////////////////////////////////////////
void GetWarehouseInitializesCorrectly()
{
    mapping warehouse = Trader->getWarehouse("testport");
    
    ExpectEq(10000, warehouse["capacity"]);
    ExpectTrue(mappingp(warehouse["inventory"]));
    ExpectEq(0, sizeof(warehouse["inventory"]));
    ExpectTrue(warehouse["rent paid"] > time());
}

/////////////////////////////////////////////////////////////////////////////
void GetWarehouseUsesCurrentLocationByDefault()
{
    Trader->setCurrentLocation("testport");
    mapping warehouse1 = Trader->getWarehouse(0);
    mapping warehouse2 = Trader->getWarehouse("testport");
    
    ExpectEq(warehouse1["capacity"], warehouse2["capacity"]);
}

/////////////////////////////////////////////////////////////////////////////
void StoreInWarehouseWorksCorrectly()
{
    int result = Trader->storeInWarehouse("/test/item", 100, "testport");
    
    ExpectEq(1, result);
    
    mapping warehouse = Trader->getWarehouse("testport");
    ExpectEq(100, warehouse["inventory"]["/test/item"]);
}

/////////////////////////////////////////////////////////////////////////////
void StoreInWarehouseFailsWhenExceedingCapacity()
{
    int result = Trader->storeInWarehouse("/test/item", 15000, "testport");
    
    ExpectEq(0, result);
    
    mapping warehouse = Trader->getWarehouse("testport");
    ExpectFalse(member(warehouse["inventory"], "/test/item"));
}

/////////////////////////////////////////////////////////////////////////////
void StoreInWarehouseAccumulatesQuantities()
{
    Trader->storeInWarehouse("/test/item", 100, "testport");
    Trader->storeInWarehouse("/test/item", 50, "testport");
    
    mapping warehouse = Trader->getWarehouse("testport");
    ExpectEq(150, warehouse["inventory"]["/test/item"]);
}

/////////////////////////////////////////////////////////////////////////////
void LoadFromWarehouseWorksCorrectly()
{
    Trader->storeInWarehouse("/test/item", 100, "testport");
    
    int result = Trader->loadFromWarehouse("/test/item", 50, "testport");
    
    ExpectEq(1, result);
    
    mapping warehouse = Trader->getWarehouse("testport");
    ExpectEq(50, warehouse["inventory"]["/test/item"]);
    
    ExpectEq(50, Trader->getCargoQuantity("/test/item"));
}

/////////////////////////////////////////////////////////////////////////////
void LoadFromWarehouseFailsWithInsufficientQuantity()
{
    Trader->storeInWarehouse("/test/item", 100, "testport");
    
    int result = Trader->loadFromWarehouse("/test/item", 150, "testport");
    
    ExpectEq(0, result);
    
    mapping warehouse = Trader->getWarehouse("testport");
    ExpectEq(100, warehouse["inventory"]["/test/item"]);
}

/////////////////////////////////////////////////////////////////////////////
void LoadFromWarehouseFailsWhenVehicleFull()
{
    // Use proper accessor instead of direct manipulation
    Trader->addCargoToVehicle("/test/existing", 60);
    
    Trader->storeInWarehouse("/test/item", 100, "testport");
    
    int result = Trader->loadFromWarehouse("/test/item", 10, "testport");
    
    ExpectEq(0, result);
}

/////////////////////////////////////////////////////////////////////////////
void LoadFromWarehouseRemovesItemWhenQuantityZero()
{
    Trader->storeInWarehouse("/test/item", 50, "testport");
    Trader->loadFromWarehouse("/test/item", 50, "testport");
    
    mapping warehouse = Trader->getWarehouse("testport");
    ExpectFalse(member(warehouse["inventory"], "/test/item"));
}

/////////////////////////////////////////////////////////////////////////////
void UnloadToWarehouseWorksCorrectly()
{
    // Use proper accessor instead of direct manipulation
    Trader->addCargoToVehicle("/test/item", 30);
    
    int result = Trader->unloadToWarehouse("/test/item", 20, "testport");
    
    ExpectEq(1, result);
    ExpectEq(10, Trader->getCargoQuantity("/test/item"));
    
    mapping warehouse = Trader->getWarehouse("testport");
    ExpectEq(20, warehouse["inventory"]["/test/item"]);
}

/////////////////////////////////////////////////////////////////////////////
void UnloadToWarehouseRemovesCargoWhenEmpty()
{
    // Use proper accessor instead of direct manipulation
    Trader->addCargoToVehicle("/test/item", 20);
    
    Trader->unloadToWarehouse("/test/item", 20, "testport");
    
    ExpectEq(0, Trader->getCargoQuantity("/test/item"));
}

/////////////////////////////////////////////////////////////////////////////
void UnloadToWarehouseFailsWithInsufficientCargo()
{
    // Use proper accessor instead of direct manipulation  
    Trader->addCargoToVehicle("/test/item", 10);
    
    int result = Trader->unloadToWarehouse("/test/item", 20, "testport");
    
    ExpectEq(0, result);
    ExpectEq(10, Trader->getCargoQuantity("/test/item"));
}

/////////////////////////////////////////////////////////////////////////////
void GetTradingDataReturnsCompleteMapping()
{
    Trader->setFirmName("Test Company");
    Trader->setupStartingChoice(1);
    
    mapping data = Trader->getTradingData();
    
    ExpectEq("Test Company", data["firm"]);
    ExpectEq(400, data["cash"]);
    ExpectEq(5000, data["debt"]);
    ExpectEq("eledhel", data["location"]);
    ExpectTrue(mappingp(data["vehicle"]));
    ExpectTrue(mappingp(data["warehouse"]));
    ExpectTrue(stringp(data["date"]));
}

/////////////////////////////////////////////////////////////////////////////
void AcceptContractWorksCorrectly()
{
    mapping contractData = ([
        "description": "Test contract",
        "reward": 1000,
        "deadline": time() + 86400
    ]);
    
    int result = Trader->acceptContract("contract_1", contractData);
    
    ExpectEq(1, result);
    
    mapping contracts = Trader->getActiveContracts();
    ExpectTrue(member(contracts, "contract_1"));
    ExpectEq("Test contract", contracts["contract_1"]["description"]);
}

/////////////////////////////////////////////////////////////////////////////
void AcceptContractFailsWithInvalidInput()
{
    mapping emptyMapping = ([]);
    int result1 = Trader->acceptContract(0, emptyMapping);
    int result2 = Trader->acceptContract("test", 0);
    
    ExpectEq(0, result1);
    ExpectEq(0, result2);
    
    mapping contracts = Trader->getActiveContracts();
    ExpectEq(0, sizeof(contracts));
}

/////////////////////////////////////////////////////////////////////////////
void CompleteContractWorksCorrectly()
{
    mapping contractData = ([ "description": "Test contract" ]);
    Trader->acceptContract("contract_1", contractData);
    
    int result = Trader->completeContract("contract_1");
    
    ExpectEq(1, result);
    
    mapping contracts = Trader->getActiveContracts();
    ExpectFalse(member(contracts, "contract_1"));
}

/////////////////////////////////////////////////////////////////////////////
void CompleteContractFailsWithNonexistentContract()
{
    int result = Trader->completeContract("nonexistent");
    
    ExpectEq(0, result);
}

/////////////////////////////////////////////////////////////////////////////
void GetCargoQuantityReturnsCorrectAmount()
{
    ExpectEq(0, Trader->getCargoQuantity("/test/item"));
    
    Trader->addCargoToVehicle("/test/item", 25);
    ExpectEq(25, Trader->getCargoQuantity("/test/item"));
    
    ExpectEq(0, Trader->getCargoQuantity("/nonexistent/item"));
}

/////////////////////////////////////////////////////////////////////////////
void GetTradingExperienceReturnsCorrectValue()
{
    ExpectEq(0, Trader->getTradingExperience());
    
    Trader->addTradingExperience(50);
    ExpectEq(50, Trader->getTradingExperience());
    
    Trader->addTradingExperience(60);
    ExpectEq(10, Trader->getTradingExperience()); // Should reset after 100
}
