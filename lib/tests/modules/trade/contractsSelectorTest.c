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
    ignoreList += ({ "resetPlayerMessages" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    ContractsSelector = clone_object("/lib/modules/domains/trading/selectors/contractsSelector.c");
    
    // Use the mock player which has catch_tell capabilities
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("testtrader");
    Player->addCommands();
    Player->initializeTrader();

    // Use the real trading port for contract APIs
    Port = clone_object("/lib/modules/domains/trading/tradingPort.c");
    Port->Setup();
    
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
void ContractsSelectorDisplaysMenuCorrectly()
{
    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    string message = Player->caughtMessage();
    ExpectSubStringMatch("Trading Contracts", message);
    ExpectSubStringMatch("Return to Trading Menu", message);
}

/////////////////////////////////////////////////////////////////////////////
void ContractsSelectorRequiresPortLocation()
{
    // Move player to non-port environment
    object MockEnvironment = clone_object("/lib/tests/support/environment/mockTradeEnvironment.c");
    move_object(Player, MockEnvironment);

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    string message = Player->caughtMessage();
    ExpectSubStringMatch("You must be at a trading port to view contracts", message);

    // Clean up
    move_object(Player, Port);
    destruct(MockEnvironment);
}

/////////////////////////////////////////////////////////////////////////////
void AvailableContractsAreListed()
{
    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    string message = Player->caughtMessage();

    mapping contracts = Port->getContracts();
    int found = 0;
    foreach(string id in m_indices(contracts))
    {
        string desc = contracts[id]["description"];
        // Use regexp for substring search (.*desc.*)
        if (desc && stringp(desc) && sizeof(regexp(({ message }), desc)))
        {
            found = 1;
            break;
        }
    }
    ExpectTrue(found, "Should show at least one available contract description in the menu");
}

/////////////////////////////////////////////////////////////////////////////
void ActiveContractsAreListed()
{
    Player->acceptContract("A1", ([
        "description": "Deliver Iron Ore",
        "destination": "Port Alpha",
        "deadline": time() + 86400,
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
        "deadline": time() + 86400,
        "item type": "materials",
        "quantity": 10
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    // Find active contracts option
    string message = Player->caughtMessage();
    int activeOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "View Active Contracts")))
        {
            sscanf(line, "%d. %*s", activeOption);
            break;
        }
    }

    if (activeOption > 0)
    {
        resetPlayerMessages();
        command(to_string(activeOption), Player);
        string contractStatus = Player->caughtMessage();

        ExpectSubStringMatch("Active Trading Contracts", contractStatus);
        ExpectSubStringMatch("Deliver Iron Ore", contractStatus);
        ExpectSubStringMatch("Destination", contractStatus);
        ExpectSubStringMatch("Time Left", contractStatus);
        ExpectSubStringMatch("Progress", contractStatus);
    }
}

/////////////////////////////////////////////////////////////////////////////
void SelectingAvailableContractShowsNotImplementedNote()
{
    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    // Find any available contract option
    string message = Player->caughtMessage();
    int contractOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "contract_")))
        {
            sscanf(line, "%d. %*s", contractOption);
            break;
        }
    }

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
    string message = Player->caughtMessage();

    // Find exit option
    int exitOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "Return to Trading Menu")))
        {
            sscanf(line, "%d. %*s", exitOption);
            break;
        }
    }

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
    // Set up contracts with different urgency levels
    Player->acceptContract("urgent", ([
        "description": "Rush Delivery",
        "destination": "Port Beta",
        "deadline": time() + 86400, // 1 day - urgent
        "item type": "materials",
        "quantity": 5
    ]));

    Player->acceptContract("soon", ([
        "description": "Quick Delivery",
        "destination": "Port Gamma",
        "deadline": time() + (3 * 86400), // 3 days - soon
        "item type": "textiles",
        "quantity": 8
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    // Find active contracts option and select it
    string message = Player->caughtMessage();
    int activeOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "View Active Contracts")))
        {
            sscanf(line, "%d. %*s", activeOption);
            break;
        }
    }

    if (activeOption > 0)
    {
        resetPlayerMessages();
        command(to_string(activeOption), Player);
        string contractStatus = Player->caughtMessage();

        ExpectSubStringMatch("Rush Delivery", contractStatus);
        ExpectSubStringMatch("Quick Delivery", contractStatus);
        ExpectSubStringMatch("1 days", contractStatus);
        ExpectSubStringMatch("3 days", contractStatus);
    }
}

/////////////////////////////////////////////////////////////////////////////
void ContractProgressCalculatesCorrectly()
{
    // Add cargo that matches a contract
    Player->addCargoToVehicle("/lib/instances/items/materials/metal/iron", 5);
    
    Player->acceptContract("progress_test", ([
        "description": "Test Progress",
        "destination": "Port Delta",
        "deadline": time() + (7 * 86400),
        "item type": "materials",
        "quantity": 10
    ]));

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    // Find active contracts option and select it
    string message = Player->caughtMessage();
    int activeOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "View Active Contracts")))
        {
            sscanf(line, "%d. %*s", activeOption);
            break;
        }
    }

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
    // Should not show "View Active Contracts" when player has no active contracts
    ExpectFalse(sizeof(regexp(({ message }), "View Active Contracts")) > 0,
        "Should not show active contracts option when player has none");
}

/////////////////////////////////////////////////////////////////////////////
void ActiveContractsWithNoActiveShowsMessage()
{
    Player->acceptContract("test", ([
        "description": "Test Contract",
        "destination": "Port Echo",
        "deadline": time() + (14 * 86400),
        "item type": "materials",
        "quantity": 1
    ]));

    // Complete the contract to remove it
    Player->completeContract("test");

    resetPlayerMessages();
    ContractsSelector->initiateSelector(Player);

    string message = Player->caughtMessage();
    // Should not show "View Active Contracts" when player has no active contracts
    ExpectFalse(sizeof(regexp(({ message }), "View Active Contracts")) > 0,
        "Should not show active contracts option when all contracts are completed");
}
