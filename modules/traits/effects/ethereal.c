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
        addSpecification("type", "effect");
        addSpecification("name", "ethereal");
        addSpecification("description", "You are ethereal.");
        addSpecification("root", "ethereal");
        "baseTrait"::reset(arg);
    }
}
