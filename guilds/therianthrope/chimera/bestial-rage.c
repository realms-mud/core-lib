//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bestial Rage");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in chimera form, you can surrender "
        "to bestial fury, greatly enhancing your offensive power at the "
        "cost of defensive awareness.");

    addPrerequisite("/guilds/therianthrope/chimera/goats-tenacity.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 33
        ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 4);
    addSpecification("stamina point cost", 25);

    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 3);
    addSpecification("penalty to dodge", 3);
    addSpecification("penalty to defense", 1);

    addSpecification("trait",
        "/guilds/therianthrope/chimera/bestial-rage-active.c");

    addSpecification("command template", "bestial rage");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::throw## back ##InitiatorPossessive## heads and "
        "##Infinitive::roar## with unhinged fury, eyes blazing with "
        "primal rage!");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::regain## ##InitiatorPossessive## composure, the "
        "bestial rage fading from ##InitiatorPossessive## eyes.");
}
