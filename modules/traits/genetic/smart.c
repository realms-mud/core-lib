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
        addSpecification("type", "genetic");
        addSpecification("name", "smart");
        addSpecification("description", "You are a person with exceptional "
            "intelligence and creativity.");
        addSpecification("root", "intelligent");
        addSpecification("opposing root", "unintelligent");
        addSpecification("opinion", 5);
        addSpecification("bonus intelligence", 2);
        addSpecification("cost", 1);
        "baseTrait"::reset(arg);
    }
}

