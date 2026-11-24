//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Sairen Drel");
    short("Sairen Drel, the net-mender");
    description("Sairen is a human woman with copper curls, sea-green "
        "eyes, and a small notch in her left ear. She knots twine "
        "without looking at her hands and has a habit of counting "
        "each repaired mesh aloud. Her brother took the first boat "
        "north years ago; she still keeps his name on the landing "
        "board beside the tide marks.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("fisher", 4);
    addTrait("/lib/instances/traits/personality/quick-witted.c");
    addTrait("/lib/instances/traits/personality/honest.c");
    addConversation(
        "/areas/northern-road/upper-northern-wilds/characters/"
        "sairen-drelConversation.c");
}
