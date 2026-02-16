//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Silver Dragon Ascendant");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You have ascended beyond mere "
        "therianthropic transformation. Your dragon form is a force of "
        "primal winter itself, each strike carrying the weight of "
        "glacial epochs.");

    addSpecification("limited by", ([ "research active": ({
        "/guilds/therianthrope/dragon/dragon-root.c" }) ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope", 
            "value": 73 ]));
    addPrerequisite("/guilds/therianthrope/dragon/elder-wyrm.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 175);
    addSpecification("bonus attack", 4);
    addSpecification("bonus damage", 4);
    addSpecification("bonus dodge", 6);
    addSpecification("bonus defense", 6);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Frost Claw": 30, 
        "Tail Lash": 30, 
        "Frost Breath": 30,
        "Soul Freeze": 30, 
        "Frozen Blight": 30, 
        "Glacial Tempest": 30
    ]));
}
