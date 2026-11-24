//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Hedran Varel");
    short("Hedran Varel, the Phaedra outpost quartermaster");
    description("Hedran's dark hair has gone silver at the temples, "
        "and a fine scar crosses his right eyebrow. Ink stains the "
        "side of his thumb where he keeps the supply ledgers. He "
        "checks every sack himself, not from distrust of his staff "
        "but because he remembers the winter a missing flour cart "
        "left a patrol eating boiled roots.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 6);
    addTrait("/lib/instances/traits/personality/focused.c");
    addTrait("/lib/instances/traits/personality/diligent.c");
    addConversation(
        "/areas/northern-road/upper-northern-wilds/characters/"
        "hedran-varelConversation.c");
}
