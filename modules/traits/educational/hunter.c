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
        addSpecification("name", "hunter");
        addSpecification("description", "You have a knack for tracking and killing creatures of all kinds");
        addSpecification("root", "educated");
        addSpecification("opposing root", "uneducated");
        addSpecification("opinion", 10);
        addSpecification("bonus dagger", 1);
        addSpecification("bonus bow", 1);
        addSpecification("bonus sling", 1);
        addSpecification("bonus thrown", 1);
        addSpecification("bonus bowyer and fletcher", 1);
        addSpecification("bonus perception", 2);
        addSpecification("bonus astronomy", 1);
        addSpecification("bonus local history", 1);
        addSpecification("bonus navigation", 2);
        addSpecification("bonus zoology", 2);
        addSpecification("bonus disable traps", 1);
        addSpecification("bonus find traps", 1);
        addSpecification("bonus search", 1);
        addSpecification("bonus move silently", 1);
        addSpecification("bonus listen", 1);
        addSpecification("bonus hide", 1);
        addSpecification("bonus direction sense", 1);
        addSpecification("bonus set traps and snares", 1);
        addSpecification("bonus spot", 2);
        addSpecification("bonus tracking", 2);
        addSpecification("bonus hunting", 5);
        addSpecification("bonus weather sense", 1);
        addSpecification("cost", 2);
        "baseTrait"::reset(arg);
    }
}

