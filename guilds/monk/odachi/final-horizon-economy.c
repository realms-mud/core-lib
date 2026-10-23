//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Final Horizon Economy", "Make the finishing "
        "commitment less wasteful: reduce Final Horizon's authored "
        "stamina cost by three.", 30, "longblade-final-theory", "odachi",
        "Final Horizon", "decrease cost", 3);
}
