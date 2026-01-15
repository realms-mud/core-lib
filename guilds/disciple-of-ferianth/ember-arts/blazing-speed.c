//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blazing Speed");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of channeling sacred fire to enhance an ally's speed "
        "and reflexes.");
    addSpecification("usage summary", "Buff granting haste and dexterity");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/kindle-spirit.c",
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

    addSpecification("bonus dexterity", 1);
    addSpecification("apply haste", 1);
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
    addSpecification("event handler", "blazingSpeedEvent");
    addSpecification("command template", "blazing speed [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::channel## blazing speed into ##TargetName##! "
        "Fire dances around ##TargetPossessive## limbs.");
}
