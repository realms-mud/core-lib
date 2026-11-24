//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Vessa Arn");
    short("Vessa Arn, a drover");
    description("Vessa is a human woman with dark, tightly curled "
        "hair bound beneath a faded red cap and calm hazel eyes. "
        "A healed split crosses her lower lip. Her coat is patched "
        "at both elbows, and she carries a long ash switch that "
        "she uses to point, never to strike.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addTrait("/lib/instances/traits/personality/brave.c");
    addTrait("/lib/instances/traits/personality/reasonable.c");
    addConversation("/areas/northern-road/minlach-approaches/characters/"
        "vessa-arnConversation.c");
}
