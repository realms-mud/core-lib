//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "educational");
        addSpecification("name", "tactician");
        addSpecification("description", "You have a good mind for tactics.");
        addSpecification("root", "educated");
        addSpecification("opposing root", "uneducated");
        addSpecification("opinion", 10);
        addSpecification("bonus intelligence", 2);
        addSpecification("bonus ancient history", 1);
        addSpecification("bonus local history", 1);
        addSpecification("bonus engineering", 1);
        addSpecification("bonus mathematics", 1);
        addSpecification("bonus physics", 1);
        addSpecification("bonus reading", 1);
        addSpecification("bonus writing", 1);
        addSpecification("bonus perception", 5);
        addSpecification("bonus attack", 4);
        addSpecification("bonus defense", 4);
        addSpecification("cost", 2);
        "baseTrait"::reset(arg);
    }
}

