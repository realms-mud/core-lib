//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Gripping Rake", "Tax the opponent's stamina with "
        "one close tiger-claw action. No grapple or movement lock applies.",
        15, "claw-leverage", "claw", "damage stamina points",
        16, 3, 12, 16, "grip-geometry");
}
