//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Recovery Cycle");
    addSpecification("source", "monk");
    addSpecification("description",
        "Trace the interval between one impact and the next. As the shield "
        "settles, its ripples guide spent chi back toward your center, "
        "completing a circle that violence would otherwise break.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":3
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/ward-anatomy.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Mana Shield":2,
        "Ward Mending":2,
        "Breath Conversion":3,
        "Measured Renewal":3,
        "Vigilant Renewal":3,
        "Sheltering Touch":2
    ]));

    addSpecification("related research", ({
        "/guilds/monk/mana-shield/breath-conversion.c",
        "/guilds/monk/mana-shield/recovery-habit.c"
    }));
}
