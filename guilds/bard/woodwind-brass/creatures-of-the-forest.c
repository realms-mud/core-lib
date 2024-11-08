//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/summoningResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Creatures of the Forest");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "/guilds/bard/compositions/root.c");
    addSpecification("composite type", "instrumental rhythm");
    addSpecification("composite class", "woodwind");
    addSpecification("default composite description",
        "simple G major arpeggio");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of a fox-summoning arpeggio that can be played with "
        "woodwind and brass instruments.");

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 3
    ]));

    addPrerequisite("/guilds/bard/woodwind-brass/root.c",
        (["type":"research"]));

    addSpecification("limited by", ([
        "equipment":({ "instrument: woodwind", "instrument: brass" }),
        "environment": ({ "forest", "hilly forest", "mountainous forest",
            "rural", "hilly rural", "forest village", "riverside forest",
            "rocky lakeside forest", "sandy lakeside forest",
            "elvish forest" })
    ]));

    addSpecification("number to summon", 1);
    addSpecification("maximum that can be summoned", 3);
    addSpecification("persona level", 5);
    addSpecification("persona", "red fox");

    addSpecification("modifiers", ([
        "/guilds/bard/woodwind-brass/creatures-of-might.c":({
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
        "/guilds/bard/woodwind-brass/denizens-dance.c":({
            (["modifier": "bonus attack",
               "value": 20 ]),
            (["modifier": "bonus damage",
               "value": 10 ]),
            (["modifier":"bonus defense",
               "value": 10 ]),
            (["modifier":"bonus hit points",
               "value" : 300]),
        }),
        "/guilds/bard/woodwind-brass/flight-of-the-fox.c":({
            (["modifier": "bonus heal hit points",
               "value": 10 ]),
            (["modifier":"bonus heal spell points",
               "value": 10 ]),
            (["modifier": "bonus heal hit points rate",
               "value": 5 ]),
            (["modifier":"bonus heal spell points rate",
               "value": 5 ]),
        }),
        "/guilds/bard/woodwind-brass/dexterous-denizens.c":({
            (["modifier": "bonus dexterity",
               "value": 6 ]),
            (["modifier":"bonus dodge",
               "value": 10 ]),
            (["modifier": "bonus no armor",
               "value": 10 ]),
        }),
    ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 30);
    addSpecification("stamina point cost", 30);

    addSpecification("event handler", "creaturesOfTheForestEvent");
    addSpecification("use composite message", "##InitiatorName## "
        "##Infinitive::play## a ##CompositeSegment## on "
        "##InitiatorPossessive## ##InitiatorWeapon##.");
}
