//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Soren");
    short("Soren, a spice seller");
    description("Soren's ginger hair is braided close, and amber eyes "
        "measure each spice packet. He is spirited and generous.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("grocer", 4);
    addTrait("/lib/instances/traits/eyes/amber.c");
    addTrait("/lib/instances/traits/hair/ginger.c");
    addTrait("/lib/instances/traits/personality/spirited.c");
    addTrait("/lib/instances/traits/personality/generous.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "sorenConversation.c");
}
