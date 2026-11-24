//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Oren Vey");
    short("Oren Vey, the Hollow miller");
    description("Oren is a broad-shouldered maegenstryd man with "
        "umber skin, close-cut black hair, and one amber eye clouded "
        "by an old grain-dust injury. He listens to the wheel as "
        "carefully as he listens to people. A leather cord at his "
        "wrist holds two small wooden beads, carved by his daughter "
        "while he was laid up after the axle cracked.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("miller", 4);
    addTrait("/lib/instances/traits/personality/pragmatic.c");
    addTrait("/lib/instances/traits/personality/patient.c");
    addConversation(
        "/areas/northern-road/upper-northern-wilds/characters/"
        "oren-veyConversation.c");
}
