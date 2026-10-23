//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Crossing Talons", "Study the crossing thrust: "
        "adds three to Crossing Rake's damage formula.", 15,
        "crossing-rake", "claw", "Crossing Rake", "bonus", 3);
}
