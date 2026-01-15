//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ferianth's Vigor");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of channeling Ferianth's divine vigor into an ally, "
        "granting exceptional physical enhancement.");
    addSpecification("usage summary", "Major physical stat buff");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/indomitable-spirit.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 35
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);
    addSpecification("effect", "beneficial");

    addSpecification("bonus hit points", 150);
    addSpecification("bonus heal hit points", 5);
    addSpecification("bonus heal hit points rate", 2);
    addSpecification("bonus constitution", 2);
    addSpecification("duration", 300);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ember-arts/divine-ember-potency.c",
            "name": "Divine Ember Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.20
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.12
        ])
    }));

    addSpecification("cooldown", 240);
    addSpecification("event handler", "ferianthsVigorEvent");
    addSpecification("command template", "ferianths vigor [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::channel## Ferianth's vigor into ##TargetName##! "
        "Divine strength surges through ##TargetPossessive## body.");
}