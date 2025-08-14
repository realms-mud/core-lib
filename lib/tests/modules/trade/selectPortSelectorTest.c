//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object SelectPortSelector;
object MockPort1;
object MockPort2;
object TradingDictionary;
object ParentSelector;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({
        "resetPlayerMessages",
        "navigateToSelectPortSelector",
        "findMenuOption"
    });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("testtrader");
    Player->colorConfiguration("none");
    Player->addCommands();
    Player->initializeTrader();

    // Create two mock ports
    MockPort1 = clone_object("/lib/tests/support/environment/mockTradePort.c");
    MockPort1->setPortName("Port Alpha");
    MockPort1->setShortDescription("A bustling port city.");

    MockPort2 = clone_object("/lib/tests/support/environment/mockTradePort.c");
    MockPort2->setPortName("Port Beta");
    MockPort2->setShortDescription("A quiet river port.");

    TradingDictionary = load_object("/lib/dictionaries/tradingDictionary.c");
    TradingDictionary->registerPort(MockPort1);
    TradingDictionary->registerPort(MockPort2);

    if (objectp(SelectPortSelector)) destruct(SelectPortSelector);
    SelectPortSelector = clone_object("/lib/modules/domains/trading/selectors/selectPortSelector.c");
    move_object(SelectPortSelector, Player);

    // Use the real tradingSelector as parent
    ParentSelector = clone_object("/lib/modules/domains/trading/selectors/tradingSelector.c");
    move_object(ParentSelector, Player);
    ParentSelector->registerEvent(SelectPortSelector);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(SelectPortSelector);
    destruct(Player);
    destruct(MockPort1);
    destruct(MockPort2);
    destruct(ParentSelector);
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
private void navigateToSelectPortSelector()
{
    resetPlayerMessages();
    SelectPortSelector->initiateSelector(Player);
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

        if (sizeof(regexp(({ line }), optionText, 1)))
        {
            ret = regreplace(line, "^.*[[]([0-9]+)[^-]+- " + optionText + ".*", "\\1", 1);
            break;
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
void SelectPortSelectorDisplaysPorts()
{
    navigateToSelectPortSelector();
    string message = Player->caughtMessage();

    ExpectSubStringMatch("Select Port", message);
    ExpectSubStringMatch("Port Alpha", message);
    ExpectSubStringMatch("Port Beta", message);
    ExpectSubStringMatch("Return to Previous Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void SelectPortSelectorHandlesPortSelection()
{
    navigateToSelectPortSelector();
    string alphaOption = findMenuOption("Port Alpha");
    command(alphaOption, Player);

    string message = Player->caughtMessage();
    ExpectSubStringMatch("Buy Goods at Port Alpha", message);
    ExpectSubStringMatch("Sell Goods at Port Alpha", message);
    ExpectSubStringMatch("Manage Warehouse at Port Alpha", message);
    ExpectSubStringMatch("Travel to Another Port from Port Alpha", message);
    ExpectSubStringMatch("Hire Crew at Port Alpha", message);
    ExpectSubStringMatch("Return to Previous Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void SelectPortSelectorHandlesCancel()
{
    ParentSelector->initiateSelector(Player);
    string navigateToSelectPort = findMenuOption("Select Port");
    command(navigateToSelectPort, Player);

    string message = Player->caughtMessage();
    ExpectSubStringMatch("Port Alpha", message);

    string cancelOption = findMenuOption("Return to Previous Menu");
    resetPlayerMessages();

    command(cancelOption, Player);

    message = implode(Player->caughtMessages(), "\n");

    ExpectSubStringMatch("Main Trading Menu", message);
    ExpectSubStringMatch("View Company Status", message);
    ExpectSubStringMatch("Select Port", message);
}

/////////////////////////////////////////////////////////////////////////////
void SelectPortSelectorHandlesInvalidInput()
{
    navigateToSelectPortSelector();
    resetPlayerMessages();
    command("999", Player);
    string message = Player->caughtMessage();
    ExpectSubStringMatch("Select Port", message);
    ExpectSubStringMatch("Port Alpha", message);
}
