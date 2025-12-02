//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object TradingSelector;

///////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "resetPlayerMessages", "getMenuOptionNumber",
        "tradingSelectorRemoved", "onSelectorCompleted" });
}

/////////////////////////////////////////////////////////////////////////////
public void onSelectorCompleted(object caller)
{
    if (objectp(caller))
    {
        caller->cleanUp();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onSelectorAborted(object caller)
{
    if (objectp(caller))
    {
        caller->cleanUp();
    }
}

///////////////////////////////////////////////////////////////////////////////
void Setup()
{
    TradingSelector = clone_object("/lib/modules/domains/trading/selectors/tradingSelector.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("testtrader");
    Player.addCommands();
    Player.initializeTrader();

    move_object(TradingSelector, Player);
    TradingSelector->registerEvent(this_object());
}

///////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(TradingSelector))
    {
        destruct(TradingSelector);
    }
    if (objectp(Player))
    {
        destruct(Player);
    }
}

///////////////////////////////////////////////////////////////////////////////
private void resetPlayerMessages()
{
    if (Player && function_exists("resetCatchList", Player))
    {
        Player.resetCatchList();
    }
}

///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
private int tradingSelectorRemoved()
{
    object *inventory = deep_inventory(Player);

    int found = 0;
    foreach(object obj in inventory)
    {
        if (obj == TradingSelector)
        {
            found = 1;
            break;
        }
    }
    return !found;
}

///////////////////////////////////////////////////////////////////////////////
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
}

///////////////////////////////////////////////////////////////////////////////
void ChoosingStatusDisplaysCompanyInformation()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);

    command(getMenuOptionNumber("View Company Status"), Player);

    string message = Player.caughtMessage();
    ExpectSubStringMatch("Trading Status", message);
}

///////////////////////////////////////////////////////////////////////////////
void ChoosingMarketPricesDisplaysMarketPricesSelector()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    command(getMenuOptionNumber("View Market Prices"), Player);
    string result = Player.caughtMessage();

    ExpectSubStringMatch("Market Prices", result);
}

///////////////////////////////////////////////////////////////////////////////
void ChoosingContractsDisplaysContractsSelector()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    command(getMenuOptionNumber("Browse Contracts"), Player);
    string result = Player.caughtMessage();

    ExpectTrue(sizeof(regexp(({ result }), "Contracts")) > 0,
        "Contracts selector should be displayed");
}

///////////////////////////////////////////////////////////////////////////////
void ChoosingBankDisplaysBankSelector()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    command(getMenuOptionNumber("Visit Bank"), Player);
    string result = Player.caughtMessage();
    ExpectTrue(sizeof(regexp(({ result }), "Bank")) > 0,
        "Bank selector should be displayed");
}

///////////////////////////////////////////////////////////////////////////////
void ChoosingSelectPortDisplaysPortSelector()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    command(getMenuOptionNumber("Select Port"), Player);
    string result = Player.caughtMessage();
    ExpectSubStringMatch("Select Port", result);
}

///////////////////////////////////////////////////////////////////////////////
void ChoosingExitExitsSelector()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);

    ExpectFalse(tradingSelectorRemoved(),
        "Selector should be present before exit command");

    command(getMenuOptionNumber("Exit Trading Menu"), Player);

    ExpectSubStringMatch("You have selected 'Exit Trading Menu'", 
        Player.caughtMessage());

    ExpectTrue(tradingSelectorRemoved(),
        "Selector should be removed from player after exit command");
}

///////////////////////////////////////////////////////////////////////////////
void InvalidSelectionShowsMenuAgain()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("999", Player);

    ExpectSubStringMatch("Main Trading Menu", Player.caughtMessage());
}

///////////////////////////////////////////////////////////////////////////////
void DescribeOptionShowsDetails()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("describe 1", Player);

    ExpectSubStringMatch("Display your trading company", Player.caughtMessage());
}

///////////////////////////////////////////////////////////////////////////////
void UndoIsNotAvailableInTradingSelector()
{
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);
    resetPlayerMessages();
    command("undo", Player);

    ExpectSubStringMatch("Main Trading Menu", Player.caughtMessage());
}

///////////////////////////////////////////////////////////////////////////////
void ExitRemovesSelectorFromPlayer()
{
    ToggleCallOutBypass();
    TradingSelector.registerEvent(this_object());
    resetPlayerMessages();
    TradingSelector.initiateSelector(Player);

    command("exit", Player);
    ExpectSubStringMatch("Trading has been exited.", Player.caughtMessage());

    ExpectTrue(tradingSelectorRemoved(),
        "Selector should be removed from player on cancel command");
    ToggleCallOutBypass();
}
