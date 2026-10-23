//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Mindful Casting", "Avoid needless energy expenditure "
        "while warded, adding one to the existing spell-point reduction "
        "bonus rather than changing absorbed damage costs.",
        15, 2, "/guilds/monk/mana-shield/economical-refuge.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("bonus reduce spell points", 1);
}
