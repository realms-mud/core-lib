//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Yeren");
    short("Yeren, a north-road dispatcher");
    description("Yeren checks a short list of incoming carts at "
        "the northern road junction.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "north-road-dispatcherConversation.c");
}
