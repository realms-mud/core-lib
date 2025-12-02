//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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

    Vehicle = Player.addVehicle("wagon", MockPort->getPortName());
    Vehicle.set("vehicle type", "wagon");
    Vehicle.set("name", "Test Wagon");
    move_object(Vehicle, Player);

    Vehicle2 = Player.addVehicle("covered wagon", MockPort->getPortName());
    Vehicle2.set("vehicle type", "covered wagon");
    Vehicle2.set("name", "Test Cart");
    move_object(Vehicle2, Player);

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
private void navigateToQuantitySelector(string item, int price, string action, int singleSource)
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
    if (singleSource)
    {
        QuantitySelector.setSingleSource(1);
    }
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

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorDisplaysTargetSelection()
{
    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 8);
    setupVehicleWithCargo(Vehicle2, "/lib/instances/items/materials/metal/iron.c", 5);

    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell", 0);
    string message = Player.caughtMessage();
    ExpectSubStringMatch("Select which vehicle/warehouse", message);
    ExpectSubStringMatch("Test Wagon", message);
    ExpectSubStringMatch("Test Cart", message);
    ExpectSubStringMatch("Cancel", message);
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorDisplaysQuantityOptionsAfterTargetSelection()
{
    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 8);
    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell", 0);
    string targetOption = findMenuOption("Test Wagon");
    ExpectTrue(targetOption != "0", "Test Wagon target should be available");
    command(targetOption, Player);
    string message = Player.caughtMessage();
    ExpectSubStringMatch("How many", message);
    ExpectSubStringMatch("Iron", message);
    ExpectSubStringMatch("sell", message);
    ExpectSubStringMatch("Test Wagon", message);
    ExpectSubStringMatch("1 unit", message);
    ExpectSubStringMatch("5 units", message);
    ExpectSubStringMatch("All units", message);
    ExpectSubStringMatch("Custom Quantity", message);
    ExpectSubStringMatch("Cancel", message);
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorAllowsQuickQuantitySelectionReturnsToTargetMenu()
{
    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 8);
    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell", 0);
    string targetOption = findMenuOption("Test Wagon");
    command(targetOption, Player);
    string quantityOption = findMenuOption("5 units");
    command(quantityOption, Player);
    // After selecting a quantity, you return to target selection
    string message = Player.caughtMessage();
    ExpectSubStringMatch("Select which vehicle/warehouse", message);
    ExpectSubStringMatch("Test Wagon", message);
    ExpectSubStringMatch("Cancel", message);
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorAllowsCustomQuantityReturnsToTargetMenu()
{
    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 8);
    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell", 0);
    string targetOption = findMenuOption("Test Wagon");
    command(targetOption, Player);
    string customOption = findMenuOption("Custom Quantity");
    ExpectTrue(customOption != "0", "Custom Quantity option should be available");
    command(customOption, Player);
    command("3", Player);
    // After entering custom quantity, you return to target selection
    string message = Player.caughtMessage();
    ExpectSubStringMatch("Select which vehicle/warehouse", message);
    ExpectSubStringMatch("Test Wagon", message);
    ExpectSubStringMatch("Cancel", message);
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorPreventsInvalidCustomQuantity()
{
    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 3);
    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell", 0);
    string targetOption = findMenuOption("Test Wagon");
    command(targetOption, Player);
    string customOption = findMenuOption("Custom Quantity");
    command(customOption, Player);
    command("5", Player);
    string message = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("Invalid quantity", message);
    ExpectSubStringMatch("Must be between", message);
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorHandlesInvalidInput()
{
    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 5);
    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell", 0);
    string targetOption = findMenuOption("Test Wagon");
    command(targetOption, Player);
    string customOption = findMenuOption("Custom Quantity");
    command(customOption, Player);
    command("notanumber", Player);
    string message = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("Invalid quantity", message);
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorAllowsCancelFromTargetMenu()
{
    setupVehicleWithCargo(Vehicle, "/lib/instances/items/materials/metal/iron.c", 5);
    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 100, "sell", 0);
    string cancelOption = findMenuOption("Cancel");
    ExpectTrue(cancelOption != "0", "Cancel option should be available");
    command(cancelOption, Player);
    // After cancel, selector is aborted, no transaction, no summary
    string message = Player.caughtMessage();
    ExpectTrue(sizeof(message) > 0, "Should get a cancel/abort message or return to previous menu");
}