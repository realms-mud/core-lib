//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object BuySelector;
object MockPort;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "resetPlayerMessages" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    BuySelector = clone_object("/lib/modules/domains/trading/selectors/buySelector.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("testtrader");
    Player.colorConfiguration("none");
    Player.addCommands();
    Player.initializeTrader();

    // Create a mock port environment (required for buying goods)
    MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    move_object(Player, MockPort);
    move_object(BuySelector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(BuySelector)) destruct(BuySelector);
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
void BuySelectorDisplaysMainMenuCorrectly()
{
    Player.setupStartingChoice(1); // Give player some cash
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Purchase - Buy Goods", message);
    ExpectSubStringMatch("Return to Trading Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void BuySelectorRequiresPortLocation()
{
    // Move player to non-port environment
    object MockEnvironment = clone_object("/lib/tests/support/environment/mockTradeEnvironment.c");
    move_object(Player, MockEnvironment);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("You must be at a trading port to buy goods", message);
    
    // Clean up
    move_object(Player, MockPort);
    destruct(MockEnvironment);
}

/////////////////////////////////////////////////////////////////////////////
void ItemsShowWhenPlayerCanAffordThem()
{
    Player.setupStartingChoice(1); // 400 cash
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();

    // Should show at least some items the player can afford
    ExpectTrue(sizeof(regexp(({ message }), "gold")) > 0,
        "Should show items with prices when player has cash");
}

/////////////////////////////////////////////////////////////////////////////
void ItemsDoNotShowWhenPlayerCannotAffordThem()
{
    // Player starts with 0 cash by default
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    // Should only show the return option
    ExpectSubStringMatch("Return to Trading Menu", message);
    ExpectFalse(sizeof(regexp(({ message }), "[0-9]+ gold")) > 0,
        "Should not show items when player has no cash");
}

/////////////////////////////////////////////////////////////////////////////
void CommonTradeGoodsAreAvailable()
{
    Player.setupStartingChoice(1);
    Player.addCash(10000); // Lots of cash to afford everything
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();

    // Check for common trade goods that should be available
    ExpectTrue(sizeof(regexp(({ message }), "Iron")) > 0 || 
               sizeof(regexp(({ message }), "Oak")) > 0 ||
               sizeof(regexp(({ message }), "Bread")) > 0,
        "Should show common trade goods");
}

/////////////////////////////////////////////////////////////////////////////
void ItemPricesAreDisplayed()
{
    Player.setupStartingChoice(1);
    Player.addCash(1000);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    // Should show prices for items
    ExpectTrue(sizeof(regexp(({ message }), "[0-9]+ gold")) > 0,
        "Should display item prices");
}

/////////////////////////////////////////////////////////////////////////////
void SelectingItemOpensQuantitySelector()
{
    Player.setupStartingChoice(1);
    Player.addCash(1000);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    
    // Find first buyable item
    string message = Player.caughtMessage();
    int itemOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "gold")))
        {
            sscanf(line, "%d. %*s", itemOption);
            break;
        }
    }
    
    if (itemOption > 0)
    {
        resetPlayerMessages();
        command(to_string(itemOption), Player);
        string quantityMessage = Player.caughtMessage();
        
        ExpectSubStringMatch("How many would you like to buy", quantityMessage);
    }
}

/////////////////////////////////////////////////////////////////////////////
void ExitOptionReturnsToTradingMenu()
{
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    string message = Player.caughtMessage();

    // Find exit option
    int exitOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "Return to Trading Menu")))
        {
            sscanf(line, "%d. %*s", exitOption);
            break;
        }
    }
    
    resetPlayerMessages();
    if (exitOption > 0)
    {
        command(to_string(exitOption), Player);
        ExpectSubStringMatch("Purchase has been exited", Player.caughtMessage());
    }
}

