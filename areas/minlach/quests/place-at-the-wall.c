//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/quests/local-quest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("A Place at the Wall");
    setDescription("Sergeant Bren gives visitors an observation "
        "exercise before accepting them for watch work.");
    addState("started", "Bren asked me to check the gate inspection board.");
    addState("gate observed", "The gate board distinguishes an "
        "unattended latch from a confirmed break-in.");
    addState("signals learned", "The drill-yard slate gives the "
        "alarm signals and the safe assembly point.");
    addState("ready", "The supply roster shows which report needs "
        "a guard, which needs a repairer, and which is only a rumor.");
    addTransition("started", "gate observed", "checkGateInspection");
    addTransition("gate observed", "signals learned", "readWatchSignals");
    addTransition("signals learned", "ready", "checkSupplyRoster");
    addResolution("civil watch", "Bren accepted my observation work "
        "without enrolling me in a guild.", "offerCivilWatch");
    addResolution("training inquiry", "Bren recorded my interest in "
        "further training without promising membership or promotion.",
        "requestWatchTraining");
    setInitialState("started");
}
