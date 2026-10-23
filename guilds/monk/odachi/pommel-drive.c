//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Pommel Drive", "Press with the odachi's hilt and "
        "weight to drain the opponent's stamina rather than health.", 10,
        "longblade-footing", "odachi", "damage stamina points",
        12, 2, 10, 16, "heavy-leverage");
}
