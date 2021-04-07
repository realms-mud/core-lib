//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/summoningResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "The Wailing Cat");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "guilds/bard/compositions/root.c");
    addSpecification("composite type", "instrumental rhythm");
    addSpecification("composite class", "woodwind");
    addSpecification("default composite description",
        "simple Ab major arpeggio");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of a cat-summoning arpeggio that can be played with "
        "woodwind and brass instruments.");

    addPrerequisite("guilds/bard/woodwind-brass/root.c",
        (["type":"research"]));

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 3
    ]));

    addSpecification("limited by", ([
        "equipment":({ "instrument: woodwind", "instrument: brass" }),
        "environment": ({ "keeper's temple", "tol-dhurath", "city",
            "rural", "hilly rural", "forest village", "riverside village",
            "riverside city", "lakeside village", "lakeside city",
            "stone keep", "limestone building", "granite building",
            "brick building", "wooden building", "opulent building",
            "wooden keep", "palace", "stone castle", "wooden castle",
            "elvish forest" })
    ]));

    addSpecification("number to summon", 1);
    addSpecification("maximum that can be summoned", 3);
    addSpecification("persona level", 5);
    addSpecification("persona", "cat");

    addSpecification("modifiers", ([
        "guilds/bard/woodwind-brass/creatures-of-might.c":({
            (["modifier": "bonus strength",
               "value": 4 ]),
            (["modifier": "bonus dexterity",
               "value": 4 ]),
            (["modifier": "bonus attack",
               "value": 10 ]),
            (["modifier": "bonus damage",
               "value": 6 ]),
            (["modifier":"bonus hit points",
               "value" : 200]),
        }),
        "guilds/bard/woodwind-brass/denizens-dance.c":({
            (["modifier": "bonus attack",
               "value": 20 ]),
            (["modifier": "bonus damage",
               "value": 10 ]),
            (["modifier":"bonus defense",
               "value": 10 ]),
            (["modifier":"bonus hit points",
               "value" : 300]),
        }),
        "guilds/bard/woodwind-brass/call-of-the-cats.c":({
            (["modifier": "bonus heal hit points",
               "value": 10 ]),
            (["modifier":"bonus heal spell points",
               "value": 10 ]),
            (["modifier": "bonus heal hit points rate",
               "value": 5 ]),
            (["modifier":"bonus heal spell points rate",
               "value": 5 ]),
        }),
        "guilds/bard/woodwind-brass/dexterous-denizens.c":({
            (["modifier": "bonus dexterity",
               "value": 6 ]),
            (["modifier":"bonus dodge",
               "value": 10 ]),
            (["modifier":"bonus no armor",
               "value": 10 ]),
        }),
    ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 30);
    addSpecification("stamina point cost", 30);

    addSpecification("event handler", "wailingCatEvent");
    addSpecification("use composite message", "##InitiatorName## "
        "##Infinitive::play## a ##CompositeSegment## on "
        "##InitiatorPossessive## ##InitiatorWeapon##.");
}
