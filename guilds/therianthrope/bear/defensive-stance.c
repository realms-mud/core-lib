//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Unyielding Guard");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in bear form, you can hunker down "
        "into an immovable defensive posture, bracing like a mountain against "
        "incoming blows. This greatly increases your ability to defend "
        "against attacks but reduces your offensive power.");

    addPrerequisite("/guilds/therianthrope/bear/den-mother.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 15
        ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/bear/bear-root.c"
        })
    ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 4);
    addSpecification("stamina point cost", 25);

    addSpecification("trait",
        "/guilds/therianthrope/bear/defensive-stance-active.c");

    addSpecification("command template", "unyielding guard");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::hunker## down on all fours, lowering "
        "##InitiatorPossessive## massive head and bracing like a mountain "
        "against incoming blows!");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::rise## from ##InitiatorPossessive## immovable posture, "
        "ready to strike once more.");
}
