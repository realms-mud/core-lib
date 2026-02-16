//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mythic Dragon");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The offensive and defensive paths of "
        "the silver dragon merge into one unified, mythic form. You are "
        "an avatar of draconic winter, wielding frost and claw with "
        "unmatched mastery.");

    addSpecification("limited by", ([ "research active": ({
        "/guilds/therianthrope/dragon/dragon-root.c" }) ]));

    addPrerequisite("level",
        (["type":"level", 
            "guild": "therianthrope", 
            "value": 79 ]));
    addPrerequisite("/guilds/therianthrope/dragon/silver-dragon-ascendant.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 5);
    addSpecification("bonus soak", 3);
    addSpecification("bonus dodge", 3);

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