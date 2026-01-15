//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Firebrand");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of marking an ally as a firebrand of Ferianth, granting "
        "haste and enhanced offensive power.");
    addSpecification("usage summary", "Haste and attack buff");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/ember-weapon.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 23
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);
    addSpecification("effect", "beneficial");

    addSpecification("bonus attack", 5);
    addSpecification("bonus fire attack", 10);
    addSpecification("apply haste", 1);
    addSpecification("duration", 180);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ember-arts/ember-potency.c",
            "name": "Ember Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ember-arts/enhanced-ember-potency.c",
            "name": "Enhanced Ember Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.10
        ])
    }));

    addSpecification("cooldown", 180);
    addSpecification("event handler", "firebrandEvent");
    addSpecification("command template", "firebrand [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::mark## ##TargetName## as a firebrand of Ferianth! "
        "Sacred flames envelop ##TargetObjective##.");
}
