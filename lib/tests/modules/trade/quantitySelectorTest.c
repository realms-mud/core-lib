//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Vehicle;
object QuantitySelector;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({
        "resetPlayerMessages",
        "setupPlayerWithCash",
        "setupVehicleWithCargo",
        "navigateToQuantitySelector",
        "findMenuOption",
        "findCustomQuantityOption",
        "findMaximumOption",
        "getPlayerCargoQuantity"
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

    Vehicle = clone_object("/lib/items/vehicle.c");
    Vehicle.set("vehicle type", "wagon");
    Vehicle.set("name", "Test Wagon");
    move_object(Vehicle, Player);

    // Give the player a vehicle and some cash
    Player.addVehicle("wagon", "TestPort");
    setupPlayerWithCash(10000);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(QuantitySelector)) destruct(QuantitySelector);
    if (objectp(Player)) destruct(Player);
    if (objectp(Vehicle)) destruct(Vehicle);
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
private void setupVehicleWithCargo(string item, int quantity)
{
    Vehicle.addCargo(item, quantity);
}

/////////////////////////////////////////////////////////////////////////////
private int getPlayerCargoQuantity(string item)
{
    return Vehicle.getCargoQuantity(item);
}

/////////////////////////////////////////////////////////////////////////////
private void navigateToQuantitySelector(string item, int maxQuantity, int price, string action)
{
    resetPlayerMessages();
    if (objectp(QuantitySelector)) destruct(QuantitySelector);
    QuantitySelector = clone_object("/lib/modules/domains/trading/selectors/quantitySelector.c");
    QuantitySelector.setItem(item);
    QuantitySelector.setMaxQuantity(maxQuantity);
    QuantitySelector.setPrice(price);
    QuantitySelector.setAction(action);
    QuantitySelector.setVehicle(Vehicle);
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
private string findCustomQuantityOption()
{
    return findMenuOption("Custom Quantity");
}

/////////////////////////////////////////////////////////////////////////////
private string findMaximumOption()
{
    return findMenuOption("Maximum");
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorDisplaysQuickOptions()
{
    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 8, 100, "sell");
    string message = Player.caughtMessage();

    ExpectSubStringMatch("1 unit", message);
    ExpectSubStringMatch("5 units", message);
    ExpectSubStringMatch("Custom Quantity", message);
    ExpectSubStringMatch("Maximum", message);
    ExpectSubStringMatch("Cancel", message);
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorAllowsQuickSell()
{
    setupVehicleWithCargo("/lib/instances/items/materials/metal/iron.c", 8);
    int startingCash = Player.getCash();

    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 8, 100, "sell");
    string quickOption = findMenuOption("5 units");
    command(quickOption, Player);

    int remaining = getPlayerCargoQuantity("/lib/instances/items/materials/metal/iron.c");
    string result = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("You sold 5 Iron", result);
    ExpectEq(3, remaining, "Should have 3 iron left after selling 5 of 8");
    int newCash = Player.getCash();
    ExpectTrue(newCash > startingCash, "Cash should increase after selling");
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorAllowsMaximumSell()
{
    setupVehicleWithCargo("/lib/instances/items/materials/metal/iron.c", 4);
    int startingCash = Player.getCash();

    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 4, 100, "sell");
    string maxOption = findMaximumOption();
    command(maxOption, Player);

    int remaining = getPlayerCargoQuantity("/lib/instances/items/materials/metal/iron.c");
    string result = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("You sold 4 Iron", result);
    ExpectEq(0, remaining, "Should have 0 iron left after selling all");
    int newCash = Player.getCash();
    ExpectTrue(newCash > startingCash, "Cash should increase after selling");
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorAllowsCustomSell()
{
    setupVehicleWithCargo("/lib/instances/items/materials/metal/iron.c", 6);
    int startingCash = Player.getCash();

    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 6, 100, "sell");
    string customOption = findCustomQuantityOption();
    command(customOption, Player);
    command("3", Player);

    int remaining = getPlayerCargoQuantity("/lib/instances/items/materials/metal/iron.c");
    string result = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("You sold 3 Iron", result);
    ExpectEq(3, remaining, "Should have 3 iron left after selling 3 of 6");
    int newCash = Player.getCash();
    ExpectTrue(newCash > startingCash, "Cash should increase after selling");
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorPreventsOversell()
{
    setupVehicleWithCargo("/lib/instances/items/materials/metal/iron.c", 2);
    int startingCash = Player.getCash();

    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 2, 100, "sell");
    string customOption = findCustomQuantityOption();
    command(customOption, Player);
    command("5", Player);

    int remaining = getPlayerCargoQuantity("/lib/instances/items/materials/metal/iron.c");
    string result = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("Invalid quantity", result);
    ExpectEq(2, remaining, "Should still have 2 iron after failed oversell");
    int newCash = Player.getCash();
    ExpectEq(startingCash, newCash, "Cash should not change after failed oversell");
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorAllowsCancel()
{
    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 5, 100, "sell");
    string cancelOption = findMenuOption("Cancel");
    command(cancelOption, Player);

    string result = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("Cancel", result);
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorAllowsBuy()
{
    // Simulate a buy action
    int startingCash = Player.getCash();

    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 10, 100, "buy");
    string quickOption = findMenuOption("5 units");
    command(quickOption, Player);

    int remaining = getPlayerCargoQuantity("/lib/instances/items/materials/metal/iron.c");
    string result = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("You purchased 5 Iron", result);
    ExpectEq(5, remaining, "Should have 5 iron after buying 5");
    int newCash = Player.getCash();
    ExpectTrue(newCash < startingCash, "Cash should decrease after buying");
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorPreventsOverbuy()
{
    // Simulate a buy action with not enough cash
    setupPlayerWithCash(100); // Not enough for 5 units at 100 each
    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 5, 100, "buy");
    string quickOption = findMenuOption("5 units");
    command(quickOption, Player);

    int remaining = getPlayerCargoQuantity("/lib/instances/items/materials/metal/iron.c");
    string result = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("don't have enough gold", result);
    ExpectEq(0, remaining, "Should not have bought any iron");
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorPreventsOverload()
{
    // Simulate a buy action with not enough space
    Vehicle.set("max cargo", 2);

    int remaining = getPlayerCargoQuantity("/lib/instances/items/materials/metal/iron.c");
    ExpectEq(0, remaining, "Should not have any iron");

    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 2, 100, "buy");
    string quickOption = findCustomQuantityOption();
    command(quickOption, Player);
    command("5", Player);

    remaining = getPlayerCargoQuantity("/lib/instances/items/materials/metal/iron.c");
    string result = implode(Player.caughtMessages(), "\n");

    ExpectSubStringMatch("Invalid quantity", result);
    ExpectEq(0, remaining, "Should not have bought any iron");
}

/////////////////////////////////////////////////////////////////////////////
void QuantitySelectorHandlesInvalidInput()
{
    setupVehicleWithCargo("/lib/instances/items/materials/metal/iron.c", 5);
    navigateToQuantitySelector("/lib/instances/items/materials/metal/iron.c", 5, 100, "sell");
    string customOption = findCustomQuantityOption();
    command(customOption, Player);
    command("notanumber", Player);

    string result = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("Invalid quantity", result);
}
