//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Channel Economy", "Prevent energy loss at the end of a "
        "large projection. Driving Wave and Piercing Intent each save two "
        "spell points; sustained reservations are unchanged.",
        20, 2, "/guilds/monk/pure-chi/measured-expenditure.c", ([]));
    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Driving Wave":2,
        "Piercing Intent":2 ]));
}
