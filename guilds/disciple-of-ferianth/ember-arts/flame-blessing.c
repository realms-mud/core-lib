//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flame Blessing");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of blessing an ally's weapon with sacred fire, adding "
        "fire damage to their attacks.");
    addSpecification("usage summary", "Buff granting bonus fire damage");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/kindle-spirit.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 9
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);
    addSpecification("effect", "beneficial");

    addSpecification("bonus fire attack", 3);
    addSpecification("bonus damage", 2);
    addSpecification("duration", 180);

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

    addSpecification("cooldown", 90);
    addSpecification("event handler", "flameBlessingEvent");
    addSpecification("command template", "flame blessing [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::bestow## Ferianth's flame blessing upon ##TargetName##! "
        "Sacred fire wreaths ##TargetPossessive## weapon.");
}
