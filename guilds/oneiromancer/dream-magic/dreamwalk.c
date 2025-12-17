//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dreamwalk");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of partially phasing into the dream realm, becoming harder "
        "to hit and moving with supernatural swiftness.");
    addSpecification("usage summary", "A self-buff granting evasion and haste");

    addPrerequisite("/guilds/oneiromancer/dream-magic/nightmare-cascade.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 47
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 80);

    addSpecification("bonus dodge", 10);
    addSpecification("bonus defense", 5);
    addSpecification("apply haste", 1);
    addSpecification("duration", 60);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/dream-magic/dream-mastery.c",
            "name": "Dream Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.20
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.30
        ]),
    }));

    addSpecification("cooldown", 120);
    addSpecification("event handler", "dreamwalkEvent");
    addSpecification("command template", "dreamwalk");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::phase## partially into the dream realm, "
        "##InitiatorPossessive## form becoming hazy and indistinct.");
}
