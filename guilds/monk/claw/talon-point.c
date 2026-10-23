//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Talon Point", "Deliver one precise tiger-claw "
        "thrust. Normal thrust resistance still applies.",
        20, "claw-readiness", "claw", "damage hit points",
        20, 2, 14, 18, "talon-point-theory");
}
