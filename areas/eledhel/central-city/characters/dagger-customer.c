//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Dareth");
    short("Dareth, a watchman collecting a belt knife");
    description("Dareth has brought in a belt knife for sharpening "
        "before his next watch along the storehouse lane.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "dagger-customerConversation.c");
}
