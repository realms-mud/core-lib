//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/domains/trading/tradingPort.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setShortDescription("the capital city of Hillgarath");
    setAdditionalLongDescription(
        "Hillgarath is the grand capital of the Hillgarath empire, renowned for its "
        "imposing architecture, vibrant markets, and political influence. The city "
        "serves as a major trading nexus, connecting overland and river routes from "
        "across the continent. Its bustling river docks and caravanserais are always "
        "alive with merchants, travelers, and imperial officials."
    );

    // Port configuration
    setPortName("Hillgarath");
    setPortType("capital");

    // Specialties (cheaper here)
    addSpecialty("administrative", 0.7);   // 30% cheaper - imperial bureaucracy
    addSpecialty("weapons", 0.85);         // 15% cheaper - imperial forges
    addSpecialty("grain", 0.8);            // 20% cheaper - fertile hinterlands

    // Import needs (more expensive here)
    addImportNeed("spices", 1.25);         // 25% markup - luxury demand
    addImportNeed("seafood", 1.2);         // 20% markup - inland city

    // Trade routes
    addTradeRoute("overland", "Ethyl-Tirath", 16);
    addTradeRoute("overland", "Eledhel", 18);
    addTradeRoute("river", "Tiraeth", 12);
    addTradeRoute("river", "Serach", 22);
    addTradeRoute("maritime", "Orothysse", 24);

    ::Setup();
}
