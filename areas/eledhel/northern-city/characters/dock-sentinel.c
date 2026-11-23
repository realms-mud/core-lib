//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Kerren");
    short("Kerren, a dockside sentry");
    description("Kerren keeps the service quay clear and checks cargo moving "
        "between the pier and the naval stores.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 6);
    addConversation(
        "/areas/eledhel/northern-city/characters/dock-sentinelConversation.c");
}
