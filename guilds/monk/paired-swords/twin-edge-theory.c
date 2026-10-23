//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Twin Edge Theory", "Study the commitment of both "
        "blade lines: adds three to Twin Edge's single damage formula.",
        30, "twin-edge", "paired-swords", "Twin Edge", "bonus", 3);
}
