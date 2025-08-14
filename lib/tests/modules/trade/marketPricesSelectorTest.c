//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object MarketPricesSelector;
object MockPort1;
object MockPort2;
object TradingDictionary;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({
        "resetPlayerMessages",
        "navigateToMarketPricesSelector",
        "findMenuOption"
    });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("testtrader");
    Player.colorConfiguration("none");
    Player.addCommands();
    Player.initializeTrader();

    // Create two mock ports with different specialties/imports
    MockPort1 = clone_object("/lib/modules/domains/trading/tradingPort.c");
    MockPort1.setPortName("Port Alpha");
    MockPort1.setShortDescription("A bustling port city.");
    MockPort1.setAvailableGoods( ({
        "/lib/instances/items/materials/metal/iron.c",
        "/lib/instances/items/materials/wood/oak.c"
    }) );
    MockPort1.addSpecialty("metal", 0.8);

    MockPort2 = clone_object("/lib/modules/domains/trading/tradingPort.c");
    MockPort2.setPortName("Port Beta");
    MockPort2.setShortDescription("A quiet river port.");
    MockPort2.setAvailableGoods( ({
        "/lib/instances/items/materials/metal/iron.c"
    }) );
    MockPort2.addImportNeed("metal", 1.2);

    // Register ports in the trading dictionary
    TradingDictionary = load_object("/lib/dictionaries/tradingDictionary.c");
    TradingDictionary->registerPort(MockPort1);
    TradingDictionary->registerPort(MockPort2);

    if (objectp(MarketPricesSelector)) destruct(MarketPricesSelector);
    MarketPricesSelector = clone_object("/lib/modules/domains/trading/selectors/marketPricesSelector.c");
    move_object(MarketPricesSelector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(MarketPricesSelector)) destruct(MarketPricesSelector);
    if (objectp(Player)) destruct(Player);
    if (objectp(MockPort1)) destruct(MockPort1);
    if (objectp(MockPort2)) destruct(MockPort2);
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
private void navigateToMarketPricesSelector()
{
    resetPlayerMessages();
    MarketPricesSelector->initiateSelector(Player);
}

