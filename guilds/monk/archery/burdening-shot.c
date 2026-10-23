//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Burdening Shot", "Spend one arrow to force an "
        "exhausting response, draining stamina without a movement lock.",
        15, "bow-leverage", "archery", "damage stamina points",
        16, 3, 12, 20, "draw-pressure-theory");
}
