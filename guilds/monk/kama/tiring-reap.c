//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Tiring Reap", "Force a demanding defense that "
        "drains stamina without paralysis or a movement lock.",
        25, "sickle-composure", "kama", "damage stamina points",
        28, 3, 18, 24, 0);
}
