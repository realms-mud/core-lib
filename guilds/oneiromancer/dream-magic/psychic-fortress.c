//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Psychic Fortress");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of erecting an impenetrable psychic fortress around their "
        "mind, greatly improving their defenses and mental resilience.");
    addSpecification("usage summary", "A powerful sustained defensive ability");

    addPrerequisite("/guilds/oneiromancer/dream-magic/somnolent-aura.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 39
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);

    addSpecification("bonus defense", 8);
    addSpecification("bonus resist psionic", 15);
    addSpecification("bonus resist magical", 5);
    addSpecification("bonus soak", 5);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
    }));

    addSpecification("cooldown", 180);
    addSpecification("event handler", "psychicFortressEvent");
    addSpecification("command template", "psychic fortress");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::erect## an impenetrable psychic fortress around "
        "##InitiatorPossessive## mind.");
    addSpecification("use ability deactivate message", "The psychic fortress "
        "surrounding ##InitiatorName## crumbles away.");
}
