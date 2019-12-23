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
        addSpecification("type", "health");
        addSpecification("name", "hallucinating");
        addSpecification("description", "You are under the influence of hallucinogens.");
        addSpecification("root", "biological");
        addSpecification("opinion", -75);
        addSpecification("duration", 300);
        addSpecification("expire message", "You are no longer hallucinating.");
        "baseTrait"::reset(arg);
    }
}
