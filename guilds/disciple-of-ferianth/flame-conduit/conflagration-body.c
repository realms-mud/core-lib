//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Conflagration Body");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill transforms your entire body "
        "into a walking conflagration while in conduit form.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 45
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/elemental-fury.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 4);
    addSpecification("bonus damage", 4);
}
