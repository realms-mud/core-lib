//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/summoningResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pan's Mephit");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "/guilds/bard/compositions/root.c");
    addSpecification("composite type", "instrumental solo");
    addSpecification("composite class", "woodwind");
    addSpecification("default composite description",
        "simple Ab7 arpeggio");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of a mephit-summoning arpeggio that can be played with "
        "woodwind and brass instruments.");

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 5
    ]));

    addPrerequisite("/guilds/bard/woodwind-brass/root.c",
        (["type":"research"]));

    addSpecification("limited by", ([
        "equipment":({ "instrument: woodwind", "instrument: brass" }),
    ]));

    addSpecification("number to summon", 1);
    addSpecification("persona level", 5);
    addSpecification("persona", "sonic mephit");

    addSpecification("modifiers", ([
        "/guilds/bard/woodwind-brass/mephits-of-malice.c":({
            (["modifier": "bonus attack",
               "value": 5 ]),
            (["modifier": "bonus damage",
               "value": 2 ]),
            (["modifier":"bonus hit points",
               "value" : 100]),
        }),
        "/guilds/bard/woodwind-brass/serenade-to-a-mephit.c":({
            (["modifier":"bonus defense",
               "value": 5 ]),
            (["modifier":"bonus soak",
               "value": 2 ]),
            (["modifier":"bonus hit points",
               "value" : 100]),
        }),
        "/guilds/bard/woodwind-brass/mephit-minstrel.c":({
            (["modifier": "bonus attack",
               "value": 4 ]),
            (["modifier":"bonus defense",
               "value": 4 ]),
            (["modifier": "bonus damage",
               "value": 2 ]),
            (["modifier":"bonus soak",
               "value": 2 ]),
        }),
        "/guilds/bard/woodwind-brass/menace-of-a-mephit.c":({
            (["modifier": "bonus destruction",
               "value": 20 ]),
            (["modifier":"bonus spell points",
               "value" : 100 ]),
        }),
        "/guilds/bard/woodwind-brass/lay-of-mephias.c":({
            (["modifier": "bonus spellcraft",
               "value": 20 ]),
            (["modifier":"bonus spell points",
               "value" : 100 ]),
        }),
        "/guilds/bard/woodwind-brass/a-mephits-ballad.c":({
            (["modifier": "bonus attack",
               "value": 8 ]),
            (["modifier":"bonus defense",
               "value": 8 ]),
            (["modifier": "bonus damage",
               "value": 5 ]),
            (["modifier":"bonus soak",
               "value": 5 ]),
        }),
        "/guilds/bard/woodwind-brass/march-of-the-mephits.c":({
            (["modifier": "bonus heal hit points",
               "value": 10 ]),
            (["modifier":"bonus heal spell points",
               "value": 10 ]),
            (["modifier": "bonus heal hit points rate",
               "value": 5 ]),
            (["modifier":"bonus heal spell points rate",
               "value": 5 ]),
        }),
    ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 50);

    addSpecification("event handler", "pansMephitEvent");
    addSpecification("use composite message", "##InitiatorName## "
        "##Infinitive::intone## a ##CompositeSegment## on "
        "##InitiatorPossessive## ##InitiatorWeapon##.");
}
