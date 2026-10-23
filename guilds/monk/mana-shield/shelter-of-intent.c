//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Shelter of Intent", "While warded, spend chi to prepare "
        "twenty seconds of fire, cold, and electricity resistance. These "
        "resistances are ordinary defenses, not an extra shield.",
        30, 4, "/guilds/monk/mana-shield/lucid-refuge.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 18);
    addSpecification("cooldown", 70);
    addSpecification("duration", 20);
    addSpecification("bonus resist fire", 3);
    addSpecification("bonus resist cold", 3);
    addSpecification("bonus resist electricity", 3);
    addSpecification("command template", "chi shelter of intent");
    addSpecification("use ability message",
        "##InitiatorName## gather##InitiatorReflexive## a shelter "
        "of intent against the elements.");
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/mana-shield/seamless-recovery.c":8 ]));
}
