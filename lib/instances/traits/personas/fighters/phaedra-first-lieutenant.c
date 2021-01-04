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
        addSpecification("type", "persona");
        addSpecification("name", "phaedra first lieutenant");
        addSpecification("description", "You are a first lieutenant in the Phaedra.");
        addSpecification("root", "fighter persona");
        "baseTrait"::reset(arg);
    }
}
