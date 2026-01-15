//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Soul of Fire");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of transforming their very soul into living fire, gaining "
        "immense magical power.");
    addSpecification("usage summary", "Sustained transformation enhancing spell power");

    addPrerequisite("/guilds/disciple-of-ferianth/ember-arts/blazing-barrier.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 39
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("hit point cost", 100);

    addSpecification("bonus spell points", 150);
    addSpecification("bonus elemental fire", 10);
    addSpecification("bonus intelligence", 2);

    addSpecification("modifiers", ({ 
        ({
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ember-arts/divine-ember-potency.c",
            "name": "Divine Ember Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        }),
        ({
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ember-arts/master-ember-potency.c",
            "name": "Master Ember Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        })
    }));

    addSpecification("cooldown", 30);
    addSpecification("command template", "soul of fire");

    addSpecification("use ability activate message", "##InitiatorName##'s "
        "soul ##Infinitive::ignite## with divine fire! ##InitiatorSubjective## "
        "##Infinitive::become## a living embodiment of flame.");
    addSpecification("use ability deactivate message", "##InitiatorName##'s "
        "soul of fire returns to mortal form.");
}
