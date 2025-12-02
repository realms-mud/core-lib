//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        "clearContracts"
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
    getService("trading")->registerPort(Port);

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
            ret = regreplace(line, "^[^0-9]*([0-9]+).*", "\\1", 1);
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private void addContract(string id, mapping contract)
{
    Port.addContract(id, contract);
    getService("trading")->registerPort(Port);
}

/////////////////////////////////////////////////////////////////////////////
private void clearContracts()
{
    object *ports = getService("trading")->getAvailablePorts();
    foreach(object port in ports)
    {
        port.clearContracts();
    }
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
        "deadline": getService("trading")->generateDeadline(1000),
        "reward": 100,
        "item type": "metal",
        "quantity": 10
    ]));
    addContract("A2", ([
        "description": "Deliver Copper",
        "destination": "Eledhel",
        "deadline": getService("trading")->generateDeadline(20000),
        "reward": 80,
        "item type": "metal",
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
        "deadline": getService("trading")->generateDeadline(1000),
        "item type": "metal",
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
    Player.colorConfiguration("none");
    Player.charsetConfiguration("ascii");

    Player->acceptContract("A1", ([
        "description": "Deliver Iron Ore",
        "destination": "Port Alpha",
        "deadline": ([ "year": 100, "day": 1, "minute": 600 ]),
        "item type": "metal",
        "quantity": 10
    ]));

    string expected =
        "+-=-=-=-=-=-=-=-=-=-=-=-=-+ Active Trading Contracts +=-=-=-=-=-=-=-=-=-=-=-=-+\n"
        "|   A1: Deliver Iron Ore                                                      |\n"
        "|     Destination: Port Alpha     Time Left: expired                          |\n"
        "|     Progress: 0% complete                                                   |\n"
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+ - +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n";

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    command(getMenuOptionNumber("View Active Contracts"), Player);
    string contractStatus = Player->caughtMessages()[2];

    ExpectEq(expected, contractStatus);
}

/////////////////////////////////////////////////////////////////////////////
void SelectingAvailableContractAcceptsIt()
{
    clearContracts();
    addContract("A1", ([
        "description": "Deliver Iron Ore",
        "destination": "Port Alpha",
        "deadline": getService("trading")->generateDeadline(1000),
        "reward": 100,
        "item type": "metal",
        "quantity": 10
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    command(getMenuOptionNumber("Deliver Iron Ore"), Player);
    string contractNote = implode(Player->caughtMessages(), "\n");

    // Check for success message
    ExpectSubStringMatch("You have accepted the contract", contractNote);

    // Check that the contract is now in the player's active contracts
    mapping active = Player->getActiveContracts();
    ExpectTrue(member(active, "A1"), "Contract A1 should be in active contracts after acceptance");
}

/////////////////////////////////////////////////////////////////////////////
void ExitOptionReturnsToTradingMenu()
{
    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    command(getMenuOptionNumber("Return to Trading Menu"), Player);

    ExpectSubStringMatch("You have selected 'Return to Trading Menu'", 
        Player->caughtMessage());
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
        "deadline": getService("trading")->generateDeadline(1000),
        "reward": 100,
        "item type": "metal",
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
        "deadline": getService("trading")->generateDeadline(1000),
        "item type": "metal",
        "quantity": 5
    ]));

    Player->acceptContract("soon", ([
        "description": "Quick Delivery",
        "destination": "Port Gamma",
        "deadline": getService("trading")->generateDeadline(5000),
        "item type": "textile",
        "quantity": 8
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    command(getMenuOptionNumber("View Active Contracts"), Player);

    string contractStatus = implode(Player->caughtMessages(), "\n");

    ExpectSubStringMatch("Rush Delivery", contractStatus);
    ExpectSubStringMatch("Quick Delivery", contractStatus);
    ExpectSubStringMatch("URGENT", contractStatus);
    ExpectSubStringMatch("Soon", contractStatus);
}

/////////////////////////////////////////////////////////////////////////////
void ContractUrgencyIndicatorsAppearInMenu()
{
    clearContracts();
    addContract("urgent", ([
        "description": "Critical Delivery",
        "destination": "Port Zeta",
        "deadline": getService("trading")->generateDeadline(1000),
        "reward": 100,
        "item type": "metal",
        "quantity": 2
    ]));
    addContract("soon", ([
        "description": "Standard Delivery",
        "destination": "Port Eta",
        "deadline": getService("trading")->generateDeadline(1000),
        "reward": 50,
        "item type": "textile",
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
    clearContracts();
    Player.addVehicle("wagon", "Port Alpha");

    addContract("progress_test", ([
        "description": "Test Progress",
        "destination": "Port Alpha",
        "deadline": getService("trading")->generateDeadline(1000),
        "item type": "metal",
        "quantity": 10
    ]));

    // Accept the contract
    getService("trading")->acceptContract(Player, "Port Alpha", "progress_test");
    Player->assignVehicleToTradeRun("progress_test", Player.getVehicles()[0]);

    // Add partial cargo to the vehicle
    Player->addCargoToVehicleForTradeRun("progress_test", 
        "/lib/instances/items/materials/metal/iron.c", 5);

    // Deliver the cargo at the port
    Port.deliverContract(Player, "progress_test");

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    command(getMenuOptionNumber("View Active Contracts"), Player);
    string contractStatus = implode(Player->caughtMessages(), "\n");

    ExpectSubStringMatch("Test Progress", contractStatus);
    ExpectSubStringMatch("50% complete", contractStatus);
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
        "deadline": getService("trading")->generateDeadline(1000),
        "item type": "metal",
        "quantity": 1
    ]));

    Player->removeActiveContract("test");

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
        "deadline": getService("trading")->generateDeadline(1000),
        "reward": 100,
        "item type": "metal",
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
        "deadline": getService("trading")->generateDeadline(1000),
        "reward": 100,
        "item type": "metal",
        "quantity": 10
    ]));
    Player->acceptContract("A2", ([
        "description": "Deliver Copper",
        "destination": "Port Beta",
        "deadline": getService("trading")->generateDeadline(1000),
        "item type": "metal",
        "quantity": 5
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);
    int maxOption = to_int(getMenuOptionNumber("Return to Trading Menu"));

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
        "item type": "metal",
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
        "deadline": getService("trading")->generateDeadline(1000),
        "reward": 100,
        "item type": "metal",
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
    string error = catch(ContractsSelector->initiateSelector(Player));
    ExpectSubStringMatch("tradingService.c: Invalid deadline format", error);
}
