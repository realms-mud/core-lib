//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Horizon Rhythm", "Recover the odachi's broad line "
        "sooner: reduce Horizon Cut's cooldown by four seconds.",
        25, "horizon-geometry", "odachi", "Horizon Cut",
        "decrease cooldown", 4);
}
