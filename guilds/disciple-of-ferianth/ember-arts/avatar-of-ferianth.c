//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar of Ferianth");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of transforming an ally into a temporary avatar of Ferianth, "
        "granting immense combat prowess.");
    addSpecification("usage summary", "Ultimate offensive transformation buff");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/ferianths-blessing.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 55
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 200);
    addSpecification("effect", "beneficial");

    addSpecification("bonus fire attack", 25);
    addSpecification("bonus attack", 10);
    addSpecification("bonus damage", 8);
    addSpecification("bonus weapon attack", 1);
    addSpecification("apply haste", 1);
    addSpecification("duration", 180);

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
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.30
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.20
        ])
    }));

    addSpecification("cooldown", 600);
    addSpecification("event handler", "avatarOfFerianthEvent");
    addSpecification("command template", "avatar of ferianth [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::transform## ##TargetName## into an avatar of Ferianth! "
        "##TargetSubjective## ##TargetInfinitive::become## wreathed in divine fire, "
        "eyes blazing with godly power.");
}