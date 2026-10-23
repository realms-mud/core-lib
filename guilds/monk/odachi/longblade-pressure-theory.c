//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Longblade Pressure Theory", "Understand resistance "
        "to the heavy blade: adds three to Weight Check's stamina drain "
        "and opens Stilling Arc.", 15, "weight-check", "odachi",
        "Weight Check", "bonus", 3);
}
