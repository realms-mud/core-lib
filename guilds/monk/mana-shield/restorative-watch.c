//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Restorative Watch", "Keep reserve recovery separate "
        "from anxious vigilance, adding one spell-point recovery bonus "
        "while Mindful Ward is active.",
        20, 2, "/guilds/monk/mana-shield/renewing-rhythm.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("bonus recover spell points", 1);
}
