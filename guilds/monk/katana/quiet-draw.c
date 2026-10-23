//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Quiet Draw", "An economical opening grants +1 attack "
        "with a primary katana.", 10, 2, "blade-awareness", "katana");
    addSpecification("bonus attack", 1);
}
