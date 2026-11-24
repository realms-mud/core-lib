//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Lord Argalen");
    short("Lord Argalen, lord of the keep");
    description("Lord Argalen's formal bearing has softened with the "
        "years, though his attention remains fixed on the people and "
        "lands under his care. A folded letter lies beside the maps "
        "on his study table.");
    Gender("male");
    Race("human");
    addConversation(
        "/areas/argalen-keep/characters/lord-argalen/startingConversation.c");
}
