//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Sickle Leverage", "Study tiring defensive responses: "
        "adds three to Sickle Check's stamina-drain formula.", 10,
        "sickle-check", "kama", "Sickle Check", "bonus", 3);
}
