//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Faler");
    short("Faler, a harbor clerk");
    description("Faler's ash-gray hair is neatly parted, and hazel eyes "
        "check berth assignments. He is rational and diligent.");
    Gender("male");
    Race("halfling");
    SetUpPersonaOfLevel("grocer", 4);
    addTrait("/lib/instances/traits/eyes/hazel.c");
    addTrait("/lib/instances/traits/hair/ash-gray.c");
    addTrait("/lib/instances/traits/personality/rational.c");
    addTrait("/lib/instances/traits/personality/diligent.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/docks/"
        "falerConversation.c");
}
