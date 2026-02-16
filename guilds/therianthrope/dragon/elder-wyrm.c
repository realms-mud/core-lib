//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elder Wyrm");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The offensive paths of the silver "
        "dragon merge into the form of an elder wyrm, wielding frost "
        "with devastating mastery.");

    addSpecification("limited by", ([ "research active": ({
        "/guilds/therianthrope/dragon/dragon-root.c" }) ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope", 
            "value": 67 ]));
    addPrerequisite("/guilds/therianthrope/dragon/primordial-dragon.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 3);
    addSpecification("bonus soak", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Frost Claw": 35, 
        "Tail Lash": 35, 
        "Frost Breath": 35,
        "Soul Freeze": 35, 
        "Frozen Blight": 35, 
        "Glacial Tempest": 35
    ]));
}