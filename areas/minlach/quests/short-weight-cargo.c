//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/quests/local-quest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("The Short-Weight Cargo");
    setDescription("Fennel needs an impartial account of a disputed "
        "delivery before he charges a dock worker with theft.");
    addState("started", "Fennel asked me to check the warehouse manifest.");
    addState("manifest checked", "The manifest records sealed fish barrels "
        "by their full weight, including packing brine.");
    addState("scales checked", "The market's test weight balances "
        "correctly. Several delivered barrels have lost their brine.");
    addState("ready", "The dock tally records a split cart hoop and "
        "leaking barrels. The shortage is damage, not evidence of theft.");
    addTransition("started", "manifest checked", "checkCargoManifest");
    addTransition("manifest checked", "scales checked", "checkMarketScales");
    addTransition("scales checked", "ready", "checkDockTally");
    addResolution("restitution", "I arranged a corrected tally and "
        "shared repair costs rather than accusing the dock crew.",
        "settleCargoCosts");
    addResolution("formal record", "I asked Fennel to file the damage "
        "and faulty delivery record for an independent review.",
        "recordCargoDamage");
    setInitialState("started");
}
