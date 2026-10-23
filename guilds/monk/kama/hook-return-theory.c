//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Hook Return Theory", "Study recovery into a return "
        "cut: adds three to Returning Hook's damage formula.", 25,
        "returning-hook", "kama", "Returning Hook", "bonus", 3);
}
