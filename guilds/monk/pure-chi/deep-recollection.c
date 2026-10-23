//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Deep Recollection", "Reassemble scattered attention "
        "during recovery, adding one to spell-point recovery bonuses.",
        20, 2, "/guilds/monk/pure-chi/replenishing-stillness.c", ([]));
    addSpecification("bonus recover spell points", 1);
}
