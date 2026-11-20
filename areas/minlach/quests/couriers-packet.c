//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/quests/local-quest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("What the Courier Carried");
    setDescription("Tristan wants a diverted delivery traced without "
        "breaking the seal or treating every traveler as an enemy.");
    addState("started", "Tristan asked me to check the relay receipt.");
    addState("receipt checked", "The receipt directs the packet to "
        "Minlach's archive, not the harbor warehouse.");
    addState("seal checked", "The packet's seal is intact. The outer "
        "routing slip was replaced, not the contents.");
    addState("ready", "The archive register identifies it as a "
        "local repair assessment, unrelated to the Tol-Dhurath mission.");
    addTransition("started", "receipt checked", "readCourierReceipt");
    addTransition("receipt checked", "seal checked", "inspectPacketSeal");
    addTransition("seal checked", "ready", "checkCourierRegister");
    addResolution("correct delivery", "Tristan sent the packet to "
        "the archive and corrected its routing record.",
        "correctCourierRoute");
    addResolution("routing inquiry", "Tristan preserved the false "
        "routing slip and opened a narrowly scoped inquiry.",
        "investigateCourierRoute");
    setInitialState("started");
}
