//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Hook Breath Theory", "Study concentration under "
        "curved-blade pressure: adds three to Breath Hook's spell-point "
        "drain.", 15, "breath-hook", "kama", "Breath Hook", "bonus", 3);
}
