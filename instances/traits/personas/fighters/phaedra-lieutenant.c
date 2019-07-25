//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "persona");
        addSpecification("name", "phaedra lieutenant");
        addSpecification("description", "You are a lieutenant in the Phaedra.");
        addSpecification("root", "fighter persona");
        "baseTrait"::reset(arg);
    }
}
