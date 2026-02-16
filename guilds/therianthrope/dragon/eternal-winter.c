//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Winter");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your draconic frost takes on an eternal "
        "quality, clinging endlessly and deepening your cold attacks.");

    addSpecification("limited by", ([ "research active": ({
        "/guilds/therianthrope/dragon/dragon-root.c" }) ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 67 ]));
    addPrerequisite("/guilds/therianthrope/dragon/silver-dominion.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus cold enchantment", 3);
    addSpecification("bonus damage", 3);
    addSpecification("bonus defense", 3);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Frost Breath": 30,
        "Soul Freeze": 30,
        "Frozen Blight": 35,
        "Glacial Tempest": 30
    ]));
}