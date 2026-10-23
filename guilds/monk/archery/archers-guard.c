//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Archer's Guard", "Keep the body ready to evade "
        "between shots: +1 dodge while wielding a primary bow.",
        10, 1, "archers-footing", "archery");
    addSpecification("bonus dodge", 1);
}
