//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Daina");
    short("Daina, an herbalist's customer");
    description("Daina's platinum-blond hair catches the light as green "
        "eyes check each label. She is charming and generous.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addTrait("/lib/instances/traits/eyes/green.c");
    addTrait("/lib/instances/traits/hair/platinum-blond.c");
    addTrait("/lib/instances/traits/personality/charming.c");
    addTrait("/lib/instances/traits/personality/generous.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "dainaConversation.c");
}
