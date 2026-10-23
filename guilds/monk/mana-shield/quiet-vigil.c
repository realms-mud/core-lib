//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Quiet Vigil", "Let watchfulness coexist with bodily "
        "rest, adding one natural hit-point healing while Mindful Ward "
        "is active rather than enlarging the spell-point pool.",
        30, 3, "/guilds/monk/mana-shield/restorative-watch.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("bonus heal hit points", 1);
}
