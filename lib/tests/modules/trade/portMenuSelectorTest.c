//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object PortMenuSelector;
object MockPort;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({
        "resetPlayerMessages",
        "navigateToPortMenuSelector",
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

    MockPort = clone_object("/lib/tests/support/environment/mockTradePort.c");
    MockPort->setPortName("Port Alpha");
    MockPort->setShortDescription("A bustling port city.");
    getService("trading")->registerPort(MockPort);
    Player->addVehicle("wagon", "Port Alpha");

    if (objectp(PortMenuSelector)) destruct(PortMenuSelector);
    PortMenuSelector = clone_object("/lib/modules/domains/trading/selectors/portMenuSelector.c");
    move_object(PortMenuSelector, Player);
    PortMenuSelector->setPort(MockPort);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(PortMenuSelector);
    destruct(Player);
    destruct(MockPort);
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
private void navigateToPortMenuSelector()
{
    resetPlayerMessages();
    PortMenuSelector->initiateSelector(Player);
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
void PortMenuSelectorDisplaysMenu()
{
    navigateToPortMenuSelector();
    string message = Player->caughtMessage();

    ExpectSubStringMatch("Port Menu", message);
    ExpectSubStringMatch("Buy Goods at Port Alpha", message);
    ExpectSubStringMatch("Sell Goods at Port Alpha", message);
    ExpectSubStringMatch("Manage Warehouse at Port Alpha", message);
    ExpectSubStringMatch("Travel to Another Port from Port Alpha", message);
    ExpectSubStringMatch("Hire Crew at Port Alpha", message);
    ExpectSubStringMatch("Return to Previous Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void PortMenuSelectorHandlesBuySelection()
{
    navigateToPortMenuSelector();
    string buyOption = findMenuOption("Buy Goods at Port Alpha");
    command(buyOption, Player);

    string message = implode(Player->caughtMessages(), "\n");
    ExpectSubStringMatch("Spices", message);
    ExpectSubStringMatch("Return to Previous Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void PortMenuSelectorHandlesSellSelection()
{
    navigateToPortMenuSelector();
    string sellOption = findMenuOption("Sell Goods at Port Alpha");
    command(sellOption, Player);

    string message = implode(Player->caughtMessages(), "\n");
    ExpectSubStringMatch("from 1 to 1", message);
    ExpectSubStringMatch("Return to Previous Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void PortMenuSelectorHandlesWarehouseSelection()
{
    navigateToPortMenuSelector();
    string warehouseOption = findMenuOption("Manage Warehouse at Port Alpha");
    command(warehouseOption, Player);

    string message = implode(Player->caughtMessages(), "\n");
    ExpectSubStringMatch("Warehouse", message);
    ExpectSubStringMatch("Return to Previous Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void PortMenuSelectorHandlesTravelSelection()
{
    navigateToPortMenuSelector();
    string travelOption = findMenuOption("Travel to Another Port from Port Alpha");
    command(travelOption, Player);

    string message = Player->caughtMessage();
    ExpectSubStringMatch("Travel", message);
    ExpectSubStringMatch("Return to Previous Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void PortMenuSelectorHandlesHireCrewSelection()
{
    navigateToPortMenuSelector();
    string hireCrewOption = findMenuOption("Hire Crew at Port Alpha");
    command(hireCrewOption, Player);

    string message = implode(Player->caughtMessages(), "\n");
    ExpectSubStringMatch("Hire Crew", message);
    ExpectSubStringMatch("Return to Previous Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void PortMenuSelectorHandlesReturnToPreviousMenu()
{
    object ParentSelector = 
        clone_object("/lib/modules/domains/trading/selectors/selectPortSelector.c");
    move_object(ParentSelector, Player);
    ParentSelector->initiateSelector(Player);

    string alphaOption = findMenuOption("Port Alpha");
    resetPlayerMessages();
    command(alphaOption, Player);

    string message = implode(Player->caughtMessages(), "\n");
    ExpectSubStringMatch("Buy Goods at Port Alpha", message);

    string returnOption = findMenuOption("Return to Previous Menu");
    resetPlayerMessages();
    command(returnOption, Player);

    message = implode(Player->caughtMessages(), "\n");
    ExpectSubStringMatch("Select Port", message);
    ExpectSubStringMatch("Port Alpha", message);
    ExpectSubStringMatch("Return to Previous Menu", message);
    destruct(ParentSelector);
}

/////////////////////////////////////////////////////////////////////////////
void PortMenuSelectorHandlesInvalidInput()
{
    navigateToPortMenuSelector();
    resetPlayerMessages();
    command("999", Player);
    string message = Player->caughtMessage();
    ExpectSubStringMatch("Port Menu", message);
    ExpectSubStringMatch("Buy Goods at Port Alpha", message);
}
