//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Tempered Nerves", "Refuse to echo hostile magic within "
        "your nerves. Gain two magical resistance while warded.",
        20, 2, "/guilds/monk/mana-shield/refuge-theory.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("bonus resist magical", 2);
}
