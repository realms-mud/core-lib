//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Absolute Zero");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents the pinnacle of "
        " frost blade mastery. The battlemage sustains an enchantment of "
        "absolute cold that freezes the very air around their blade.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/avalanche-strike.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 49
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
    addSpecification("bonus cold enchantment", 15);
    addSpecification("bonus cold attack", 15);
    addSpecification("bonus damage", 8);

    addSpecification("command template", "absolute zero");
    addSpecification("use ability activate message",
        "##InitiatorPossessive::Name## blade radiates an aura of impossible cold, frost crystallizing from the very air.");
    addSpecification("use ability deactivate message", "The absolute zero "
        "enchantment releases its grip on ##InitiatorPossessive## blade.");
}
