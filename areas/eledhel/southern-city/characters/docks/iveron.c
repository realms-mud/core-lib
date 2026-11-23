//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Iveron");
    short("Iveron, a fish buyer");
    description("Iveron's russet-brown hair is windblown, and hazel eyes "
        "inspect the catch. He is pragmatic and diligent.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("fisher", 4);
    addTrait("/lib/instances/traits/eyes/hazel.c");
    addTrait("/lib/instances/traits/hair/russet-brown.c");
    addTrait("/lib/instances/traits/personality/pragmatic.c");
    addTrait("/lib/instances/traits/personality/diligent.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/docks/"
        "iveronConversation.c");
}
