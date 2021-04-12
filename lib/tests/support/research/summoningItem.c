//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/summoningResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Summon Weasel");
    addSpecification("source", "blarg");
    addSpecification("description", "I like weasels.");

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);
    addSpecification("stamina point cost", 25);

    addSpecification("number to summon", 2);
    addSpecification("maximum that can be summoned", 3);

    addSpecification("persona level", 5);
    addSpecification("persona", "weasel");
    addSpecification("modifiers", ([
        "/lib/tests/support/research/weaselBuff.c":({
            (["modifier": "bonus strength",
               "value": 3]),
            (["modifier": "bonus wisdom",
               "value" : 3]),
            (["modifier":"bonus hit points",
               "value" : 50]),
            (["modifier":"penalty to charisma",
               "value" : 1]),
            (["modifier":"bonus stamina points",
               "value" : -50]),
            (["modifier":"apply fortified",
               "value" : 1]),
        }),
        "/lib/tests/support/research/weaselMagic.c":({
            (["modifier": "apply research",
               "value": "/lib/tests/support/research/weaselSpell.c" ]),
        })
    ]));

    addSpecification("event handler", "weaselEvent");
    addSpecification("command template", "summon weasel");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::scream##, `Let there be weasels!'");
}
