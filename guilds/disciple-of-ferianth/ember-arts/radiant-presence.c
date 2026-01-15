//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Radiant Presence");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of emanating a radiant presence of divine fire that "
        "sears attackers and enhances magical prowess.");
    addSpecification("usage summary", "Sustained aura with damage reflection and spell bonus");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/soul-of-fire.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 43
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);

    addSpecification("apply damage reflection", 15);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus resist fire", 35);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ember-arts/divine-ember-potency.c",
            "name": "Divine Ember Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ember-arts/master-ember-potency.c",
            "name": "Master Ember Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ])
    }));

    addSpecification("cooldown", 30);
    addSpecification("command template", "radiant presence");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::emanate## a radiant presence! Divine fire "
        "radiates from ##InitiatorObjective## in waves.");
    addSpecification("use ability deactivate message", "##InitiatorName##'s "
        "radiant presence dims.");
}
