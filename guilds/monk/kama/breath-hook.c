//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Breath Hook", "Distract the opponent with one "
        "kama motion that drains spell points. It applies no silence.",
        15, "hook-alignment", "kama", "damage spell points",
        14, 2, 10, 18, "hook-breath-theory");
}
