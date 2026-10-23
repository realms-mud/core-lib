//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Claw Check", "Force an exhausting close defense "
        "that drains stamina without immobilizing the opponent.",
        10, "claw-footwork", "claw", "damage stamina points",
        10, 2, 8, 12, "claw-leverage");
}
