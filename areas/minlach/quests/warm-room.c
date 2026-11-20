//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/quests/local-quest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("The Warm Room");
    setDescription("Roven needs a workable arrangement for a "
        "traveling household whose passage has been delayed.");
    addState("started", "Roven asked me to read the household's account.");
    addState("needs checked", "The household needs two nights' lodging "
        "and food while a coastal boat is repaired.");
    addState("stores checked", "The common granary can supply stored "
        "food without depending on fresh seasonal harvesting.");
    addState("ready", "The work board lists paid mending and tally "
        "work that fits the travelers' skills.");
    addTransition("started", "needs checked", "readTravelersAccount");
    addTransition("needs checked", "stores checked", "checkCommonStores");
    addTransition("stores checked", "ready", "readHouseholdWorkBoard");
    addResolution("work exchange", "Roven agreed to lodging against "
        "paid work at a stated rate, not an indefinite debt.",
        "arrangeLodgingWork");
    addResolution("community aid", "Roven used the town's relief "
        "arrangement, keeping the household's difficulty private.",
        "arrangeLodgingAid");
    setInitialState("started");
}
