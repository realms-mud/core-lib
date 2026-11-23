//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Eland");
    short("Eland, a cloth vendor");
    description("Eland's chestnut hair is neatly combed, and amber eyes "
        "inspect each length of cloth. He is honest and patient.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addTrait("/lib/instances/traits/eyes/amber.c");
    addTrait("/lib/instances/traits/hair/chestnut-brown.c");
    addTrait("/lib/instances/traits/personality/honest.c");
    addTrait("/lib/instances/traits/personality/patient.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "elandConversation.c");
}
