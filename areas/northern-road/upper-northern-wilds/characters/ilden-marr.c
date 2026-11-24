//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Ilden Marr");
    short("Ilden Marr, boatwright and shore fisher");
    description("Ilden is a compact dwarf with a copper-ringed beard, "
        "dark eyes, and a missing tip on his left forefinger. He "
        "measures a boat by how it behaves in a crosswind, not by "
        "the length written on a builder's slate. The finger was "
        "lost to a split oar; he still uses the scar to teach his "
        "apprentices where not to grip.");
    Gender("male");
    Race("dwarf");
    SetUpPersonaOfLevel("fisher", 4);
    addTrait("/lib/instances/traits/personality/stoic.c");
    addTrait("/lib/instances/traits/personality/diligent.c");
    addConversation(
        "/areas/northern-road/upper-northern-wilds/characters/"
        "ilden-marrConversation.c");
}
