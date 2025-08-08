//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

//object Player;
//object MarketPricesSelector;
//object MockPort;
//
///////////////////////////////////////////////////////////////////////////////
//void Init()
//{
//    ignoreList += ({
//        "resetPlayerMessages",
//        "navigateToMarketPricesSelector",
//        "findMenuOption"
//    });
//}
//
///////////////////////////////////////////////////////////////////////////////
//void Setup()
//{
//    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
//    Player.Name("testtrader");
//    Player.colorConfiguration("none");
//    Player.addCommands();
//    Player.initializeTrader();
//
//    MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
//    move_object(Player, MockPort);
//
//    // Register the port so selectors can find it
//    object tradingDictionary = load_object("/lib/dictionaries/tradingDictionary.c");
//    tradingDictionary.registerPort(MockPort);
//
//    MarketPricesSelector = clone_object("/lib/modules/domains/trading/selectors/marketPricesSelector.c");
//    move_object(MarketPricesSelector, Player);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void CleanUp()
//{
//    if (objectp(MarketPricesSelector)) destruct(MarketPricesSelector);
//    if (objectp(Player)) destruct(Player);
//    if (objectp(MockPort)) destruct(MockPort);
//}
//
///////////////////////////////////////////////////////////////////////////////
//private void resetPlayerMessages()
//{
//    if (Player && function_exists("resetCatchList", Player))
//    {
//        Player.resetCatchList();
//    }
//}
//
///////////////////////////////////////////////////////////////////////////////
//private string findMenuOption(string optionText)
//{
//    string ret = "0";
//    string message = Player.caughtMessage();
//    string *lines = explode(message, "\n");
//    foreach (string line in lines)
//    {
//        line = regreplace(line, "\x1B\\[[0-9;]*[A-Za-z]", "", 1);
//        if (sizeof(regexp(({ line }), optionText)))
//        {
//            ret = regreplace(line, "^[^0-9]*([0-9]+).*", "\\1", 1);
//            break;
//        }
//    }
//    return ret;
//}
//
///////////////////////////////////////////////////////////////////////////////
//private void navigateToMarketPricesSelector(string port)
//{
//    resetPlayerMessages();
//    MarketPricesSelector.initiateSelector(Player);
//    command(findMenuOption(port), Player);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void MarketPricesSelectorDisplaysPricesForCurrentPort()
//{
//    navigateToMarketPricesSelector("Mock Trading Port");
//    string message = implode(Player.caughtMessages(), "\n");
//
//    ExpectSubStringMatch("Mock Trading Port", message);
//    ExpectSubStringMatch("Market Prices", message);
//    ExpectSubStringMatch("Iron", message);
//    ExpectSubStringMatch("Oak", message);
//    ExpectSubStringMatch("Cancel", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void MarketPricesSelectorAllowsViewingItemDetails()
//{
//    navigateToMarketPricesSelector("Mock Trading Port");
//    string ironOption = findMenuOption("Iron");
//    ExpectTrue(ironOption != "0", "Iron option should be present");
//    command(ironOption, Player);
//
//    string result = Player.caughtMessage();
//    ExpectSubStringMatch("Iron", result);
//    ExpectSubStringMatch("Price", result);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void MarketPricesSelectorHandlesInvalidInput()
//{
//    navigateToMarketPricesSelector("Mock Trading Port");
//    command("999", Player);
//
//    string result = Player.caughtMessage();
//    ExpectSubStringMatch("Market Prices", result);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void MarketPricesSelectorAllowsCancel()
//{
//    navigateToMarketPricesSelector("Mock Trading Port");
//    string cancelOption = findMenuOption("Cancel");
//    command(cancelOption, Player);
//
//    string result = Player.caughtMessage();
//    ExpectSubStringMatch("Market", result); // Should return to menu or show exit message
//}
//
///////////////////////////////////////////////////////////////////////////////
//void UndoIsAvailableInMarketPricesSelector()
//{
//    navigateToMarketPricesSelector("Mock Trading Port");
//    resetPlayerMessages();
//    command("undo", Player);
//
//    string message = Player.caughtMessage();
//    ExpectTrue(sizeof(message) > 0, "Undo should provide some response");
//}
