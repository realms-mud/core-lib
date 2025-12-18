//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fire Resistance");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill deepens your resistance "
        "to fire while in conduit form, though it further weakens you "
        "against water and cold.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 17
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/smoldering-skin.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist fire", 5);
    addSpecification("penalty to resist water", 2);
    addSpecification("penalty to resist cold", 2);
}
