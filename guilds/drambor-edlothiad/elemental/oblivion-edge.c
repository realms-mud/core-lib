//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Oblivion Edge");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents mastery of "
        "shadow  blade techniques. The battlemage sustains an enchantment of "
            "pure "
        "oblivion that erases all it touches.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/void-blade.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 55
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);
    addSpecification("stamina point cost", 50);
    addSpecification("cooldown", 90);
    addSpecification("bonus shadow enchantment", 15);
    addSpecification("bonus shadow attack", 15);
    addSpecification("bonus damage", 8);

    addSpecification("command template", "oblivion edge");
    addSpecification("use ability activate message",
        "##InitiatorPossessive::Name## blade opens a sliver of void along its edge, reality distorting around the oblivion enchantment.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## ##Infinitive::seal## the oblivion enchantment, the void closing along the blade's edge.");
}
