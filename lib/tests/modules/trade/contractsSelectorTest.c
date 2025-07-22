//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object ContractsSelector;
object Port;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({
        "resetPlayerMessages",
        "getMenuOptionNumber",
        "addContract",
        "clearContracts",
        "countMenuOptions"
    });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ContractsSelector = clone_object("/lib/modules/domains/trading/selectors/contractsSelector.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("testtrader");
    Player->addCommands();
    Player->initializeTrader();
    Port = clone_object("/lib/modules/domains/trading/tradingPort.c");
    Port.setPortName("Port Alpha");
    getDictionary("trading")->registerPort(Port);

    move_object(Player, Port);
    move_object(ContractsSelector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(ContractsSelector)) destruct(ContractsSelector);
    if (objectp(Player)) destruct(Player);
    if (objectp(Port)) destruct(Port);
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
private string getMenuOptionNumber(string optionText)
{
    string ret = "0";
    string message = Player->caughtMessage();
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        // Remove ANSI codes for matching
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
private void addContract(string id, mapping contract)
{
    Port.addContract(id, contract);
    getDictionary("trading")->registerPort(Port);
}

/////////////////////////////////////////////////////////////////////////////
private void clearContracts()
{
    object *ports = getDictionary("trading")->getAvailablePorts();
    foreach(object port in ports)
    {
        port.clearContracts();
    }
}

/////////////////////////////////////////////////////////////////////////////
private int countMenuOptions()
{
    string message = Player->caughtMessage();
    int count = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        int option;
        if (sscanf(line, "%d.", option) == 1)
        {
            count++;
        }
    }
    return count;
}

/////////////////////////////////////////////////////////////////////////////
void ContractsSelectorMenuDisplaysAnywhere()
{
    object MockEnvironment = clone_object("/lib/tests/support/environment/mockTradeEnvironment.c");
    move_object(Player, MockEnvironment);

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    string message = Player->caughtMessage();
    ExpectSubStringMatch("Trading Contracts", message);
    ExpectSubStringMatch("Deliver [0-9]+ units of [A-Za-z ]+ to [A-Za-z]+", message);
    ExpectSubStringMatch("Return to Trading Menu", message);

    move_object(Player, Port);
    destruct(MockEnvironment);
}

/////////////////////////////////////////////////////////////////////////////
void AvailableContractsAreListed()
{
    clearContracts();

    addContract("A1", ([
        "description": "Deliver Iron Ore",
        "destination": "Eledhel",
        "deadline": getDictionary("trading")->generateDeadline(1000),
        "reward": 100,
        "item type": "materials",
        "quantity": 10
    ]));
    addContract("A2", ([
        "description": "Deliver Copper",
        "destination": "Eledhel",
        "deadline": getDictionary("trading")->generateDeadline(20000),
        "reward": 80,
        "item type": "materials",
        "quantity": 5
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    string message = Player->caughtMessage();
    ExpectSubStringMatch("Deliver Iron Ore", message);
    ExpectSubStringMatch("Deliver Copper", message);
}

/////////////////////////////////////////////////////////////////////////////
void NoAvailableContractsShowsMessage()
{
    clearContracts();

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    string message = Player->caughtMessage();
    ExpectSubStringMatch("No Contracts Available", message);
    ExpectSubStringMatch("Return to Trading Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void ActiveContractsAreListed()
{
    Player->acceptContract("A1", ([
        "description": "Deliver Iron Ore",
        "destination": "Port Alpha",
        "deadline": ([ "year": 100, "day": 1, "minute": 600 ]),
        "item type": "materials",
        "quantity": 10
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    string message = Player->caughtMessage();
    ExpectSubStringMatch("View Active Contracts", message);
}

/////////////////////////////////////////////////////////////////////////////
void SelectingActiveContractsDisplaysStatus()
{
    Player->acceptContract("A1", ([
        "description": "Deliver Iron Ore",
        "destination": "Port Alpha",
        "deadline": ([ "year": 100, "day": 1, "minute": 600 ]),
        "item type": "materials",
        "quantity": 10
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

//    resetPlayerMessages();
    command(getMenuOptionNumber("View Active Contracts (1)"), Player);
    string contractStatus = implode(Player->caughtMessages(), "\n");

    ExpectSubStringMatch("Active Trading Contracts", contractStatus);
    ExpectSubStringMatch("Deliver Iron Ore", contractStatus);
    ExpectSubStringMatch("Destination", contractStatus);
    ExpectSubStringMatch("Time Left", contractStatus);
    ExpectSubStringMatch("Progress", contractStatus);
}

/////////////////////////////////////////////////////////////////////////////
void SelectingAvailableContractShowsNotImplementedNote()
{
    clearContracts();
    addContract("A1", ([
        "description": "Deliver Iron Ore",
        "destination": "Port Alpha",
        "deadline": ([ "year": 100, "day": 1, "minute": 600 ]),
        "reward": 100,
        "item type": "materials",
        "quantity": 10
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    int contractOption = to_int(getMenuOptionNumber("Deliver Iron Ore"));

    if (contractOption > 0)
    {
        resetPlayerMessages();
        command(to_string(contractOption), Player);
        string contractNote = Player->caughtMessage();

        ExpectSubStringMatch("Contract acceptance system not yet implemented", contractNote);
    }
}

/////////////////////////////////////////////////////////////////////////////
void ExitOptionReturnsToTradingMenu()
{
    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    int exitOption = to_int(getMenuOptionNumber("Return to Trading Menu"));

    resetPlayerMessages();
    if (exitOption > 0)
    {
        command(to_string(exitOption), Player);
        ExpectSubStringMatch("Trading Contracts has been exited", Player->caughtMessage());
    }
}

/////////////////////////////////////////////////////////////////////////////
void InvalidSelectionShowsMenuAgain()
{
    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);
    resetPlayerMessages();
    command("999", Player);

    ExpectSubStringMatch("Trading Contracts", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UndoIsAvailableInContractsSelector()
{
    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);
    resetPlayerMessages();
    command("undo", Player);

    string message = Player->caughtMessage();
    ExpectTrue(sizeof(message) > 0, "Undo should provide some response");
}

/////////////////////////////////////////////////////////////////////////////
void DescribeOptionShowsDetails()
{
    clearContracts();
    addContract("A1", ([
        "description": "Deliver Iron Ore",
        "destination": "Port Alpha",
        "deadline": ([ "year": 100, "day": 1, "minute": 600 ]),
        "reward": 100,
        "item type": "materials",
        "quantity": 10
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);
    resetPlayerMessages();
    command("describe 1", Player);

    string message = Player->caughtMessage();
    ExpectTrue(sizeof(message) > 0, "Describe should provide some response");
}

/////////////////////////////////////////////////////////////////////////////
void ContractUrgencyLabelsDisplayCorrectly()
{
    Player->acceptContract("urgent", ([
        "description": "Rush Delivery",
        "destination": "Port Beta",
        "deadline": ([ "year": 100, "day": 1, "minute": 600 ]),
        "item type": "materials",
        "quantity": 5
    ]));

    Player->acceptContract("soon", ([
        "description": "Quick Delivery",
        "destination": "Port Gamma",
        "deadline": ([ "year": 100, "day": 3, "minute": 600 ]),
        "item type": "textiles",
        "quantity": 8
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    int activeOption = to_int(getMenuOptionNumber("View Active Contracts"));

    if (activeOption > 0)
    {
        resetPlayerMessages();
        command(to_string(activeOption), Player);
        string contractStatus = Player->caughtMessage();

        ExpectSubStringMatch("Rush Delivery", contractStatus);
        ExpectSubStringMatch("Quick Delivery", contractStatus);
        ExpectSubStringMatch("1 day", contractStatus);
        ExpectSubStringMatch("3 day", contractStatus);
    }
}

/////////////////////////////////////////////////////////////////////////////
void ContractUrgencyIndicatorsAppearInMenu()
{
    clearContracts();
    addContract("urgent", ([
        "description": "Critical Delivery",
        "destination": "Port Zeta",
        "deadline": ([ "year": 100, "day": 2, "minute": 600 ]),
        "reward": 100,
        "item type": "materials",
        "quantity": 2
    ]));
    addContract("soon", ([
        "description": "Standard Delivery",
        "destination": "Port Eta",
        "deadline": ([ "year": 100, "day": 5, "minute": 600 ]),
        "reward": 50,
        "item type": "textiles",
        "quantity": 3
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    string message = Player->caughtMessage();
    ExpectSubStringMatch("Critical Delivery", message);
    ExpectSubStringMatch("\\[!\\]", message); // Urgency indicator for <= 3 days
    ExpectSubStringMatch("Standard Delivery", message);
}

/////////////////////////////////////////////////////////////////////////////
void ContractProgressCalculatesCorrectly()
{
    // Add cargo to vehicle for a matching item type
    Player->addCargoToVehicle("/lib/instances/items/materials/metal/iron.c", 5);

    Player->acceptContract("progress_test", ([
        "description": "Test Progress",
        "destination": "Port Delta",
        "deadline": ([ "year": 100, "day": 7, "minute": 600 ]),
        "item type": "metal",
        "quantity": 10
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    int activeOption = to_int(getMenuOptionNumber("View Active Contracts"));

    if (activeOption > 0)
    {
        resetPlayerMessages();
        command(to_string(activeOption), Player);
        string contractStatus = Player->caughtMessage();

        ExpectSubStringMatch("Test Progress", contractStatus);
        ExpectSubStringMatch("50% complete", contractStatus);
    }
}

/////////////////////////////////////////////////////////////////////////////
void NoActiveContractsShowsMessage()
{
    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    string message = Player->caughtMessage();
    ExpectFalse(sizeof(regexp(({ message }), "View Active Contracts")) > 0,
        "Should not show active contracts option when player has none");
}

/////////////////////////////////////////////////////////////////////////////
void ActiveContractsWithNoActiveShowsMessage()
{
    Player->acceptContract("test", ([
        "description": "Test Contract",
        "destination": "Port Echo",
        "deadline": ([ "year": 100, "day": 14, "minute": 600 ]),
        "item type": "materials",
        "quantity": 1
    ]));

    Player->completeContract("test");

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    string message = Player->caughtMessage();
    ExpectFalse(sizeof(regexp(({ message }), "View Active Contracts")) > 0,
        "Should not show active contracts option when all contracts are completed");
}

/////////////////////////////////////////////////////////////////////////////
void MenuAlwaysIncludesExit()
{
    clearContracts();
    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);
    string message = Player->caughtMessage();
    ExpectSubStringMatch("Return to Trading Menu", message);

    addContract("A1", ([
        "description": "Deliver Iron Ore",
        "destination": "Port Alpha",
        "deadline": ([ "year": 100, "day": 1, "minute": 600 ]),
        "reward": 100,
        "item type": "materials",
        "quantity": 10
    ]));
    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);
    message = Player->caughtMessage();
    ExpectSubStringMatch("Return to Trading Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void DescribeWorksForAllMenuOptions()
{
    clearContracts();
    addContract("A1", ([
        "description": "Deliver Iron Ore",
        "destination": "Port Alpha",
        "deadline": ([ "year": 100, "day": 1, "minute": 600 ]),
        "reward": 100,
        "item type": "materials",
        "quantity": 10
    ]));
    Player->acceptContract("A2", ([
        "description": "Deliver Copper",
        "destination": "Port Beta",
        "deadline": ([ "year": 100, "day": 2, "minute": 600 ]),
        "item type": "materials",
        "quantity": 5
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);
    int maxOption = countMenuOptions();

    for (int i = 1; i <= maxOption; i++)
    {
        resetPlayerMessages();
        command("describe " + to_string(i), Player);
        string desc = Player->caughtMessage();
        ExpectTrue(sizeof(desc) > 0, "Describe should provide some response for option " + to_string(i));
    }
}

/////////////////////////////////////////////////////////////////////////////
void ExpiredContractsAreNotShown()
{
    clearContracts();
    addContract("expired", ([
        "description": "Expired Delivery",
        "destination": "Port Omega",
        "deadline": ([ "year": 1, "day": 1, "minute": 1 ]), // Clearly expired
        "reward": 100,
        "item type": "materials",
        "quantity": 10
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);
    string message = Player->caughtMessage();
    ExpectFalse(sizeof(regexp(({ message }), "Expired Delivery")) > 0,
        "Expired contracts should not be shown");
}

/////////////////////////////////////////////////////////////////////////////
void ContractWithZeroQuantityDoesNotCrash()
{
    clearContracts();
    addContract("zero", ([
        "description": "Zero Quantity",
        "destination": "Port Null",
        "deadline": ([ "year": 100, "day": 1, "minute": 600 ]),
        "reward": 100,
        "item type": "materials",
        "quantity": 0
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);
    string message = Player->caughtMessage();
    ExpectSubStringMatch("Zero Quantity", message);
    // Should not crash or divide by zero
}

/////////////////////////////////////////////////////////////////////////////
void ContractWithMissingFieldsHandledGracefully()
{
    clearContracts();
    addContract("broken", ([
        "description": "Broken Contract"
        // Missing destination, deadline, item type, quantity, reward
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);
    string message = Player->caughtMessage();
    ExpectSubStringMatch("Broken Contract", message);
}
