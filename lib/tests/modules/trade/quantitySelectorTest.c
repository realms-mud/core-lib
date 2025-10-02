//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Vehicle;
object Vehicle2;
object QuantitySelector;
object MockPort;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({
        "resetPlayerMessages",
        "setupPlayerWithCash",
        "setupVehicleWithCargo",
        "navigateToQuantitySelector",
        "findMenuOption",
        "getPlayerCargoQuantity",
        "createTargetsMapping"
    });
}

/////////////////////////////////////////////////////////////////////////////
private void setupPlayerWithCash(int amount)
{
    Player.setupStartingChoice(1);
    if (amount > 400)
    {
        Player.addCash(amount - 400);
    }
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("testtrader");
    Player.colorConfiguration("none");
    Player.addCommands();
    Player.initializeTrader();

    MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");

    Vehicle = clone_object("/lib/items/vehicle.c");
    Vehicle.set("vehicle type", "wagon");
    Vehicle.set("name", "Test Wagon");
    move_object(Vehicle, Player);

    Vehicle2 = clone_object("/lib/items/vehicle.c");
    Vehicle2.set("vehicle type", "cart");
    Vehicle2.set("name", "Test Cart");
    move_object(Vehicle2, Player);

    // Give the player vehicles and some cash
    Player.addVehicle("wagon", MockPort->getPortName());
    Player.addVehicle("cart", MockPort->getPortName());
    setupPlayerWithCash(10000);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(QuantitySelector)) destruct(QuantitySelector);
    if (objectp(Player)) destruct(Player);
    if (objectp(Vehicle)) destruct(Vehicle);
    if (objectp(Vehicle2)) destruct(Vehicle2);
    if (objectp(MockPort)) destruct(MockPort);
}

/////////////////////////////////////////////////////////////////////////////
private void resetPlayerMessages()
{
    if (Player && function_exists("resetCatchList", Player))
    {
        Player.resetCatchList();
    }
}

/////////////////////////////////////////////////////////////////////////////
private void setupVehicleWithCargo(object vehicle, string item, int quantity)
{
    if (objectp(vehicle))
    {
        vehicle.addCargo(item, quantity);
    }
}

/////////////////////////////////////////////////////////////////////////////
private int getPlayerCargoQuantity(object vehicle, string item)
{
    return objectp(vehicle) ? vehicle.getCargoQuantity(item) : 0;
}

/////////////////////////////////////////////////////////////////////////////
private mapping createTargetsMapping(string action, string item)
{
    mapping targets = ([]);
    
    if (action == "sell")
    {
        // For selling, targets are vehicles/warehouses that have the item
        if (Vehicle->getCargoQuantity(item) > 0)
        {
            targets["Test Wagon"] = ([
                "object": Vehicle,
                "maxQuantity": Vehicle->getCargoQuantity(item)
            ]);
        }
        if (Vehicle2->getCargoQuantity(item) > 0)
        {
            targets["Test Cart"] = ([
                "object": Vehicle2,
                "maxQuantity": Vehicle2->getCargoQuantity(item)
            ]);
        }
    }
    else if (action == "buy")
    {
        // For buying, targets are vehicles/warehouses with free space
        if (Vehicle->getFreeSpace() > 0)
        {
            targets["Test Wagon"] = ([
                "object": Vehicle,
                "maxQuantity": Vehicle->getFreeSpace()
            ]);
        }
        if (Vehicle2->getFreeSpace() > 0)
        {
            targets["Test Cart"] = ([
                "object": Vehicle2,
                "maxQuantity": Vehicle2->getFreeSpace()
            ]);
        }
    }
    
    return targets;
}

/////////////////////////////////////////////////////////////////////////////
private void navigateToQuantitySelector(string item, int price, string action)
{
    resetPlayerMessages();
    if (objectp(QuantitySelector)) destruct(QuantitySelector);
    QuantitySelector = clone_object("/lib/modules/domains/trading/selectors/quantitySelector.c");
    
    mapping targets = createTargetsMapping(action, item);
    
    QuantitySelector.setItem(item);
    QuantitySelector.setPrice(price);
    QuantitySelector.setAction(action);
    QuantitySelector.setPort(MockPort);
    QuantitySelector.setTargets(targets);
    move_object(QuantitySelector, Player);
    QuantitySelector.initiateSelector(Player);
}

