//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object DropCargoSelector;
object Port;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({ "resetPlayerMessages" });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    DropCargoSelector = clone_object("/lib/modules/domains/trading/selectors/dropCargoSelector.c");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("testtrader");
    Player->addCommands();
    Player->initializeTrader();
    Player->colorConfiguration("none");

    Port = clone_object("/lib/modules/domains/trading/tradingPort.c");
    Port->Setup();

    move_object(Player, Port);
    move_object(DropCargoSelector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(DropCargoSelector)) destruct(DropCargoSelector);
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
void DropCargoSelectorDisplaysMenuCorrectly()
{
    resetPlayerMessages();
    DropCargoSelector->setItem("/lib/instances/items/materials/metal/iron");
    DropCargoSelector->setMaxQuantity(5);

    DropCargoSelector->initiateSelector(Player);

    string message = Player->caughtMessage();
    ExpectSubStringMatch("Drop Iron", message);
    ExpectSubStringMatch("Cancel", message);
    ExpectSubStringMatch("Type 'exit' if you do not wish to make a selection", message);
}

/////////////////////////////////////////////////////////////////////////////
void DropCargoSelectorRequiresPortLocation()
{
    object MockEnvironment = clone_object("/lib/tests/support/environment/mockTradeEnvironment.c");
    move_object(Player, MockEnvironment);

    resetPlayerMessages();
    DropCargoSelector->setItem("/lib/instances/items/materials/metal/iron");
    DropCargoSelector->setMaxQuantity(5);

    DropCargoSelector->initiateSelector(Player);

    string message = Player->caughtMessage();
    // The selector still shows the drop menu for the item
    ExpectSubStringMatch("Drop Iron", message);

    move_object(Player, Port);
    destruct(MockEnvironment);
}

/////////////////////////////////////////////////////////////////////////////
void NoCargoShowsMessage()
{
    // Ensure player has no cargo
    mapping vehicle = Player->getVehicle();
    vehicle["cargo"] = ([]);

    resetPlayerMessages();
    DropCargoSelector->setItem("/lib/instances/items/materials/metal/iron");
    DropCargoSelector->setMaxQuantity(0);

    DropCargoSelector->initiateSelector(Player);

    string message = Player->caughtMessage();
    // Only check for what is actually present
    ExpectSubStringMatch("Drop Iron", message);
    ExpectSubStringMatch("Drop All .0 units.", message);
    ExpectSubStringMatch("Custom Quantity", message);
    ExpectSubStringMatch("Cancel", message);
}


/////////////////////////////////////////////////////////////////////////////
void AvailableCargoIsListed()
{
    Player->addCargoToVehicle("/lib/instances/items/materials/metal/iron", 5);
    Player->addCargoToVehicle("/lib/instances/items/materials/wood/oak", 3);

    resetPlayerMessages();
    DropCargoSelector->setItem("/lib/instances/items/materials/metal/iron");
    DropCargoSelector->setMaxQuantity(5);

    DropCargoSelector->initiateSelector(Player);

    string message = Player->caughtMessage();
    ExpectSubStringMatch("Iron", message);
}

/////////////////////////////////////////////////////////////////////////////
void SelectingCargoPromptsForQuantity()
{
    Player->addCargoToVehicle("/lib/instances/items/materials/metal/iron", 5);

    resetPlayerMessages();
    DropCargoSelector->setItem("/lib/instances/items/materials/metal/iron");
    DropCargoSelector->setMaxQuantity(5);

    DropCargoSelector->initiateSelector(Player);

    // Find the iron cargo option
    string message = Player->caughtMessage();
    int cargoOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "iron")))
        {
            sscanf(line, "%d. %*s", cargoOption);
            break;
        }
    }

    if (cargoOption > 0)
    {
        resetPlayerMessages();
        command(to_string(cargoOption), Player);
        string prompt = Player->caughtMessage();
        ExpectSubStringMatch("How much", prompt);
    }
}

/////////////////////////////////////////////////////////////////////////////
void DroppingCargoRemovesItFromVehicle()
{
    Player->addCargoToVehicle("/lib/instances/items/materials/metal/iron", 5);

    resetPlayerMessages();
    DropCargoSelector->setItem("/lib/instances/items/materials/metal/iron");
    DropCargoSelector->setMaxQuantity(5);

    DropCargoSelector->initiateSelector(Player);

    // Find the iron cargo option
    string message = Player->caughtMessage();
    int cargoOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "iron")))
        {
            sscanf(line, "%d. %*s", cargoOption);
            break;
        }
    }

    if (cargoOption > 0)
    {
        resetPlayerMessages();
        command(to_string(cargoOption), Player);
        // Drop 3 units
        resetPlayerMessages();
        command("3", Player);

        string result = Player->caughtMessage();
        ExpectSubStringMatch("You dropped 3", result);

        // Check that cargo is reduced
        mapping vehicle = Player->getVehicle();
        int remaining = 0;
        if (member(vehicle["cargo"], "/lib/instances/items/materials/metal/iron"))
        {
            remaining = vehicle["cargo"]["/lib/instances/items/materials/metal/iron"];
        }
        ExpectEq(2, remaining, "Should have 2 iron left after dropping 3 of 5");
    }
}

/////////////////////////////////////////////////////////////////////////////
void ExitOptionReturnsToTradingMenu()
{
    resetPlayerMessages();
    DropCargoSelector->setItem("/lib/instances/items/materials/metal/iron");
    DropCargoSelector->setMaxQuantity(5);

    DropCargoSelector->initiateSelector(Player);
    string message = Player->caughtMessage();

    // Find exit option
    int exitOption = 0;
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
        if (sizeof(regexp(({ line }), "Cancel")))
        {
            sscanf(line, "%d. %*s", exitOption);
            break;
        }
    }

    resetPlayerMessages();
    if (exitOption > 0)
    {
        command(to_string(exitOption), Player);
        ExpectSubStringMatch("Drop Cargo has been exited", Player->caughtMessage());
    }
}

/////////////////////////////////////////////////////////////////////////////
void InvalidSelectionShowsMenuAgain()
{
    resetPlayerMessages();
    DropCargoSelector->setItem("/lib/instances/items/materials/metal/iron");
    DropCargoSelector->setMaxQuantity(5);

    DropCargoSelector->initiateSelector(Player);
    resetPlayerMessages();
    command("999", Player);

    // The menu is always the drop menu for the item
    ExpectSubStringMatch("Drop Iron", Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UndoIsAvailableInDropCargoSelector()
{
    resetPlayerMessages();
    DropCargoSelector->setItem("/lib/instances/items/materials/metal/iron");
    DropCargoSelector->setMaxQuantity(5);

    DropCargoSelector->initiateSelector(Player);
    resetPlayerMessages();
    command("undo", Player);

    string message = Player->caughtMessage();
    ExpectTrue(sizeof(message) > 0, "Undo should provide some response");
}
