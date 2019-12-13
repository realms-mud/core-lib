//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "educational");
        addSpecification("name", "strategist");
        addSpecification("description", "You have a good mind for strategy.");
        addSpecification("root", "educated");
        addSpecification("opposing root", "uneducated");
        addSpecification("opinion", 10);
        addSpecification("bonus intelligence", 1);
        addSpecification("bonus ancient history", 1);
        addSpecification("bonus local history", 1);
        addSpecification("bonus engineering", 1);
        addSpecification("bonus mathematics", 1);
        addSpecification("bonus physics", 1);
        addSpecification("bonus reading", 1);
        addSpecification("bonus writing", 1);
        addSpecification("bonus perception", 2);
        addSpecification("bonus attack", 2);
        addSpecification("bonus defense", 2);
        addSpecification("cost", 1);
        "baseTrait"::reset(arg);
    }
}

