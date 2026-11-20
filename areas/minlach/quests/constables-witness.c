//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/quests/local-quest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("The Constable's Witness");
    setDescription("Tristan needs a checked account of a warehouse "
        "break-in, not another accusation based on an unfamiliar face.");
    addState("started", "Tristan asked me to compare the gate statement.");
    addState("gate checked", "The gate statement places the accused "
        "traveler outside town before the warehouse alarm.");
    addState("latch checked", "The warehouse latch was broken outward. "
        "Its splinters lie on the yard side.");
    addState("ready", "The inn account confirms the alarm time. The "
        "evidence contradicts the accusation but does not name a thief.");
    addTransition("started", "gate checked", "readGateStatement");
    addTransition("gate checked", "latch checked", "inspectWarehouseLatch");
    addTransition("latch checked", "ready", "readInnWitnessAccount");
    addResolution("traveler cleared", "Tristan cleared the traveler "
        "and corrected the public accusation.", "clearAccusedTraveler");
    addResolution("case held open", "Tristan released the traveler "
        "while keeping the unexplained warehouse incident open.",
        "keepWarehouseInquiry");
    setInitialState("started");
}
