//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lelyan Isilme");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a maneuver wherein a counter-attack is placed "
        "after an opponent has pulled back from an attack, missed on "
        "an attack, or has attempted another action in place of an attack.");

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Aegis Guard",
          "value": 16 ]));

    addPrerequisite("/guilds/aegis-guard/forms/sword-attacks/nistaros.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Naetho": 25,
        "Maetha": 15,
        "Hasto": 15,
        "Maego": 15,
        "Narcha": 15,
        "Raeg": 25,
        "Lanc": 25,
        "Gleina": 25
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dagger", 1);
    addSpecification("bonus short sword", 1);
    addSpecification("bonus long sword", 1);
    addSpecification("bonus hand and a half sword", 1);
    addSpecification("bonus two-handed sword", 1);
    addSpecification("bonus attack", 2);
    addSpecification("equivalence", "nachreisen");
}
