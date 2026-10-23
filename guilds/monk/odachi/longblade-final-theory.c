//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Longblade Final Theory", "Master the finishing "
        "commitment: adds three to Final Horizon's damage formula.",
        30, "final-horizon", "odachi", "Final Horizon", "bonus", 3);
}
