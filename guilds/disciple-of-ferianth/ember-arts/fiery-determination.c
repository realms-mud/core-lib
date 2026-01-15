//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fiery Determination");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of infusing an ally with fiery determination, granting "
        "enhanced endurance and stamina.");
    addSpecification("usage summary", "Buff granting constitution and stamina");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/burning-resolve.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 19
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 55);
    addSpecification("effect", "beneficial");

    addSpecification("bonus constitution", 2);
    addSpecification("bonus stamina points", 50);
    addSpecification("bonus heal stamina", 3);
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
    addSpecification("event handler", "fieryDeterminationEvent");
    addSpecification("command template", "fiery determination [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::infuse## ##TargetName## with fiery determination! "
        "Inner flames strengthen ##TargetPossessive## resolve.");
}
