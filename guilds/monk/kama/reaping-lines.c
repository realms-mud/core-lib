//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Reaping Lines", "Study a committed curved cut: "
        "adds three to Reaping Cut's damage formula.", 15,
        "reaping-cut", "kama", "Reaping Cut", "bonus", 3);
}
