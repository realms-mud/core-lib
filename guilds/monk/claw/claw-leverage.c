//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Claw Leverage", "Study exhausting close defenses: "
        "adds three to Claw Check's stamina-drain formula.", 10,
        "claw-check", "claw", "Claw Check", "bonus", 3);
}
