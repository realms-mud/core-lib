//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object SellSelector;
object MockPort;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({
        "resetPlayerMessages",
        "getMenuOptionNumber",
        "setupPlayerWithCargo",
        "setupPlayerWithCash",
        "navigateToSellMenu",
        "findItemOption",
        "findCustomQuantityOption",
        "findMaximumOption",
        "clearAllPlayerCargo",
        "getPlayerCargoQuantity",
        "getFirstVehicle",
        "getVehicleByName"
    });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    SellSelector = clone_object("/lib/modules/domains/trading/selectors/sellSelector.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("testtrader");
    Player.colorConfiguration("none");
    Player.addCommands();
    Player.initializeTrader();

    MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");

    Player.addVehicle("wagon", MockPort->getPortName());
    move_object(Player, MockPort);
    move_object(SellSelector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(SellSelector)) destruct(SellSelector);
    if (objectp(Player)) destruct(Player);
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
private string getMenuOptionNumber(string optionText)
{
    string ret = "0";
    string message = Player.caughtMessage();
    if (message && (message != ""))
    {
        string *lines = explode(message, "\n");
        foreach (string line in lines)
        {
            // Remove ANSI codes for matching
            line = regreplace(line, "\x1B\\[[0-9;]*[A-Za-z]", "", 1);
            if (sizeof(regexp(({ line }), optionText)))
            {
                ret = regreplace(line, "^[^0-9]*([0-9]+).*", "\\1", 1);
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private object getFirstVehicle()
{
    object *vehicles = Player.getVehicles();
    return (vehicles && sizeof(vehicles)) ? vehicles[0] : 0;
}

/////////////////////////////////////////////////////////////////////////////
private object getVehicleByName(string name)
{
    object result = 0;
    object *vehicles = Player.getVehicles();
    foreach (object vehicle in vehicles)
    {
        string vehicleName = vehicle->query("name") ? 
            vehicle->query("name") : vehicle->query("vehicle type");

        if (objectp(vehicle) && vehicleName == name)
        {
            result = vehicle;
            break;
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
private void setupPlayerWithCargo(string item, int quantity, object vehicle)
{
    if (objectp(vehicle))
    {
        vehicle.addCargo(item, quantity);
    }
}

/////////////////////////////////////////////////////////////////////////////
private int getPlayerCargoQuantity(string item, object vehicle)
{
    return objectp(vehicle) ? vehicle.getCargoQuantity(item) : 0;
}

/////////////////////////////////////////////////////////////////////////////
private void clearAllPlayerCargo()
{
    object *vehicles = Player.getVehicles();
    foreach (object vehicle in vehicles)
    {
        if (objectp(vehicle))
        {
            vehicle.set("cargo", ([]));
        }
    }
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
private void navigateToSellMenu()
{
    resetPlayerMessages();
    SellSelector.setPort(MockPort);
    SellSelector.initiateSelector(Player);
}

/////////////////////////////////////////////////////////////////////////////
private string findItemOption(string itemText)
{
    string ret = "0";
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        line = regreplace(line, "\x1B\\[[0-9;]*[A-Za-z]", "", 1);
        if (sizeof(regexp(({ line }), itemText)))
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
    string ret = "0";
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        line = regreplace(line, "\x1B\\[[0-9;]*[A-Za-z]", "", 1);
        if (sizeof(regexp(({ line }), "Custom Quantity")))
        {
            ret = regreplace(line, "^[^0-9]*([0-9]+).*", "\\1", 1);
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string findMaximumOption()
{
    string ret = "0";
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        line = regreplace(line, "\x1B\\[[0-9;]*[A-Za-z]", "", 1);

        if (sizeof(regexp(({ line }), "All units")))
        {
            ret = regreplace(line, "^[^0-9]*([0-9]+).*", "\\1", 1);
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorDisplaysCargoCorrectly()
{
    object vehicle = getFirstVehicle();
    setupPlayerWithCargo("/lib/instances/items/materials/metal/iron.c", 5, vehicle);
    setupPlayerWithCargo("/lib/instances/items/materials/wood/oak.c", 3, vehicle);

    navigateToSellMenu();

    string message = Player.caughtMessage();
    string vehicleName = vehicle->query("name") ? vehicle->query("name") : vehicle->query("vehicle type");

    ExpectSubStringMatch("Iron x5", message);
    ExpectSubStringMatch("Oak x3", message);
    ExpectSubStringMatch(vehicleName, message);
    ExpectSubStringMatch("Return to Trading Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorHandlesNoCargo()
{
    clearAllPlayerCargo();

    navigateToSellMenu();

    string message = Player.caughtMessage();
    ExpectSubStringMatch("from 1 to 1", message);
    ExpectSubStringMatch("Return to Trading Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorAllowsSellingPartialQuantity()
{
    object vehicle = getFirstVehicle();
    setupPlayerWithCargo("/lib/instances/items/materials/metal/iron.c", 8, vehicle);
    int startingCash = Player->getCash();

    ExpectEq(8, getPlayerCargoQuantity("/lib/instances/items/materials/metal/iron.c", vehicle),
        "Should start with 8 iron");
    navigateToSellMenu();

    string vehicleName = vehicle->query("name") ? vehicle->query("name") : vehicle->query("vehicle type");
    string ironOption = findItemOption("Iron x8.*\\[" + vehicleName + "\\]");
    ExpectTrue(ironOption != "0", "Iron x8 option should be present in the menu");
    command(ironOption, Player);

    // Now we're in quantitySelector - should go straight to quantity selection for single source
    string message = Player.caughtMessage();
    ExpectSubStringMatch("How many Iron would you like to sell", message);

    // Select 5 units option (should be option 2 based on output: 1 unit, 5 units, ...)
    command("2", Player);

    // Transaction should be executed immediately, verify results
    int remaining = getPlayerCargoQuantity("/lib/instances/items/materials/metal/iron.c", vehicle);
    ExpectEq(3, remaining, "Should have 3 iron left after selling 5/8");

    string result = implode(Player->caughtMessages(), "\n");
    ExpectSubStringMatch("Sold 5 units of Iron", result);

    int newCash = Player->getCash();
    ExpectTrue(newCash > startingCash, "Cash should increase after selling");
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorAllowsSellingFullQuantity()
{
    object vehicle = getFirstVehicle();
    setupPlayerWithCargo("/lib/instances/items/materials/metal/iron.c", 8, vehicle);
    int startingCash = Player->getCash();

    ExpectEq(8, getPlayerCargoQuantity("/lib/instances/items/materials/metal/iron.c", vehicle),
        "Should start with 8 iron");
    navigateToSellMenu();

    string vehicleName = vehicle->query("name") ? vehicle->query("name") : vehicle->query("vehicle type");
    string ironOption = findItemOption("Iron x8.*\\[" + vehicleName + "\\]");
    ExpectTrue(ironOption != "0", "Iron x8 option should be present in the menu");
    command(ironOption, Player);

    // Should go straight to quantity selection for single source
    string message = Player.caughtMessage();
    ExpectSubStringMatch("How many Iron would you like to sell", message);

    // Select "All units" (should be last option)
    string maxOption = findMaximumOption();
    ExpectTrue(maxOption != "0", "Maximum option should be present in the menu");

    Player.resetCatchList();
    command(maxOption, Player);

    int remaining = getPlayerCargoQuantity("/lib/instances/items/materials/metal/iron.c", vehicle);
    ExpectEq(0, remaining, "Should have 0 iron left after selling all 8");

    string result = implode(Player->caughtMessages(), "\n");
    ExpectSubStringMatch("Sold 8 units of Iron", result);

    int newCash = Player->getCash();
    ExpectTrue(newCash > startingCash, "Cash should increase after selling");
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorAllowsSellingCustomQuantity()
{
    object vehicle = getFirstVehicle();
    setupPlayerWithCargo("/lib/instances/items/materials/metal/iron.c", 5, vehicle);
    int startingCash = Player->getCash();

    navigateToSellMenu();
    string vehicleName = vehicle->query("name") ? vehicle->query("name") : vehicle->query("vehicle type");
    string ironOption = findItemOption("Iron x5.*" + vehicleName);
    command(ironOption, Player);

    string qtyOption = findCustomQuantityOption();
    command(qtyOption, Player);
    command("3", Player);

    int remaining = getPlayerCargoQuantity("/lib/instances/items/materials/metal/iron.c", vehicle);
    string result = implode(Player->caughtMessages(), "\n");
    ExpectSubStringMatch("Sold 3 units of Iron", result);

    int newCash = Player->getCash();
    ExpectTrue(newCash > startingCash, "Cash should increase after selling");
    ExpectEq(2, remaining, "Should have 2 iron left after selling 3 of 5");
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorPreventsOverselling()
{
    object vehicle = getFirstVehicle();
    setupPlayerWithCargo("/lib/instances/items/materials/metal/iron.c", 2, vehicle);

    navigateToSellMenu();
    string vehicleName = vehicle->query("name") ? vehicle->query("name") : vehicle->query("vehicle type");
    string ironOption = findItemOption("Iron x2.*" + vehicleName);
    command(ironOption, Player);

    string customOption = findCustomQuantityOption();
    resetPlayerMessages();

    command(customOption, Player);
    command("5", Player);

    string result = implode(Player->caughtMessages(), "\n");
    ExpectSubStringMatch("Invalid quantity", result);
    int remaining = getPlayerCargoQuantity("/lib/instances/items/materials/metal/iron.c", vehicle);
    ExpectEq(2, remaining, "Should still have 2 iron after failed oversell");
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorMultipleVehiclesShowCorrectly()
{
    // Add a second vehicle and give it different cargo
    object vehicle1 = getFirstVehicle();
    object vehicle2 = Player.addVehicle("wagon", MockPort->getPortName());
    vehicle1->set("name", "Wagon Alpha");
    vehicle2->set("name", "Cart Beta");

    setupPlayerWithCargo("/lib/instances/items/materials/metal/iron.c", 4, vehicle1);
    setupPlayerWithCargo("/lib/instances/items/food/bread/wheat-bread.c", 7, vehicle2);

    navigateToSellMenu();

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Iron x4.*Wagon Alpha", message);
    ExpectSubStringMatch("Wheat Bread x7.*Cart Beta", message);
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorSellsFromCorrectVehicle()
{
    // Add a second vehicle and give it different cargo
    object vehicle1 = getFirstVehicle();
    object vehicle2 = Player.addVehicle("wagon", MockPort->getPortName());
    vehicle1->set("name", "Wagon Alpha");
    vehicle2->set("name", "Cart Beta");

    setupPlayerWithCargo("/lib/instances/items/materials/metal/iron.c", 4, vehicle1);
    setupPlayerWithCargo("/lib/instances/items/food/bread/wheat-bread.c", 7, vehicle2);

    // Sell 3 wheat bread from Cart Beta
    navigateToSellMenu();
    string breadOption = findItemOption("Wheat Bread x7.*Cart Beta");
    ExpectTrue(breadOption != "0", "Wheat Bread x7 from Cart Beta should be present");
    command(breadOption, Player);

    // Should go straight to quantity selection for Cart Beta
    string message = Player.caughtMessage();
    ExpectSubStringMatch("How many Wheat Bread would you like to sell", message);

    // Select custom quantity
    string customOption = findCustomQuantityOption();
    command(customOption, Player);
    command("3", Player);

    int remainingBread = getPlayerCargoQuantity("/lib/instances/items/food/bread/wheat-bread.c", vehicle2);
    int remainingIron = getPlayerCargoQuantity("/lib/instances/items/materials/metal/iron.c", vehicle1);

    ExpectEq(4, remainingBread, "Should have 4 wheat bread left in Cart Beta after selling 3");
    ExpectEq(4, remainingIron, "Iron in Wagon Alpha should be unchanged");

    string result = implode(Player->caughtMessages(), "\n");
    ExpectSubStringMatch("Sold 3 units of Wheat Bread", result);
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorShowsVehicleTypeIfNoName()
{
    // Add a vehicle with no name set
    object vehicle2 = Player.addVehicle("barge", MockPort->getPortName());
    setupPlayerWithCargo("/lib/instances/items/materials/wood/oak.c", 2, vehicle2);

    navigateToSellMenu();

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Oak x2.*Barge", message);
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorMenuAlwaysIncludesExit()
{
    clearAllPlayerCargo();
    navigateToSellMenu();
    string message = Player.caughtMessage();
    ExpectSubStringMatch("Return to Trading Menu", message);

    // Add cargo and check again
    object vehicle = getFirstVehicle();
    setupPlayerWithCargo("/lib/instances/items/materials/metal/iron.c", 2, vehicle);
    navigateToSellMenu();
    message = Player.caughtMessage();
    ExpectSubStringMatch("Return to Trading Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorInvalidSelectionShowsMenuAgain()
{
    object vehicle = getFirstVehicle();
    setupPlayerWithCargo("/lib/instances/items/materials/metal/iron.c", 2, vehicle);
    navigateToSellMenu();
    resetPlayerMessages();
    command("999", Player);
    ExpectSubStringMatch("Sell Goods", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorDescribeOptionShowsItemDetails()
{
    object vehicle = getFirstVehicle();
    setupPlayerWithCargo("/lib/instances/items/materials/metal/iron.c", 2, vehicle);
    navigateToSellMenu();
    resetPlayerMessages();
    command("describe 1", Player);
    string message = Player.caughtMessage();
    ExpectTrue(sizeof(regexp(({ message }), "Sell")) > 0, "Should show item sell details");
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorDescribeWorksForAllMenuOptions()
{
    object vehicle = getFirstVehicle();
    setupPlayerWithCargo("/lib/instances/items/materials/metal/iron.c", 2, vehicle);
    setupPlayerWithCargo("/lib/instances/items/materials/wood/oak.c", 1, vehicle);
    navigateToSellMenu();
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    int maxOption = 0;
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "Return to Trading Menu")))
        {
            maxOption = to_int(regreplace(line, "^[^0-9]*([0-9]+).*", "\\1", 1));
        }
    }
    for (int i = 1; i <= maxOption; i++)
    {
        resetPlayerMessages();
        command("describe " + to_string(i), Player);
        string desc = Player.caughtMessage();
        ExpectTrue(sizeof(desc) > 0, "Describe should provide some response for option " + to_string(i));
    }
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorUndoIsAvailable()
{
    object vehicle = getFirstVehicle();
    setupPlayerWithCargo("/lib/instances/items/materials/metal/iron.c", 5, vehicle);
    navigateToSellMenu();
    resetPlayerMessages();
    command("undo", Player);
    string message = Player.caughtMessage();
    ExpectTrue(sizeof(message) > 0, "Undo should provide some response");
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorSupportsExit()
{
    object vehicle = getFirstVehicle();
    setupPlayerWithCargo("/lib/instances/items/materials/metal/iron.c", 2, vehicle);
    navigateToSellMenu();
    string message = Player.caughtMessage();
    ExpectSubStringMatch("Type 'exit' if you do not wish", message);
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorFormattingIsConsistent()
{
    object vehicle = getFirstVehicle();
    setupPlayerWithCargo("/lib/instances/items/materials/metal/iron.c", 5, vehicle);
    setupPlayerWithCargo("/lib/instances/items/materials/wood/oak.c", 3, vehicle);
    navigateToSellMenu();
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    string *itemLines = ({});
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "\\[[0-9]+\\].*x[0-9]+")) > 0)
        {
            itemLines += ({ line });
        }
    }
    ExpectTrue(sizeof(itemLines) > 0, "Should find item lines to test formatting");
    foreach (string line in itemLines)
    {
        ExpectTrue(sizeof(regexp(({ line }), "\\[[0-9]+\\]")) > 0,
            "Item lines should have properly formatted numbers");
        ExpectTrue(sizeof(regexp(({ line }), "x[0-9]+")) > 0,
            "Item lines should show quantity");
    }
}

/////////////////////////////////////////////////////////////////////////////
void SellSelectorMenuHandlesNoSellableItems()
{
    clearAllPlayerCargo();
    navigateToSellMenu();
    string message = Player.caughtMessage();
    ExpectSubStringMatch("from 1 to 1", message);
    ExpectSubStringMatch("Return to Trading Menu", message);
}
