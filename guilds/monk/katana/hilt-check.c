//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Hilt Check", "A close hilt check drains stamina rather "
        "than health and grants no stun or disarm.", 10,
        "guard-lines", "katana", "damage stamina points", 10, 3, 6, 12,
        "hilt-leverage");
}
