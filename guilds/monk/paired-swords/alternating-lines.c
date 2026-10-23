//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Alternating Lines", "Read the safer of two openings: "
        "adds three to Alternating Cut's single damage formula.", 20,
        "alternating-cut", "paired-swords", "Alternating Cut", "bonus", 3);
}
