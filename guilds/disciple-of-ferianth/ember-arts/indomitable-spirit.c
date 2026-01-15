//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Indomitable Spirit");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of granting an ally an indomitable spirit, purging "
        "negative effects and granting immunity.");
    addSpecification("usage summary", "Buff against status effects");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/fiery-determination.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 27
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 80);
    addSpecification("effect", "beneficial");

    addSpecification("bonus resist disease", 25);
    addSpecification("bonus resist poison", 25);
    addSpecification("bonus resist paralysis", 25);
    addSpecification("duration", 240);

    addSpecification("modifiers", ({ 
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
    addSpecification("event handler", "indomitableSpiritEvent");
    addSpecification("command template", "indomitable spirit [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::grant## ##TargetName## an indomitable spirit! "
        "Divine fire burns away weakness.");
}
