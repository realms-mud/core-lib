//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hunter's Crouch");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in panther form, you can coil low "
        "to the ground in a predatory crouch, channeling all focus into the "
        "kill. This greatly increases your ability to land attacks but "
        "reduces your defensive capabilities.");

    addPrerequisite("/guilds/therianthrope/panther/predatory-grace.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 15
        ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 4);
    addSpecification("stamina point cost", 25);

    addSpecification("trait",
        "/guilds/therianthrope/panther/offensive-stance-active.c");

    addSpecification("command template", "hunter's crouch");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::drop## low to the ground, muscles coiled and eyes "
        "locked on ##InitiatorPossessive## prey with lethal intent!");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::relax## from ##InitiatorPossessive## predatory "
        "crouch.");
}
