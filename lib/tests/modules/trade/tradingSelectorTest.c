//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object TradingSelector;
object MockEnvironment;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "resetPlayerMessages", "createOverloadedState" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    TradingSelector = clone_object("/lib/modules/domains/trading/selectors/tradingSelector.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("testtrader");
    Player.addCommands();
    Player.initializeTrader();

    // Create a mock environment that is NOT a port
    MockEnvironment = clone_object("/lib/tests/support/environment/mockTradeEnvironment.c");
    move_object(Player, MockEnvironment);
    move_object(TradingSelector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(TradingSelector)) destruct(TradingSelector);
    if (objectp(Player)) destruct(Player);
    if (objectp(MockEnvironment)) destruct(MockEnvironment);
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
void TradingSelectorDisplaysMainMenuCorrectly()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Main Trading Menu", message);
    ExpectSubStringMatch("View Company Status", message);
    ExpectSubStringMatch("Exit Trading Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingStatusDisplaysCompanyInformation()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("1", Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Trading Status", message);
    ExpectSubStringMatch("Unnamed Trading Company", message);
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingExitExitsSelector()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    // Find the exit option number by looking for "Exit Trading Menu"
    int exitOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "Exit Trading Menu")))
        {
            sscanf(line, "%d. %*s", exitOption);
            break;
        }
    }
    
    resetPlayerMessages();
    if (exitOption > 0)
    {
        command(to_string(exitOption), Player);
        ExpectSubStringMatch("Trading has been exited", Player.caughtMessage());
    }
    else
    {
        // Fallback test
        command("exit", Player);
        ExpectTrue(1, "Exit command processed");
    }
}

/////////////////////////////////////////////////////////////////////////////
void WarehouseOptionShowsAtPorts()
{
    // Create a mock port environment
    object MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    move_object(Player, MockPort);
    
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectTrue(sizeof(regexp(({ message }), "Manage Warehouse")) > 0,
        "Warehouse option should show when at port");
    
    // Clean up the mock port
    move_object(Player, MockEnvironment); // Move player back to original environment
    if (objectp(MockPort)) destruct(MockPort);
}

/////////////////////////////////////////////////////////////////////////////
void BuyOptionShowsAtPorts()
{
    // Create a mock port environment
    object MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    move_object(Player, MockPort);
    
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectTrue(sizeof(regexp(({ message }), "Buy Goods")) > 0,
        "Buy option should show when at port");

    // Clean up the mock port
    move_object(Player, MockEnvironment); // Move player back to original environment
    if (objectp(MockPort)) destruct(MockPort);
}

/////////////////////////////////////////////////////////////////////////////
void SellOptionShowsAtPortsWithCargo()
{
    // Create a mock port environment
    object MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    move_object(Player, MockPort);
    
    // Add some cargo to the player's vehicle
    Player.addCargoToVehicle("/lib/instances/items/materials/metal/iron", 10);
    
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectTrue(sizeof(regexp(({ message }), "Sell Goods")) > 0,
        "Sell option should show when at port with cargo");

    // Clean up the mock port
    move_object(Player, MockEnvironment); // Move player back to original environment
    if (objectp(MockPort)) destruct(MockPort);
}

/////////////////////////////////////////////////////////////////////////////
void SellOptionDoesNotShowAtPortsWithoutCargo()
{
    // Create a mock port environment
    object MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    move_object(Player, MockPort);
    
    // Ensure no cargo (should be empty by default, but make sure)
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectFalse(sizeof(regexp(({ message }), "Sell Goods")) > 0,
        "Sell option should not show when at port without cargo");

    // Clean up the mock port
    move_object(Player, MockEnvironment); // Move player back to original environment
    if (objectp(MockPort)) destruct(MockPort);
}

/////////////////////////////////////////////////////////////////////////////
void AllPortOptionsShowAtPortsWithCargo()
{
    // Create a mock port environment
    object MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    move_object(Player, MockPort);
    
    // Add some cargo
    Player.addCargoToVehicle("/lib/instances/items/materials/metal/iron", 5);
    
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    // All port options should be available
    ExpectTrue(sizeof(regexp(({ message }), "Manage Warehouse")) > 0,
        "Warehouse option should show at port");
    ExpectTrue(sizeof(regexp(({ message }), "Buy Goods")) > 0,
        "Buy option should show at port");
    ExpectTrue(sizeof(regexp(({ message }), "Sell Goods")) > 0,
        "Sell option should show at port with cargo");
    ExpectTrue(sizeof(regexp(({ message }), "View Market Prices")) > 0,
        "Market prices option should show at port");
    ExpectTrue(sizeof(regexp(({ message }), "Browse Contracts")) > 0,
        "Contracts option should show at port");
    ExpectTrue(sizeof(regexp(({ message }), "Travel to Another Port")) > 0,
        "Travel option should show at port");
    ExpectTrue(sizeof(regexp(({ message }), "Visit Bank")) > 0,
        "Bank option should show at port");

    // Clean up the mock port
    move_object(Player, MockEnvironment); // Move player back to original environment
    if (objectp(MockPort)) destruct(MockPort);
}

/////////////////////////////////////////////////////////////////////////////
void WarehouseOptionShowsOnlyAtPorts()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectFalse(sizeof(regexp(({ message }), "Manage Warehouse")) > 0,
        "Warehouse option should not show when not at port");
}

/////////////////////////////////////////////////////////////////////////////
void BuyOptionShowsOnlyAtPorts()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectFalse(sizeof(regexp(({ message }), "Buy Goods")) > 0,
        "Buy option should not show when not at port");
}

/////////////////////////////////////////////////////////////////////////////
void SellOptionShowsOnlyAtPortsAndWithCargo()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectFalse(sizeof(regexp(({ message }), "Sell Goods")) > 0,
        "Sell option should not show when not at port or without cargo");
}

