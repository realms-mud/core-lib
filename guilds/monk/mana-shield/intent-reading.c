//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Intent Reading", "Use the ward as a stable reference "
        "for interpreting magic, gaining two spellcraft while it is active.",
        20, 2, "/guilds/monk/mana-shield/ward-listening.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("bonus spellcraft", 2);
}
