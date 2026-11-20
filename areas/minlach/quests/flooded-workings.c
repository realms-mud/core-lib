//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/quests/local-quest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("The Flooded Workings");
    setDescription("Quarry foreman Harl needs a safe route checked "
        "before sending a crew into the disused adit.");
    addState("started", "Harl asked me to inspect the adit's water mark.");
    addState("water measured", "The water has stopped rising but "
        "the lower gallery remains unsafe.");
    addState("supports checked", "The upper supports are sound; "
        "the lower props have shifted and must not be disturbed.");
    addState("ready", "A crew slate marks an upper refuge and a "
        "safe approach. Rescue must use it, not the flooded gallery.");
    addTransition("started", "water measured", "inspectAditWatermark");
    addTransition("water measured", "supports checked", "inspectUpperProps");
    addTransition("supports checked", "ready", "readCrewRefugeSlate");
    addResolution("trained crew", "Harl sent a trained recovery crew "
        "by the upper route and closed the lower gallery.",
        "sendQuarryRecovery");
    addResolution("watch support", "Harl requested watch support "
        "for the recovery and posted warnings at the flooded entrance.",
        "requestQuarrySupport");
    setInitialState("started");
}
