//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object OverloadSelector;
object Port;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "resetPlayerMessages", "forceOverload" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    OverloadSelector = clone_object("/lib/modules/domains/trading/selectors/overloadSelector.c");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("testtrader");
    Player->addCommands();
    Player->initializeTrader();
    Player->colorConfiguration("none");

    Port = clone_object("/lib/modules/domains/trading/tradingPort.c");
    Port->Setup();

    move_object(Player, Port);
    move_object(OverloadSelector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(OverloadSelector)) destruct(OverloadSelector);
    if (objectp(Player)) destruct(Player);
    if (objectp(Port)) destruct(Port);
}

/////////////////////////////////////////////////////////////////////////////
private void resetPlayerMessages()
{
    if (Player && function_exists("resetCatchList", Player))
    {
        Player->resetCatchList();
    }
}

/////////////////////////////////////////////////////////////////////////////
private void forceOverload()
{
    Player->setVehicleCapacity(10);
    // Clear any existing cargo first if needed
    Player->setVehicleCargo(([]));
    Player->addCargoToVehicle("/lib/instances/items/materials/metal/iron", 15);
}

///////////////////////////////////////////////////////////////////////////////
//void OverloadSelectorDisplaysMenuCorrectly()
//{
//    forceOverload();
//
//    resetPlayerMessages();
//    OverloadSelector->initiateSelector(Player);
//
//    string message = Player->caughtMessage();
//    ExpectSubStringMatch("Vehicle Overload", message);
//    ExpectSubStringMatch("View Overload Status", message);
//    ExpectSubStringMatch("Drop Iron", message);
//    ExpectSubStringMatch("Drop All Cargo", message);
//    ExpectSubStringMatch("Upgrade Vehicle Capacity", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void OverloadSelectorShowsWarehouseOptionAtPort()
//{
//    forceOverload();
//
//    resetPlayerMessages();
//    OverloadSelector->initiateSelector(Player);
//
//    string message = Player->caughtMessage();
//    ExpectSubStringMatch("Transfer to Warehouse", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void OverloadSelectorDoesNotShowWarehouseOptionAwayFromPort()
//{
//    object MockEnvironment = clone_object("/lib/tests/support/environment/mockTradeEnvironment.c");
//    move_object(Player, MockEnvironment);
//
//    forceOverload();
//
//    resetPlayerMessages();
//    OverloadSelector->initiateSelector(Player);
//
//    string message = Player->caughtMessage();
//    ExpectFalse(sizeof(regexp(({ message }), "Transfer to Warehouse")), "Should not show warehouse option away from port");
//
//    move_object(Player, Port);
//    destruct(MockEnvironment);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void OverloadSelectorStatusOptionDisplaysStatus()
//{
//    forceOverload();
//
//    resetPlayerMessages();
//    OverloadSelector->initiateSelector(Player);
//
//    // Find status option
//    string message = Player->caughtMessage();
//    int statusOption = 0;
//    string *lines = explode(message, "\n");
//    foreach (string line in lines)
//    {
//        if (sizeof(regexp(({ line }), "View Overload Status")))
//        {
//            sscanf(line, "%d. %*s", statusOption);
//            break;
//        }
//    }
//
//    if (statusOption > 0)
//    {
//        resetPlayerMessages();
//        command(to_string(statusOption), Player);
//        message = Player->caughtMessage();
//        ExpectSubStringMatch("Vehicle Overload Crisis", message);
//        ExpectSubStringMatch("Vehicle Capacity", message);
//        ExpectSubStringMatch("Current Load", message);
//        ExpectSubStringMatch("Excess Cargo", message);
//        ExpectSubStringMatch("YOU CANNOT TRAVEL", message);
//    }
//}
//
///////////////////////////////////////////////////////////////////////////////
//void OverloadSelectorDropAllRemovesAllCargo()
//{
//    forceOverload();
//
//    resetPlayerMessages();
//    OverloadSelector->initiateSelector(Player);
//
//    // Find drop all option
//    string message = Player->caughtMessage();
//    int dropAllOption = 0;
//    string *lines = explode(message, "\n");
//    foreach (string line in lines)
//    {
//        if (sizeof(regexp(({ line }), "Drop All Cargo")))
//        {
//            sscanf(line, "%d. %*s", dropAllOption);
//            break;
//        }
//    }
//
//    if (dropAllOption > 0)
//    {
//        resetPlayerMessages();
//        command(to_string(dropAllOption), Player);
//        string result = Player->caughtMessage();
//        ExpectSubStringMatch("You dropped all cargo", result);
//
//        // Check that cargo is empty
//        mapping cargo = Player->getVehicleCargo();
//        ExpectEq(0, sizeof(cargo), "Cargo should be empty after drop all");
//    }
//}
//
///////////////////////////////////////////////////////////////////////////////
//void OverloadSelectorUpgradeIncreasesCapacity()
//{
//    forceOverload();
//
//    // Give player enough cash for upgrade
//    Player->addCash(100000);
//
//    resetPlayerMessages();
//    OverloadSelector->initiateSelector(Player);
//
//    // Find upgrade option
//    string message = Player->caughtMessage();
//    int upgradeOption = 0;
//    string *lines = explode(message, "\n");
//    foreach (string line in lines)
//    {
//        if (sizeof(regexp(({ line }), "Upgrade Vehicle Capacity")))
//        {
//            sscanf(line, "%d. %*s", upgradeOption);
//            break;
//        }
//    }
//
//    if (upgradeOption > 0)
//    {
//        int oldCapacity = Player->getVehicleCapacity();
//        resetPlayerMessages();
//        command(to_string(upgradeOption), Player);
//        string result = Player->caughtMessage();
//        ExpectSubStringMatch("upgraded your vehicle capacity", result);
//
//        int newCapacity = Player->getVehicleCapacity();
//        ExpectEq(oldCapacity + 50, newCapacity, "Capacity should increase by 50 after upgrade");
//    }
//}
//
///////////////////////////////////////////////////////////////////////////////
//void OverloadSelectorUpgradeFailsWithInsufficientFunds()
//{
//    forceOverload();
//
//    // Set player cash to 0
//    Player->addCash(-Player->getCash());
//
//    resetPlayerMessages();
//    OverloadSelector->initiateSelector(Player);
//
//    // Find upgrade option
//    string message = Player->caughtMessage();
//    int upgradeOption = 0;
//    string *lines = explode(message, "\n");
//    foreach (string line in lines)
//    {
//        if (sizeof(regexp(({ line }), "Upgrade Vehicle Capacity")))
//        {
//            sscanf(line, "%d. %*s", upgradeOption);
//            break;
//        }
//    }
//
//    if (upgradeOption > 0)
//    {
//        resetPlayerMessages();
//        command(to_string(upgradeOption), Player);
//        string result = Player->caughtMessage();
//        ExpectSubStringMatch("need", result);
//        ExpectSubStringMatch("to upgrade your vehicle", result);
//    }
//}
//
///////////////////////////////////////////////////////////////////////////////
//void OverloadSelectorDropOptionInvokesDropSelector()
//{
//    forceOverload();
//
//    resetPlayerMessages();
//    OverloadSelector->initiateSelector(Player);
//
//    // Find drop option
//    string message = Player->caughtMessage();
//    int dropOption = 0;
//    string *lines = explode(message, "\n");
//    foreach (string line in lines)
//    {
//        if (sizeof(regexp(({ line }), "Drop Iron")))
//        {
//            sscanf(line, "%d. %*s", dropOption);
//            break;
//        }
//    }
//
//    if (dropOption > 0)
//    {
//        resetPlayerMessages();
//        command(to_string(dropOption), Player);
//        string result = Player->caughtMessage();
//        // The dropCargoSelector should prompt for how much to drop
//        ExpectSubStringMatch("How many Iron would you like to drop", result);
//    }
//}
//
///////////////////////////////////////////////////////////////////////////////
//void OverloadSelectorResolvesOnDropAll()
//{
//    forceOverload();
//
//    resetPlayerMessages();
//    OverloadSelector->initiateSelector(Player);
//
//    // Find drop all option
//    string message = Player->caughtMessage();
//    int dropAllOption = 0;
//    string *lines = explode(message, "\n");
//    foreach (string line in lines)
//    {
//        if (sizeof(regexp(({ line }), "Drop All Cargo")))
//        {
//            sscanf(line, "%d. %*s", dropAllOption);
//            break;
//        }
//    }
//
//    if (dropAllOption > 0)
//    {
//        resetPlayerMessages();
//        command(to_string(dropAllOption), Player);
//        string result = Player->caughtMessage();
//        ExpectSubStringMatch("You dropped all cargo", result);
//
//        // After drop all, overload should be resolved and user notified
//        ExpectSubStringMatch("Overload situation resolved", result);
//    }
//}
//
///////////////////////////////////////////////////////////////////////////////
//void OverloadSelectorUndoIsAvailable()
//{
//    forceOverload();
//
//    resetPlayerMessages();
//    OverloadSelector->initiateSelector(Player);
//    resetPlayerMessages();
//    command("undo", Player);
//
//    string message = Player->caughtMessage();
//    ExpectTrue(sizeof(message) > 0, "Undo should provide some response");
//}
//
///////////////////////////////////////////////////////////////////////////////
//void OverloadSelectorExitsIfNotOverloaded()
//{
//    // Set vehicle to not overloaded
//    Player->setVehicleCapacity(20);
//    Player->setVehicleCargo(([ "/lib/instances/items/materials/metal/iron": 5 ]));
//
//    resetPlayerMessages();
//    OverloadSelector->initiateSelector(Player);
//
//    string message = Player->caughtMessage();
//    ExpectSubStringMatch("not overloaded", message);
//    // Should not show overload menu
//    ExpectFalse(sizeof(regexp(({ message }), "Vehicle Overload")), "Should not show overload menu if not overloaded");
//}
