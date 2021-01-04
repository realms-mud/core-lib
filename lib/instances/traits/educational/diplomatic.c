//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "educational");
        addSpecification("name", "diplomatic");
        addSpecification("description", "You are very good at talking to others and working to get your desires through speech and compromise.");
        addSpecification("root", "educated");
        addSpecification("opposing root", "uneducated");
        addSpecification("opinion", 25);
        addSpecification("opposing opinion", 10);
        addSpecification("bonus charisma", 2);
        addSpecification("bonus perception", 2);
        addSpecification("bonus linguistics", 1);
        addSpecification("bonus etiquette", 2);
        addSpecification("bonus persuasion", 5);
        addSpecification("bonus barter", 2);
        addSpecification("bonus diplomacy", 5);
        addSpecification("cost", 2);
        "baseTrait"::reset(arg);
    }
}

