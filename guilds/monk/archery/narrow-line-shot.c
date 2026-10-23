//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Narrow-Line Shot", "Release one arrow along a narrow "
        "opening. Ordinary arrow resistance still applies.",
        20, "archers-sight", "archery", "damage hit points",
        24, 2, 16, 22, "point-of-release");
}
