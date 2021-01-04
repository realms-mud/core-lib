//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Alagos Tir Angannon");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a defensive maneuver where the dominant foot is "
            "forward and the other foot placed sideways, both knees bent. The "
            "pommel is held just inside and above the knee with the tip "
            "pointed at the foe's face. From this position, it is possible to "
            "easily launch several cuts and thrusts.");
        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Aegis Guard",
              "value": 7 ]));

        addPrerequisite("guilds/aegis-guard/forms/sword-guarding/angannon.c",
            (["type":"research"]));

        addSpecification("affected research", ([
            "Ercho": 25,
            "Nestegi": 25
        ]));
        addSpecification("affected research type", "percentage");

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus defense", 2);
        addSpecification("bonus attack", 1);
        addSpecification("bonus parry", 2);
        addSpecification("equivalence", "porta di ferro e stretta");
    }
}
