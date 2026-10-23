//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Ward Listening", "Read small disturbances across your "
        "ward's surface, gaining two perception only while it is active.",
        10, 1, "/guilds/monk/mana-shield/ward-anatomy.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("bonus perception", 2);
}
