//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Rising Heel", "An ascending heel kick has a wider damage "
        "range and a longer commitment than the palm.", 15,
        "supple-form", "unarmed", "damage hit points", 20, 6, 10, 12,
        "heel-trajectory");
}
