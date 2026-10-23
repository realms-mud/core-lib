//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Sickle Guard", "Keep the kama between your body "
        "and the next blow: +1 parry.", 10, 1, "sickle-footing", "kama");
    addSpecification("bonus parry", 1);
}