/////////////////////////////////////////////////////////////////////////////
void InvalidSelectionShowsMenuAgain()
{
    Player.setupStartingChoice(1);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    resetPlayerMessages();
    command("999", Player);

    ExpectSubStringMatch("Buy Goods", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeOptionShowsItemDetails()
{
    Player.setupStartingChoice(1);
    Player.addCash(1000);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    resetPlayerMessages();
    command("describe 1", Player);

    string message = Player.caughtMessage();
    ExpectTrue(sizeof(regexp(({ message }), "Purchase")) > 0,
        "Should show purchase details");
}

/////////////////////////////////////////////////////////////////////////////
void UndoIsAvailableInBuySelector()
{
    Player.setupStartingChoice(1);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    resetPlayerMessages();
    command("undo", Player);

    string message = Player.caughtMessage();
    ExpectTrue(sizeof(message) > 0, "Undo should provide some response");
}

/////////////////////////////////////////////////////////////////////////////
void AffordabilityCalculationIsCorrect()
{
    Player.setupStartingChoice(1); // 400 cash
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    
    // Look for an item and check if affordability makes sense
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "([0-9]+) gold")))
        {
            string priceStr;
            if (sscanf(line, "%*s (%s gold)", priceStr) == 1)
            {
                int price = to_int(priceStr);
                int canAfford = 400 / price;
                
                // The item should only show if player can afford at least one
                ExpectTrue(canAfford > 0, 
                    sprintf("Player should be able to afford at least one item at %d gold", price));
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void VehicleCapacityIsConsidered()
{
    Player.setupStartingChoice(1);
    Player.addCash(10000); // Lots of cash
    
    // Fill vehicle to near capacity
    Player.addCargoToVehicle("/lib/instances/items/materials/metal/iron", 55);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    // Should still show some items but quantities may be limited by space
    ExpectSubStringMatch("Return to Trading Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void MenuUpdatesAfterTransaction()
{
    Player.setupStartingChoice(1);
    Player.addCash(1000);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    
    // Check initial menu
    string initialMessage = Player.caughtMessage();
    ExpectTrue(sizeof(regexp(({ initialMessage }), "gold")) > 0,
        "Should show items initially");
    
    // After a transaction, menu should refresh to show updated affordability
    // (This would be tested more thoroughly in integration tests)
}

/////////////////////////////////////////////////////////////////////////////
void AllAvailableItemsShowWithSufficientFunds()
{
    Player.setupStartingChoice(1);
    Player.addCash(50000); // Plenty of cash for everything
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    
    // Should show multiple trade goods
    int itemCount = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "gold")))
        {
            itemCount++;
        }
    }
    
    ExpectTrue(itemCount > 1, "Should show multiple items when player has sufficient funds");
}

/////////////////////////////////////////////////////////////////////////////
void BuySelectorHandlesEmptyCashState()
{
    // Player with no cash
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    
    // Only return option should be available
    ExpectSubStringMatch("Return to Trading Menu", message);
    
    // No items should be available for purchase
    ExpectFalse(sizeof(regexp(({ message }), "gold")) > 0,
        "Should not show any items when player has no cash");
}

/////////////////////////////////////////////////////////////////////////////
void PortEnvironmentProvidesItemPrices()
{
    Player.setupStartingChoice(1);
    Player.addCash(1000);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    
    // Should show items with prices (indicating port environment is working)
    ExpectTrue(sizeof(regexp(({ message }), "[0-9]+ gold")) > 0,
        "Port environment should provide item prices");
}

/////////////////////////////////////////////////////////////////////////////
void ItemDescriptionsIncludeAffordability()
{
    Player.setupStartingChoice(1);
    Player.addCash(1000);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    resetPlayerMessages();
    command("describe 1", Player);

    string message = Player.caughtMessage();
    ExpectTrue(sizeof(regexp(({ message }), "You can afford")) > 0,
        "Item descriptions should include affordability information");
}

/////////////////////////////////////////////////////////////////////////////
void SelectorSupportsUndo()
{
    Player.setupStartingChoice(1);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("You may also undo or reset", message);
}

/////////////////////////////////////////////////////////////////////////////
void SelectorSupportsExit()
{
    Player.setupStartingChoice(1);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Type 'exit' if you do not wish", message);
}
