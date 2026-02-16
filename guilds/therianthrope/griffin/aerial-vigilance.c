//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aerial Vigilance");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in griffin form, you take to a "
        "watchful aerial perch, greatly enhancing your evasion and defense "
        "at the cost of offensive power.");

    addPrerequisite("/guilds/therianthrope/griffin/iron-feathers.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 27
        ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/griffin/griffin-root.c"
        })
    ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 4);
    addSpecification("stamina point cost", 25);

    addSpecification("bonus dodge", 5);
    addSpecification("bonus defense", 3);
    addSpecification("penalty to attack", 2);
    addSpecification("penalty to damage", 1);

    addSpecification("trait",
        "/guilds/therianthrope/griffin/aerial-vigilance-active.c");

    addSpecification("command template", "aerial vigilance");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::spread## ##InitiatorPossessive## wings wide and "
        "##Infinitive::take## to a watchful, circling posture high above "
        "the battlefield!");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::fold## ##InitiatorPossessive## wings and "
        "##Infinitive::descend## to engage directly once more.");
}
