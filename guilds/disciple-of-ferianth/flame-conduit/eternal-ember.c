//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Ember");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill kindles an eternal ember of "
        "divine fire within your soul. While in conduit form, your inner "
        "flame sustains you.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 53
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/primordial-fire.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental fire", 4);
    addSpecification("bonus heal hit points rate", 3);
    addSpecification("bonus soak", 3);
}
