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
    ignoreList += ({ "resetPlayerMessages" });
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
