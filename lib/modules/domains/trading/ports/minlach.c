//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/domains/trading/tradingPort.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setShortDescription("the small port of Minlach");
    setAdditionalLongDescription(
        "Minlach is a modest coastal port nestled between the major trade hubs of Eledhel and "
        "Ethyl-Tirath. Known for its quiet docks and friendly local merchants, Minlach serves as "
        "a convenient stopover for traders moving goods along the coast. The port is 3 days north "
        "of Eledhel and 3 days south of Ethyl-Tirath."
    );

    // Port configuration
    setPortName("Minlach");
    setPortType("small");

    // Specialties (cheaper here)
    addSpecialty("food", 0.85);           // 15% cheaper - local produce
    addSpecialty("wood", 0.9);            // 10% cheaper - nearby forests

    // Import needs (more expensive here)
    addImportNeed("spices", 1.2);         // 20% markup - limited access
    addImportNeed("textiles", 1.15);      // 15% markup - small market

    // Trade routes
    addTradeRoute("maritime", "eledhel", 3);
    addTradeRoute("maritime", "ethyl-tirath", 3);
    addTradeRoute("maritime", "adurin", 8);

    ::Setup();
}
