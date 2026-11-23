//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Cira");
    short("Cira, a boat crew caller");
    description("Cira's raven hair is cut to her shoulders, and amber "
        "eyes command attention at the gangplank. She is quick-witted "
        "and confident.");
    Gender("female");
    Race("elf");
    SetUpPersonaOfLevel("fisher", 4);
    addTrait("/lib/instances/traits/eyes/amber.c");
    addTrait("/lib/instances/traits/hair/raven.c");
    addTrait("/lib/instances/traits/personality/quick-witted.c");
    addTrait("/lib/instances/traits/personality/commanding-presence.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/docks/"
        "ciraConversation.c");
}
