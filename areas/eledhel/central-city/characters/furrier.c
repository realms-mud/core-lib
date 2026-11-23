//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Othrel");
    short("Othrel, furrier of the Old City");
    description("Othrel cleans and sews pelts into practical winter "
        "cloaks for city residents and travelers from the northern road.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation(
        "/areas/eledhel/central-city/characters/furrierConversation.c");
}
