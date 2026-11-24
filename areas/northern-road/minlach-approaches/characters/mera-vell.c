//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Mera Vell");
    short("Mera Vell, the Mallowford miller");
    description("Mera is a maegenstryd woman in her early forties, with "
        "deep brown eyes and white-blond hair braided close to her head. "
        "Flour dusts the front of her green work dress, and a narrow "
        "leather band keeps the sleeve clear of the mill gears. She "
        "speaks carefully, as if measuring each word against the grain.");
    Gender("female");
    Race("maegenstryd");
    SetUpPersonaOfLevel("miller", 4);
    addTrait("/lib/instances/traits/personality/patient.c");
    addTrait("/lib/instances/traits/personality/pragmatic.c");
    addConversation("/areas/northern-road/minlach-approaches/characters/"
        "mera-vellConversation.c");
}
