//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Heavy Rebuke", "Exhaust a single opponent through "
        "heavy guard pressure. Drains stamina without a paralysis effect.",
        25, "longblade-composure", "odachi", "damage stamina points",
        28, 4, 20, 26, 0);
}
