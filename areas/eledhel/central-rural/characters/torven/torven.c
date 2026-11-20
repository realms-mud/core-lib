//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Torven");
    short("Torven, the stream miller");
    description("Flour clings to Torven's sleeves, but the fingers "
        "checking his measures are clean. He listens to the wheel "
        "between sentences and keeps the loading book close at hand.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("miller", 4);
    addConversation("/areas/eledhel/central-rural/characters/"
        "torven/startingConversation.c");
}
