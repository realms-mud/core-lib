//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Halan");
    short("Halan, the apothecary");
    description("Halan works among clean shelves of jars and wrapped "
        "bundles. His sleeves are rolled neatly above the wrist, and "
        "he checks every label before handing over a remedy.");

    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("priest", 5);

    addConversation(
        "/areas/eledhel/southern-city/characters/halan/startingConversation.c");
}
