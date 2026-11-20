//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Elen");
    short("Elen, an Anor salt and fish merchant");
    description("Elen weighs salted fish for travelers and keeps "
        "a careful account of the boats due back at the harbor.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);
    addConversation("/areas/anor/characters/salt-merchantConversation.c");
}
