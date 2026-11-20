//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Rinna Inaeus");
    short("Rinna Inaeus, keeper of the Looming Stag");
    description("Rinna keeps the Looming Stag's common room ready for "
        "carters, travelers, and the town's own Werric households.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("innkeeper", 5);
    addConversation(
        "/areas/linwaeth/characters/inaeus-innkeeperConversation.c");
}
