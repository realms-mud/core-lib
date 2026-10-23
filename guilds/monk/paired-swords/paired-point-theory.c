//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Paired Point Theory", "Support the thrusting line "
        "with the other blade: adds three to Companion Thrust's damage.",
        20, "companion-thrust", "paired-swords", "Companion Thrust",
        "bonus", 3);
}
