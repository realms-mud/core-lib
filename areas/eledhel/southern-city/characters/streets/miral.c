//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Miral");
    short("Miral, a herb gardener");
    description("Miral's auburn hair is braided loosely, and her hazel "
        "eyes are warm. She is compassionate and peaceful.");
    Gender("female");
    Race("elf");
    SetUpPersonaOfLevel("farmer", 3);
    addTrait("/lib/instances/traits/eyes/hazel.c");
    addTrait("/lib/instances/traits/hair/auburn.c");
    addTrait("/lib/instances/traits/personality/compassionate.c");
    addTrait("/lib/instances/traits/personality/peaceful.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "miralConversation.c");
}
