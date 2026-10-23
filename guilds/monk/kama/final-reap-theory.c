//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Final Reap Theory", "Study the committed final "
        "curve: adds three to Final Reap's damage formula.", 30,
        "final-reap", "kama", "Final Reap", "bonus", 3);
}
