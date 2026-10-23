//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Claw Breath Theory", "Study concentration under "
        "close pressure: adds three to Breath Rake's spell-point drain.",
        15, "breath-rake", "claw", "Breath Rake", "bonus", 3);
}
