//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ghostly Reflexes");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your panther form becomes almost "
        "incorporeal in its evasiveness, dodging attacks with supernatural ease.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 27
        ]));

    addPrerequisite("/guilds/therianthrope/panther/night-eyes.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 3);
    addSpecification("bonus parry", 3);
    addSpecification("bonus resist physical", 2);
    addSpecification("bonus resist magical", 3);
    addSpecification("bonus resist energy", 3);
}