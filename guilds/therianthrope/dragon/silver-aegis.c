//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Silver Aegis");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in dragon form, you wrap yourself "
        "in a shield of draconic frost, greatly enhancing your defenses "
        "at the cost of offensive power.");

    addPrerequisite("/guilds/therianthrope/dragon/dragons-fortitude.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 37
        ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/dragon/dragon-root.c"
        })
    ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 4);
    addSpecification("stamina point cost", 25);

    addSpecification("bonus dodge", 5);
    addSpecification("bonus defense", 3);
    addSpecification("bonus soak", 2);
    addSpecification("penalty to attack", 2);
    addSpecification("penalty to damage", 2);

    addSpecification("trait",
        "/guilds/therianthrope/dragon/silver-aegis-active.c");

    addSpecification("command template", "silver aegis");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::wrap## ##InitiatorPossessive## wings around "
        "##InitiatorPossessive## body as a shimmering frost barrier "
        "envelops ##InitiatorPossessive## silver scales!");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::unfurl## ##InitiatorPossessive## wings, releasing "
        "the frost barrier.");
}
