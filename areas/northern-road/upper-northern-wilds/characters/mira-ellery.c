//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Mira");
    short("Mira Ellery, keeper of the Windward Inn");
    description("Mira Ellery has auburn hair gone silver at the "
        "temples, green-hazel eyes, and a slight hitch in her right "
        "step from an old fall on the inn stairs. She sets a clean "
        "cup down before asking a traveler's name, and keeps a "
        "separate ledger for guests who cannot pay until spring.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("innkeeper", 5);
    addTrait("/lib/instances/traits/personality/gregarious.c");
    addTrait("/lib/instances/traits/personality/patient.c");
    addConversation(
        "/areas/northern-road/upper-northern-wilds/characters/"
        "mira-elleryConversation.c");
}
