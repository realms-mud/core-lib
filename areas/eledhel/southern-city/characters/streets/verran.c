//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Verran");
    short("Verran, a shop porter");
    description("Verran's chocolate-brown hair is tied with twine, and "
        "hazel eyes follow his parcel cart. He is honest and diligent.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("grocer", 4);
    addTrait("/lib/instances/traits/eyes/hazel.c");
    addTrait("/lib/instances/traits/hair/chocolate-brown.c");
    addTrait("/lib/instances/traits/personality/honest.c");
    addTrait("/lib/instances/traits/personality/diligent.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "verranConversation.c");
}
