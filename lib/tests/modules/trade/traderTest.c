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
    Trader->addVehicle("wagon", "eledhel");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Trader);
}

/////////////////////////////////////////////////////////////////////////////
void DefaultValuesAreCorrect()
{
    ExpectEq("Unnamed Trading Company", Trader->getFirmName());
    ExpectEq(0, Trader->getCash());
    ExpectEq(0, Trader->getBank());
    ExpectEq(0, Trader->getDebt());
    ExpectEq("", Trader->getCurrentLocation());
    object *vehicles = Trader->getVehicles();
    ExpectEq(1, sizeof(vehicles));
    ExpectEq("wagon", vehicles[0]->query("vehicle type"));
    ExpectEq("eledhel", vehicles[0]->getLocation());
}

/////////////////////////////////////////////////////////////////////////////
void SetFirmNameBehavesCorrectly()
{
    Trader->setFirmName("Test Trading Co");
    ExpectEq("Test Trading Co", Trader->getFirmName());

    string longName = "This is a very long trading company name that should be truncated";
    Trader->setFirmName(longName);
    ExpectEq(23, sizeof(Trader->getFirmName()));
    ExpectEq("This is a very long tra", Trader->getFirmName());

    Trader->setFirmName(0);
    ExpectEq("This is a very long tra", Trader->getFirmName());
    Trader->setFirmName("");
    ExpectEq("This is a very long tra", Trader->getFirmName());
}

/////////////////////////////////////////////////////////////////////////////
void SetupStartingChoiceSetsCorrectValues()
{
    Trader->setupStartingChoice(1);
    ExpectEq(400, Trader->getCash());
    ExpectEq(5000, Trader->getDebt());

    Trader->setupStartingChoice(2);
    ExpectEq(0, Trader->getCash());
    ExpectEq(0, Trader->getDebt());
}

/////////////////////////////////////////////////////////////////////////////
void AddCashBehavesCorrectly()
{
    Trader->setupStartingChoice(1);
    int initial = Trader->getCash();
    Trader->addCash(100);
    ExpectEq(initial + 100, Trader->getCash());

    Trader->addCash(-1000);
    ExpectEq(0, Trader->getCash());

    int result = Trader->addCash("invalid");
    ExpectEq(0, result);
    ExpectEq(0, Trader->getCash());
}

/////////////////////////////////////////////////////////////////////////////
void DepositAndWithdrawMoneyBehaveCorrectly()
{
    Trader->setupStartingChoice(1);
    int result = Trader->depositMoney(200);
    ExpectEq(1, result);
    ExpectEq(200, Trader->getCash());
    ExpectEq(200, Trader->getBank());

    result = Trader->depositMoney(500);
    ExpectEq(0, result);
    ExpectEq(200, Trader->getCash());
    ExpectEq(200, Trader->getBank());

    result = Trader->depositMoney(-100);
    ExpectEq(0, result);

    result = Trader->withdrawMoney(100);
    ExpectEq(1, result);
    ExpectEq(300, Trader->getCash());
    ExpectEq(100, Trader->getBank());

    result = Trader->withdrawMoney(200);
    ExpectEq(0, result);
    ExpectEq(300, Trader->getCash());
    ExpectEq(100, Trader->getBank());
}

/////////////////////////////////////////////////////////////////////////////
void BorrowAndRepayDebtBehaveCorrectly()
{
    Trader->setupStartingChoice(1);
    int result = Trader->borrowMoney(500);
    ExpectEq(1, result);
    ExpectEq(900, Trader->getCash());
    ExpectEq(5500, Trader->getDebt());

    result = Trader->borrowMoney(2000);
    ExpectEq(0, result);

    result = Trader->repayDebt(200);
    ExpectEq(1, result);
    ExpectEq(700, Trader->getCash());
    ExpectEq(5300, Trader->getDebt());

    result = Trader->repayDebt(10000);
    ExpectEq(0, result);

    result = Trader->repayDebt(-100);
    ExpectEq(0, result);
}

/////////////////////////////////////////////////////////////////////////////
void VehicleManagementWorks()
{
    object v1 = Trader->addVehicle("cart", "eledhel");
    object v2 = Trader->addVehicle("barge", "riverport");
    object *vehicles = Trader->getVehicles();
    ExpectTrue(sizeof(vehicles) >= 3);
    ExpectTrue(vehicles[1] == v1);
    ExpectTrue(vehicles[2] == v2);

    // Assign and unassign to trade run
    int assigned = Trader->assignVehicleToTradeRun("run1", v1);
    ExpectEq(1, assigned);
    object found = Trader->getVehicleForTradeRun("run1");
    ExpectTrue(found == v1);

    Trader->unassignVehicleFromTradeRun("run1");
    found = Trader->getVehicleForTradeRun("run1");
    ExpectFalse(objectp(found));
}

