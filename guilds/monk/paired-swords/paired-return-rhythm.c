//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Paired Return Rhythm", "Recover into the paired "
        "line sooner: reduce Returning Cut's cooldown by four seconds.",
        25, "returning-cut", "paired-swords", "Returning Cut",
        "decrease cooldown", 4);
}
