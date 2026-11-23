//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Yaveth");
    short("Yaveth, a street patrol");
    description("Yaveth's close-cropped black hair and brown eyes give "
        "him a watchful look. He is disciplined and just.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 5);
    addTrait("/lib/instances/traits/eyes/brown.c");
    addTrait("/lib/instances/traits/hair/black.c");
    addTrait("/lib/instances/traits/personality/disciplined-warrior.c");
    addTrait("/lib/instances/traits/personality/just.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "yavethConversation.c");
}
