//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ancient Wyrm");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You channel the essence of the ancient "
        "silver wyrms, gaining tremendous combat prowess and a more "
        "fearsome draconic form.");

    addSpecification("limited by", ([ "research active": ({
        "/guilds/therianthrope/dragon/dragon-root.c" }) ]));

    addPrerequisite("level",
        (["type":"level", "guild": "therianthrope", "value": 53 ]));
    addPrerequisite("/guilds/therianthrope/dragon/boreal-fury.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 15);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 1);
    addSpecification("bonus soak", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Frost Claw": 25, 
        "Tail Lash": 25, 
        "Frost Breath": 25,
        "Soul Freeze": 25, 
        "Frozen Blight": 25, 
        "Glacial Tempest": 25
    ]));
}