/////////////////////////////////////////////////////////////////////////////
void WarehouseManagementWorks()
{
    mapping warehouse = Trader->getWarehouse("testport");
    ExpectEq(10000, warehouse["capacity"]);
    ExpectTrue(mappingp(warehouse["inventory"]));
    ExpectEq(0, sizeof(warehouse["inventory"]));
    ExpectTrue(warehouse["rent paid"] > time());

    int result = Trader->storeInWarehouse("/test/item", 100, "testport");
    ExpectEq(1, result);
    warehouse = Trader->getWarehouse("testport");
    ExpectEq(100, warehouse["inventory"]["/test/item"]);

    result = Trader->storeInWarehouse("/test/item", 15000, "testport");
    ExpectEq(0, result);

    Trader->storeInWarehouse("/test/item", 50, "testport");
    warehouse = Trader->getWarehouse("testport");
    ExpectEq(150, warehouse["inventory"]["/test/item"]);
}

/////////////////////////////////////////////////////////////////////////////
void LocationAndDateBehaveCorrectly()
{
    Trader->setCurrentLocation("hillgarath");
    ExpectEq("hillgarath", Trader->getCurrentLocation());

    string original = Trader->getCurrentLocation();
    Trader->setCurrentLocation(0);
    ExpectEq(original, Trader->getCurrentLocation());
    Trader->setCurrentLocation("");
    ExpectEq(original, Trader->getCurrentLocation());

    string date = Trader->getDateString();
    ExpectTrue(stringp(date));
}

/////////////////////////////////////////////////////////////////////////////
void TradingExperienceWorks()
{
    ExpectEq(0, Trader->getTradingExperience());
    Trader->addTradingExperience(50);
    ExpectEq(50, Trader->getTradingExperience());
    Trader->addTradingExperience(60);
    ExpectEq(10, Trader->getTradingExperience()); // Should reset after 100
}

/////////////////////////////////////////////////////////////////////////////
void ContractsWork()
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

    result = Trader->completeContract("contract_1");
    ExpectEq(1, result);
    contracts = Trader->getActiveContracts();
    ExpectFalse(member(contracts, "contract_1"));

    result = Trader->completeContract("nonexistent");
    ExpectEq(0, result);
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
    ExpectEq("", data["location"]);
    ExpectTrue(pointerp(data["vehicles"]));
    ExpectTrue(mappingp(data["warehouse"]));
    ExpectTrue(stringp(data["date"]));
}

/////////////////////////////////////////////////////////////////////////////
// Additional edge cases and negative tests
void CannotAssignSameVehicleToMultipleTradeRuns()
{
    object v1 = Trader->addVehicle("cart", "eledhel");
    int assigned1 = Trader->assignVehicleToTradeRun("run1", v1);
    int assigned2 = Trader->assignVehicleToTradeRun("run2", v1);
    ExpectEq(1, assigned1);
    ExpectEq(0, assigned2);
}

/////////////////////////////////////////////////////////////////////////////
void UnassignNonexistentTradeRunDoesNothing()
{
    // Should not throw or error
    Trader->unassignVehicleFromTradeRun("not-a-run");
    // No assertion needed, just ensure no crash
}

/////////////////////////////////////////////////////////////////////////////
void GetVehicleForNonexistentTradeRunReturnsZero()
{
    object found = Trader->getVehicleForTradeRun("not-a-run");
    ExpectFalse(objectp(found));
}

/////////////////////////////////////////////////////////////////////////////
void StoreInWarehouseWithNoLocationUsesCurrent()
{
    Trader->setCurrentLocation("testport");
    int result = Trader->storeInWarehouse("/test/item", 10, 0);
    ExpectEq(1, result);
    mapping warehouse = Trader->getWarehouse("testport");
    ExpectEq(10, warehouse["inventory"]["/test/item"]);
}

/////////////////////////////////////////////////////////////////////////////
void GetWarehouseWithNoLocationUsesCurrent()
{
    Trader->setCurrentLocation("testport");
    mapping warehouse1 = Trader->getWarehouse(0);
    mapping warehouse2 = Trader->getWarehouse("testport");
    ExpectEq(warehouse1["capacity"], warehouse2["capacity"]);
}

/////////////////////////////////////////////////////////////////////////////
void StoreInWarehouseFailsIfOverCapacity()
{
    int result = Trader->storeInWarehouse("/test/item", 20000, "testport");
    ExpectEq(0, result);
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
void CompleteContractFailsWithNonexistentContract()
{
    int result = Trader->completeContract("nonexistent");
    ExpectEq(0, result);
}
