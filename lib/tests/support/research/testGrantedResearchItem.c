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
        addSpecification("name", "Granted research");
        addSpecification("source", "quests");
        addSpecification("description", "This is granted research");
        addSpecification("scope", "self");
        addSpecification("research type", "granted");
        addSpecification("bonus strength", 2);
        addSpecification("bonus long sword", 5);
        addSpecification("bonus fire attack", 15);
        addSpecification("bonus weapon attack", 2);
        addSpecification("bonus spell points", 5);
    }
}
