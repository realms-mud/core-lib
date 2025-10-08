//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Init()
{
    ignoreList += ({
        "__inline_lib_tests_modules_trade_vehicleSelectorTest_c_163_#0000",
        "resetPlayerMessages",
        "getMenuOptionNumber", 
        "setupPlayerVehicles",
        "setupPlayerHenchmen",
        "findOptionByText",
        "getFirstVehicleOfType",
        "navigateToVehicleMenu"
    });
}

/////////////////////////////////////////////////////////////////////////////
private void setupPlayerVehicles()
{
    // Use the trader's addVehicle method correctly - it takes type and location, returns the vehicle
    object handcart = Player->addVehicle("handcart", "eledhel");
    if (objectp(handcart))
    {
        object vehicleService = getService("vehicle");
        mapping blueprint = vehicleService->queryVehicleBlueprint("handcart");
        handcart->initializeVehicle(blueprint);
    }

    // Create a wagon with some cargo and crew
    object wagon = Player->addVehicle("wagon", "eledhel");
    if (objectp(wagon))
    {
        object vehicleService = getService("vehicle");
        mapping blueprint = vehicleService->queryVehicleBlueprint("wagon");
        wagon->initializeVehicle(blueprint);
        wagon->addCargo("grain", 5);
        wagon->assignHenchman("henchman", "Gareth");
    }
}

