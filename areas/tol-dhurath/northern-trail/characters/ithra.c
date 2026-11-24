//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Ithra");
    short("Ithra, a retired road-warden");
    description("Ithra has a traveler's bow within reach and a row of "
        "dried plants arranged by the cave wall. Years on the northern "
        "trail have left her attentive to every change in weather and "
        "every stranger who approaches.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("archer", 4);
    addConversation(
        "/areas/tol-dhurath/northern-trail/characters/ithraConversation.c");
}
