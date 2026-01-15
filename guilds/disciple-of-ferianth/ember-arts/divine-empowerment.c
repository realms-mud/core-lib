//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Empowerment");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of channeling Ferianth's ultimate divine empowerment, "
        "the pinnacle of defensive ember arts mastery.");
    addSpecification("usage summary", "Ultimate defensive empowerment");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/mantle-of-flames.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 59
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 250);
    addSpecification("effect", "beneficial");

    addSpecification("bonus defense", 10);
    addSpecification("bonus soak", 15);
    addSpecification("bonus hit points", 150);
    addSpecification("bonus resist fire", 50);
    addSpecification("bonus resist cold", 50);
    addSpecification("apply fortified", 1);
    addSpecification("duration", 300);

    addSpecification("modifiers", ({ 
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
            "rate": 0.30
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.35
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.25
        ])
    }));

    addSpecification("cooldown", 600);
    addSpecification("event handler", "divineEmpowermentEvent");
    addSpecification("command template", "divine empowerment [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::channel## Ferianth's divine empowerment into ##TargetName##! "
        "Sacred fire courses through ##TargetPossessive## being, granting "
        "divine protection.");
}
