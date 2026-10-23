//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Arresting Shot", "Spend one arrow to tax an opponent's "
        "stamina. This does not immobilize or interrupt the opponent.",
        10, "archers-footing", "archery", "damage stamina points",
        10, 2, 8, 16, "bow-leverage");
}
