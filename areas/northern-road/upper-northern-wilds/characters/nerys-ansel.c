//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Nerys Ansel");
    short("Nerys Ansel, the ridge sentry");
    description("Nerys is a maegenstryd woman with close-braided "
        "ash-brown hair, pale gray eyes, and a white scar on one "
        "knuckle. She keeps her bow unstrung while speaking, but "
        "never lets the road leave her sight. Her left boot is "
        "patched with a strip of red sailcloth from the first "
        "winter she spent at the outpost.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("archer", 7);
    addTrait("/lib/instances/traits/personality/brave.c");
    addTrait("/lib/instances/traits/personality/disciplined-warrior.c");
    addConversation(
        "/areas/northern-road/upper-northern-wilds/characters/"
        "nerys-anselConversation.c");
}
