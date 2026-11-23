//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Daerwen");
    short("Daerwen, shepherd of the south folds");
    description("Daerwen counts the flock near the tree line and "
        "keeps a wary eye on the old track.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
}
