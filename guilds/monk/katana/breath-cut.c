//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Breath Cut", "A precise concentration-breaking cut "
        "drains spell points instead of health.", 15, "unwavering-eye",
        "katana", "damage spell points", 12, 3, 8, 14, "breath-timing");
}
