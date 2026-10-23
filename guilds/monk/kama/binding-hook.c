//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Binding Hook", "Tax the opponent's stamina with "
        "one close kama action. It does not bind movement or disarm.",
        15, "sickle-leverage", "kama", "damage stamina points",
        20, 3, 12, 18, "binding-geometry");
}
