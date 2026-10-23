//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Close Circle", "Tire a single opponent with closing "
        "blade lines. Drains stamina without preventing movement.", 25,
        "paired-readiness", "paired-swords", "damage stamina points",
        24, 3, 14, 20, 0);
}
