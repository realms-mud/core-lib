//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Phoenix Essence");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill infuses your conduit form "
        "with the essence of the divine phoenix. You gain regenerative "
        "powers and resilience.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 41
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/molten-core.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal hit points rate", 3);
    addSpecification("bonus soak", 2);
    addSpecification("bonus resist fire", 2);
}
