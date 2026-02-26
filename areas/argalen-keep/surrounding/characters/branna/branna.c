//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("branna");
    short("Branna the blacksmith");
    description("Branna is a tall, powerfully built woman with close-cropped "
        "auburn hair and arms corded with muscle. Her skin is darkened "
        "by years at the forge, and her leather apron bears the marks "
        "of countless sparks. She moves with the deliberate economy "
        "of someone accustomed to working with dangerous heat.");

    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 8);

    addConversation(
        "/areas/argalen-keep/surrounding/characters/branna/startingConversation.c");
}
