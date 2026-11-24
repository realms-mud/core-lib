//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/quests/local-quest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("The Road's Measure");
    setDescription("Aegis surveyor Basil asks for an honest account of "
        "the forest waystations, Minlach's watch coverage, and the stores "
        "available for road work.");
    addState("started", "Basil asked me to assess the road and the support "
        "Minlach can reasonably offer.");
    addState("waystations checked", "The waystation ledger records the "
        "condition of the forest route and its shelters.");
    addState("watch checked", "Minlach's watch has useful local coverage, "
        "but its people cannot be diverted without agreement.");
    addState("stores checked", "The town's stores can support limited "
        "repairs, but not an open-ended Aegis operation.");
    addState("ready", "I have a complete account of the route, watch, "
        "and available stores for Basil.");
    addTransition("started", "waystations checked", "checkWaystations");
    addTransition("waystations checked", "watch checked", "checkTownWatch");
    addTransition("watch checked", "stores checked", "checkAvailableStores");
    addTransition("stores checked", "ready", "reportRoadMeasures");
    addResolution("limited repair", "Basil proposed modest road repairs "
        "and local watch support, subject to Minlach's agreement.",
        "acceptRoadRepair");
    addResolution("reserve stores", "Basil reserved Minlach's stores "
        "and will revise the Aegis patrol plan before requesting more.",
        "reserveStores");
    setInitialState("started");
}
