//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/domains/trading/tradingPort.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup() 
{
    setShortDescription("the port city of Adurin");
    setAdditionalLongDescription(
        "Adurin is a small but lively coastal city perched on the northern shore. "
        "It serves as a modest trading hub for goods moving along the coast and is known "
        "for its hardy sailors and fresh seafood. The city is located an 8-day journey due north of Eledhel."
    );

    // Port configuration
    setPortName("Adurin");
    setPortType("small");

    // Specialties (cheaper here)
    addSpecialty("seafood", 0.7);         // 30% cheaper - local catch
    addSpecialty("wood", 0.85);           // 15% cheaper - coastal forests

    // Import needs (more expensive here)
    addImportNeed("textiles", 1.2);       // 20% markup - limited local production
    addImportNeed("weapons", 1.15);       // 15% markup - small city, imports arms

    // Trade routes
    addTradeRoute("maritime", "Eledhel", 8);
    addTradeRoute("maritime", "Minlach", 5);
    addTradeRoute("maritime", "Ethyl-Tirath", 2);

    ::Setup();
}
