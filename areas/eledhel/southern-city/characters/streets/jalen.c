//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Jalen");
    short("Jalen, a tailor's runner");
    description("Jalen's chestnut hair falls across amber eyes. He is "
        "humble and loyal to the tailor who trained him.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addTrait("/lib/instances/traits/eyes/amber.c");
    addTrait("/lib/instances/traits/hair/chestnut-brown.c");
    addTrait("/lib/instances/traits/personality/humble.c");
    addTrait("/lib/instances/traits/personality/loyal.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "jalenConversation.c");
}
