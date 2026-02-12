//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Night Eyes");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The panther's nocturnal nature grants you "
        "enhanced stamina recovery and heightened resilience while transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 23
        ]));

    addPrerequisite("/guilds/therianthrope/panther/lithe-form.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal stamina", 5);
    addSpecification("bonus heal stamina rate", 2);
    addSpecification("bonus resist psionic", 3);
}
