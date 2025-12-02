//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/domains/trading/tradingPort.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup() 
{
    setShortDescription("the major port of Ethyl-Tirath");
    setAdditionalLongDescription(
        "Ethyl-Tirath is a bustling major port city on the northern coast, serving as a vital hub "
        "for maritime trade between the southern and northern regions. Its expansive docks are "
        "filled with ships from distant lands, and the city is renowned for its vibrant markets, "
        "diverse population, and strategic importance. Ethyl-Tirath lies 6 days north of Eledhel "
        "and 2 days south of Adurin."
    );

    // Port configuration
    setPortName("Ethyl-Tirath");
    setPortType("major");

    // Specialties (cheaper here)
    addSpecialty("spices", 0.8);         // 20% cheaper - trade crossroads
    addSpecialty("textiles", 0.85);      // 15% cheaper - weaving industry
    addSpecialty("seafood", 0.9);        // 10% cheaper - coastal abundance

    // Import needs (more expensive here)
    addImportNeed("wood", 1.2);          // 20% markup - high demand for shipbuilding
    addImportNeed("weapons", 1.15);      // 15% markup - strategic location

    // Trade routes
    addTradeRoute("maritime", "Eledhel", 6);
    addTradeRoute("maritime", "Adurin", 2);
    addTradeRoute("maritime", "Minlach", 3);


    ::Setup();
}
