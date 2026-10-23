//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Traveling Guard", "Keeping cover during movement "
        "grants +1 parry with a primary katana.", 10, 2, "guard-lines", "katana");
    addSpecification("bonus parry", 1);
}
