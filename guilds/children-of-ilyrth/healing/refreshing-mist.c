//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Refreshing Mist");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to enhance their connection to Ilyrth's healing essence. "
        "A subtle mist of divine energy surrounds the caster, gradually "
        "restoring their own vitality.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 3 ]));

    addPrerequisite("/guilds/children-of-ilyrth/healing/soothing-touch.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus heal hit points rate", 1);
    addSpecification("bonus heal spell points rate", 1);

    addSpecification("affected research", ([
        "Soothing Touch": 10
    ]));
    addSpecification("affected research type", "percentage");
}
