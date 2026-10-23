//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Bow Breath Theory", "Study concentration under "
        "pressure: adds three to Breath-Piercing Shot's spell-point drain.",
        15, "breath-piercing-shot", "archery", "Breath-Piercing Shot",
        "bonus", 3);
}
