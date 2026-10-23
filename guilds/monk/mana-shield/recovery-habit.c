//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Recovery Habit", "Use the ward's regular rhythm to "
        "settle your breathing, adding one natural spell-point healing "
        "while Mindful Ward is active.",
        10, 1, "/guilds/monk/mana-shield/recovery-cycle.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("bonus heal spell points", 1);
}
