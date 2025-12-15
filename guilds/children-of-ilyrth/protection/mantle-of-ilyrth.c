//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mantle of Ilyrth");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the mantle of Ilyrth spell - the ultimate protective "
        "ability. The goddess wraps her divine mantle around the caster and "
        "all allies, granting supreme protection from all harm.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 67 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/divine-carapace.c",
        (["type":"research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 350);
    addSpecification("stamina point cost", 200);

    addSpecification("bonus defense", 15);
    addSpecification("bonus soak", 20);
    addSpecification("bonus resist physical", 25);
    addSpecification("bonus resist magical", 25);
    addSpecification("bonus damage reflection", 10);

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "divine essence",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.50
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.25
        ])
    }));

    addSpecification("cooldown", 600);
    addSpecification("event handler", "mantleOfIlrythEvent");
    addSpecification("command template", "mantle of ilyrth");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::call## upon the goddess as Ilryth's divine mantle "
        "descends from the heavens, wrapping around all nearby allies in "
        "an ethereal embrace of sacred water and light.");
    addSpecification("use ability deactivate message", "Ilryth's divine "
        "mantle ascends back to the heavens, leaving a profound sense of "
        "the goddess's blessing.");
}
