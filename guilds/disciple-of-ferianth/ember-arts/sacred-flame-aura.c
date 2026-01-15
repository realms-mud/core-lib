//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sacred Flame Aura");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of radiating an aura of sacred flame that mends wounds "
        "and restores vitality.");
    addSpecification("usage summary", "Sustained aura with hit point regeneration");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/smoldering-presence.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 23
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);

    addSpecification("bonus heal hit points", 5);
    addSpecification("bonus resist fire", 25);
    addSpecification("bonus hit points", 35);

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
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ember-arts/enhanced-ember-potency.c",
            "name": "Enhanced Ember Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ])
    }));

    addSpecification("cooldown", 20);
    addSpecification("command template", "sacred flame aura");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::radiate## a sacred flame aura! Holy fire surrounds "
        "##InitiatorObjective##.");
    addSpecification("use ability deactivate message", "##InitiatorName##'s "
        "sacred flame aura fades.");
}
