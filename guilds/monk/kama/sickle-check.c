//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Sickle Check", "Force an exhausting response to "
        "one kama motion, draining stamina without immobilization.",
        10, "sickle-footing", "kama", "damage stamina points",
        12, 2, 8, 14, "sickle-leverage");
}
