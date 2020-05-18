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
        addSpecification("type", "persona");
        addSpecification("name", "hydra");
        addSpecification("description", "You are a hydra.");
        addSpecification("root", "large creature persona");
        addSpecification("bonus soak", 5);
        addSpecification("bonus heal hit points rate", 25);
        "baseTrait"::reset(arg);
    }
}
