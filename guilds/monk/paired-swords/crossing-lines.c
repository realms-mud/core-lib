//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Crossing Lines", "Recognize a crossing opening: "
        "adds three to Crossing Cut's damage formula and opens later "
        "paired cuts.", 15, "crossing-cut", "paired-swords",
        "Crossing Cut", "bonus", 3);
}
