//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Rinan");
    short("Rinan, a wainwright's customer");
    description("Rinan's platinum-blond hair is cropped at her jaw, "
        "and light-green eyes check the new wheel. She is determined "
        "and shrewd.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 4);
    addTrait("/lib/instances/traits/eyes/light-green.c");
    addTrait("/lib/instances/traits/hair/platinum-blond.c");
    addTrait("/lib/instances/traits/personality/determined.c");
    addTrait("/lib/instances/traits/personality/shrewd.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "rinanConversation.c");
}
