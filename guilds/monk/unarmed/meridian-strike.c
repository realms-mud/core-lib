//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Meridian Strike", "An advanced concentration-breaking "
        "strike drains spell points, not health.", 20, "meridian-lore",
        "unarmed", "damage spell points", 20, 4, 12, 18, "pulse-mapping");
}
