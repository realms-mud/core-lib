//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/domains/trading/tradingPort.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup() 
{
    setShortDescription("the trading district of Eledhel");
    setAdditionalLongDescription("This is the bustling trading district of Eledhel, the capital city. "
           "Magnificent stone buildings house trading companies, banks, and "
           "warehouses. The harbor extends to the east, while administrative "
           "buildings rise to the west. A large board displays current prices "
           "and trade opportunities.");
    
    // Port configuration
    setPortName("Eledhel");
    setPortType("capital");
    
    // Specialties (cheaper here)
    addSpecialty("magical", 0.7);        // 30% cheaper - capital magic
    addSpecialty("weapons", 0.8);        // 20% cheaper - royal armories
    addSpecialty("administrative", 0.75); // 25% cheaper - government surplus
    
    // Import needs (more expensive here)
    addImportNeed("food", 1.3);          // 30% markup - large population
    addImportNeed("materials", 1.25);    // 25% markup - high consumption
    addImportNeed("textiles", 1.2);      // 20% markup - luxury demand
    
    // Trade routes
    addTradeRoute("maritime", "Orothysse", 3);
    addTradeRoute("overland", "Hillgarath", 5);
    addTradeRoute("overland", "Naecis", 7);
    
    // Items - these will be in the room for players to interact with
    addItem("/lib/modules/domains/trading/priceBoard.c", "north");
    
    // Exits
    addExit("east", "/lib/modules/domains/trading/ports/eledhel-harbor");
    addExit("west", "/lib/modules/domains/trading/rooms/eledhel-government");
    addExit("north", "/lib/modules/domains/trading/rooms/eledhel-merchant-quarter");

    ::Setup();
}
