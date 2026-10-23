//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Commitment Theory", "Study the odachi's committed "
        "line: adds three to Committed Cut's damage formula.", 10,
        "committed-cut", "odachi", "Committed Cut", "bonus", 3);
}
