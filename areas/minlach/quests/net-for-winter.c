//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/quests/local-quest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("A Net for Winter");
    setDescription("Sella's fishing suppliers cannot replace a damaged "
        "net until the cause of its damage is understood.");
    addState("started", "Sella asked me to inspect the net yard.");
    addState("net checked", "The torn net has frayed knots, not knife cuts.");
    addState("shore checked", "Animal tracks lead through the shore "
        "rack, but the loose lashings were already worn.");
    addState("ready", "The chandler's repair record shows an overdue "
        "replacement line. Poor maintenance made the damage worse.");
    addTransition("started", "net checked", "inspectTornNet");
    addTransition("net checked", "shore checked", "inspectNetRack");
    addTransition("shore checked", "ready", "readNetRepairRecord");
    addResolution("repair together", "Sella arranged a shared repair "
        "with the net maker rather than blaming the fishing household.",
        "arrangeNetRepair");
    addResolution("replacement account", "Sella negotiated a replacement "
        "line against the next catch, recording the household's debt.",
        "arrangeNetCredit");
    setInitialState("started");
}
