//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Eira Pell");
    short("Eira Pell, keeper of the barrow ridge");
    description("Eira is an elderly human woman with a long white "
        "braid, one clouded eye, and a steady, unclouded stare from "
        "the other. She carries a small mallet for resetting loose "
        "mound stones and wears no badge of office. Her father "
        "taught her the names on the ridge; she has spent forty "
        "years making sure the living do not mistake age for "
        "permission to dig.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addTrait("/lib/instances/traits/personality/pious.c");
    addTrait("/lib/instances/traits/personality/patient.c");
    addConversation(
        "/areas/northern-road/upper-northern-wilds/characters/"
        "eira-pellConversation.c");
}
