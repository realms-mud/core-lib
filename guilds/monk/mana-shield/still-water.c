//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Still Water", "Let the ward bear distractions while "
        "your muscles relax, adding one natural stamina healing while "
        "Mindful Ward is active.",
        15, 2, "/guilds/monk/mana-shield/recovery-habit.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("bonus heal stamina", 1);
}
