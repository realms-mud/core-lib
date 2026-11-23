//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Mellen");
    short("Mellen, a glassblower's runner");
    description("Mellen's strawberry-blond hair is tied in a ribbon, "
        "and light-gray-blue eyes guard the fragile crate. She is "
        "rational and kind.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 3);
    addTrait("/lib/instances/traits/eyes/light-gray-blue.c");
    addTrait("/lib/instances/traits/hair/strawberry-blond.c");
    addTrait("/lib/instances/traits/personality/rational.c");
    addTrait("/lib/instances/traits/personality/kind.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "mellenConversation.c");
}
