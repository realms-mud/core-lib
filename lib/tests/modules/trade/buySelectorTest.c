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
    ignoreList += ({ 
        "resetPlayerMessages", 
        "getMenuOptionNumber",
        "findCategoryOption",
        "findItemOption",
        "findDisabledItemOption",
        "findEnabledItemOption",
        "setupPlayerWithCash",
        "selectCategory",
        "navigateToItems"
    });
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

    // Create a mock port environment
    MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    MockPort->setPortName("Mock Trading Port");

    // Add a vehicle so the player can actually buy things
    Player.addVehicle("wagon", MockPort->getPortName());
    
    // Set the port on the buySelector
    BuySelector.setPort(MockPort);
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
private string findCategoryOption()
{
    string ret = "0";
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        // Remove ANSI codes for matching
        line = regreplace(line, "\x1B\\[[0-9;]*[A-Za-z]", "", 1);
        if (sizeof(regexp(({ line }), "available\\)")))
        {
            ret = regreplace(line, "^[^0-9]*([0-9]+).*", "\\1", 1);
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string findItemOption()
{
    string ret = "0";
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        // Remove ANSI codes for matching
        line = regreplace(line, "\x1B\\[[0-9;]*[A-Za-z]", "", 1);
        // Look for lines that don't contain "available\\)" or "Return" or "Categories"
        if (sizeof(regexp(({ line }), "^[^0-9]*[0-9]+")) && 
            !sizeof(regexp(({ line }), "available\\)")) &&
            !sizeof(regexp(({ line }), "Return")) &&
            !sizeof(regexp(({ line }), "Categories")))
        {
            ret = regreplace(line, "^[^0-9]*([0-9]+).*", "\\1", 1);
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string findDisabledItemOption()
{
    string ret = "0";
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        // Remove ANSI codes for matching
        line = regreplace(line, "\x1B\\[[0-9;]*[A-Za-z]", "", 1);
        // Look for lines that contain X marker (disabled items)
        if (sizeof(regexp(({ line }), " X")) > 0 && 
            sizeof(regexp(({ line }), "^[^0-9]*[0-9]+")))
        {
            ret = regreplace(line, "^[^0-9]*([0-9]+).*", "\\1", 1);
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string findEnabledItemOption()
{
    string ret = "0";
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        // Remove ANSI codes for matching
        line = regreplace(line, "\x1B\\[[0-9;]*[A-Za-z]", "", 1);
        // Look for item lines that don't have X marker and aren't navigation
        if (sizeof(regexp(({ line }), "^[^0-9]*[0-9]+")) && 
            !sizeof(regexp(({ line }), " X")) &&
            !sizeof(regexp(({ line }), "available\\)")) &&
            !sizeof(regexp(({ line }), "Return")) &&
            !sizeof(regexp(({ line }), "Categories")))
        {
            ret = regreplace(line, "^[^0-9]*([0-9]+).*", "\\1", 1);
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private void setupPlayerWithCash(int cashAmount)
{
    if (cashAmount > 0)
    {
        Player.setupStartingChoice(1);
        if (cashAmount > 400)
        {
            Player.addCash(cashAmount - 400);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private void selectCategory()
{
    string categoryOption = findCategoryOption();
    if (categoryOption != "0")
    {
        command(categoryOption, Player);
    }
}

/////////////////////////////////////////////////////////////////////////////
private void navigateToItems()
{
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    selectCategory();
}

/////////////////////////////////////////////////////////////////////////////
void BuySelectorDisplaysCategoryMenuCorrectly()
{
    setupPlayerWithCash(400);
  
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    
    ExpectSubStringMatch("Purchase - Buy Goods", message);
    ExpectSubStringMatch("Return to", message);
    ExpectSubStringMatch("available", message); // Should show categories with availability counts
}

/////////////////////////////////////////////////////////////////////////////
void BuySelectorRequiresValidPortToBeSet()
{
    // Create selector without setting port
    object TestSelector = clone_object("/lib/modules/domains/trading/selectors/buySelector.c");
    move_object(TestSelector, Player);
    
    resetPlayerMessages();
    TestSelector.initiateSelector(Player);

    string message = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("No valid trading port has been selected", message);
    ExpectSubStringMatch("Return to Trading Menu", message);
    
    destruct(TestSelector);
}

/////////////////////////////////////////////////////////////////////////////
void BuySelectorWorksWithSetPort()
{
    setupPlayerWithCash(400);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    // Should show port-specific content
    ExpectTrue(sizeof(regexp(({ message }), MockPort->getPortName())) > 0,
        "Should reference the set port name");
}

/////////////////////////////////////////////////////////////////////////////
void CategoriesShowWhenPlayerCanAffordThem()
{
    setupPlayerWithCash(400);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    // Should show at least some categories with availability counts
    ExpectTrue(sizeof(regexp(({ message }), "available\\)")) > 0,
        "Should show categories with availability counts when player has cash");
}

/////////////////////////////////////////////////////////////////////////////
void CategoriesShowWhenPlayerCannotAffordThem()
{
    // Player starts with 0 cash by default
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    // Should show categories but they should all be disabled with X markers
    ExpectSubStringMatch("Return to", message);
    ExpectTrue(sizeof(regexp(({ message }), "available\\)")) > 0,
        "Should show categories with availability counts when player has no cash");
    ExpectTrue(sizeof(regexp(({ message }), " X")) > 0,
        "Should show X indicator for disabled categories when player has no cash");
}

/////////////////////////////////////////////////////////////////////////////
void CommonTradeCategoriesAreAvailable()
{
    setupPlayerWithCash(10000);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    // Check for common trade categories that should be available
    ExpectTrue(sizeof(regexp(({ message }), "Metal")) > 0 || 
               sizeof(regexp(({ message }), "Wood")) > 0 ||
               sizeof(regexp(({ message }), "Food")) > 0,
        "Should show common trade categories");
}

/////////////////////////////////////////////////////////////////////////////
void SelectingCategoryShowsItems()
{
    setupPlayerWithCash(1000);
    
    navigateToItems();
    
    string message = Player.caughtMessage();
    // Should now show individual items, not categories
    ExpectSubStringMatch("Return to the category selection menu", message);
    ExpectFalse(sizeof(regexp(({ message }), "available\\)")) > 0,
        "Should not show category availability counts in item view");
}

/////////////////////////////////////////////////////////////////////////////
void SelectingItemOpensQuantitySelector()
{
    setupPlayerWithCash(1000);
    
    navigateToItems();
    
    string itemOption = findEnabledItemOption();

    command(itemOption, Player);
    string quantityMessage = Player.caughtMessage();
        
    ExpectSubStringMatch("How many .* would you like to buy", quantityMessage);
}

/////////////////////////////////////////////////////////////////////////////
void ReturnToCategoriesWorks()
{
    setupPlayerWithCash(1000);
    
    navigateToItems();
    
    // Verify we're in the items view first
    string itemsMessage = Player.caughtMessage();
    ExpectSubStringMatch("Return to the category selection menu", itemsMessage);
    
    command(getMenuOptionNumber("Return to the category selection menu."), Player);
    
    string message = Player.caughtMessage();
    ExpectSubStringMatch("available\\)", message); // Back to category view
    ExpectSubStringMatch("Return to.*Menu", message); // Should show port menu return
}

/////////////////////////////////////////////////////////////////////////////
void ExitFromCategoriesReturnsToPortMenu()
{
    setupPlayerWithCash(400);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    
    command(getMenuOptionNumber("Return to.*Menu"), Player);
    ExpectSubStringMatch("You have selected 'Return to Mock Trading Port Menu'", 
        Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void InvalidSelectionShowsMenuAgain()
{
    setupPlayerWithCash(400);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    resetPlayerMessages();
    command("999", Player);

    ExpectSubStringMatch("Buy Goods", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescribeOptionShowsCategoryDetails()
{
    setupPlayerWithCash(1000);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    resetPlayerMessages();
    command("describe 1", Player);

    string message = Player.caughtMessage();
    ExpectTrue(sizeof(regexp(({ message }), "Browse")) > 0,
        "Should show category browse details");
}

/////////////////////////////////////////////////////////////////////////////
void DescribeOptionShowsItemDetails()
{
    setupPlayerWithCash(1000);
    
    navigateToItems();
    resetPlayerMessages();
    command("describe 1", Player);

    string message = Player.caughtMessage();
    ExpectTrue(sizeof(regexp(({ message }), "Purchase")) > 0,
        "Should show item purchase details");
}

/////////////////////////////////////////////////////////////////////////////
void UndoIsAvailableInBuySelector()
{
    setupPlayerWithCash(400);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    resetPlayerMessages();
    command("undo", Player);

    string message = Player.caughtMessage();
    ExpectTrue(sizeof(message) > 0, "Undo should provide some response");
}

/////////////////////////////////////////////////////////////////////////////
void CategoryAvailabilityCalculationIsCorrect()
{
    setupPlayerWithCash(400);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    
    // Simple assertion: should show at least one category with availability
    ExpectTrue(sizeof(regexp(({ message }), "\\([0-9]+/[0-9]+ available\\)")) > 0,
        "Should show categories with availability format");
}

/////////////////////////////////////////////////////////////////////////////
void DisabledCategoriesShowXIndicator()
{
    setupPlayerWithCash(10); // Very limited cash
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    
    string message = Player.caughtMessage();
    
    // Simple assertions: should show categories and some should be disabled
    ExpectSubStringMatch("available\\)", message);
    ExpectSubStringMatch(" X", message);
}

/////////////////////////////////////////////////////////////////////////////
void EnabledCategoriesDoNotShowXIndicator()
{
    setupPlayerWithCash(50000); // Lots of cash
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    
    string message = Player.caughtMessage();
    
    // Should show categories but none should be disabled
    ExpectSubStringMatch("available\\)", message);
    // Most categories should not have X markers with lots of cash
    int totalLines = sizeof(explode(message, "\n"));
    int disabledLines = sizeof(regexp(explode(message, "\n"), " X"));
    ExpectTrue(disabledLines < totalLines / 2, "Most categories should be enabled with sufficient cash");
}

/////////////////////////////////////////////////////////////////////////////
void ItemsShowXIndicatorWhenUnaffordable()
{
    setupPlayerWithCash(300); // Limited cash
    
    navigateToItems();
    
    string message = Player.caughtMessage();
    
    // Should show some items with X indicators
    ExpectSubStringMatch(" X", message);
}

/////////////////////////////////////////////////////////////////////////////
void ItemsWithoutXIndicatorAreSelectable()
{
    setupPlayerWithCash(1000);
    
    navigateToItems();
    
    string enabledOption = findEnabledItemOption();
    ExpectTrue(enabledOption != "0", "Should find at least one enabled item");
    
    resetPlayerMessages();
    command(enabledOption, Player);
    
    // Should open quantity selector
    ExpectSubStringMatch("How many", Player.caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ItemsWithXIndicatorAreNotSelectable()
{
    setupPlayerWithCash(300); // Limited cash to create disabled items
    
    navigateToItems();
    
    string disabledOption = findDisabledItemOption();
    ExpectTrue(disabledOption != "0", "Should find at least one disabled item");
    
    resetPlayerMessages();
    command(disabledOption, Player);

    // Should show error message
    ExpectSubStringMatch("cannot afford that item or lack cargo capacity", 
        implode(Player.caughtMessages(), "\n"));
}

/////////////////////////////////////////////////////////////////////////////
void VehicleCapacityIsConsidered()
{
    setupPlayerWithCash(10000);
    
    // Add a vehicle first
    Player.addVehicle("wagon", MockPort->getPortName());
    object *vehicles = Player->getVehicles();

    ExpectTrue(sizeof(vehicles) > 0, "Should have at least one vehicle for capacity test");
    ExpectTrue(vehicles[0]->addCargo("/lib/instances/items/materials/metal/iron.c", 8));

    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    // Should still show categories, some may be disabled due to capacity
    ExpectSubStringMatch("Return to", message);
    ExpectTrue(sizeof(regexp(({ message }), "available\\)")) > 0,
        "Should show categories even with reduced capacity");
}

/////////////////////////////////////////////////////////////////////////////
void CapacityConstraintsAreDisplayedInItemDescriptions()
{
    setupPlayerWithCash(1000);
    
    navigateToItems();
    resetPlayerMessages();
    command("describe 1", Player);

    string message = Player.caughtMessage();
    ExpectTrue(sizeof(regexp(({ message }), "capacity allows")) > 0,
        "Should show capacity constraints in item descriptions");
}

/////////////////////////////////////////////////////////////////////////////
void AllCategoriesShowWithSufficientFunds()
{
    setupPlayerWithCash(50000);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    
    int categoryCount = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "available\\)")))
        {
            categoryCount++;
        }
    }
    
    ExpectTrue(categoryCount > 1, "Should show multiple categories when player has sufficient funds");
}

/////////////////////////////////////////////////////////////////////////////
void BuySelectorHandlesEmptyCashState()
{
    // Player with no cash
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Return to", message);
    // Should show categories but they should be disabled with X markers
    ExpectTrue(sizeof(regexp(({ message }), "available\\)")) > 0,
        "Should show categories even when player has no cash");
    ExpectTrue(sizeof(regexp(({ message }), " X")) > 0,
        "Should show X indicator for disabled categories");
}

/////////////////////////////////////////////////////////////////////////////
void PortSpecificPricingIsUsed()
{
    setupPlayerWithCash(1000);
    
    navigateToItems();
    resetPlayerMessages();
    command("describe 1", Player);

    string message = Player.caughtMessage();
    ExpectTrue(sizeof(regexp(({ message }), "gold")) > 0,
        "Should display port-specific item prices in descriptions");
    ExpectTrue(sizeof(regexp(({ message }), MockPort->getPortName())) > 0,
        "Should reference the specific port being used");
}

/////////////////////////////////////////////////////////////////////////////
void ItemDescriptionsIncludeAffordabilityAndCapacity()
{
    setupPlayerWithCash(1000);
    
    navigateToItems();
    resetPlayerMessages();
    command("describe 1", Player);

    string message = Player.caughtMessage();
    ExpectTrue(sizeof(regexp(({ message }), "You can afford")) > 0 ||
               sizeof(regexp(({ message }), "capacity allows")) > 0,
        "Item descriptions should include affordability and capacity information");
}

/////////////////////////////////////////////////////////////////////////////
void SelectorSupportsUndo()
{
    setupPlayerWithCash(400);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("You may also undo or reset", message);
}

/////////////////////////////////////////////////////////////////////////////
void SelectorSupportsExit()
{
    setupPlayerWithCash(400);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Type 'exit' if you do not wish", message);
}

/////////////////////////////////////////////////////////////////////////////
void PortNameAppearsInMenuItems()
{
    setupPlayerWithCash(1000);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    string portName = MockPort->getPortName();
    
    ExpectTrue(sizeof(regexp(({ message }), portName)) > 0,
        sprintf("Port name '%s' should appear in the menu", portName));
}

/////////////////////////////////////////////////////////////////////////////
void NoCapacityShowsError()
{
    setupPlayerWithCash(1000);
    
    // Add a vehicle and fill all capacity
    object *vehicles = Player->getVehicles();
    string itemOption = "0";
    
    ExpectTrue(sizeof(vehicles) > 0, "Should have at least one vehicle for capacity test");
    ExpectTrue(vehicles[0]->getCapacity() == 8, "Vehicle should have 8 capacity");
    ExpectTrue(vehicles[0]->addCargo("/lib/instances/items/materials/metal/iron.c", 8));

    ExpectTrue(vehicles[0]->getFreeSpace() == 0, "Vehicle should have 0 free space");

    navigateToItems();
    itemOption = findDisabledItemOption(); // Look for disabled items specifically
    
    command(itemOption, Player);
    string errorMessage = implode(Player.caughtMessages(), "\n");
        
    ExpectSubStringMatch("That category has no affordable items", errorMessage);
}

/////////////////////////////////////////////////////////////////////////////
void ItemsShowCorrectMaxQuantityBasedOnCapacity()
{
    setupPlayerWithCash(50000);
    
    object *vehicles = Player->getVehicles();
    
    ExpectTrue(sizeof(vehicles) > 0, "Should have at least one vehicle for capacity test");
    vehicles[0]->addCargo("/lib/instances/items/materials/metal/iron.c", 4);
    
    navigateToItems();
    resetPlayerMessages();
    command("describe 1", Player);

    string message = Player.caughtMessage();
    ExpectTrue(sizeof(regexp(({ message }), "capacity allows")) > 0,
        "Should show capacity-constrained quantities");
}

/////////////////////////////////////////////////////////////////////////////
void DisabledItemsShowProperMessage()
{
    setupPlayerWithCash(1000);
    
    object *vehicles = Player->getVehicles();
    
    ExpectTrue(sizeof(vehicles) > 0, "Should have at least one vehicle for capacity test");
    vehicles[0]->addCargo("/lib/instances/items/materials/metal/iron.c", 8);
    
    navigateToItems();
    
    string disabledOption = findDisabledItemOption();

    resetPlayerMessages();
    command(disabledOption, Player);

    string message = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("That category has no affordable items", message);
}

/////////////////////////////////////////////////////////////////////////////
void DisabledItemsShowXIndicator()
{
    setupPlayerWithCash(500); // Limited cash to create some disabled items
    
    navigateToItems();
    
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    
    int disabledItemsFound = 0;
    foreach (string line in lines)
    {
        // Look for item lines that contain X marker
        if (sizeof(regexp(({ line }), "\\) X")) > 0)
        {
            disabledItemsFound++;

            ExpectTrue(sizeof(regexp(({ line }), "\\([ 0-9.]+[KMg ]+\\)")) > 0,
                "Disabled items should show price information");
        }
    }
    
    // With limited cash, there should be some disabled items
    ExpectTrue(disabledItemsFound > 0, "Should find disabled items marked with X");
}

/////////////////////////////////////////////////////////////////////////////
void DisabledItemsCannotBeSelected()
{
    setupPlayerWithCash(500); // Limited cash
    
    navigateToItems();
    
    string disabledOption = findDisabledItemOption();
    command(disabledOption, Player);
        
    string errorMessage = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("cannot afford that item or lack cargo capacity", errorMessage);
    // Should redisplay the menu, not exit
    ExpectSubStringMatch("Return to the category selection menu", errorMessage);
}

/////////////////////////////////////////////////////////////////////////////
void EnabledAndDisabledItemsFormatConsistently()
{
    setupPlayerWithCash(1000); // Enough for some items, not others
    
    navigateToItems();
    
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    
    string *itemLines = ({});
    foreach (string line in lines)
    {
        // Find lines that look like item entries (have prices)
        if (sizeof(regexp(({ line }), "\\[[0-9 ]+\\].*\\([0-9.]+[KMg ]+\\)")) > 0)
        {
            itemLines += ({ line });
        }
    }
    
    ExpectTrue(sizeof(itemLines) > 0, "Should find item lines to test formatting");
    
    // Check that both enabled and disabled items follow consistent formatting
    foreach (string line in itemLines)
    {
        // All item lines should have proper number formatting
        ExpectTrue(sizeof(regexp(({ line }), "\\[[0-9]+\\]")) > 0,
            "Item lines should have properly formatted numbers");
        
        // All item lines should have price information
        ExpectTrue(sizeof(regexp(({ line }), "\\([0-9. ]+[KMg ]+\\)")) > 0,
            "Item lines should have price information");
    }
}

/////////////////////////////////////////////////////////////////////////////
void XIndicatorWorksWithNoneColorConfiguration()
{
    Player.colorConfiguration("none");
    setupPlayerWithCash(200); // Very limited cash to create disabled items
    
    navigateToItems();
    
    string message = Player.caughtMessage();
    
    // With "none" color configuration, X should still be visible
    ExpectTrue(sizeof(regexp(({ message }), " X")) > 0,
        "Disabled indicator X should be visible even with 'none' color configuration");
}

/////////////////////////////////////////////////////////////////////////////
void XIndicatorWorksWithUnicodeConfiguration()
{
    Player.charsetConfiguration("unicode");
    Player.colorConfiguration("none");
    setupPlayerWithCash(200); // Very limited cash
    
    navigateToItems();
    
    string message = Player.caughtMessage();
    
    ExpectTrue(sizeof(regexp(({ message }), "\u2717")) > 0,
        "Should show Unicode \\u2717 character for disabled items with unicode charset");
}

/////////////////////////////////////////////////////////////////////////////
void DescribeWorksForAllMenuOptionsInCategories()
{
    setupPlayerWithCash(1000);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    string exitOption = getMenuOptionNumber("Return to.*Menu");
    int maxOption = to_int(exitOption);

    for (int i = 1; i <= maxOption; i++)
    {
        resetPlayerMessages();
        command("describe " + to_string(i), Player);
        string desc = Player.caughtMessage();
        ExpectTrue(sizeof(desc) > 0, "Describe should provide some response for category option " + to_string(i));
    }
}

/////////////////////////////////////////////////////////////////////////////
void DescribeWorksForAllMenuOptionsInItems()
{
    setupPlayerWithCash(1000);
    
    navigateToItems();
    string exitOption = getMenuOptionNumber("Return to the category selection menu");
    int maxOption = to_int(exitOption);

    for (int i = 1; i <= maxOption; i++)
    {
        resetPlayerMessages();
        command("describe " + to_string(i), Player);
        string desc = Player.caughtMessage();
        ExpectTrue(sizeof(desc) > 0, "Describe should provide some response for item option " + to_string(i));
    }
}

/////////////////////////////////////////////////////////////////////////////
void MenuAlwaysIncludesExit()
{
    // Test categories view with no cash
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    string message = Player.caughtMessage();
    ExpectSubStringMatch("Return to.*Menu", message);
    
    // Test categories view with cash
    setupPlayerWithCash(1000);
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    message = Player.caughtMessage();
    ExpectSubStringMatch("Return to.*Menu", message);
    
    // Test items view
    navigateToItems();
    message = Player.caughtMessage();
    ExpectSubStringMatch("Return to the category selection menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void CategoryCountsAreAccurate()
{
    setupPlayerWithCash(1000);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "\\(([0-9]+)/([0-9]+) available\\)")))
        {
            // Extract category name and count
            string categoryLine = regreplace(line, "\x1B\\[[0-9;]*[A-Za-z]", "", 1);
            string availableStr, totalStr;
            if (sscanf(categoryLine, "%*s (%s/%s available\\)", availableStr, totalStr) == 2)
            {
                int availableCount = to_int(availableStr);
                int totalCount = to_int(totalStr);
                ExpectTrue(availableCount >= 0, "Available count should be >= 0");
                ExpectTrue(totalCount > 0, "Total count should be greater than 0");
                ExpectTrue(totalCount < 200, "Total count should be reasonable (< 200)");
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void HierarchicalNavigationMaintainsState()
{
    setupPlayerWithCash(1000);
    
    // Start at categories
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    ExpectSubStringMatch("available\\)", Player.caughtMessage());
    
    // Navigate to items
    selectCategory();
    ExpectSubStringMatch("Return to the category selection menu", 
        implode(Player.caughtMessages(), "\n"));
    
    command(getMenuOptionNumber("Return to the category selection menu."), Player);

    string message = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("available\\)", message);
    ExpectSubStringMatch("Return to.*Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void AllCategoriesAreAlwaysShown()
{
    // Player with very limited cash that can't afford anything in some categories
    setupPlayerWithCash(10);
    
    resetPlayerMessages();
    BuySelector.initiateSelector(Player);
    
    string message = Player.caughtMessage();
    // All categories should be shown, even with 0 available items
    ExpectTrue(sizeof(regexp(({ message }), "available\\)")) > 0,
        "Categories should be shown even when no items are affordable");
    
    // Should have some disabled categories marked with X
    ExpectTrue(sizeof(regexp(({ message }), " X")) > 0,
        "Should show X markers for categories with no affordable items");
}

/////////////////////////////////////////////////////////////////////////////
void ExpensiveItemsShowAbbreviatedPrices()
{
    setupPlayerWithCash(50000); // Lots of cash to see expensive items
    
    navigateToItems();
    
    string message = Player.caughtMessage();
    // Should show abbreviated prices for expensive items (1K, 2.5K, etc.)
    ExpectTrue(sizeof(regexp(({ message }), "\\([0-9.]+K")) > 0 ||
               sizeof(regexp(({ message }), "\\([0-9.]+M")) > 0,
        "Should show abbreviated prices for expensive items (K, M format)");
}

/////////////////////////////////////////////////////////////////////////////
void PriceAbbreviationIsConsistent()
{
    setupPlayerWithCash(50000);
    
    navigateToItems();
    
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    
    foreach (string line in lines)
    {
        // Check lines with prices
        if (sizeof(regexp(({ line }), "\\([0-9.]+[KM]g\\)")))
        {
            // Abbreviated prices should be properly formatted
            ExpectTrue(sizeof(regexp(({ line }), "\\([0-9]+\\.[0-9][KM]g\\)")) > 0 ||
                       sizeof(regexp(({ line }), "\\([0-9]+[KM]g\\)")) > 0,
                "Abbreviated prices should be formatted correctly");
        }
        else if (sizeof(regexp(({ line }), "\\([0-9]+g\\)")))
        {
            // Regular prices should be under 1000
            string priceStr;
            if (sscanf(line, "%*s (%sg)", priceStr) == 1)
            {
                int price = to_int(priceStr);
                ExpectTrue(price < 1000, "Regular prices should be less than 1000 gold");
            }
        }
    }
}
