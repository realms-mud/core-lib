//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Infernal Veins");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill causes liquid fire to flow "
        "through your veins while in conduit form, increasing your combat "
        "prowess.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 25
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/heart-of-cinders.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental fire", 2);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 2);
}
