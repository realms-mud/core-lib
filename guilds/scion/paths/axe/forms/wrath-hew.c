//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wrath Hew");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a master hew - the wrath hew. This is a powerful "
        "diagonal hewing stroke dealt from the wrath guard and ending "
        "in a wechsel guard on the opposite side. When used to displace "
        "another hew, the impact and weapon binding will result in the hew "
        "ending in a hanging parry.");
    addSpecification("limited by", (["equipment":({ "axe" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Scion of Dhuras",
          "value": 15 ]));

    addPrerequisite("/guilds/scion/paths/axe/forms/over-hew.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/axe/forms/wrath-guard.c",
        (["type":"research"]));
    addPrerequisite("/guilds/scion/paths/axe/forms/wechsel.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus axe", 1);
    addSpecification("bonus attack", 2);
    addSpecification("bonus damage", 2);
}
