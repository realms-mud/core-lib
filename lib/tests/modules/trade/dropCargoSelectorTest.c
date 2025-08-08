//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object DropCargoSelector;
object Vehicle1;
object Vehicle2;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({
        "resetPlayerMessages",
        "setupVehicleWithCargo",
        "navigateToDropCargoSelector",
        "findMenuOption",
        "getVehicleCargoQuantity"
    });
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("testtrader");
    Player.colorConfiguration("none");
    Player.addCommands();
    Player.initializeTrader();

    Vehicle1 = Player.addVehicle("wagon", "TestPort");
    Vehicle1.set("name", "Wagon Alpha");

    Vehicle2 = Player.addVehicle("wagon", "TestPort");
    Vehicle2.set("name", "Wagon Beta");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(DropCargoSelector)) destruct(DropCargoSelector);
    if (objectp(Player)) destruct(Player);
    if (objectp(Vehicle1)) destruct(Vehicle1);
    if (objectp(Vehicle2)) destruct(Vehicle2);
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
private void setupVehicleWithCargo(object vehicle, string item, int quantity)
{
    vehicle.addCargo(item, quantity);
}

/////////////////////////////////////////////////////////////////////////////
private int getVehicleCargoQuantity(object vehicle, string item)
{
    return vehicle.getCargoQuantity(item);
}

/////////////////////////////////////////////////////////////////////////////
private void navigateToDropCargoSelector(string item)
{
    resetPlayerMessages();
    if (objectp(DropCargoSelector)) destruct(DropCargoSelector);
    DropCargoSelector = clone_object("/lib/modules/domains/trading/selectors/dropCargoSelector.c");
    DropCargoSelector.setItem(item);
    move_object(DropCargoSelector, Player);
    DropCargoSelector.initiateSelector(Player);
}

/////////////////////////////////////////////////////////////////////////////
private string findMenuOption(string optionText)
{
    string ret = "0";
    string message = Player.caughtMessage();
    string *lines = explode(message, "\n");
    foreach (string line in lines)
    {
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
void DropCargoSelectorDisplaysMenuCorrectly()
{
    setupVehicleWithCargo(Vehicle1, "/lib/instances/items/materials/metal/iron", 5);
    navigateToDropCargoSelector("/lib/instances/items/materials/metal/iron");
    string message = Player.caughtMessage();

    ExpectSubStringMatch("Drop Iron", message);
    ExpectSubStringMatch("Cancel", message);
    ExpectSubStringMatch("Wagon Alpha", message);
}

/////////////////////////////////////////////////////////////////////////////
void DropCargoSelectorShowsNoCargoMessage()
{
    Vehicle1.set("cargo", ([]));
    Vehicle2.set("cargo", ([]));
    navigateToDropCargoSelector("/lib/instances/items/materials/metal/iron");
    string message = Player.caughtMessage();

    ExpectSubStringMatch("Drop Iron", message);
    ExpectSubStringMatch("Drop All .0 units.", message);
    ExpectSubStringMatch("Cancel", message);
}

/////////////////////////////////////////////////////////////////////////////
void DropCargoSelectorListsAllVehiclesWithCargo()
{
    setupVehicleWithCargo(Vehicle1, "/lib/instances/items/materials/metal/iron", 5);
    setupVehicleWithCargo(Vehicle2, "/lib/instances/items/materials/metal/iron", 3);
    navigateToDropCargoSelector("/lib/instances/items/materials/metal/iron");
    string message = Player.caughtMessage();

    ExpectSubStringMatch("Iron x5", message);
    ExpectSubStringMatch("Wagon Alpha", message);
    ExpectSubStringMatch("Iron x3", message);
    ExpectSubStringMatch("Wagon Beta", message);
}

/////////////////////////////////////////////////////////////////////////////
void SelectingVehiclePromptsForQuantity()
{
    setupVehicleWithCargo(Vehicle1, "/lib/instances/items/materials/metal/iron", 5);
    navigateToDropCargoSelector("/lib/instances/items/materials/metal/iron");
    string message = Player.caughtMessage();

    string option = findMenuOption("Wagon Alpha");
    ExpectTrue(option != "0", "Vehicle option should be present");
    command(option, Player);

    string prompt = Player.caughtMessage();
    ExpectSubStringMatch("How much", prompt);
}

/////////////////////////////////////////////////////////////////////////////
void DroppingCargoRemovesItFromCorrectVehicle()
{
    setupVehicleWithCargo(Vehicle1, "/lib/instances/items/materials/metal/iron", 5);
    setupVehicleWithCargo(Vehicle2, "/lib/instances/items/materials/metal/iron", 3);
    navigateToDropCargoSelector("/lib/instances/items/materials/metal/iron");

    string v1Option = findMenuOption("Wagon Alpha");
    command(v1Option, Player);
    command("3", Player);

    string result = Player.caughtMessage();
    ExpectSubStringMatch("You dropped 3", result);

    int remaining1 = getVehicleCargoQuantity(Vehicle1, "/lib/instances/items/materials/metal/iron");
    int remaining2 = getVehicleCargoQuantity(Vehicle2, "/lib/instances/items/materials/metal/iron");
    ExpectEq(2, remaining1, "Should have 2 iron left in Wagon Alpha");
    ExpectEq(3, remaining2, "Cart Beta should be unchanged");
}

/////////////////////////////////////////////////////////////////////////////
void DropCargoSelectorPreventsOverspill()
{
    setupVehicleWithCargo(Vehicle1, "/lib/instances/items/materials/metal/iron", 2);
    navigateToDropCargoSelector("/lib/instances/items/materials/metal/iron");

    string v1Option = findMenuOption("Wagon Alpha");
    command(v1Option, Player);
    command("5", Player);

    string result = implode(Player.caughtMessages(), "\n");
    ExpectSubStringMatch("Invalid quantity", result);

    int remaining = getVehicleCargoQuantity(Vehicle1, "/lib/instances/items/materials/metal/iron");
    ExpectEq(2, remaining, "Should still have 2 iron after failed drop");
}

/////////////////////////////////////////////////////////////////////////////
void DropCargoSelectorAllowsCancel()
{
    setupVehicleWithCargo(Vehicle1, "/lib/instances/items/materials/metal/iron", 5);
    navigateToDropCargoSelector("/lib/instances/items/materials/metal/iron");

    string cancelOption = findMenuOption("Cancel");
    command(cancelOption, Player);

    string result = Player.caughtMessage();
    ExpectSubStringMatch("Drop Cargo has been exited", result);
}

/////////////////////////////////////////////////////////////////////////////
void DropCargoSelectorHandlesInvalidInput()
{
    setupVehicleWithCargo(Vehicle1, "/lib/instances/items/materials/metal/iron", 5);
    navigateToDropCargoSelector("/lib/instances/items/materials/metal/iron");

    command("999", Player);
    string result = Player.caughtMessage();
    ExpectSubStringMatch("Drop Iron", result);
}

/////////////////////////////////////////////////////////////////////////////
void UndoIsAvailableInDropCargoSelector()
{
    setupVehicleWithCargo(Vehicle1, "/lib/instances/items/materials/metal/iron", 5);
    navigateToDropCargoSelector("/lib/instances/items/materials/metal/iron");

    resetPlayerMessages();
    command("undo", Player);

    string message = Player.caughtMessage();
    ExpectTrue(sizeof(message) > 0, "Undo should provide some response");
}
