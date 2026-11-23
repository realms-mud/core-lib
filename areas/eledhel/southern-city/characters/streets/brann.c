//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Brann");
    short("Brann, a cart driver");
    description("Brann's black hair is cropped short, and light-brown "
        "eyes watch the crossing. He is patient and kind.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("farmer", 4);
    addTrait("/lib/instances/traits/eyes/light-brown.c");
    addTrait("/lib/instances/traits/hair/black.c");
    addTrait("/lib/instances/traits/personality/patient.c");
    addTrait("/lib/instances/traits/personality/kind.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "brannConversation.c");
}
