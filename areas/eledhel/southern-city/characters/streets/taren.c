//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Taren");
    short("Taren, a retired sailor");
    description("Taren's salt-and-pepper hair is wind-tossed, and blue "
        "eyes watch the carts. He is stoic and kind.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("fisher", 4);
    addTrait("/lib/instances/traits/eyes/blue.c");
    addTrait("/lib/instances/traits/hair/salt-and-pepper.c");
    addTrait("/lib/instances/traits/personality/stoic.c");
    addTrait("/lib/instances/traits/personality/kind.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "tarenConversation.c");
}
