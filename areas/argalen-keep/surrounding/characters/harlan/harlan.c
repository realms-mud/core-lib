//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Harlan Reed");
    short("Harlan Reed, a tenant farmer");
    description("Harlan keeps the farm's accounts in a narrow book "
        "tucked into his belt. His sleeves are rolled above sun-browned "
        "forearms, and a length of fence rail rests across the barn "
        "sawhorses behind him. He measures a good day by sound drainage, "
        "fed animals, and enough daylight left to mend what broke.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);

    addConversation(
        "/areas/argalen-keep/surrounding/characters/harlan/"
        "startingConversation.c");
}
