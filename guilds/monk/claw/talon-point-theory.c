//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Talon Point Theory", "Study the precise claw "
        "opening: adds three to Talon Point's damage formula.", 20,
        "talon-point", "claw", "Talon Point", "bonus", 3);
}
