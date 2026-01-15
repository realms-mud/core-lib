//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fury of Flames");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of channeling Ferianth's fury into an ally, dramatically "
        "enhancing their combat prowess.");
    addSpecification("usage summary", "Powerful attack and damage buff");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/flame-blessing.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 15
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);
    addSpecification("effect", "beneficial");

    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 4);
    addSpecification("bonus strength", 1);
    addSpecification("duration", 120);

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
            "rate": 1.08
        ])
    }));

    addSpecification("cooldown", 120);
    addSpecification("event handler", "furyOfFlamesEvent");
    addSpecification("command template", "fury of flames [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::channel## the fury of flames into ##TargetName##! "
        "Fire erupts around ##TargetObjective## as divine power surges through.");
}
