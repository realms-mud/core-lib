//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Stable Footing", "Move your feet independently of the "
        "ward's motion, gaining two dodge while Mindful Ward is active.",
        15, 2, "/guilds/monk/mana-shield/soft-boundary.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("bonus dodge", 2);
}
