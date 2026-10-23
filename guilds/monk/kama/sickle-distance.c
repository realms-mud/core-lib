//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Sickle Distance", "Read the distance before "
        "committing the curved blade: +1 perception.",
        10, 1, "root", "kama");
    addSpecification("bonus perception", 1);
}
