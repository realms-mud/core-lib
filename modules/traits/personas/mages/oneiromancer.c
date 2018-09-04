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
        addSpecification("type", "persona");
        addSpecification("name", "oneiromancer");
        addSpecification("description", "You are an oneiromancer.");
        addSpecification("root", "mage persona");
        addSpecification("bonus resist psionic", 75);
        "baseTrait"::reset(arg);
    }
}
