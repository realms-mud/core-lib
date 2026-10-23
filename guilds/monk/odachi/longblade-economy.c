//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Longblade Economy", "Remove wasted effort from "
        "the foundational stroke: reduce Committed Cut's authored "
        "stamina cost by two.", 20, "commitment-theory", "odachi",
        "Committed Cut", "decrease cost", 2);
}
