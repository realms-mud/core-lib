//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Rake Return Theory", "Study recovery into one "
        "return thrust: adds three to Returning Rake's damage formula.",
        25, "returning-rake", "claw", "Returning Rake", "bonus", 3);
}
