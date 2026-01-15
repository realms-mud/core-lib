//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fire Shield");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of wrapping an ally in a protective shield of fire that "
        "enhances defense and damages attackers.");
    addSpecification("usage summary", "Buff granting defense and damage reflection");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/inner-fire.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 7
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("effect", "beneficial");

    addSpecification("bonus defense", 3);
    addSpecification("apply damage reflection", 5);
    addSpecification("duration", 120);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ember-arts/ember-mastery.c",
            "name": "Ember Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 60);
    addSpecification("event handler", "fireShieldEvent");
    addSpecification("command template", "fire shield [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::wrap## ##TargetName## in a protective fire shield! "
        "Flames dance protectively around ##TargetObjective##.");
}
