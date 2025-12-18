//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ember Blood");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill infuses Ferianth's sacred fire "
        "into your very blood. While in flame conduit form, your inner heat "
        "enhances your magical potency.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 9
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/inner-spark.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental fire", 2);
    addSpecification("bonus damage", 1);
}
