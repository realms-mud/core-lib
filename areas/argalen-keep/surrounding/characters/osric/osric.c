//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("osric");
    short("Father Osric");
    description("Father Osric is an elderly man with a thin frame and "
        "kind, deep-set eyes. His white hair is neatly trimmed, and "
        "his simple vestments are immaculately kept despite their "
        "age. He moves slowly but with quiet dignity, and his "
        "voice carries the gentle cadence of someone accustomed "
        "to offering comfort.");

    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("priest", 10);

    addConversation(
        "/areas/argalen-keep/surrounding/characters/osric/startingConversation.c");
}