/////////////////////////////////////////////////////////////////////////////
private string findMenuOption(string optionText)
{
    string message = Player->caughtMessage();
    string *lines = explode(message, "\n");
    string ret = "0";

    foreach (string line in lines)
    {
        // Remove ANSI codes
        line = regreplace(line, "\x1B\\[[0-9;]*[A-Za-z]", "", 1);

        if(sizeof(regexp(({ line }), optionText, 1)))
        {
            ret = regreplace(line, "^.*[[]([0-9]+)[^-]+- " + optionText + ".*", "\\1", 1);
            break;
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
void MarketPricesSelectorDisplaysCategories()
{
    navigateToMarketPricesSelector();
    string message = implode(Player->caughtMessages(), "\n");

    ExpectSubStringMatch("Market Prices", message);
    ExpectSubStringMatch("Metal", message);
    ExpectSubStringMatch("Wood", message);
    ExpectSubStringMatch("Return to Previous Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void MarketPricesSelectorHandlesInvalidCategoryInput()
{
    navigateToMarketPricesSelector();
    resetPlayerMessages();
    command("999", Player);
    string message = Player->caughtMessage();
    ExpectSubStringMatch("Market Prices", message);
    ExpectSubStringMatch("Metal", message);
}

/////////////////////////////////////////////////////////////////////////////
void MarketPricesSelectorDisplaysItemsAfterCategorySelection()
{
    navigateToMarketPricesSelector();
    string metalOption = findMenuOption("Metal");

    command(metalOption, Player);

    string message = implode(Player->caughtMessages(), "\n");
    ExpectSubStringMatch("Iron", message);
    ExpectSubStringMatch("Platinum", message);
    ExpectSubStringMatch("Return to Previous Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void MarketPricesSelectorHandlesInvalidItemInput()
{
    navigateToMarketPricesSelector();
    string metalOption = findMenuOption("Metal");
    command(metalOption, Player);

    resetPlayerMessages();
    command("999", Player);
    string message = Player->caughtMessage();
    ExpectSubStringMatch("You must select a number from 1 to", message);
    ExpectSubStringMatch("Return to Previous Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void MarketPricesSelectorDisplaysPriceBoardForItem()
{
    navigateToMarketPricesSelector();
    string metalOption = findMenuOption("Metal");
    command(metalOption, Player);

    string ironOption = findMenuOption("Iron");
    command(ironOption, Player);

    string result = Player->caughtMessage();
    ExpectSubStringMatch("One trade unit of Iron", result);
    ExpectSubStringMatch("[A-Za-z]+.*[0-9]+ gold .[+-][0-9]+.[0-9]+", result);
}

/////////////////////////////////////////////////////////////////////////////
void MarketPricesSelectorBackFromItemReturnsToCategory()
{
    navigateToMarketPricesSelector();
    string metalOption = findMenuOption("Metal");
    command(metalOption, Player);

    string returnOption = findMenuOption("Return to Category Selection");
    command(returnOption, Player);

    string message = Player->caughtMessage();
    ExpectSubStringMatch("Market Prices", message);
    ExpectSubStringMatch("Admantite", message);
}

/////////////////////////////////////////////////////////////////////////////
void MarketPricesSelectorBackFromPriceBoardReturnsToItem()
{
    navigateToMarketPricesSelector();
    string metalOption = findMenuOption("Metal");
    command(metalOption, Player);

    string ironOption = findMenuOption("Iron");
    command(ironOption, Player);

    string returnOption = findMenuOption("Return to Item Selection");
    command(returnOption, Player);

    string message = Player->caughtMessage();
    ExpectSubStringMatch("Iron", message);
    ExpectSubStringMatch("Return to Previous Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void MarketPricesSelectorReturnToPreviousMenu()
{
    navigateToMarketPricesSelector();
    string returnOption = findMenuOption("Return to Trading Menu");
    command(returnOption, Player);

    string message = Player->caughtMessage();

    ExpectTrue(sizeof(message) == 0 || sizeof(regexp(({ message }), 
        "menu|completed|exit")), "Should return to previous menu or exit");
}

/////////////////////////////////////////////////////////////////////////////
void MarketPricesSelectorHandlesPortsWithNoSpecialtyOrImport()
{
    // Recreate ports without specialty/import
    if (objectp(MockPort1)) destruct(MockPort1);
    if (objectp(MockPort2)) destruct(MockPort2);

    MockPort1 = clone_object("/lib/modules/domains/trading/tradingPort.c");
    MockPort1->setPortName("Port Alpha");
    MockPort1->setShortDescription("A bustling port city.");
    MockPort1->setAvailableGoods( ({
        "/lib/instances/items/materials/metal/iron.c",
        "/lib/instances/items/materials/wood/oak.c"
    }) );

    MockPort2 = clone_object("/lib/modules/domains/trading/tradingPort.c");
    MockPort2->setPortName("Port Beta");
    MockPort2->setShortDescription("A quiet river port.");
    MockPort2->setAvailableGoods( ({
        "/lib/instances/items/materials/metal/iron.c"
    }) );

    TradingDictionary->registerPort(MockPort1);
    TradingDictionary->registerPort(MockPort2);

    navigateToMarketPricesSelector();
    string metalOption = findMenuOption("Metal");
    command(metalOption, Player);

    string ironOption = findMenuOption("Iron");
    command(ironOption, Player);

    string priceboardOption = findMenuOption("View Market Prices");
    command(priceboardOption, Player);

    string result = Player->caughtMessage();
    // Should not show Specialty or Import highlights
    ExpectFalse(sizeof(regexp(({ result }), "Specialty")), "Should not show Specialty");
    ExpectFalse(sizeof(regexp(({ result }), "Import")), "Should not show Import");
}

/////////////////////////////////////////////////////////////////////////////
void MarketPricesSelectorHandlesInvalidNavigation()
{
    // Try to go back at the top-level menu (should do nothing or redisplay menu)
    navigateToMarketPricesSelector();
    resetPlayerMessages();
    command("999", Player); // Invalid selection
    string message = Player->caughtMessage();
    ExpectSubStringMatch("Market Prices", message);
}
