//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Carn");
    short("Carn, a carter");
    description("Carn's russet-brown hair is tousled, and pale-brown "
        "eyes inspect every lashing. He is brave and diligent.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 4);
    addTrait("/lib/instances/traits/eyes/light-brown.c");
    addTrait("/lib/instances/traits/hair/russet-brown.c");
    addTrait("/lib/instances/traits/personality/brave.c");
    addTrait("/lib/instances/traits/personality/diligent.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "carnConversation.c");
}
