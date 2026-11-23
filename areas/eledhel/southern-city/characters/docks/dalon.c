//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Dalon");
    short("Dalon, a quay watchman");
    description("Dalon's salt-and-pepper hair is cropped short, and "
        "light-gray eyes scan the quay. He is stoic and just.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 5);
    addTrait("/lib/instances/traits/eyes/light-gray.c");
    addTrait("/lib/instances/traits/hair/salt-and-pepper.c");
    addTrait("/lib/instances/traits/personality/stoic.c");
    addTrait("/lib/instances/traits/personality/just.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/docks/"
        "dalonConversation.c");
}
