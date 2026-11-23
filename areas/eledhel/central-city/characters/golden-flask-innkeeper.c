//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Marel");
    short("Marel, keeper of the Golden Flask");
    description("Marel keeps the common room welcoming, the kitchen "
        "supplied, and a careful eye on the travelers passing through.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("innkeeper", 8);
    addConversation(
        "/areas/eledhel/central-city/characters/golden-flask-innkeeperConversation.c");
}
