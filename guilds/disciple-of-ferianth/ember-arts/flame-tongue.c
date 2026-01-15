//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flame Tongue");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of blessing an ally's weapon with a flame tongue, causing "
        "it to deal devastating fire damage with each strike.");
    addSpecification("usage summary", "Powerful fire damage weapon enhancement");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/firebrand.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 31
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 90);
    addSpecification("effect", "beneficial");

    addSpecification("bonus fire attack", 15);
    addSpecification("bonus damage", 5);
    addSpecification("bonus fire enchantment", 5);
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
            "rate": 1.10
        ])
    }));

    addSpecification("cooldown", 180);
    addSpecification("event handler", "flameTongueEvent");
    addSpecification("command template", "flame tongue [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::bless## ##TargetName##'s weapon with a flame tongue! "
        "The weapon speaks with sacred fire.");
}
