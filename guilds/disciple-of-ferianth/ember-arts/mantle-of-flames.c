//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mantle of Flames");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of cloaking themselves in a mantle of divine flames, "
        "becoming a fearsome avatar of fire.");
    addSpecification("usage summary", "Powerful sustained offensive fire transformation");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/radiant-presence.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 51
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 150);

    addSpecification("bonus fire attack", 20);
    addSpecification("bonus attack", 8);
    addSpecification("bonus damage", 5);
    addSpecification("bonus resist fire", 50);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ember-arts/master-ember-potency.c",
            "name": "Master Ember Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ember-arts/supreme-ember-potency.c",
            "name": "Supreme Ember Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.35
        ])
    }));

    addSpecification("cooldown", 60);
    addSpecification("command template", "mantle of flames");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::cloak## ##InitiatorReflexive## in a mantle of divine flames! "
        "Fire dances around ##InitiatorObjective## in spectacular fashion.");
    addSpecification("use ability deactivate message", "##InitiatorName##'s "
        "mantle of flames dissipates.");
}