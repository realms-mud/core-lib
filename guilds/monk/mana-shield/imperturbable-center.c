//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Imperturbable Center", "Keep foreign energy from "
        "disturbing your central current, gaining three energy resistance "
        "while Mindful Ward is active.",
        30, 3, "/guilds/monk/mana-shield/tempered-nerves.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("bonus resist energy", 3);
}
