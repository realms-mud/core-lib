//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Weryn");
    short("Weryn, a bowstring maker");
    description("Ash-blond hair frames Weryn's light-blue eyes. Patient "
        "and focused, she tests each finished string before delivery.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("blacksmith", 4);
    addTrait("/lib/instances/traits/eyes/light-blue.c");
    addTrait("/lib/instances/traits/hair/ash-blond.c");
    addTrait("/lib/instances/traits/personality/patient.c");
    addTrait("/lib/instances/traits/personality/focused.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "werynConversation.c");
}
