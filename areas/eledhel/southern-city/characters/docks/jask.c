//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Jask");
    short("Jask, a net mender");
    description("Jask's black hair is tied behind his head, and green "
        "eyes follow each knot. He is patient and reserved.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("fisher", 4);
    addTrait("/lib/instances/traits/eyes/green.c");
    addTrait("/lib/instances/traits/hair/black.c");
    addTrait("/lib/instances/traits/personality/patient.c");
    addTrait("/lib/instances/traits/personality/introvert.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/docks/"
        "jaskConversation.c");
}
