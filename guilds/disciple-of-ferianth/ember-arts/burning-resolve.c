//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Burning Resolve");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of infusing an ally with burning resolve, granting "
        "resistance to fear and mental attacks.");
    addSpecification("usage summary", "Buff granting mental resistance and willpower");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/blazing-speed.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 11
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);
    addSpecification("effect", "beneficial");

    addSpecification("bonus wisdom", 1);
    addSpecification("bonus resist psionic", 10);
    addSpecification("bonus resist magical", 5);
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
    addSpecification("event handler", "burningResolveEvent");
    addSpecification("command template", "burning resolve [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::infuse## ##TargetName## with burning resolve! "
        "##TargetPossessive## eyes glow with inner fire.");
}
