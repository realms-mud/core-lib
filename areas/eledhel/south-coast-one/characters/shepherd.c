//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Tiriel");
    short("Tiriel, a sheep farmer");
    description("Tiriel checks the hurdles and counts the flock before "
        "the evening wind rises from the sea.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/south-coast-one/characters/shepherdConversation.c");
}
