//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Kaelin");
    short("Kaelin, a water carrier");
    description("Kaelin's sandy-brown hair is sun-lightened, and his "
        "light-blue eyes are calm. He is patient and tolerant.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("farmer", 3);
    addTrait("/lib/instances/traits/eyes/light-blue.c");
    addTrait("/lib/instances/traits/hair/sandy-brown.c");
    addTrait("/lib/instances/traits/personality/patient.c");
    addTrait("/lib/instances/traits/personality/tolerant.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "kaelinConversation.c");
}
