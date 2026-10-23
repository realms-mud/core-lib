//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Return Trajectory", "Study recovery into a follow-up: "
        "adds three to Returning Shot's damage formula.", 25,
        "returning-shot", "archery", "Returning Shot", "bonus", 3);
}
