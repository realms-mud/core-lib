//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Sickle Readiness", "Keep the kama hand ready "
        "to change lines: +1 dexterity.", 20, 1, "sickle-distance", "kama");
    addSpecification("bonus dexterity", 1);
}