/////////////////////////////////////////////////////////////////////////////
private void setupPlayerHenchmen()
{
    Player->addHenchman("eledhel", ([
        "name": "Gareth",
        "type": "sailor", 
        "traits": ({ "/lib/instances/traits/domains/journeyman-sailor.c" }),
        "persona": "swordsman",
        "level": 8,
        "activity": "idle"
    ]));

    Player->addHenchman("eledhel", ([
        "name": "Marcus",
        "type": "marine",
        "traits": ({ "/lib/instances/traits/domains/journeyman-marine.c" }),
        "persona": "fighter",
        "level": 10,
        "activity": "idle"
    ]));

    Player->addHenchman("riverport", ([
        "name": "Finn",
        "type": "sailor",
        "traits": ({ "/lib/instances/traits/domains/master-sailor.c" }),
        "persona": "rogue",
        "level": 12,
        "activity": "idle"
    ]));
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/domains/vehicleSelector.c");
    Selector->setLocation("eledhel");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
    Player->colorConfiguration("none");
    Player->charsetConfiguration("ascii");
    Player->addMoney(10000);
    Player->addPlayerHolding("eledhel");
    Player->initializeTrader(); // Initialize trader functionality

    setupPlayerHenchmen();
    setupPlayerVehicles();

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Selector);
    destruct(Player);
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
    if (message && (message != ""))
    {
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
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string findOptionByText(string searchText)
{
    string result = "0";
    string message = Player->caughtMessage();
    string *lines = explode(message, "\n");
    
    foreach (string line in lines)
    {
        line = regreplace(line, "\x1B\\[[0-9;]*[A-Za-z]", "", 1);
        if (sizeof(regexp(({ line }), searchText)))
        {
            result = regreplace(line, "^[^0-9]*([0-9]+).*", "\\1", 1);
            break;
        }
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
private object getFirstVehicleOfType(string vehicleType)
{
    object result = 0;
    object *vehicles = Player->getVehiclesAtLocation("eledhel");
    object *filteredVehicles = filter(vehicles, (: $1->query("vehicle type") == $2 :), vehicleType);
    
    if (sizeof(filteredVehicles))
    {
        result = filteredVehicles[0];
    }
    return result;
}

/////////////////////////////////////////////////////////////////////////////
private void navigateToVehicleMenu()
{
    resetPlayerMessages();
    Selector->initiateSelector(Player);
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysVehicleManagementMenu()
{
    navigateToVehicleMenu();

    string message = Player->caughtMessage();
    
    ExpectSubStringMatch("Vehicle Management.*Main Menu", message);
    ExpectSubStringMatch("Purchase New Vehicle", message);
    ExpectSubStringMatch("View Vehicle Fleet", message);
    ExpectSubStringMatch("Manage Handcart", message);
    ExpectSubStringMatch("Manage Wagon", message);
    ExpectSubStringMatch("Exit Vehicle Management Menu", message);
}

///////////////////////////////////////////////////////////////////////////////
//void PurchaseVehicleMenuDisplaysCorrectly()
//{
//    navigateToVehicleMenu();
//    string purchaseOption = findOptionByText("Purchase New Vehicle");
//    command(purchaseOption, Player);
//
//    string message = Player->caughtMessage();
//    
//    ExpectSubStringMatch("Purchase Vehicle", message);
//    ExpectSubStringMatch("Handcart.*\\$40", message);
//    ExpectSubStringMatch("Pushcart.*\\$50", message);
//    ExpectSubStringMatch("Wagon.*\\$250", message);
//    ExpectSubStringMatch("Return", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void CanPurchaseVehicleWithSufficientFunds()
//{
//    int initialMoney = Player->getMoney();
//    int initialVehicleCount = sizeof(Player->getVehiclesAtLocation("eledhel"));
//    
//    navigateToVehicleMenu();
//    string purchaseOption = findOptionByText("Purchase New Vehicle");
//    command(purchaseOption, Player);
//    
//    string handcartOption = findOptionByText("Handcart.*\\$40");
//    command(handcartOption, Player);
//    
//    ExpectEq(initialMoney - 40, Player->getMoney());
//    ExpectEq(initialVehicleCount + 1, sizeof(Player->getVehiclesAtLocation("eledhel")));
//    ExpectSubStringMatch("purchased.*Handcart.*40 gold", Player->caughtMessage());
//}
//
///////////////////////////////////////////////////////////////////////////////
//void CannotPurchaseVehicleWithInsufficientFunds()
//{
//    Player->addMoney(-9900); // Leave only 100 gold
//    
//    navigateToVehicleMenu();
//    string purchaseOption = findOptionByText("Purchase New Vehicle");
//    command(purchaseOption, Player);
//    
//    string message = Player->caughtMessage();
//    
//    // Expensive vehicles should show "low $" indicator
//    ExpectSubStringMatch("Wagon.*low \\$", message);
//    ExpectSubStringMatch("Covered Wagon.*low \\$", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void ViewVehicleFleetDisplaysCorrectInformation()
//{
//    navigateToVehicleMenu();
//    string fleetOption = findOptionByText("View Vehicle Fleet");
//    command(fleetOption, Player);
//    
//    string message = Player->caughtMessage();
//    
//    ExpectSubStringMatch("=== Vehicle Fleet ===", message);
//    ExpectSubStringMatch("Handcart", message);
//    ExpectSubStringMatch("Wagon", message);
//    ExpectSubStringMatch("Capacity:", message);
//    ExpectSubStringMatch("Crew Efficiency:", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void ManageVehicleDisplaysEnhancementOptions()
//{
//    navigateToVehicleMenu();
//    string wagonOption = findOptionByText("Manage Wagon");
//    command(wagonOption, Player);
//    
//    string message = Player->caughtMessage();
//    
//    ExpectSubStringMatch("Enhance Vehicle", message);
//    ExpectSubStringMatch("View Vehicle Layout", message);
//    ExpectSubStringMatch("Upgrade.*Slot", message);
//    ExpectSubStringMatch("Return", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void VehicleLayoutDisplaysCorrectly()
//{
//    navigateToVehicleMenu();
//    string wagonOption = findOptionByText("Manage Wagon");
//    command(wagonOption, Player);
//    
//    string layoutOption = findOptionByText("View Vehicle Layout");
//    command(layoutOption, Player);
//    
//    string message = Player->caughtMessage();
//    
//    // Check for wagon layout elements
//    ExpectSubStringMatch("\\[FRAME\\]", message);
//    ExpectSubStringMatch("\\[CARGO1\\]", message);
//    ExpectSubStringMatch("\\[CARGO2\\]", message);
//    ExpectSubStringMatch("\\[HENCHMAN\\]", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void ComponentUpgradeMenuDisplaysAvailableComponents()
//{
//    navigateToVehicleMenu();
//    string wagonOption = findOptionByText("Manage Wagon");
//    command(wagonOption, Player);
//    
//    string upgradeOption = findOptionByText("Upgrade.*frame.*Slot");
//    command(upgradeOption, Player);
//    
//    string message = Player->caughtMessage();
//    
//    ExpectSubStringMatch("Available Components", message);
//    ExpectSubStringMatch("basic.*frame", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void CrewManagementDisplaysAvailableHenchmen()
//{
//    navigateToVehicleMenu();
//    string wagonOption = findOptionByText("Manage Wagon");
//    command(wagonOption, Player);
//    
//    string crewOption = findOptionByText("Manage.*henchman.*Position");
//    command(crewOption, Player);
//    
//    string message = Player->caughtMessage();
//    
//    ExpectSubStringMatch("Crew Assignment", message);
//    ExpectSubStringMatch("View Current Crew", message);
//    ExpectSubStringMatch("Assign.*Gareth", message);
//    ExpectSubStringMatch("Assign.*Marcus", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void CanAssignHenchmanToVehicle()
//{
//    object wagon = getFirstVehicleOfType("wagon");
//    ExpectTrue(objectp(wagon));
//    
//    // Remove current crew assignment
//    wagon->unassignHenchman("henchman");
//    
//    navigateToVehicleMenu();
//    string wagonOption = findOptionByText("Manage Wagon");
//    command(wagonOption, Player);
//    
//    string crewOption = findOptionByText("Manage.*henchman.*Position");
//    command(crewOption, Player);
//    
//    string assignOption = findOptionByText("Assign.*Marcus");
//    command(assignOption, Player);
//    
//    mapping crew = wagon->getCrew();
//    ExpectTrue(member(crew, "henchman"));
//    ExpectEq("Marcus", crew["henchman"]);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void CrewAssignmentUpdatesVehicleEfficiency()
//{
//    object wagon = getFirstVehicleOfType("wagon");
//    ExpectTrue(objectp(wagon));
//    
//    // Test without crew
//    wagon->unassignHenchman("henchman");
//    int lowEfficiency = wagon->getCrewEfficiency();
//    
//    // Test with crew
//    wagon->assignHenchman("henchman", "Marcus");
//    int highEfficiency = wagon->getCrewEfficiency();
//    
//    ExpectTrue(highEfficiency > lowEfficiency);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void VehicleStatusDisplaysDetailedInformation()
//{
//    object wagon = getFirstVehicleOfType("wagon");
//    ExpectTrue(objectp(wagon));
//    
//    string stat = wagon->getVehicleStatus(Player);
//    
//    ExpectSubStringMatch("=== Wagon Status ===", stat);
//    ExpectSubStringMatch("Location: eledhel", stat);
//    ExpectSubStringMatch("Structure:", stat);
//    ExpectSubStringMatch("Capacity:", stat);
//    ExpectSubStringMatch("Speed:", stat);
//    ExpectSubStringMatch("Protection:", stat);
//    ExpectSubStringMatch("Crew Efficiency:", stat);
//    ExpectSubStringMatch("grain: 5 units", stat);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void CanHireNewCrewMember()
//{
//    int initialMoney = Player->getMoney();
//    mapping initialHenchmen = Player->getHenchmen("all", "eledhel");
//    
//    navigateToVehicleMenu();
//    string wagonOption = findOptionByText("Manage Wagon");
//    command(wagonOption, Player);
//    
//    string crewOption = findOptionByText("Manage.*henchman.*Position");
//    command(crewOption, Player);
//    
//    string hireOption = findOptionByText("Hire Sailor.*1000");
//    command(hireOption, Player);
//    
//    ExpectEq(initialMoney - 1000, Player->getMoney());
//    mapping newHenchmen = Player->getHenchmen("all", "eledhel");
//    ExpectTrue(sizeof(newHenchmen) > sizeof(initialHenchmen));
//}
//
///////////////////////////////////////////////////////////////////////////////
//void VehiclesAtDifferentLocationsNotShown()
//{
//    // Add vehicle at different location
//    object barge = clone_object("/lib/items/vehicle.c");
//    barge->set("vehicle type", "barge");
//    barge->setLocation("riverport");
//    
//    object vehicleService = getService("vehicle");
//    mapping blueprint = vehicleService->queryVehicleBlueprint("barge");
//    barge->initializeVehicle(blueprint);
//    Player->addVehicle(barge);
//    
//    navigateToVehicleMenu();
//    string message = Player->caughtMessage();
//    
//    // Should show eledhel vehicles but not riverport barge
//    ExpectSubStringMatch("Handcart", message);
//    ExpectSubStringMatch("Wagon", message);
//    ExpectFalse(sizeof(regexp(({ message }), "Barge")));
//}
//
///////////////////////////////////////////////////////////////////////////////
//void SelectorHandlesEmptyVehicleList()
//{
//    // Remove all vehicles at location
//    object *vehicles = Player->getVehiclesAtLocation("eledhel");
//    foreach (object vehicle in vehicles)
//    {
//        Player->removeVehicle(vehicle);
//    }
//    
//    navigateToVehicleMenu();
//    string message = Player->caughtMessage();
//    
//    ExpectSubStringMatch("Purchase New Vehicle", message);
//    ExpectFalse(sizeof(regexp(({ message }), "View Vehicle Fleet")));
//    ExpectFalse(sizeof(regexp(({ message }), "Manage.*Vehicle")));
//}
//
///////////////////////////////////////////////////////////////////////////////
//void VehicleCapacityAffectedByCrewEfficiency()
//{
//    object wagon = getFirstVehicleOfType("wagon");
//    ExpectTrue(objectp(wagon));
//    
//    // Test without crew
//    wagon->unassignHenchman("henchman");
//    int lowCapacity = wagon->getCapacity();
//    
//    // Test with crew
//    wagon->assignHenchman("henchman", "Marcus");
//    int highCapacity = wagon->getCapacity();
//    
//    ExpectTrue(highCapacity > lowCapacity);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void VehicleCargoManagementWorks()
//{
//    object wagon = getFirstVehicleOfType("wagon");
//    ExpectTrue(objectp(wagon));
//    
//    int initialUsed = wagon->getUsedSpace();
//    ExpectTrue(wagon->addCargo("wood", 2));
//    ExpectEq(initialUsed + 2, wagon->getUsedSpace());
//    
//    ExpectTrue(wagon->removeCargo("grain", 3));
//    ExpectEq(2, wagon->getCargoQuantity("grain"));
//}
//
///////////////////////////////////////////////////////////////////////////////
//void VehicleDamageAndRepairWorks()
//{
//    object wagon = getFirstVehicleOfType("wagon");
//    ExpectTrue(objectp(wagon));
//    
//    int maxStructure = wagon->getMaxStructure();
//    int initialStructure = wagon->getCurrentStructure();
//    
//    ExpectEq(10, wagon->takeDamage(10));
//    ExpectEq(initialStructure - 10, wagon->getCurrentStructure());
//    ExpectFalse(wagon->isDestroyed());
//    
//    ExpectEq(5, wagon->repair(5));
//    ExpectEq(initialStructure - 5, wagon->getCurrentStructure());
//    
//    // Test destruction
//    wagon->takeDamage(maxStructure);
//    ExpectTrue(wagon->isDestroyed());
//}
//
///////////////////////////////////////////////////////////////////////////////
//void ExitReturnsToMainMenu()
//{
//    navigateToVehicleMenu();
//    string exitOption = findOptionByText("Exit Vehicle Management");
//    command(exitOption, Player);
//    
//    string message = Player->caughtMessage();
//    ExpectSubStringMatch("Vehicle Management.*Main Menu", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void DescribeOptionShowsDetailedInformation()
//{
//    navigateToVehicleMenu();
//    command("? 1", Player);
//    
//    string message = Player->caughtMessage();
//    ExpectSubStringMatch("Browse and purchase new vehicles", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void InvalidSelectionHandledGracefully()
//{
//    navigateToVehicleMenu();
//    command("99", Player);
//    
//    string message = Player->caughtMessage();
//    ExpectSubStringMatch("You must select a number from", message);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void VehicleComponentsDisplayCorrectly()
//{
//    object wagon = getFirstVehicleOfType("wagon");
//    ExpectTrue(objectp(wagon));
//    
//    mapping components = wagon->getComponents();
//    ExpectTrue(sizeof(components) > 0);
//    ExpectTrue(member(components, "frame"));
//    ExpectTrue(member(components, "cargo1"));
//    ExpectTrue(member(components, "cargo2"));
//    ExpectTrue(member(components, "henchman"));
//}
//
///////////////////////////////////////////////////////////////////////////////
//void VehicleVisualizationDisplaysCorrectly()
//{
//    object wagon = getFirstVehicleOfType("wagon");
//    ExpectTrue(objectp(wagon));
//    
//    string visualization = wagon->displayVehicle(Player);
//    ExpectTrue(sizeof(visualization) > 0);
//    ExpectSubStringMatch("\\[FRAME\\]", visualization);
//}
//
///////////////////////////////////////////////////////////////////////////////
//void HenchmenFilteredByLocation()
//{
//    mapping localHenchmen = Player->getHenchmen("all", "eledhel");
//    mapping allHenchmen = Player->getHenchmen("all");
//    
//    ExpectEq(2, sizeof(localHenchmen)); // Gareth and Marcus at eledhel
//    ExpectEq(3, sizeof(allHenchmen));   // Including Finn at riverport
//    
//    ExpectTrue(member(localHenchmen, "Gareth"));
//    ExpectTrue(member(localHenchmen, "Marcus"));
//    ExpectFalse(member(localHenchmen, "Finn"));
//}
//
///////////////////////////////////////////////////////////////////////////////
//void HenchmenFilteredByType()
//{
//    mapping sailors = Player->getHenchmen("sailor", "eledhel");
//    mapping marines = Player->getHenchmen("marine", "eledhel");
//    
//    ExpectEq(1, sizeof(sailors));  // Only Gareth
//    ExpectEq(1, sizeof(marines));  // Only Marcus
//    
//    ExpectTrue(member(sailors, "Gareth"));
//    ExpectTrue(member(marines, "Marcus"));
//}
