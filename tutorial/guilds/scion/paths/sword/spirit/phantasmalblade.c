//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        sustainedResearchItem::reset(arg);
        addSpecification("name", "Phantasmal Blade");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "");

        addPrerequisite("lib/tutorial/guilds/scion/paths/sword/root.c",
            (["type":"research"]));
        addPrerequisite("lib/tutorial/guilds/scion/paths/spirit.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("cooldown", 4);
        addSpecification("spell point cost", 10);
        addSpecification("stamina point cost", 50);
        addSpecification("command template", "phantasmal blade");
        addSpecification("bonus magical attack", 3);
        addSpecification("bonus resist magical", 3);
    }
}
