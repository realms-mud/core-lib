//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/domains/trading/tradingPort.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setShortDescription("the major port of Linwaeth");
    setAdditionalLongDescription(
        "Linwaeth is a bustling major port city located about six days south of Eledhel. "
        "Its harbors are filled with ships from distant lands, and its markets are alive "
        "with traders and travelers. Linwaeth serves as a key junction for both maritime "
        "and overland trade, connecting the southern coast to the heartlands and beyond."
    );

    // Port configuration
    setPortName("Linwaeth");
    setPortType("major");

    // Specialties (cheaper here)
    addSpecialty("textiles", 0.8);        // 20% cheaper - renowned weaving
    addSpecialty("grain", 0.85);          // 15% cheaper - fertile hinterlands
    addSpecialty("seafood", 0.9);         // 10% cheaper - coastal abundance

    // Import needs (more expensive here)
    addImportNeed("spices", 1.2);         // 20% markup - imported luxury
    addImportNeed("weapons", 1.15);       // 15% markup - defensive demand

    // Trade routes
    addTradeRoute("maritime", "Eledhel", 6);
    addTradeRoute("overland", "Eledhel", 9);
    addTradeRoute("overland", "Dor Cathrim", 12);
    addTradeRoute("maritime", "Ethyl-Tirath", 12);

    ::Setup();
}
