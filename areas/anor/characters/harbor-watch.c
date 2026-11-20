//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Cailen");
    short("Cailen, an Anor harbor watch");
    description("Cailen checks boats entering the harbor and listens "
        "to reports from the coast road.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 7);
    addConversation("/areas/anor/characters/harbor-watchConversation.c");
}
