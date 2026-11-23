//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Luvain");
    short("Luvain, a water carrier");
    description("Luvain's honey-brown hair is braided beneath a wrap, "
        "and brown eyes are warm. She is charitable and patient.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("fisher", 4);
    addTrait("/lib/instances/traits/eyes/brown.c");
    addTrait("/lib/instances/traits/hair/honey-brown.c");
    addTrait("/lib/instances/traits/personality/charitable.c");
    addTrait("/lib/instances/traits/personality/patient.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/docks/"
        "luvainConversation.c");
}
