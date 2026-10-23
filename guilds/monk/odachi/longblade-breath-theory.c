//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Longblade Breath Theory", "Time heavy blade "
        "pressure against concentration: adds three to Breath Cleaver's "
        "spell-point drain.", 15, "breath-cleaver", "odachi",
        "Breath Cleaver", "bonus", 3);
}
