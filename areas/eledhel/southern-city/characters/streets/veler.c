//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Veler");
    short("Veler, a blacksmith's apprentice");
    description("Veler's silver hair is tied behind his head, and "
        "hazel eyes study a wrapped tool head. He is introverted and "
        "determined.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 4);
    addTrait("/lib/instances/traits/eyes/hazel.c");
    addTrait("/lib/instances/traits/hair/silver.c");
    addTrait("/lib/instances/traits/personality/introvert.c");
    addTrait("/lib/instances/traits/personality/determined.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "velerConversation.c");
}
