//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/quests/questItem.c";

/////////////////////////////////////////////////////////////////////////////
private void registerEventHandlers()
{
    registerEventHandler("setupHelpingHand");
}

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setName("Something's Rotten in Tol Dhurath");
    setType("primary");
    setDescription("Basil, the commander of the Aegis Guard, has tasked "
        "you to look into rumors of activity in the ruins of Tol Dhurath.");

    addState("start quest", "I've been asked to look into rumors of "
        "illicit activities coming from the ruins of Tol Dhurath.");

    addState("met maiwyn",
        "I met a woman named Maiwyn who was attempting to escape her "
        "captors in Tol Dhurath. She has given some interesting information "
        "about this place: A Lord Sullath appears to be a major player "
        "in events reaching far beyond what is going on here.");
    addTransition("start quest", "met maiwyn", "met maiwyn");

    addState("a helping hand",
        "Maiwyn has decided to help infiltrate Tol Dhurath.");
    addTransition("met maiwyn", "a helping hand", "maiwyn helps");
    addEntryAction("a helping hand", "setupHelpingHand");

    setInitialState("start quest");

    registerEventHandlers();
}                  

/////////////////////////////////////////////////////////////////////////////
void setupHelpingHand(object player)
{
    notify("setupHelpingHand", player);
}
