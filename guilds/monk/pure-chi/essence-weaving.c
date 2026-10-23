//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Essence Weaving", "Interlace narrow streams without "
        "letting them interfere, improving spellcraft by two.",
        15, 2, "/guilds/monk/pure-chi/essence-sensitivity.c", ([]));
    addSpecification("bonus spellcraft", 2);
}
