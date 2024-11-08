//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mithrannon");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a mixed maneuver where the dominant foot is "
        "forward, the pommel held just inside the knee with the tip "
        "pointed at the foe's face.");
    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Aegis Guard",
          "value": 31 ]));

    addPrerequisite("/guilds/aegis-guard/forms/sword-guarding/angannon.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Maetha": 25,
        "Hasto": 25,
        "Maego": 25,
        "Narcha": 25,
        "Athra": 50,
        "Celeg": 50
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 1);
    addSpecification("bonus defense", 3);
    addSpecification("bonus parry", 2);
}
