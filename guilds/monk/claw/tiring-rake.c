//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Tiring Rake", "Force a tiring defense that drains "
        "stamina without paralysis, pinning, or a grapple.",
        25, "claw-composure", "claw", "damage stamina points",
        24, 3, 16, 22, 0);
}
