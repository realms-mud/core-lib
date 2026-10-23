//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Exhausting Shot", "Commit one arrow to a costly "
        "stamina-draining release. It does not paralyze or pin the target.",
        25, "archers-composure", "archery", "damage stamina points",
        24, 3, 18, 24, 0);
}
