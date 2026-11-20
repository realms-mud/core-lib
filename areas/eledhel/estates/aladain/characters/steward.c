//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Ellisar");
    short("Ellisar, steward of House Aladain");
    description("Ellisar keeps the household accounts in order, "
        "with separate ledgers for the keep, village stores, and "
        "the work owed under each field contract.");
    Gender("male");
    Race("human");
    addConversation(
        "/areas/eledhel/estates/aladain/characters/stewardConversation.c");
}