/////////////////////////////////////////////////////////////////////////////
private string findMenuOption(string optionText)
{
    string ret = "0";
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        line = regreplace(line, "\x1B\\[[0-9;]*[A-Za-z]", "", 1);
        if (sizeof(regexp(({ line }), optionText)))
        {
            ret = regreplace(line, "^[^0-9]*([0-9]+).*", "\\1", 1);
            break;
        }
    }
    return ret;
}

///////////////////////////////////////////////////////////////////////////////
//void QuantitySelectorDisplaysTargetSelection()
//{
//    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 8);
//    setupVehicleWithCargo(Vehicle2, "/lib/instances/items/materials/metal/iron.c", 5);
//    
//    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell");
//    string message = Player.caughtMessage();
//
//    ExpectSubStringMatch("Select which vehicle/warehouse", message);
//    ExpectSubStringMatch("Test Wagon", message);
//    ExpectSubStringMatch("Test Cart", message);
//    ExpectSubStringMatch("Done", message);
//    ExpectSubStringMatch("Cancel", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void QuantitySelectorDisplaysQuantityOptionsAfterTargetSelection()
//{
//    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 8);
//    
//    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell");
//    
//    // Select the Test Wagon target
//    string targetOption = findMenuOption("Test Wagon");
//    ExpectTrue(targetOption != "0", "Test Wagon target should be available");
//    command(targetOption, Player);
//    
//    string message = Player.caughtMessage();
//    ExpectSubStringMatch("How many", message);
//    ExpectSubStringMatch("Iron", message);
//    ExpectSubStringMatch("sell", message);
//    ExpectSubStringMatch("Test Wagon", message);
//    ExpectSubStringMatch("0 units", message);
//    ExpectSubStringMatch("1 unit", message);
//    ExpectSubStringMatch("5 units", message);
//    ExpectSubStringMatch("Custom Quantity", message);
//    ExpectSubStringMatch("Cancel", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void QuantitySelectorAllowsQuickQuantitySelection()
//{
//    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 8);
//    int startingCash = Player.getCash();
//    
//    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell");
//    
//    // Select target
//    string targetOption = findMenuOption("Test Wagon");
//    command(targetOption, Player);
//    
//    // Select 5 units
//    string quantityOption = findMenuOption("5 units");
//    ExpectTrue(quantityOption != "0", "5 units option should be available");
//    command(quantityOption, Player);
//    
//    // Should return to target selection screen
//    string message = Player.caughtMessage();
//    ExpectSubStringMatch("Select which vehicle/warehouse", message);
//    
//    // Complete the transaction
//    string doneOption = findMenuOption("Done");
//    command(doneOption, Player);
//    
//    // Should show confirmation screen
//    message = Player.caughtMessage();
//    ExpectSubStringMatch("You have selected", message);
//    ExpectSubStringMatch("Test Wagon: 5 units", message);
//    ExpectSubStringMatch("Total: 5 units for 500 gold", message);
//    ExpectSubStringMatch("Confirm Transaction", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void QuantitySelectorAllowsCustomQuantity()
//{
//    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 8);
//    
//    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell");
//    
//    // Select target
//    string targetOption = findMenuOption("Test Wagon");
//    command(targetOption, Player);
//    
//    // Select custom quantity
//    string customOption = findMenuOption("Custom Quantity");
//    ExpectTrue(customOption != "0", "Custom Quantity option should be available");
//    command(customOption, Player);
//    
//    // Enter custom amount
//    command("3", Player);
//    
//    // Should return to target selection
//    string message = Player.caughtMessage();
//    ExpectSubStringMatch("Select which vehicle/warehouse", message);
//    
//    // Complete transaction
//    string doneOption = findMenuOption("Done");
//    command(doneOption, Player);
//    
//    // Verify confirmation shows correct amount
//    message = Player.caughtMessage();
//    ExpectSubStringMatch("Test Wagon: 3 units", message);
//    ExpectSubStringMatch("Total: 3 units for 300 gold", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void QuantitySelectorPreventsInvalidCustomQuantity()
//{
//    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 3);
//    
//    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell");
//    
//    // Select target
//    string targetOption = findMenuOption("Test Wagon");
//    command(targetOption, Player);
//    
//    // Try custom quantity that's too high
//    string customOption = findMenuOption("Custom Quantity");
//    command(customOption, Player);
//    command("5", Player); // More than the 3 available
//    
//    string message = Player.caughtMessage();
//    ExpectSubStringMatch("Invalid quantity", message);
//    ExpectSubStringMatch("Must be between 0 and 3", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void QuantitySelectorAllowsMultipleTargets()
//{
//    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 5);
//    setupVehicleWithCargo(Vehicle2, "/lib/instances/items/materials/metal/iron.c", 3);
//    
//    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell");
//    
//    // Select first target and quantity
//    string wagon1Option = findMenuOption("Test Wagon");
//    command(wagon1Option, Player);
//    string qty1Option = findMenuOption("5 units");
//    command(qty1Option, Player);
//    
//    // Select second target and quantity
//    string wagon2Option = findMenuOption("Test Cart");
//    command(wagon2Option, Player);
//    string qty2Option = findMenuOption("3 units");
//    command(qty2Option, Player);
//    
//    // Complete transaction
//    string doneOption = findMenuOption("Done");
//    command(doneOption, Player);
//    
//    // Verify confirmation shows both allocations
//    string message = Player.caughtMessage();
//    ExpectSubStringMatch("Test Wagon: 5 units", message);
//    ExpectSubStringMatch("Test Cart: 3 units", message);
//    ExpectSubStringMatch("Total: 8 units for 800 gold", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void QuantitySelectorExecutesSellTransaction()
//{
//    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 5);
//    int startingCash = Player.getCash();
//    
//    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell");
//    
//    // Complete a simple transaction
//    string targetOption = findMenuOption("Test Wagon");
//    command(targetOption, Player);
//    string quantityOption = findMenuOption("3 units");
//    command(quantityOption, Player);
//    string doneOption = findMenuOption("Done");
//    command(doneOption, Player);
//    
//    // Confirm the transaction
//    string confirmOption = findMenuOption("Confirm Transaction");
//    ExpectTrue(confirmOption != "0", "Confirm Transaction should be available");
//    command(confirmOption, Player);
//    
//    // Verify the transaction occurred
//    int remaining = getPlayerCargoQuantity(Vehicle, "/lib/instances/items/materials/metal/iron.c");
//    ExpectEq(2, remaining, "Should have 2 iron left after selling 3");
//    
//    int newCash = Player.getCash();
//    ExpectTrue(newCash > startingCash, "Cash should increase after selling");
//}
//
///////////////////////////////////////////////////////////////////////////////
//void QuantitySelectorExecutesBuyTransaction()
//{
//    int startingCash = Player.getCash();
//    
//    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "buy");
//    
//    // Complete a buy transaction
//    string targetOption = findMenuOption("Test Wagon");
//    command(targetOption, Player);
//    string quantityOption = findMenuOption("5 units");
//    command(quantityOption, Player);
//    string doneOption = findMenuOption("Done");
//    command(doneOption, Player);
//    
//    // Confirm the transaction
//    string confirmOption = findMenuOption("Confirm Transaction");
//    command(confirmOption, Player);
//    
//    // Verify the transaction occurred
//    int cargo = getPlayerCargoQuantity(Vehicle, "/lib/instances/items/materials/metal/iron.c");
//    ExpectEq(5, cargo, "Should have 5 iron after buying");
//    
//    int newCash = Player.getCash();
//    ExpectTrue(newCash < startingCash, "Cash should decrease after buying");
//}
//
///////////////////////////////////////////////////////////////////////////////
//void QuantitySelectorPreventsInsufficientFundsBuy()
//{
//    setupPlayerWithCash(200); // Only 200 gold, not enough for 5 units at 100 each
//    
//    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "buy");
//    
//    // Try to buy more than we can afford
//    string targetOption = findMenuOption("Test Wagon");
//    command(targetOption, Player);
//    string quantityOption = findMenuOption("5 units");
//    command(quantityOption, Player);
//    string doneOption = findMenuOption("Done");
//    command(doneOption, Player);
//    
//    // Try to confirm - should fail
//    string confirmOption = findMenuOption("Confirm Transaction");
//    command(confirmOption, Player);
//    
//    string message = Player.caughtMessage();
//    ExpectSubStringMatch("do not have enough gold", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void QuantitySelectorAllowsCancel()
//{
//    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 5);
//    
//    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell");
//    
//    // Cancel from target selection
//    string cancelOption = findMenuOption("Cancel");
//    ExpectTrue(cancelOption != "0", "Cancel option should be available");
//    command(cancelOption, Player);
//    
//    // Verify nothing changed
//    int cargo = getPlayerCargoQuantity(Vehicle, "/lib/instances/items/materials/metal/iron.c");
//    ExpectEq(5, cargo, "Should still have 5 iron after cancel");
//}
//
///////////////////////////////////////////////////////////////////////////////
//void QuantitySelectorAllowsCancelFromQuantitySelection()
//{
//    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 5);
//    
//    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell");
//    
//    // Select target first
//    string targetOption = findMenuOption("Test Wagon");
//    command(targetOption, Player);
//    
//    // Cancel from quantity selection
//    string cancelOption = findMenuOption("Cancel");
//    command(cancelOption, Player);
//    
//    // Verify nothing changed
//    int cargo = getPlayerCargoQuantity(Vehicle, "/lib/instances/items/materials/metal/iron.c");
//    ExpectEq(5, cargo, "Should still have 5 iron after cancel");
//}
//
///////////////////////////////////////////////////////////////////////////////
//void QuantitySelectorAllowsCancelFromConfirmation()
//{
//    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 5);
//    
//    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell");
//    
//    // Go through selection process
//    string targetOption = findMenuOption("Test Wagon");
//    command(targetOption, Player);
//    string quantityOption = findMenuOption("3 units");
//    command(quantityOption, Player);
//    string doneOption = findMenuOption("Done");
//    command(doneOption, Player);
//    
//    // Cancel from confirmation screen
//    string cancelOption = findMenuOption("Cancel");
//    command(cancelOption, Player);
//    
//    // Verify nothing changed
//    int cargo = getPlayerCargoQuantity(Vehicle, "/lib/instances/items/materials/metal/iron.c");
//    ExpectEq(5, cargo, "Should still have 5 iron after cancel");
//}
//
///////////////////////////////////////////////////////////////////////////////
//void QuantitySelectorHandlesZeroQuantity()
//{
//    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 5);
//    
//    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell");
//    
//    // Select target and 0 units
//    string targetOption = findMenuOption("Test Wagon");
//    command(targetOption, Player);
//    string zeroOption = findMenuOption("0 units");
//    ExpectTrue(zeroOption != "0", "0 units option should be available");
//    command(zeroOption, Player);
//    
//    // Complete transaction
//    string doneOption = findMenuOption("Done");
//    command(doneOption, Player);
//    
//    // Confirm should show 0 units
//    string message = Player.caughtMessage();
//    ExpectSubStringMatch("Total: 0 units for 0 gold", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void QuantitySelectorHandlesInvalidInput()
//{
//    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 5);
//    
//    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell");
//    
//    // Select target
//    string targetOption = findMenuOption("Test Wagon");
//    command(targetOption, Player);
//    
//    // Try custom quantity with invalid input
//    string customOption = findMenuOption("Custom Quantity");
//    command(customOption, Player);
//    command("notanumber", Player);
//    
//    string message = Player.caughtMessage();
//    ExpectSubStringMatch("Invalid quantity", message);
//}
