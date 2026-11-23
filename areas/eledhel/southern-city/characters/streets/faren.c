//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Faren");
    short("Faren, a potter's apprentice");
    description("Faren's black hair is cropped short above brown eyes. "
        "He is shy but determined to learn his craft.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 3);
    addTrait("/lib/instances/traits/eyes/brown.c");
    addTrait("/lib/instances/traits/hair/black.c");
    addTrait("/lib/instances/traits/personality/shy.c");
    addTrait("/lib/instances/traits/personality/determined.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "farenConversation.c");
}
