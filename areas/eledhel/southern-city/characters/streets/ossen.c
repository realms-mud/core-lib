//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Ossen");
    short("Ossen, a dyer's assistant");
    description("Ossen's chocolate-brown hair is bound with a leather "
        "tie, and gray eyes appraise each dyed cloth. He is reserved "
        "and diligent.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addTrait("/lib/instances/traits/eyes/gray.c");
    addTrait("/lib/instances/traits/hair/chocolate-brown.c");
    addTrait("/lib/instances/traits/personality/introvert.c");
    addTrait("/lib/instances/traits/personality/diligent.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "ossenConversation.c");
}
