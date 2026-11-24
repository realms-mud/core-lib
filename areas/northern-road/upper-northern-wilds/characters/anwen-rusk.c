//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Anwen Rusk");
    short("Anwen Rusk, a shaken coach attendant");
    description("Anwen is a human woman in a torn blue traveling "
        "coat, with one sleeve pinned above a bandaged forearm. Her "
        "black hair is cut short where someone burned it while she "
        "hid beneath the stagecoach wreck. She inventories every "
        "sound before answering, then apologizes for doing so. The "
        "small brass buckle on her collar belonged to her younger "
        "sister, who is waiting at the southern road post.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addTrait("/lib/instances/traits/personality/determined.c");
    addTrait("/lib/instances/traits/personality/strong-willpower.c");
    addConversation(
        "/areas/northern-road/upper-northern-wilds/characters/"
        "anwen-ruskConversation.c");
}
