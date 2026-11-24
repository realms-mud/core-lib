//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Renn Vell");
    short("Renn Vell, the Mallowford field hand");
    description("Renn is a human man with red-brown curls, green "
        "eyes, and a pale scatter of freckles across his nose. One "
        "upper tooth is chipped, and a strip of blue cloth ties "
        "his tool roll to his belt. He has the easy restlessness "
        "of someone who would rather mend a wheel than wait beside it.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addTrait("/lib/instances/traits/personality/quick-witted.c");
    addTrait("/lib/instances/traits/personality/openminded.c");
    addConversation("/areas/northern-road/minlach-approaches/characters/"
        "renn-vellConversation.c");
}
