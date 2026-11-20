//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Werric Knight");
    short("a Werric Knight on patrol");
    description("The knight wears a plain traveling cloak over a "
        "serviceable mail shirt. A small Werric token is fastened at "
        "the shoulder.");

    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 9);

    addConversation(
        "/areas/minlach/characters/werric-patrolConversation.c");
}
