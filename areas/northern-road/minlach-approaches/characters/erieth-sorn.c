//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Erieth Sorn");
    short("Erieth Sorn, keeper of the roadside shrine");
    description("Erieth is an elf with long silver hair threaded "
        "through a single braid and clear violet eyes. Her blue "
        "wool mantle is mended at one shoulder with careful "
        "stitches, and a brass wick-trimmer hangs from her belt. "
        "She has the quiet attention of someone who remembers "
        "the faces that pass twice.");
    Gender("female");
    Race("elf");
    SetUpPersonaOfLevel("farmer", 2);
    addTrait("/lib/instances/traits/personality/pious.c");
    addTrait("/lib/instances/traits/personality/peaceful.c");
    addConversation("/areas/northern-road/minlach-approaches/characters/"
        "erieth-sornConversation.c");
}
