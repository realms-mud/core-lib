//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Smoldering Presence");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of emanating a smoldering presence that wards against "
        "harm and fortifies the body.");
    addSpecification("usage summary", "Sustained aura providing soak and fortification");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/heat-aura.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 17
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);

    addSpecification("bonus soak", 5);
    addSpecification("bonus resist cold", 15);
    addSpecification("apply fortified", 1);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ember-arts/ember-potency.c",
            "name": "Ember Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ])
    }));

    addSpecification("cooldown", 15);
    addSpecification("command template", "smoldering presence");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::emanate## a smoldering presence! Warmth radiates "
        "from ##InitiatorObjective##, warding against harm.");
    addSpecification("use ability deactivate message", "##InitiatorName##'s "
        "smoldering presence fades.");
}
