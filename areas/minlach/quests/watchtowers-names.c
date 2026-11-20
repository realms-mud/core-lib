//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/quests/local-quest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("The Watchtower's Names");
    setDescription("Scribe Orlen wants the old relay tower's records "
        "preserved before salvage crews dismantle its cellar.");
    addState("started", "Orlen asked me to read the relay marker.");
    addState("marker read", "The marker dates the tower to an old "
        "coastal watch route rather than a royal palace.");
    addState("ledger read", "The cellar ledger names local workers "
        "and a repair fund maintained by neighboring households.");
    addState("ready", "The archive's household register matches the "
        "names, identifying the records without inventing noble ancestry.");
    addTransition("started", "marker read", "readRelayMarker");
    addTransition("marker read", "ledger read", "readTowerLedger");
    addTransition("ledger read", "ready", "compareHouseholdRegister");
    addResolution("archive copies", "Orlen preserved copies in the "
        "archive and returned the household entries to their families.",
        "preserveTowerRecords");
    addResolution("salvage notice", "Orlen documented ownership and "
        "posted a notice requiring records to be saved before salvage.",
        "recordTowerOwnership");
    setInitialState("started");
}
