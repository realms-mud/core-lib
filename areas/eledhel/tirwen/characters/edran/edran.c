//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Edran");
    short("Edran, shepherd of Tirwen's upper fold");
    description("Edran checks each fastening along the fold before "
        "he turns his attention to the flock.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation("/areas/eledhel/tirwen/characters/edran/"
        "startingConversation.c");
}
