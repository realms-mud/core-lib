//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fire Eternal");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill represents the ultimate mastery "
        "of the flame conduit form. You have become fire eternal - a perfect "
        "vessel for Ferianth's divine flame.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 67
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/ferianths-chosen.c",
        (["type":"research"]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/immortal-inferno.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental fire", 8);
    addSpecification("bonus attack", 8);
    addSpecification("bonus damage", 6);
    addSpecification("bonus resist fire", 8);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus wisdom", 1);
    addSpecification("bonus fire attack", 40);
}
