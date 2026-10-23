//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Crossing Rhythm", "Recover the claw guard smoothly: "
        "Crossing Rake's cooldown is four seconds shorter.",
        20, "crossing-talons", "claw", "Crossing Rake",
        "decrease cooldown", 4);
}
