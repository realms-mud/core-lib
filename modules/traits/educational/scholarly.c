//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "educational");
        addSpecification("name", "scholarly");
        addSpecification("description", "You have spent a great deal of time in study.");
        addSpecification("root", "educated");
        addSpecification("opposing root", "uneducated");
        addSpecification("opinion", 15);
        addSpecification("bonus intelligence", 2);
        addSpecification("bonus ancient history", 4);
        addSpecification("bonus local history", 4);
        addSpecification("bonus astronomy", 2);
        addSpecification("bonus chemistry", 2);
        addSpecification("bonus engineering", 2);
        addSpecification("bonus geology", 2);
        addSpecification("bonus mathematics", 4);
        addSpecification("bonus linguistics", 4);
        addSpecification("bonus philosophy", 4);
        addSpecification("bonus physics", 2);
        addSpecification("bonus reading", 5);
        addSpecification("bonus writing", 5);
        addSpecification("cost", 2);
        "baseTrait"::reset(arg);
    }
}

