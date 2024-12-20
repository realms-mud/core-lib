//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Block Attack");
    addSpecification("source", "fighter");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of a technique that changes the fighter's next round "
        "of combat to be intent on blocking an opponent's attack with "
        "a shield.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "fighter",
          "value": 1 ]));

    addSpecification("limited by", (["equipment":({ "shield" })]));

    addPrerequisite("/guilds/fighter/shields/root.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name" : "shield",
            "formula" : "additive",
            "rate" : 1.5
        ]),
        ([
            "type": "skill",
            "name": "parry",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "physics",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 6);

    addSpecification("stamina point cost", 25);

    addSpecification("bonus shield", 15);
    addSpecification("bonus defense", 15);
    addSpecification("bonus soak", 5);
    addSpecification("duration", 3);

    addSpecification("event handler", "blockEvent");
    addSpecification("command template", "block");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::ready## ##InitiatorPossessive## shield against "
        "oncoming attacks.");
}
