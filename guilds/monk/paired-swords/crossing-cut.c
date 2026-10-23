//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Crossing Cut", "Cross the defensive line and commit "
        "one coordinated cut against a single opponent.", 15,
        "paired-guard", "paired-swords", "damage hit points", 16, 3, 12, 14,
        "crossing-lines");
}
