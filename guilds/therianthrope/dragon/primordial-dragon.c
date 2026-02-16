//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Primordial Dragon");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your dragon form reaches mythical "
        "proportions, channeling the power of the primordial silver "
        "dragons.");

    addSpecification("limited by", ([ "research active": ({
        "/guilds/therianthrope/dragon/dragon-root.c" }) ]));

    addPrerequisite("level",
        (["type":"level", 
            "guild": "therianthrope", 
            "value": 61 ]));

    addPrerequisite("/guilds/therianthrope/dragon/dragon-apotheosis.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 10);
    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Frost Claw": 30, 
        "Tail Lash": 35, 
        "Frost Breath": 30,
        "Soul Freeze": 30,
        "Frozen Blight": 30, 
        "Glacial Tempest": 30
    ]));
}
