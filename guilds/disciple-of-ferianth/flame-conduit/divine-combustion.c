//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Combustion");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill grants you mastery over divine "
        "combustion. While in conduit form, your flames carry Ferianth's "
        "blessing.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 61
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/avatar-of-flame.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental fire", 5);
    addSpecification("bonus damage", 5);
    addSpecification("bonus magical essence", 4);
}
