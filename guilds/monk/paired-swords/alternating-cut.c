//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Alternating Cut", "Choose an opening between the two "
        "blade lines and deliver one strike, not two independent hits.",
        20, "paired-pressure", "paired-swords", "damage hit points",
        20, 4, 14, 18, "alternating-lines");
}
