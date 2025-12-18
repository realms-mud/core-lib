//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sun-Touched");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill marks you as one touched by "
        "the divine sun. While in conduit form, you radiate solar intensity.");

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

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/phoenix-essence.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental fire", 4);
    addSpecification("bonus resist fire", 3);
    addSpecification("bonus spellcraft", 3);
}
