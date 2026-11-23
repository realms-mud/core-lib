//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Tavren");
    short("Tavren, a petitioner waiting for a hearing");
    description("Tavren holds a folded statement and waits quietly "
        "for the court to call his name.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 2);
    addConversation(
        "/areas/eledhel/southern-city/halls-of-justice/characters/"
        "petitionerConversation.c");
}
