//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Companion Leverage", "Use the blade pair's leverage "
        "efficiently: adds three to Companion Check's stamina drain.",
        10, "companion-check", "paired-swords", "Companion Check", "bonus", 3);
}
