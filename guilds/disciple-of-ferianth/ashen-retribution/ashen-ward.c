//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ashen Ward");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of wreathing themselves in protective flames that shield "
        "against harm.");

    addPrerequisite("/guilds/disciple-of-ferianth/ashen-retribution/root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 7
        ]));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ashen-retribution/enhanced-ward.c",
            "name": "Enhanced Ward",
            "formula": "additive",
            "base value": 3,
            "rate": 1.0
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ashen-retribution/greater-ward.c",
            "name": "Greater Ward",
            "formula": "additive",
            "base value": 3,
            "rate": 1.0
        ]),
    }));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 30);
    addSpecification("cooldown modifiers", ([
        "/guilds/disciple-of-ferianth/ashen-retribution/quickened-ward.c": 10,
    ]));
    addSpecification("spell point cost", 50);

    addSpecification("bonus resist fire", 5);
    addSpecification("bonus defense", 2);

    addSpecification("event handler", "ashenWardEvent");
    addSpecification("command template", "ashen ward");

    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::become## wreathed in protective flames that form "
        "an ashen ward.");
    addSpecification("use ability deactivate message", "The ashen ward "
        "around ##InitiatorName## dissipates into wisps of smoke.");
}
