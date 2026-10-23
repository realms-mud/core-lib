//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Rising Talon Theory", "Study the upward thrust: "
        "adds three to Rising Talon's damage formula.", 20,
        "rising-talon", "claw", "Rising Talon", "bonus", 3);
}
