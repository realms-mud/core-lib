//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Rake Geometry", "Study the close claw line: adds "
        "three to Measured Rake's damage formula.", 10,
        "measured-rake", "claw", "Measured Rake", "bonus", 3);
}
