//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Breath Rake", "Distract the opponent's concentration "
        "with one claw action, draining spell points without silence.",
        15, "claw-alignment", "claw", "damage spell points",
        12, 2, 10, 16, "claw-breath-theory");
}
