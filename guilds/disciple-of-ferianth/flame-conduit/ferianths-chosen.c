//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ferianth's Chosen");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill marks you as one of Ferianth's "
        "chosen vessels. While in conduit form, you wield her divine fire "
        "with supreme mastery.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 65
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/divine-combustion.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental fire", 6);
    addSpecification("bonus spellcraft", 5);
    addSpecification("bonus resist fire", 5);
    addSpecification("bonus defense", 2);
    addSpecification("bonus soak", 2);
}
