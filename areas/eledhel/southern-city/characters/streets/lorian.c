//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Lorian");
    short("Lorian, an engraver");
    description("Lorian's raven-black hair is carefully combed, and "
        "blue-green eyes study the wrapped plates. He is proud and "
        "patient.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("blacksmith", 4);
    addTrait("/lib/instances/traits/eyes/blue-green.c");
    addTrait("/lib/instances/traits/hair/raven.c");
    addTrait("/lib/instances/traits/personality/proud.c");
    addTrait("/lib/instances/traits/personality/patient.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "lorianConversation.c");
}
