//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream God");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "ultimate expression of dream magic mastery. The oneiromancer becomes "
        "a living conduit to the dream realm, their form flickering between "
        "reality and nightmare as they wield godlike power over the minds "
        "of all who oppose them.");
    addSpecification("usage summary", "The ultimate sustained ability that "
        "dramatically increases combat capabilities");

    addPrerequisite("/guilds/oneiromancer/dream-magic/master-of-dreams.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 67
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 200);

    addSpecification("bonus psionic attack", 15);
    addSpecification("bonus attack", 10);
    addSpecification("bonus damage", 5);
    addSpecification("bonus defense", 15);
    addSpecification("bonus soak", 5);
    addSpecification("bonus resist psionic", 20);
    addSpecification("bonus resist magical", 10);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.20
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
            "rate": 1.15
        ]),
    }));

    addSpecification("cooldown", 300);
    addSpecification("event handler", "dreamGodEvent");
    addSpecification("command template", "dream god");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::ascend## to godhood, ##InitiatorPossessive## form "
        "becoming a living conduit between the waking world and the infinite "
        "realm of dreams.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::relinquish## ##InitiatorPossessive## divine connection "
        "to the dream realm, returning to mortal form.");
}