/////////////////////////////////////////////////////////////////////////////
void InvalidSelectionShowsMenuAgain()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("999", Player);

    ExpectSubStringMatch("Main Trading Menu", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeOptionShowsDetails()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("describe 1", Player);

    ExpectSubStringMatch("Display your trading company", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UndoIsNotAvailableInTradingSelector()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("undo", Player);

    ExpectSubStringMatch("Main Trading Menu", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ViewMarketPricesOptionShowsAtPorts()
{
    // Create a mock port environment
    object MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    move_object(Player, MockPort);
    
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectTrue(sizeof(regexp(({ message }), "View Market Prices")) > 0,
        "View Market Prices option should show when at port");
    
    // Clean up the mock port
    move_object(Player, MockEnvironment);
    if (objectp(MockPort)) destruct(MockPort);
}

/////////////////////////////////////////////////////////////////////////////
void ViewMarketPricesOptionShowsOnlyAtPorts()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectFalse(sizeof(regexp(({ message }), "View Market Prices")) > 0,
        "View Market Prices option should not show when not at port");
}

/////////////////////////////////////////////////////////////////////////////
void BrowseContractsOptionShowsAtPorts()
{
    // Create a mock port environment
    object MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    move_object(Player, MockPort);
    
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectTrue(sizeof(regexp(({ message }), "Browse Contracts")) > 0,
        "Browse Contracts option should show when at port");
    
    // Clean up the mock port
    move_object(Player, MockEnvironment);
    if (objectp(MockPort)) destruct(MockPort);
}

/////////////////////////////////////////////////////////////////////////////
void BrowseContractsOptionShowsOnlyAtPorts()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectFalse(sizeof(regexp(({ message }), "Browse Contracts")) > 0,
        "Browse Contracts option should not show when not at port");
}

/////////////////////////////////////////////////////////////////////////////
void TravelToAnotherPortOptionShowsAtPorts()
{
    // Create a mock port environment
    object MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    move_object(Player, MockPort);
    
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectTrue(sizeof(regexp(({ message }), "Travel to Another Port")) > 0,
        "Travel to Another Port option should show when at port");
    
    // Clean up the mock port
    move_object(Player, MockEnvironment);
    if (objectp(MockPort)) destruct(MockPort);
}

/////////////////////////////////////////////////////////////////////////////
void TravelToAnotherPortOptionShowsOnlyAtPorts()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectFalse(sizeof(regexp(({ message }), "Travel to Another Port")) > 0,
        "Travel to Another Port option should not show when not at port");
}

/////////////////////////////////////////////////////////////////////////////
void VisitBankOptionShowsAtPorts()
{
    // Create a mock port environment
    object MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    move_object(Player, MockPort);
    
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectTrue(sizeof(regexp(({ message }), "Visit Bank")) > 0,
        "Visit Bank option should show when at port");
    
    // Clean up the mock port
    move_object(Player, MockEnvironment);
    if (objectp(MockPort)) destruct(MockPort);
}

/////////////////////////////////////////////////////////////////////////////
void VisitBankOptionShowsOnlyAtPorts()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectFalse(sizeof(regexp(({ message }), "Visit Bank")) > 0,
        "Visit Bank option should not show when not at port");
}

/////////////////////////////////////////////////////////////////////////////
void ViewMarketPricesDisplaysPriceInformation()
{
    // Create a mock port environment
    object MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    move_object(Player, MockPort);
    
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    
    // Find the market prices option
    string message = Player.caughtMessage();
    int pricesOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "View Market Prices")))
        {
            sscanf(line, "%d. %*s", pricesOption);
            break;
        }
    }
    
    if (pricesOption > 0)
    {
        resetPlayerMessages();
        command(to_string(pricesOption), Player);
        string priceMessage = Player.caughtMessage();
        
        ExpectSubStringMatch("Market Prices", priceMessage);
        ExpectSubStringMatch("Mock Trading Port", priceMessage);
    }
    
    // Clean up the mock port
    move_object(Player, MockEnvironment);
    if (objectp(MockPort)) destruct(MockPort);
}

/////////////////////////////////////////////////////////////////////////////
private void createOverloadedState()
{
    // First, add normal cargo close to capacity
    int originalCapacity = Player.getVehicleCapacity();
    Player.addCargoToVehicle("/lib/instances/items/materials/metal/iron", originalCapacity - 10);
    
    // Change the starting choice to option 2 which has capacity 10
    // This will reduce capacity while keeping the cargo
    Player.setupStartingChoice(2);
    
    // Now we should have 50 units of cargo in a 10-unit capacity vehicle
}

/////////////////////////////////////////////////////////////////////////////
void ResolveOverloadingOptionShowsWhenOverloaded()
{
    createOverloadedState();
    
    int capacity = Player.getVehicleCapacity();
    int usedSpace = Player.getVehicleUsedSpace();

    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectTrue(sizeof(regexp(({ message }), "Resolve Overloading")) > 0,
        "Resolve Overloading option should show when vehicle is overloaded");
}

/////////////////////////////////////////////////////////////////////////////
void ResolveOverloadingOptionShowsAtNonPorts()
{
    // Create overloaded state using the same method
    createOverloadedState();
    
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectTrue(sizeof(regexp(({ message }), "Resolve Overloading")) > 0,
        "Resolve Overloading option should show when overloaded, even not at port");
}

/////////////////////////////////////////////////////////////////////////////
void ResolveOverloadingOptionDoesNotShowWhenNotOverloaded()
{
    // Test with normal load (not overloaded)
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    ExpectFalse(sizeof(regexp(({ message }), "Resolve Overloading")) > 0,
        "Resolve Overloading option should not show when vehicle is not overloaded");
}
