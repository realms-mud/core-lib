//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Wrath Smite");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a master smite - the wrath smite. This is a powerful "
            "diagonal smiteing stroke dealt from the wrath guard and ending "
            "in a wechsel guard on the opposite side. When used to displace "
            "another smite, the impact and weapon binding will result in the smite "
            "ending in a hanging parry.");
        addSpecification("limited by", (["equipment":({ "mace", "flail" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 15 ]));

        addPrerequisite("lib/guilds/scion/paths/mace/forms/over-smite.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/mace/forms/wrath-guard.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/mace/forms/wechsel.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus mace", 1);
        addSpecification("bonus flail", 1);
        addSpecification("bonus attack", 2);
        addSpecification("bonus damage", 2);
    }
}
