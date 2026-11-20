//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/quests/local-quest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("The False Harbor Light");
    setDescription("Harbor pilot Neris wants to know why a fishing "
        "boat followed a light below the official beacon.");
    addState("started", "Neris asked me to compare the beacon log.");
    addState("log checked", "The official light was tended throughout "
        "the night; the boat saw a different signal.");
    addState("false light found", "A hooded lantern and shutter marks "
        "show that someone signaled from the cove.");
    addState("ready", "The boat's scratched slate records cargo unloaded "
        "under pressure. Its crew took shelter at the harbor refuge.");
    addTransition("started", "log checked", "readBeaconLog");
    addTransition("log checked", "false light found", "inspectFalseLantern");
    addTransition("false light found", "ready", "readBoatSlate");
    addResolution("crew first", "Neris sheltered the crew and sent "
        "their account to Tristan without exposing them at the quay.",
        "protectHarborCrew");
    addResolution("harbor inquiry", "Neris opened a harbor inquiry, "
        "preserving the lantern and slate as evidence.",
        "openHarborInquiry");
    setInitialState("started");
}
