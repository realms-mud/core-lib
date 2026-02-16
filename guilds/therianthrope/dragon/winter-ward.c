//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Winter Ward");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your connection to the silver dragon "
        "spirit infuses your scales with the essence of deepest winter, "
        "granting mastery over cold.");

    addSpecification("limited by", ([ "research active": ({
        "/guilds/therianthrope/dragon/dragon-root.c" }) ]));

    addPrerequisite("level",
        (["type":"level", "guild": "therianthrope", "value": 53 ]));
    addPrerequisite("/guilds/therianthrope/dragon/glacial-tempest.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 2);
    addSpecification("bonus resist cold", 5);
    addSpecification("bonus resist air", 5);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Frost Breath": 30, 
        "Soul Freeze": 25,
        "Frozen Blight": 30,
        "Glacial Tempest": 30
    ]));
}