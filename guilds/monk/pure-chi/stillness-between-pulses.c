//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Stillness Between Pulses", "Reset intent rather than "
        "carrying it into the next attack. Needle of Chi recovers one "
        "second sooner and Driving Wave two seconds sooner.",
        30, 3, "/guilds/monk/pure-chi/pulse-cadence.c", ([]));
    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Needle of Chi":1,
        "Driving Wave":2 ]));
}
