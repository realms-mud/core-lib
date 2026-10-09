//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Serpent Aspect");
    addSpecification("source", "druid");
    addSpecification("description", "This research allows the druid to channel the patient lethality of the great serpents, entering a stance of precise, venomous efficiency.");

    addPrerequisite("/guilds/druid/wild-shape/root.c",
        ([ "type": "research" ]));

    addPrerequisite("level", ([
        "type": "level",
        "guild": "druid",
        "value": 27
    ]));

    addPrerequisite("/guilds/druid/wild-shape/eagle-aspect.c",
        ([ "type": "research" ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);
    addSpecification("stamina point cost", 25);
    addSpecification("cooldown", 180);
    addSpecification("bonus attack", 6);
    addSpecification("bonus damage", 5);
    addSpecification("bonus parry", 6);
    addSpecification("modifiers", ({
    ([
        "type": "skill",
        "name": "nature",
        "formula": "additive",
        "rate": 0.1
    ]),
    ([
        "type": "skill",
        "name": "unarmed",
        "formula": "additive",
        "rate": 0.15
    ]),
    ([
        "type": "level",
        "name": "druid",
        "formula": "logarithmic",
        "rate": 1.05
    ]),
    ([
        "type": "attribute",
        "name": "strength",
        "formula": "logarithmic",
        "rate": 1.15
    ]),
    ([
        "type": "attribute",
        "name": "constitution",
        "formula": "additive",
        "rate": 0.05
    ]),
    }));
    addSpecification("command template", "serpent aspect");
    addSpecification("use ability activate message", "##InitiatorName## ##Infinitive::draw## slow, deliberate breaths, movement ##Infinitive::become## unnervingly smooth and precise as the serpent's nature ##Infinitive::flow## into ##InitiatorPossessive## limbs.");
    addSpecification("use ability deactivate message", "##InitiatorName## ##Infinitive::release## the serpent aspect, returning to normal form.");
}
