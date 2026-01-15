//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ferianth's Blessing");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of bestowing Ferianth's divine blessing upon an ally, "
        "granting fortification and enhanced resilience.");
    addSpecification("usage summary", "Major fortification and attribute buff");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/ferianths-vigor.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 47
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 150);
    addSpecification("effect", "beneficial");

    addSpecification("bonus strength", 2);
    addSpecification("bonus constitution", 2);
    addSpecification("bonus dexterity", 2);
    addSpecification("bonus damage", 2);
    addSpecification("apply fortified", 1);
    addSpecification("duration", 360);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ember-arts/master-ember-potency.c",
            "name": "Master Ember Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ember-arts/supreme-ember-potency.c",
            "name": "Supreme Ember Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.35
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.20
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
            "rate": 1.15
        ])
    }));

    addSpecification("cooldown", 300);
    addSpecification("event handler", "ferianthsBlessingEvent");
    addSpecification("command template", "ferianths blessing [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::bestow## Ferianth's blessing upon ##TargetName##! "
        "Divine fire envelops ##TargetObjective## in a warm embrace.");
}
