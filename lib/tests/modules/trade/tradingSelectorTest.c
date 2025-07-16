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
    ignoreList += ({ "resetPlayerMessages", "getMenuOptionNumber" });
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
private string getMenuOptionNumber(string optionText)
{
    string ret = "0";
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        line = regreplace(line, "\x1B\\[[0-9;]*[A-Za-z]", "", 1);

        if (sizeof(regexp(({ line }), optionText)))
        {
            ret = regreplace(line, "^.*([0-9]+).*", "\\1", 1);
            break;
        }
    }
    return ret;
}


/////////////////////////////////////////////////////////////////////////////
void TradingSelectorDisplaysMainMenuCorrectly()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Main Trading Menu", message);
    ExpectSubStringMatch("View Company Status", message);
    ExpectSubStringMatch("View Market Prices", message);
    ExpectSubStringMatch("Browse Contracts", message);
    ExpectSubStringMatch("Visit Bank", message);
    ExpectSubStringMatch("Select Port", message);
    ExpectSubStringMatch("Exit Trading Menu", message);

    // Port-specific actions should NOT be present
    ExpectFalse(sizeof(regexp(({ message }), "Buy Goods")) > 0, "Buy Goods should not show in main menu");
    ExpectFalse(sizeof(regexp(({ message }), "Sell Goods")) > 0, "Sell Goods should not show in main menu");
    ExpectFalse(sizeof(regexp(({ message }), "Manage Warehouse")) > 0, "Manage Warehouse should not show in main menu");
    ExpectFalse(sizeof(regexp(({ message }), "Travel to Another Port")) > 0, "Travel to Another Port should not show in main menu");
    ExpectFalse(sizeof(regexp(({ message }), "Hire Crew")) > 0, "Hire Crew should not show in main menu");
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingStatusDisplaysCompanyInformation()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);

    command(getMenuOptionNumber("View Company Status"), Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Trading Status", message);
    ExpectSubStringMatch("Unnamed Trading Company", message);
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingMarketPricesDisplaysMarketPricesSelector()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    command(getMenuOptionNumber("View Market Prices"), Player);
    string result = Player.caughtMessage();

    ExpectSubStringMatch("Market Prices", result);
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingContractsDisplaysContractsSelector()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    command(getMenuOptionNumber("Browse Contracts"), Player);
    string result = Player.caughtMessage();
    ExpectTrue(sizeof(regexp(({ result }), "Contracts")) > 0,
        "Contracts selector should be displayed");
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingBankDisplaysBankSelector()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    command(getMenuOptionNumber("Visit Bank"), Player);
    string result = Player.caughtMessage();
    ExpectTrue(sizeof(regexp(({ result }), "Bank")) > 0,
        "Bank selector should be displayed");
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingSelectPortDisplaysPortSelector()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    command(getMenuOptionNumber("Select Port"), Player);
    string result = Player.caughtMessage();
    ExpectSubStringMatch("Select Port", result);
}

/////////////////////////////////////////////////////////////////////////////
void ChoosingExitExitsSelector()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    command(getMenuOptionNumber("Exit Trading Menu"), Player);
    ExpectSubStringMatch("Trading has been exited", Player.caughtMessage());
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
void CancelRemovesSelectorFromPlayer()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);

    // Simulate the cancel command
    command("cancel", Player);

    // The selector should no longer be in the player's inventory/environment
    object *inventory = deep_inventory(Player);
    int found = 0;
    foreach (object obj in inventory)
    {
        if (obj == TradingSelector)
        {
            found = 1;
            break;
        }
    }
    ExpectFalse(found, "Selector should be removed from player on cancel");
}

/////////////////////////////////////////////////////////////////////////////
void AbortRemovesSelectorFromPlayer()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);

    // Simulate the abort command
    command("abort", Player);

    // The selector should no longer be in the player's inventory/environment
    object *inventory = deep_inventory(Player);
    int found = 0;
    foreach (object obj in inventory)
    {
        if (obj == TradingSelector)
        {
            found = 1;
            break;
        }
    }
    ExpectFalse(found, "Selector should be removed from player on abort");
}
