//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Aedran");
    short("Aedran, a ship rigger");
    description("Aedran's silver hair is tied back, and copper-blue "
        "eyes follow the line aloft. He is focused and determined.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("blacksmith", 5);
    addTrait("/lib/instances/traits/eyes/copper-blue.c");
    addTrait("/lib/instances/traits/hair/silver.c");
    addTrait("/lib/instances/traits/personality/focused.c");
    addTrait("/lib/instances/traits/personality/determined.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/docks/"
        "aedranConversation.c");
}
