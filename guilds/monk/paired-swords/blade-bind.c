//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Blade Bind", "Exhaust the opponent's guard through "
        "a brief bind. Drains stamina without disarming or immobilizing.",
        15, "companion-leverage", "paired-swords", "damage stamina points",
        16, 3, 12, 18, "binding-lines");
}
